package MinAndMax;

import java.util.Scanner;


class MinMax<T extends Comparable<T>>   {
    T min;
    T max;
    int total = 0, countMin = 0, countMax = 0;



    public MinMax() {

    }


    void update(T element) {
        total++;

        if (min == null || element.compareTo(min) < 0) { min = element; countMin = 1; }
        else if (element.compareTo(min) == 0)          { countMin++; }

        if (max == null || element.compareTo(max) > 0) { max = element; countMax = 1; }
        else if (element.compareTo(max) == 0)          { countMax++; }
    }

    public T getMax() {
        return max;
    }

    public T getMin() {
        return min;
    }

//    to overload the method toString()that returns a string consisting of the minimum and maximum element and
//    the number of elements processed in the method updatethat are different from the current minimum/maximum,
//      separated by a space.


    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();


        return String.format("%s %s %d%n", min, max, total - countMin - countMax);
    }
}


public class MinAndMax {
    public static void main(String[] args) throws ClassNotFoundException {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        MinMax<String> strings = new MinMax<String>();
        for(int i = 0; i < n; ++i) {
            String s = scanner.next();
            strings.update(s);
        }
        System.out.println(strings);
        MinMax<Integer> ints = new MinMax<Integer>();
        for(int i = 0; i < n; ++i) {
            int x = scanner.nextInt();
            ints.update(x);
        }
        System.out.println(ints);
    }
}