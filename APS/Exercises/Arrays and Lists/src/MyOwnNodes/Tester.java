package MyOwnNodes;

import java.util.Random;
import java.util.Scanner;

class Pair {

}

public class Tester {



    static void main(String[] args) {
        int n = 5;
        NodeList list = new NodeList();
        Scanner input = new Scanner(System.in);

        Random random = new Random();

        double num = random.nextDouble();
        System.out.println("=====Inserting=====");

        for(int i = 0; i < n; i++) {


            if(num < 0.5) {
                list.insertFirst(input.nextInt());
                System.out.println("First");
            } else {
                list.insertLast(input.nextInt());
                System.out.println("Last");
            }

            System.out.println(list);
        }

        System.out.println("=====Deleting=====");
        for(int i = 0; i < n; i++) {


            if(num < 0.5) {
                list.deleteFirst();
                System.out.println("First");
            } else {
                list.deleteLast();
                System.out.println("Last");
            }

            System.out.println(list);
        }

    }
}
