package Exercise3;

import java.util.Scanner;

public class Exercise3 {

    public static void addTarget(SLL<String> list, int L) {
        SLLNode<String> curr = list.getFirst();
        while(curr != null) {
            SLLNode<String> next = curr.succ;
            if(curr.element.length() == L) {
                SLLNode<String> target = new SLLNode<String>("Target", next);
                curr.succ = target;
            }

            curr = next;
        }
    }

    public static void main(String[] args) {
        SLL<String> list = new SLL<String>();
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        input.nextLine();

        for(int i = 0; i < n; i++) {
            String word = input.nextLine();
            list.insertLast(word);
        }

        int l = input.nextInt();

        System.out.println(list);
        addTarget(list, l);
        System.out.println(list);


    }




}
