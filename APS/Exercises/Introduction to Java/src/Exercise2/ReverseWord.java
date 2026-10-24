package Exercise2;

import java.util.Scanner;

public class ReverseWord {

    public static void printReversed(String word) {
        for (int i = word.length() - 1; i >= 0; i-- ) {
            System.out.print(word.charAt(i));
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        input.nextLine();
        for (int i = 0; i < n; i++) {
            String word = input.nextLine();
            printReversed(word);
        }
    }
}
