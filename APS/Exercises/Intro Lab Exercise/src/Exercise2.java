import java.util.ArrayList;
import java.util.Scanner;

class Product {
    private String name;
    private double price;

    public Product(String name, double price) {
        this.name = name;
        this.price = price;
    }

    public double finalPrice() {
        return price;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return String.format("%s price=%.2f final=%.2f", name, price, finalPrice());
    }
}

class Food extends Product {
    private int daysToExpiry;

    public Food(String name, double price, int daysToExpiry) {
        super(name, price);
        this.daysToExpiry = daysToExpiry;
    }

    public int getDaysToExpiry() {
        return daysToExpiry;
    }

    @Override
    public double finalPrice() {
        double price = super.finalPrice();
        if (daysToExpiry <= 3) {
            price *= 0.5;
        }
        return price;
    }

    @Override
    public String toString() {
        return super.toString() + String.format(" days=%d", daysToExpiry);
    }
}

class Electronics extends Product {
    private int warrantyMonths;

    public Electronics(String name, double price, int warrantyMonths) {
        super(name, price);
        this.warrantyMonths = warrantyMonths;
    }

    public int getWarrantyMonths() {
        return warrantyMonths;
    }

    @Override
    public double finalPrice() {
        double price = super.finalPrice();
        if (warrantyMonths > 24) {
            price *= 1.15;
        }
        return price;
    }

    @Override
    public String toString() {
        return super.toString() + String.format(" warranty=%d", warrantyMonths);
    }
}

class Pair<K, V> {
    private K key;
    private V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K getKey() {
        return key;
    }

    public V getValue() {
        return value;
    }
}

class Container<T extends Product> {
    private String name;
    private int capacity;
    private ArrayList<T> list;

    public Container(String name, int capacity) {
        this.name = name;
        this.capacity = capacity;
        this.list = new ArrayList<>();
    }

    public boolean add(T item) {
        if (list.size() >= capacity) return false;
        list.add(item);
        return true;
    }

    public int size() {
        return list.size();
    }

    public double totalValue() {
        double total = 0;
        for (int i = 0; i < list.size(); i++) {
            total += list.get(i).finalPrice();
        }
        return total;
    }

    public T mostExpensive() {
        if (list.isEmpty()) return null;
        T best = list.get(0);
        for (int i = 1; i < list.size(); i++) {
            if (list.get(i).finalPrice() > best.finalPrice()) {
                best = list.get(i);
            }
        }
        return best;
    }

    public Pair<String, Double> summary() {
        return new Pair<>(name, totalValue());
    }

    public void print() {
        System.out.printf("=== %s (%d/%d) ===%n", name, list.size(), capacity);
        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i));
        }
        System.out.printf("Total: %.2f%n", totalValue());
        T best = mostExpensive();
        if (best == null) {
            System.out.println("Most expensive: none");
        } else {
            System.out.printf("Most expensive: %s (%.2f)%n", best.getName(), best.finalPrice());
        }
    }
}

public class Exercise2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int fridgeCap = input.nextInt();
        int techCap = input.nextInt();
        int overflowCap = input.nextInt();
        int n = input.nextInt();

        Container<Food> fridge = new Container<Food>("Fridge", fridgeCap);
        Container<Electronics> tech = new Container<Electronics>("Tech", techCap);
        Container<Product> overflow = new Container<Product>("Overflow", overflowCap);

        for (int i = 0; i < n; i++) {
            String type = input.next();
            String name = input.next();
            double price = input.nextDouble();
            int extra = input.nextInt();

            if (type.equals("F")) {
                Food f = new Food(name, price, extra);
                if (!fridge.add(f) && !overflow.add(f)) {
                    System.out.println("Rejected: " + name);
                }
            } else {
                Electronics e = new Electronics(name, price, extra);
                if (!tech.add(e) && !overflow.add(e)) {
                    System.out.println("Rejected: " + name);
                }
            }
        }

        fridge.print();
        tech.print();
        overflow.print();

        Pair<String, Double> best = fridge.summary();
        Pair<String, Double> t = tech.summary();
        Pair<String, Double> o = overflow.summary();
        if (t.getValue() > best.getValue()) best = t;
        if (o.getValue() > best.getValue()) best = o;
        System.out.printf("Most valuable container: %s (%.2f)%n", best.getKey(), best.getValue());

        if (fridge.size() > 0) {
            System.out.printf("Top food expires in %d days%n", fridge.mostExpensive().getDaysToExpiry());
        }
        if (tech.size() > 0) {
            System.out.printf("Top electronics warranty: %d months%n", tech.mostExpensive().getWarrantyMonths());
        }



    }
}