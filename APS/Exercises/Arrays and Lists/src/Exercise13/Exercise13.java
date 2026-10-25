package Exercise13;

import java.util.Scanner;

public class Exercise13 {

    public static float countAverageBefore(DLLNode<Integer> middle) {
        int count = 0;
        float average = 0;
        DLLNode<Integer> curr = middle.pred;
        while(curr != null) {
            count++;
            average += curr.element;
            curr = curr.pred;
        }
        return average/count;
    }

    public static float countAverageAfter(DLLNode<Integer> middle) {
        int count = 0;
        float average = 0;
        DLLNode<Integer> curr = middle.succ;
        while(curr != null) {
            count++;
            average += curr.element;
            curr = curr.succ;
        }
        return average/count;
    }

    public static int countAverages(DLL<Integer> list) {
        int count = 0;
        DLLNode<Integer> splitNode = list.getFirst().succ;

        while(splitNode.succ != null) {
            float averageBefore = countAverageBefore(splitNode);
            float averageAfter = countAverageAfter(splitNode);

            if(averageBefore > averageAfter) count++;
            splitNode = splitNode.succ;
        }


        return count;
    }


    public static void main(String[] args) {
        DLL<Integer> list = new DLL<Integer>();
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();

        for(int i = 0; i < n; i++) {
            int num = input.nextInt();
            list.insertLast(num);
        }


        int correctConditons = countAverages(list);

        System.out.println(correctConditons);
    }
}
