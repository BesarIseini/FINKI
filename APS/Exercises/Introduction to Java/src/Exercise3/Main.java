package Exercise3;

import java.util.Scanner;

class QuarterlySales {

    private int numOfSales;
    private int [] revenues;
    private int quarterNo;

    public QuarterlySales(int numOfSales, int[] revenues, int quarterNo) {
        this.numOfSales = numOfSales;
        this.revenues = revenues;
        this.quarterNo = quarterNo;
    }
    @Override
    public String toString() {
        return String.format("%f", numOfSales);
    }

    public int getNumOfSales() {
        return numOfSales;
    }

    public int getRevenuesSum() {
        int count = 0;
        for(int i = 0; i < revenues.length; i++) {
            count += this.revenues[i];
        }
        return count;
    }

    public int getQuarterNo() {
        return quarterNo;
    }
}

class SalesPerson {

    private String name;
    private QuarterlySales [] quarters;

    public SalesPerson(String name, QuarterlySales[] quarters) {
        this.name = name;
        this.quarters = quarters;
    }

    public int getRevenues() {
        int count = 0;
        for(int i = 0; i < 4; i++) {
            count += quarters[i].getRevenuesSum();
        }
        return count;
    }

    public String getName() {
        return this.name;
    }

    @Override
    public String toString() {
        return String.format("%s   %d   %d   %d   %d   %d",
                name,
                quarters[0].getRevenuesSum(),
                quarters[1].getRevenuesSum(),
                quarters[2].getRevenuesSum(),
                quarters[3].getRevenuesSum(),
                getRevenues());
    }

}



public class Main {

    public static SalesPerson salesChampion(SalesPerson [] arr)
    {
        int bestIndex = 0, bestRevenue = arr[0].getRevenues();
        for(int i = 1; i < arr.length; i++) {
            if(arr[i].getRevenues() > bestRevenue) {
                bestIndex = i;
                bestRevenue = arr[i].getRevenues();
            }
        }

        return arr[bestIndex];
    }
    public static void table(SalesPerson [] arr)
    {
        System.out.println("SP   1   2   3   4   Total");
        for(int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
        System.out.println();

    }
    public static int sumSales(SalesPerson sp) {
        return sp.getRevenues();
    }

    public static void main(String[] args) {

        int n;
        Scanner input = new Scanner(System.in);
        n = input.nextInt();
        input.nextLine();
        SalesPerson [] arr = new SalesPerson[n];
        for(int i=0;i<n;i++)
        {
            String name = input.nextLine();
            QuarterlySales [] quarters = new QuarterlySales[4];
            for(int quarter = 0; quarter < 4; quarter++) {
                int numberOfSales = Integer.parseInt(input.nextLine().trim());
                int[] revenues = new int[numberOfSales];
                for(int j = 0; j < numberOfSales; j++) {
                    revenues[j] = input.nextInt();
                }
                input.nextLine();
                quarters[quarter] = new QuarterlySales(numberOfSales, revenues, quarter + 1);
            }

            arr[i] = new SalesPerson(name, quarters);

        }

        table(arr);
        System.out.println("SALES CHAMPION: " + salesChampion(arr).getName());

    }
}