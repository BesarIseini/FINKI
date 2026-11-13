package exercise2;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

class Task implements Comparable<Task> {
    private int T;
    private int W;

    public Task(int t, int w) {
        T = t;
        W = w;
    }

    public int getT() {
        return T;
    }

    public int getW() {
        return W;
    }

    @Override
    public int compareTo(Task o) {
        return Long.compare((long) T * o.W, (long) o.T * W);
    }
}

public class exercise2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        long L = input.nextLong();

        ArrayList<Task> tasks = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            tasks.add(new Task(input.nextInt(), input.nextInt()));
        }

        tasks.sort(Comparator.comparingInt(Task::getT));

        ArrayList<Task> chosen = new ArrayList<>();
        long used = 0;
        for (Task task : tasks) {
            if (used + task.getT() > L) break;
            used += task.getT();
            chosen.add(task);
        }

        Collections.sort(chosen);

        long time = 0, total = 0;
        for (Task task : chosen) {
            total += time * task.getW(); // cost uses START time
            time += task.getT();
        }

        System.out.println(chosen.size());
        System.out.println(total);
    }
}