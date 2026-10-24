package Exercise1;

import java.util.Scanner;

public class PushZero
{

    static void pushZerosToBeginning(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (arr[j] == 0) {
                    arr[j] = arr[j - 1];
                    arr[j - 1] = 0;
                }
            }
        }
    }

    public static void main (String[] args)
    {
        Scanner input = new Scanner(System.in);

        int size = input.nextInt();
        int [] arr = new int[size];

        for (int i = 0; i < size; i++) {
            arr[i] = input.nextInt();
        }

        pushZerosToBeginning(arr, size);

        System.out.println("Transformiranata niza e:");
        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}