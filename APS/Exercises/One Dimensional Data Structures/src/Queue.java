/**
 * A queue supporting insertion and removal according to its implementation's
 * ordering rule. The array and linked implementations use FIFO order.
 *
 * @param <E> the type of elements in the queue
 */
public interface Queue<E>
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
