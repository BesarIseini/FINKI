package Exercise2;
import java.util.Scanner;

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