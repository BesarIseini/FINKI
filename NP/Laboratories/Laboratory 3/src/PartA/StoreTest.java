package PartA;


import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;
import java.nio.charset.StandardCharsets;

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

    public static Product createProduct(String line) throws InvalidProductException {
        String [] parts = line.trim().split(";", -1);
        if(parts.length != 6) throw new InvalidProductException(line);

        for (int i = 0; i < parts.length; i++) parts[i] = parts[i].trim();

        String type = parts[0];
        String name = parts[2];
        String category = parts[3];


        try {
            int id = Integer.parseInt(parts[1]);
            double basePrice = Double.parseDouble(parts[4]);
            if (basePrice < 0) throw new InvalidProductException(line);

            if (type.equals("P")) {
                double weight = Double.parseDouble(parts[5]);
                if (weight <= 0) throw new InvalidProductException(line);
                return new PhysicalProduct(id, name, category, basePrice, weight);
            }
            if (type.equals("D")) {
                int sizeMb = Integer.parseInt(parts[5]);
                if (sizeMb <= 0) throw new InvalidProductException(line);
                return new DigitalProduct(id, name, category, basePrice, sizeMb);
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
    List<Product> products = new ArrayList<>();
    int succesful = 0;
    int invalid = 0;

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

    void printSorted(OutputStream os) {
        PrintWriter pw = new PrintWriter(os);
        products.stream().sorted().forEach(x -> pw.println(x.toString()));
        pw.flush();
    }

    void printByCategory(OutputStream os, String category) throws CategoryNotFoundException {
        List<Product> filtered = products.stream().filter(x -> x.getCategory().equals(category)).sorted(Comparator.comparing(Product::getName,  String.CASE_INSENSITIVE_ORDER).thenComparing(Comparator.comparingDouble(Product::getFinalPrice).reversed()
        ).thenComparingInt(Product::getId)).collect(Collectors.toList());

        if(filtered.isEmpty()) throw new CategoryNotFoundException(category);
        PrintWriter pw = new PrintWriter(os);

        filtered.forEach(pw::println);


        pw.flush();
    }

    void printStatistics(OutputStream os) {
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


}

//6. Class Store
//
//Stores all products in a list. Implement:
//
//int readProducts(InputStream is) throws IOException – reads all lines using a BufferedReader.
// Blank lines (empty or whitespace only) are ignored and not counted. Invalid lines are skipped and counted. Returns the number of successfully read products.
//int getInvalidLines() – returns how many invalid lines were skipped.
//void printSorted(OutputStream os) – using a PrintWriter, prints all products (one per line, using toString()) in natural order.

//void printByCategory(OutputStream os, String category) throws CategoryNotFoundException – prints only
// the products of the given category (exact, case-sensitive match), sorted with a Comparator: by name ascending,
// ignoring case (String.CASE_INSENSITIVE_ORDER), then by final price descending, then by id ascending. If there are no products in that category, throws CategoryNotFoundException.
//void printStatistics(OutputStream os) – prints:
//
//Total: <n> (physical: <p>, digital: <d>)
//Cheapest: <cheapest product>
//Most expensive: <most expensive product>
//Average price: <average final price, %.2f>
//
//The cheapest and most expensive products are the minimum and maximum according to the natural order. If there are no products, print only No products.
//
//Important: in the printing methods, call flush() on the PrintWriter at the end, but do not close() it – that would also close System.out.

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