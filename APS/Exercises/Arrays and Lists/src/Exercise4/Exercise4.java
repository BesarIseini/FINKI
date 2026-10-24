package Exercise4;

import java.util.Scanner;


public class Exercise4 {

    public static void findOutliers(SLL<String> list, int L) {
        SLLNode<String> curr = list.getFirst();
        while(curr != null) {
            SLLNode<String> next = curr.succ;
            if(curr.element.length() > L) {
                list.insertBefore("Outlier", curr);
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
        int L = input.nextInt();

        System.out.println(list);
        findOutliers(list, L);
        System.out.println(list);

    }




}
