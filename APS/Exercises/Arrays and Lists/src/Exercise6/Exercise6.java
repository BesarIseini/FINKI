package Exercise6;

import java.util.Scanner;

public class Exercise6 {

    public static void moveLast(SLL<String> list, int L) {
        SLLNode<String> last = null;
        SLLNode<String> curr = list.getFirst();

        while(curr != null) {
            if(curr.element.length() == L) {
                last = curr;
            }
            curr = curr.succ;
        }

        if(last == null) return;
        list.delete(last);
        list.insertFirst(last.element);
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

        int L = input.nextInt();

        System.out.println(list);
        moveLast(list, L);
        System.out.println(list);
    }
}
