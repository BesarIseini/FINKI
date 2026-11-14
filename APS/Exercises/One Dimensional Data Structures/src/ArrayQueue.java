import java.util.NoSuchElementException;

/**
 * A fixed-capacity FIFO queue backed by a circular array.
 *
 * @param <E> the type of elements stored in the structure
 * @author Aleksandar
 */
public class ArrayQueue<E> implements Queue<E>
{
    // Queue representation:
    // length stores the number of elements.
    // Elements occupy a circular segment starting at front.
    // When the segment wraps, it continues at the start of the array.
    E[] elems;
    int length, front, rear;

    // Construct an empty queue.

    @SuppressWarnings("unchecked")
    public ArrayQueue(int maxlength)
    {
        elems = (E[]) new Object[maxlength];
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
        {
            throw new NoSuchElementException();
        }

        return elems[front];

    }

    public void clear()
    {
        // Remove all elements from the queue.
        length = 0;
        front = rear = 0;  // arbitrary
    }

    public void enqueue(E x)
    {
        // Insert x into the queue.
        if (length == elems.length)
        {
            throw new NoSuchElementException();
        }

        elems[rear] = x;
        rear++;
        if (rear == elems.length)
        {
            rear = 0;
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

        E frontmost = elems[front];
        elems[front] = null;
        front++;
        if (front == elems.length)
        {
            front = 0;
        }
        length--;
        return frontmost;
    }
}
