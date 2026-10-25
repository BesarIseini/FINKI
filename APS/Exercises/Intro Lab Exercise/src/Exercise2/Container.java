package Exercise2;


import java.util.ArrayList;

public class Container<T extends Product> {
    private String name;
    private int capacity;
    private ArrayList<T> list;

    public Container(String name, int capacity) {
        this.name = name;
        this.capacity = capacity;
        this.list = new ArrayList<>();
    }

    public boolean add(T item) {
        if(list.size() == capacity) return false;

        list.add(item);

        return true;
    }

    public int size() {
        return list.size(); //??
    }

    public double totalValue() {
        double total = 0;

        for(int i = 0; i < list.size(); i++) {
            total += list.get(i).finalPrice();
        }

        return total;
    }

    public T mostExpensive() {
        if (list.isEmpty()) return null;
        T mostExpensive = list.get(0);

        for(int i = 0; i < list.size(); i++) {
            if(list.get(i).finalPrice() > mostExpensive.finalPrice()) {
                mostExpensive = list.get(i);
            }
        }

        return mostExpensive;
    }

    public Pair<String, Double> summary() {
        return new Pair<>(name, totalValue());
    }


    public void print() {
        System.out.printf("=== %s (%d/%d) ===%n", name, list.size(), capacity);
        for(int i = 0; i < list.size(); i++) {
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
