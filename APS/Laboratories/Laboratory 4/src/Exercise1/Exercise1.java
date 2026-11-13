package Exercise1;


import java.util.ArrayList;
import java.util.Scanner;
import java.util.stream.Collectors;

class Task implements Comparable<Task> {
    private int t;
    private int w;

    public Task(int t, int w) {
        this.t = t;
        this.w = w;
    }

    public int getT() {
        return t;
    }

    public int getW() {
        return w;
    }

    @Override
    public int compareTo(Task o) {
        return Integer.compare(this.t * o.w,  o.t * this.w);
    }
}



public class Exercise1 {

    public static void main(String[] args) {
        ArrayList<Task> list = new ArrayList<>();
        int n;
        Scanner input = new Scanner(System.in);

        n = input.nextInt();

        for(int i = 0; i < n; i++) {
            list.add(new Task(input.nextInt(), input.nextInt()));
        }

        ArrayList<Task> tasks = list.stream().sorted().collect(Collectors.toCollection(ArrayList::new));

        long time = 0, cost = 0;
        for (Task task : tasks) {
            cost += time * task.getW();
            time += task.getT();
        }
        System.out.println(cost);
    }


}
