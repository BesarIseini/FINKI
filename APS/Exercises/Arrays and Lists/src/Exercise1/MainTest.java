package Exercise1;

import java.util.ArrayList;
import java.util.Scanner;

public class MainTest {
    public static float getAverageOfArray(ArrayList<Integer> arr) {
        float average = 0;
        for (int i = 0; i < arr.size(); i++) {
            average += arr.get(i);
        }

        return average / arr.size();
    }
    public static void removeAverage(ArrayList<Integer> arr, float average) {
        for(int i = 0; i < arr.size(); i++) {
            if(arr.get(i) < average) {
                arr.remove(i);
                i--;
            }
        }
    }

    public static void printArray(ArrayList<Integer> arr) {
        String formattedArray = arr.toString().replace("[", "{").replace("]", "}").replace(" ", "");
        System.out.println(formattedArray);
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        ArrayList<Integer> array = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int number = input.nextInt();
            array.add(number);
        }

        printArray(array);
        removeAverage(array, getAverageOfArray(array));
        printArray(array);


    }
}