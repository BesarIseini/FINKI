package Exercise10;

import java.util.Scanner;

public class Exercise10 {

    public static void shiftMright(DLL<Integer> list, int m, int k) {
        DLLNode<Integer> selected = list.find(m);
        if(selected == null) return;

        int size = list.getSize();

        k %= size;

        DLLNode<Integer> next = selected.succ;

        for(int i = 0; i < k; i++) {
            if(next == null) {
                list.insertFirst(selected.element);
                list.delete(selected);

                selected = list.getFirst();
                next = selected.succ;

                continue;
            }


            list.insertAfter(selected.element, next);
            list.delete(selected);

            selected = next.succ;
            next = selected.succ;
        }
    }


    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        DLL<Integer> list = new DLL<Integer>();

        int n = input.nextInt();

        for(int i = 0; i < n; i++) {
            int num = input.nextInt();
            list.insertLast(num);
        }

        int m, k;
        m = input.nextInt();
        k = input.nextInt();

        System.out.println(list);
        shiftMright(list, m, k);
        System.out.println(list);
    }
}
