package Exercise11;

import java.util.Scanner;




public class Exercise11 {
    public static void shift(DLL<Integer> list, int k) {
        int size = list.getSize();
        k %= size;

        for(int i = 0; i < k; i++) {
            list.insertFirst(list.deleteLast());
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
        shift(list, k);
        System.out.println(list);


    }
}
