package Exercise1;

import java.util.NoSuchElementException;
import java.util.Scanner;

/**
 * A fixed-capacity FIFO queue backed by a circular array.
 *
 * @param <E> the type of elements stored in the structure
 * @author Aleksandar
 */


/**
 * A queue supporting insertion and removal according to its implementation's
 * ordering rule. The array and linked implementations use FIFO order.
 *
 * @param <E> the type of elements in the queue
 */
interface Queue<E>
{
    /**
     * @return whether the queue has no elements
     */
    boolean isEmpty();

    /**
     * @return the number of elements in the queue
     */
    int size();

    /**
     * Returns the front element without removing it.
     *
     * @return the front element
     * @throws java.util.NoSuchElementException if the queue is empty
     */
    E peek();

    /**
     * Removes all elements.
     */
    void clear();

    /**
     * Inserts an element according to the queue's ordering rule.
     *
     * @param element the element to insert
     */
    void enqueue(E element);

    /**
     * Removes and returns the front element.
     *
     * @return the removed element
     * @throws java.util.NoSuchElementException if the queue is empty
     */
    E dequeue();
}



/**
 * An unbounded FIFO queue backed by singly linked nodes.
 *
 * @param <E> the type of elements stored in the structure
 */


class SLLNode<E>
{
    public E element;
    public SLLNode<E> succ;

    public SLLNode(E elem, SLLNode<E> succ)
    {
        this.element = elem;
        this.succ = succ;
    }
}

class LinkedQueue<E> implements Queue<E>
{

    // Queue representation:
    // length stores the number of elements.
    // Elements are stored in singly linked nodes.
    // front and rear point to the first and last nodes.
    SLLNode<E> front, rear;
    int length;

    // Construct an empty queue.

    public LinkedQueue()
    {
        clear();
    }

    public boolean isEmpty()
    {
        // Return whether the queue is empty.
        return (length == 0);
    }

    public int size()
    {
        // Return the number of elements in the queue.
        return length;
    }

    public E peek()
    {
        // Return the front element without removing it.
        if (isEmpty())
            throw new NoSuchElementException();

        return front.element;
    }

    public void clear()
    {
        // Remove all elements from the queue.
        front = rear = null;
        length = 0;
    }

    public void enqueue(E x)
    {
        // Insert x into the queue.
        SLLNode<E> latest = new SLLNode<E>(x, null);
        if (isEmpty())
        {
            front = rear = latest;
        }
        else
        {
            rear.succ = latest;
            rear = latest;
        }
        length++;
    }

    public E dequeue()
    {
        // Remove and return the front element.
        if (isEmpty())
        {
            throw new NoSuchElementException();
        }

        E frontmost = front.element;
        front = front.succ;
        if (isEmpty())
        {
            rear = null;
        }
        length--;
        return frontmost;
    }

}

class Pair {
    String name;
    int time;

    public Pair(String name, int time) {
        this.name = name;
        this.time = time;
    }

    public String getName() {
        return name;
    }


    public int getTime() {
        return time;
    }

    public void reduceTime(int time) {
        this.time -= time;
    }

}

public class Exercise1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int t = input.nextInt();
        input.nextLine();

        LinkedQueue<Pair> list = new LinkedQueue<Pair>();

        for(int i = 0; i < n; i++) {
            String [] line = input.nextLine().trim().split("\\s+");
            String name = line[0];
            int time = Integer.parseInt(line[1]);

            Pair o = new Pair(name, time);
            list.enqueue(o);

        }

        int enumerate = 1;
        while(!list.isEmpty()) {
            Pair p = list.dequeue();
            p.reduceTime(t);
            if(p.getTime() <= 0) {
                System.out.printf("%d. %s%n", enumerate++, p.getName());
            } else {
                list.enqueue(p);
            }
        }
    }


}
