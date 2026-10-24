package Exercise2;

import java.util.Scanner;

public class Exercise2 {

    public static void removeWithLessThanLCharacters(SLL<String> list, int n) {
        SLLNode<String> curr = list.getFirst();
        while(curr != null) {
            SLLNode<String> next = curr.succ;
            if(curr.element.length() < n) {
                list.delete(curr);
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
        removeWithLessThanLCharacters(list, l);
        System.out.println(list);


    }




}
