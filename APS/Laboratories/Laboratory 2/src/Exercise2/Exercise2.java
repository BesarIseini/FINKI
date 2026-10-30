package Exercise2;

import java.util.Scanner;


public class Exercise2 {
    public static void main(String[] args) {
        DLL<Integer> list = new DLL<Integer>();

        Scanner input = new Scanner(System.in);

        int m = input.nextInt();

        for (int i = 0; i < m; i++) {
            int num = input.nextInt();
            list.insertLast(num);
        }

        int n = input.nextInt();

        for(int i = 0; i < n; i++) {
            int element = input.nextInt();
            String direction = input.next();
            long howManyPositions = input.nextLong() % list.getSize();
            if(howManyPositions == 0) howManyPositions = list.getSize();
            boolean left = direction.equals("left");

            DLLNode<Integer> curr;

            if(left) {
                curr = list.getFirst();
            } else {
                curr = list.getLast();
            }

            for(long j = 0; j < howManyPositions - 1; j++) {
                if(left) {
                    if(curr.succ == null) {
                        curr = list.getFirst();
                        continue;
                    }
                    curr = curr.succ;
                    continue;
                }

                if(curr.pred == null) {
                    curr = list.getLast();
                    continue;
                }
                curr = curr.pred;
            }

            list.insertBefore(element, curr);
        }

        System.out.println(list);


        int howMany = input.nextInt();
        DLLNode<Integer> curr = list.getLast();

        for(int i = 0; i < howMany - 1; i++) {
            curr = curr.pred;
        }

        DLLNode<Integer> lastFirst = list.getFirst();
        boolean doLoop = true;
        if(howMany == 0 || howMany == list.getSize()) doLoop = false;
        while(curr != null && doLoop) {
            DLLNode<Integer> next = curr.succ;

            list.insertBefore(curr.element, lastFirst);
            list.delete(curr);
            curr = next;
        }

        System.out.println(list);
    }
}