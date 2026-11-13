package PartB.PartA;


import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.*;
import java.util.function.Predicate;
import java.util.stream.Collectors;

class InvalidProductException extends Exception {
    InvalidProductException(String line) {
        super(String.format("Invalid product: %s", line));
    }
}

class CategoryNotFoundException extends Exception {
    CategoryNotFoundException(String category) {
        super(String.format("Category %s not found", category));
    }
}



abstract class Product implements Comparable<Product> {
    private int id;
    private String name;
    private String category;
    private double basePrice;
    private ArrayList<Integer> ratings = new ArrayList<>();



    public Product(int id, String name, String category, double basePrice) {
        this.id = id;
        this.name = name;
        this.category = category;
        this.basePrice = basePrice;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getCategory() {
        return category;
    }

    public double getBasePrice() {
        return basePrice;
    }

    public abstract double getFinalPrice();

    public abstract char getTypeCode();

    @Override
    public int compareTo(Product other) {
        int cmp = Double.compare(this.getFinalPrice(), other.getFinalPrice());
        if (cmp != 0) return cmp;

        cmp = this.name.compareTo(other.name);
        if (cmp != 0) return cmp;

        return Integer.compare(this.id, other.id);
    }

    @Override
    public String toString() {
        return String.format("%c %-5d %-15s %-12s %10.2f", getTypeCode(), id, name, category, getFinalPrice());
    }


    void addRating(int rating) {
        ratings.add(rating);
    }

    int getRatingCount() {
        return ratings.size();
    }

    double getAverageRating() {
        return ratings.stream().mapToDouble(Double::valueOf).average().orElse(0.0);
    }

    public static Product createProduct(String line) throws InvalidProductException {
        String [] parts = line.trim().split(";", -1);
        if(!(parts.length >= 6 && parts.length <= 7)) throw new InvalidProductException(line);

        for (int i = 0; i < parts.length; i++) parts[i] = parts[i].trim();

        String type = parts[0];
        String name = parts[2];
        String category = parts[3];


        String [] ratingsString = null;
        ArrayList<Integer> ratings = new ArrayList<>();


        if(parts.length == 7) {
            if(parts[6].isEmpty()) throw new InvalidProductException(line);
            ratingsString = parts[6].split(",", -1);
            try {
                for (int i = 0; i < ratingsString.length; i++) {
                    int rating = Integer.parseInt(ratingsString[i]);
                    if(rating < 1 || rating > 5) throw new InvalidProductException(line);
                    ratings.add(rating);
                }
            } catch (NumberFormatException e) {
                throw new InvalidProductException(line);
            }

        }



        try {
            int id = Integer.parseInt(parts[1]);
            double basePrice = Double.parseDouble(parts[4]);
            if (basePrice < 0) throw new InvalidProductException(line);

            Product p;
            if (type.equals("P")) {
                double weight = Double.parseDouble(parts[5]);
                if (weight <= 0) throw new InvalidProductException(line);
                p = new PhysicalProduct(id, name, category, basePrice, weight);
                for (Integer rating : ratings) {
                    p.addRating(rating);
                }
                return p;
            }
            if (type.equals("D")) {
                int sizeMb = Integer.parseInt(parts[5]);
                if (sizeMb <= 0) throw new InvalidProductException(line);
                p = new DigitalProduct(id, name, category, basePrice, sizeMb);
                for (Integer rating : ratings) {
                    p.addRating(rating);
                }
                return p;
            }

        } catch (NumberFormatException e) {
            throw new InvalidProductException(line);
        }
        throw new InvalidProductException(line);
    }
}



class PhysicalProduct extends Product {
    private double weight;

    public PhysicalProduct(int id, String name, String category, double basePrice, double weight) {
        super(id, name, category, basePrice);
        this.weight = weight;
    }

    public double getWeight() {
        return weight;
    }

    public double getShippingCost() {
        double basePrice = 60;

        if(weight <= 1) return basePrice;

        return basePrice + 30 * (weight - 1);
    }

    @Override
    public double getFinalPrice() {
        return getBasePrice() + getShippingCost();
    }

    @Override
    public char getTypeCode() {
        return 'P';
    }

    @Override
    public String toString() {
        return super.toString() + String.format(" | %.2f kg", weight);
    }
}


class DigitalProduct extends Product {
    int sizeMb;

    public DigitalProduct(int id, String name, String category, double basePrice, int sizeMb) {
        super(id, name, category, basePrice);
        this.sizeMb = sizeMb;
    }

    public int getSizeMb() {
        return sizeMb;
    }


    @Override
    public double getFinalPrice() {
        return getBasePrice() * 0.9;
    }

    @Override
    public char getTypeCode() {
        return 'D';
    }

    @Override
    public String toString() {
        return super.toString() + String.format(" | %d MB", sizeMb);
    }
}

class Store {
    private List<Product> products = new ArrayList<>();
    private int succesful = 0;
    private int invalid = 0;

    Store() {

    }

    public int readProducts(InputStream is) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(is));


        br.lines().forEach(x -> {
            try {
                if(x.trim().isEmpty()) return;
                products.add(Product.createProduct(x));
                this.succesful++;
            } catch (InvalidProductException e) {
                this.invalid++;
                e.getMessage();
            }
        });

        return this.succesful;
    }

    public int getInvalidLines() {
        return invalid;
    }

    public void printSorted(OutputStream os) {
        PrintWriter pw = new PrintWriter(os);
        products.stream().sorted().forEach(x -> pw.println(x.toString()));
        pw.flush();
    }

    public void printByCategory(OutputStream os, String category) throws CategoryNotFoundException {
        List<Product> filtered = products.stream().filter(x -> x.getCategory().equals(category)).sorted(Comparator.comparing(Product::getName,  String.CASE_INSENSITIVE_ORDER).thenComparing(Comparator.comparingDouble(Product::getFinalPrice).reversed()
        ).thenComparingInt(Product::getId)).collect(Collectors.toList());

        if(filtered.isEmpty()) throw new CategoryNotFoundException(category);
        PrintWriter pw = new PrintWriter(os);

        filtered.forEach(pw::println);


        pw.flush();
    }

    public void printStatistics(OutputStream os) {
        PrintWriter pw = new PrintWriter(os);

        if (products.isEmpty()) {
            pw.println("No products");
            pw.flush();
            return;
        }

        long physical = products.stream().filter(p -> p instanceof PhysicalProduct).count();


        Product cheapest = products.stream().min(Comparator.naturalOrder()).get();
        Product mostExpensive = products.stream().max(Comparator.naturalOrder()).get();
        double average = products.stream().mapToDouble(Product::getFinalPrice).average().orElse(0);


        pw.printf("Total: %d (physical: %d, digital: %d)%n", products.size(), physical, products.size() - physical);
        pw.println("Cheapest: " + cheapest);
        pw.println("Most expensive: " + mostExpensive);
        pw.printf("Average price: %.2f%n", average);
        pw.flush();

    }

//    void printTopRated(OutputStream os, int n) – prints the top n rated products. Only products with at least one rating are considered, sorted by:
//
//    average rating descending,
//    number of ratings descending,
//    final price ascending,
//    id ascending.

    public void printTopRated(OutputStream os, int n) {
        if(n < 1) throw new IllegalArgumentException();
        List<Product> topRated = products.stream().filter(x -> x.getAverageRating() > 0).sorted(Comparator.comparingDouble(Product::getAverageRating).reversed().thenComparing(Comparator.comparingInt(Product::getRatingCount).reversed()).thenComparingDouble(Product::getFinalPrice).thenComparingInt(Product::getId)).limit(n).collect(Collectors.toList());

        PrintWriter pw = new PrintWriter(os);


        int rank = 1;
        for (Product x : topRated) {
            pw.printf("%d. %-15s %.2f (%d)%n", rank++, x.getName(), x.getAverageRating(), x.getRatingCount());
        }

        if(rank == 1) {
            pw.printf("No rated products%n");
        }

        pw.flush();

    }


//    void printCategoryReport(OutputStream os) – for each category, in alphabetical order, prints statistics
//    of the final prices as: String.format("%-12s count: %d, min: %.2f, max: %.2f, avg: %.2f%n", category, count, min, max, average).
//    If there are no products, print No products. Tip: Collectors.groupingBy with TreeMap::new and Collectors.summarizingDouble.

    void printCategoryReport(OutputStream os) {
        PrintWriter pw = new PrintWriter(os);
        if (products.isEmpty()) {
            pw.println("No products");
            pw.flush();
            return;


        }


        TreeMap<String, DoubleSummaryStatistics> stats = products.stream().collect(Collectors.groupingBy(Product::getCategory, TreeMap::new, Collectors.summarizingDouble(Product::getFinalPrice)));

        for(Map.Entry<String, DoubleSummaryStatistics> e : stats.entrySet()) {
            DoubleSummaryStatistics s = e.getValue();
            pw.printf("%-12s count: %d, min: %.2f, max: %.2f, avg: %.2f%n",
                    e.getKey(), s.getCount(), s.getMin(), s.getMax(), s.getAverage());
        }

        List<String> categories = products.stream().map(Product::getCategory).distinct().sorted().collect(Collectors.toCollection(ArrayList::new));

        for (String category : categories) {
            DoubleSummaryStatistics s = products.stream().filter(p -> p.getCategory().equals(category)).mapToDouble(Product::getFinalPrice).summaryStatistics();

            pw.printf("%-12s count: %d, min: %.2f, max: %.2f, avg: %.2f%n", category, s.getCount(), s.getMin(), s.getMax(), s.getAverage());

        }


        TreeMap<String, DoubleSummaryStatistics> stats2 = products.stream().collect(
                Collectors.groupingBy(Product::getCategory, TreeMap::new, Collectors.summarizingDouble(Product::getFinalPrice)));

        for(Map.Entry<String, DoubleSummaryStatistics> t: stats2.entrySet()) {
            DoubleSummaryStatistics s = t.getValue();

            pw.printf("%-12s count: %d, min: %.2f, max: %.2f, avg: %.2f%n", t.getKey(), s.getCount(), s.getMin(), s.getMax(), s.getAverage());
        }

        pw.flush();
    }



    List<Product> filter(Predicate<? super Product> condition) {
        if(condition == null) throw new IllegalArgumentException();

        return products.stream().filter(condition).sorted().collect(Collectors.toList());
    }

}


public class StoreTest {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder productLines = new StringBuilder();
        String line;
        while ((line = br.readLine()) != null && !line.trim().equals("COMMANDS")) {
            productLines.append(line).append("\n");
        }

        Store store = new Store();
        int read = store.readProducts(
                new ByteArrayInputStream(productLines.toString().getBytes(StandardCharsets.UTF_8)));
        System.out.println("Read products: " + read);
        System.out.println("Invalid lines: " + store.getInvalidLines());

        while ((line = br.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty()) continue;
            String[] parts = line.split("\\s+");
            System.out.println("=== " + line + " ===");
            switch (parts[0]) {
                case "SORTED":
                    store.printSorted(System.out);
                    break;
                case "CATEGORY":
                    try {
                        store.printByCategory(System.out, parts[1]);
                    } catch (CategoryNotFoundException e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                case "STATS":
                    store.printStatistics(System.out);
                    break;
                default:
                    System.out.println("Unknown command");
            }
        }
    }
}