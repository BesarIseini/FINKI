

import java.util.NoSuchElementException;


/**
 * A doubly linked priority queue. Natural order removes the smallest element
 * first; reverse order removes the largest element first.
 *
 * @param <E> the type of elements stored in the structure
 */
public class PriorityQueue<E extends Comparable<E>> implements Queue<E>
{

    // Queue representation:
    // length stores the number of elements.
    // Elements are stored in doubly linked nodes.
    // front and rear point to the first and last nodes.
    DLLNode<E> front, rear;
    int length;
    PriorityQueueOrder order = PriorityQueueOrder.NATURAL;

    // Construct an empty queue.

    public PriorityQueue(PriorityQueueOrder priorityQueOrder)
    {
        order = priorityQueOrder;
        clear();
    }

    public PriorityQueue()
    {
        clear();
    }

    public boolean isEmpty()
    {
        // Return whether the queue is empty.
        return length == 0;
    }

    public int size()
    {
        // Return the number of elements in the queue.
        return length;
    }

    public E peek()
    {
        // Return the highest-priority element without removing it.
        if (isEmpty())
        {
            throw new NoSuchElementException();
        }

        return order == PriorityQueueOrder.NATURAL ? front.element : rear.element;
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
        DLLNode<E> latest = new DLLNode<E>(x, null, null);
        DLLNode<E> iterator = front;

        if (isEmpty())
        {
            front = rear = latest;
        }
        else if (latest.element.compareTo(front.element) < 0)
        {
            latest.succ = front;
            front.pred = latest;
            front = latest;
        }
        else
        {
            while (iterator.succ != null)
            {
                // 2 [3] 4
                if (latest.element.compareTo(iterator.succ.element) < 0)
                {
                    latest.succ = iterator.succ;
                    latest.pred = iterator;

                    iterator.succ.pred = latest;
                    iterator.succ = latest;
                    length++;
                    return;
                }

                iterator = iterator.succ;
            }
            rear.succ = latest;
            latest.pred = rear;
            rear = latest;
        }

        length++;
    }

    public E dequeue()
    {
        // Remove and return the highest-priority element.
        if (isEmpty())
        {
            throw new NoSuchElementException();
        }

        E highestPriority = null;

        if (order == PriorityQueueOrder.NATURAL)
        {
            highestPriority = front.element;
            front = front.succ;
            if (front == null)
            {
                rear = null;
            }
            else
            {
                front.pred = null;
            }
        }
        else
        {
            highestPriority = rear.element;
            rear = rear.pred;
            if (rear == null)
            {
                front = null;
            }
            else
            {
                rear.succ = null;
            }
        }
        length--;
        return highestPriority;

    }

    public String toString()
    {
        boolean naturalOrder = order == PriorityQueueOrder.NATURAL;
        DLLNode<E> current = naturalOrder ? front : rear;
        StringBuilder s = new StringBuilder();
        while (current != null)
        {
            if (s.length() > 0)
            {
                s.append(" ");
            }
            s.append(current.element);
            current = naturalOrder ? current.succ : current.pred;
        }

        return s.toString();
    }
}
