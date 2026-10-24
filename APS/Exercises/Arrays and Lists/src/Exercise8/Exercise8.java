package Exercise8;

import java.util.Scanner;

public class Exercise8 {

    public static void rotate(DLL<Integer> list, int l) {
        int size = list.getSize();

        for(int i = 0; i < l % size; i++) {
            list.insertLast(list.deleteFirst());
        }
    }

    public static void main(String[] args) {
        DLL<Integer> list = new DLL<Integer>();
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();

        for(int i = 0; i < n; i++) {
            Integer num = input.nextInt();
            list.insertLast(num);
        }

        int L = input.nextInt();


        rotate(list, L);
        System.out.println(list);

    }
}
