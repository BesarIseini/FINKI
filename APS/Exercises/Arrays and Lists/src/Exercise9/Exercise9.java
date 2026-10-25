package Exercise9;

import java.util.Scanner;

public class Exercise9 {


    public static void shiftM (DLL<Integer> list, int m, int k) {
        DLLNode<Integer> curr;
        int size = list.getSize();

        DLLNode<Integer> selectedNode = list.find(m);
        if(selectedNode == null) return;

        DLLNode<Integer> prev = selectedNode.pred;

        for(int i = 0; i < k; i++) {
            if(prev == null) {
                list.insertLast(selectedNode.element);
                selectedNode = list.getLast();
                prev = selectedNode.pred;
                list.deleteFirst();
                continue;
            }
            list.insertBefore(list.delete(selectedNode), prev);
            selectedNode = prev.pred;
            prev = selectedNode.pred;
        }
    }



    public static void main(String[] args) {
        DLL<Integer> list = new DLL<Integer>();
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();

        for (int i = 0; i < n; i++) {
            Integer num = input.nextInt();
            list.insertLast(num);
        }

        int m = input.nextInt();
        int k = input.nextInt();

        System.out.println(list);
        shiftM(list, m, k);
        System.out.println(list);
    }
}
