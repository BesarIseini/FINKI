

import java.util.NoSuchElementException;

/**
 * An unbounded FIFO queue backed by singly linked nodes.
 *
 * @param <E> the type of elements stored in the structure
 */
public class LinkedQueue<E> implements Queue<E>
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
