package Exercise5;

import java.util.Scanner;

public class Exercise5 {

    public static void moveLast(SLL<String> list, int L) {
        SLLNode<String> current = list.getFirst();
        int count = list.size();

        for(int i = 0; i < count; i++) {
            SLLNode<String> next = current.succ;
            if(current.element.length() == L) {
                list.delete(current);
                list.insertLast(current.element);
            }
            current = next;
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

        int L = input.nextInt();

        System.out.println(list);
        moveLast(list, L);
        System.out.println(list);

    }
}
