package Exercise7;

import java.util.Scanner;

public class Exercise7 {

    public static void rotateList(DLL<Integer> list, int l) {
        int n = list.getSize();
        if(n == 0) return;

        for(int i = 0; i < l % n; i++) {
            list.insertFirst(list.deleteLast());
        }
    }

    public static void main(String[] args) {
        DLL<Integer> list = new DLL<Integer>();
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        input.nextLine();

        for(int i = 0; i < n; i++) {
            Integer num = input.nextInt();
            list.insertLast(num);
        }

        int L = input.nextInt();

        System.out.println(list);
        rotateList(list, L);
        System.out.println(list);


    }
}
