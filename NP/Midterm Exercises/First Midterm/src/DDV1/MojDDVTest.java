package DDV1;


import java.io.*;
import java.util.ArrayList;
import java.util.DoubleSummaryStatistics;

class Item {
    private double price;
    private char type;

    public Item(double price, char type) {
        this.price = price;
        this.type = type;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public char getType() {
        return type;
    }

    public void setType(char type) {
        this.type = type;
    }

    double getPercentage() {
        if(type == 'A') {
            return 0.18;
        } else if (type == 'B') {
            return 0.05;
        } else {
            return 0;
        }
    }

    public double VATAmount() {
        return price * getPercentage();
    }

    public double returnAmount() {
        return VATAmount() * 0.15;
    }
}

class Receipt {
    private int id;
    private ArrayList<Item> items = new ArrayList<>();

    public Receipt(int id) {
        this.id = id;
    }

    public void addItem(double price, char type) {
        items.add(new Item(price, type));
    }

    public static Receipt create(String line) throws AmountNotAllowedException {
        String [] parts = line.trim().split("\\s+");
        int id = Integer.parseInt(parts[0]);

        Receipt r = new Receipt(id);

        for (int i = 1; i < parts.length; i += 2) {
            int price = Integer.parseInt(parts[i]);
            char type = parts[i + 1].charAt(0);
            r.addItem(price, type);
        }

        if (r.total() > 30000) throw new AmountNotAllowedException((int) r.total());
        return r;
    }

    public double total() {
        return items.stream().mapToDouble(Item::getPrice).sum();
    }

    public double totalVat() {
        return items.stream().mapToDouble(Item::returnAmount).sum();
    }


    @Override
    public String toString() {
        return String.format("%10d\t%10d\t%10.5f", id, (int) total(), totalVat());
    }
}


class AmountNotAllowedException extends Exception {
    public AmountNotAllowedException(int sum) {
        super(String.format("Receipt with amount %d is not allowed to be scanned", sum));
    }
}


class MojDDV {
    private ArrayList<Receipt> receipts = new ArrayList<>();

    public MojDDV() {

    }

    void readRecords(InputStream inputStream) {
        BufferedReader bf = new BufferedReader(new InputStreamReader(inputStream));

        bf.lines().forEach(x -> {

            try {
                receipts.add(Receipt.create(x));
            } catch (AmountNotAllowedException e) {
                System.out.println(e.getMessage());
            }



        });
    }

    void printTaxReturns (OutputStream outputStream) {
        PrintWriter pw = new PrintWriter(outputStream);

        receipts.forEach(pw::println);

        pw.flush();
    }

    void printStatistics(OutputStream outputStream) {
        DoubleSummaryStatistics summaryStatistics = receipts.stream().mapToDouble(Receipt::totalVat).summaryStatistics();

        PrintWriter pw = new PrintWriter(outputStream);

        pw.printf("min:\t%5.3f%n", summaryStatistics.getMin());
        pw.printf("max:\t%5.3f%n", summaryStatistics.getMax());
        pw.printf("sum:\t%5.3f%n", summaryStatistics.getSum());
        pw.printf("count:\t%-5d%n", summaryStatistics.getCount());
        pw.printf("avg:\t%5.3f%n", summaryStatistics.getAverage());

        pw.flush();
    }
}

public class MojDDVTest {

    public static void main(String[] args) {

        MojDDV mojDDV = new MojDDV();

        System.out.println("===READING RECORDS FROM INPUT STREAM===");
        mojDDV.readRecords(System.in);

        System.out.println("===PRINTING TAX RETURNS RECORDS TO OUTPUT STREAM ===");
        mojDDV.printTaxReturns(System.out);

        System.out.println("===PRINTING SUMMARY STATISTICS FOR TAX RETURNS TO OUTPUT STREAM===");
        mojDDV.printStatistics(System.out);

    }
}