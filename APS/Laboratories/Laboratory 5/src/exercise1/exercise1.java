package exercise1;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

class Task implements Comparable<Task> {
    private int T;
    private int W;
    private int id;

    private static int counter = 0;

    public Task(int t, int w) {
        T = t;
        W = w;
        id = ++counter;
    }

    public int getT() {
        return T;
    }

    public int getW() {
        return W;
    }

    public int getId() {
        return id;
    }

    @Override
    public int compareTo(Task o) {
        return Long.compare((long) T * o.W, (long) o.T * W);
    }
}

public class exercise1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int t = input.nextInt();

        ArrayList<Task> tasks = new ArrayList<>();

        for (int i = 0; i < t; i++) {
            tasks.add(new Task(input.nextInt(), input.nextInt()));
        }

        Collections.sort(tasks);

        long time = 0, total = 0;
        StringBuilder order = new StringBuilder();
        for (Task task : tasks) {
            time += task.getT();
            total += time * task.getW();
            order.append(task.getId()).append(" ");
        }
        System.out.println(total);
        System.out.println(order.toString().trim());
    }
}
