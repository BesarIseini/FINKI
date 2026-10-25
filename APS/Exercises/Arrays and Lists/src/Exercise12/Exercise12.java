package Exercise12;

import java.util.Scanner;

public class Exercise12 {

    public static void shift(DLL<Integer> list, int k, int n) {

        k %= n;

        for(int i = 0; i < k; i++) {
            list.insertLast(list.deleteFirst());
        }
    }

    public static void main(String[] args) {
        DLL<Integer> list = new DLL<Integer>();
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();

        for(int i = 0; i < n; i++) {
            int num = input.nextInt();
            list.insertLast(num);
        }

        int k = input.nextInt();

        System.out.println(list);
        shift(list, k, n);
        System.out.println(list);
    }
}
