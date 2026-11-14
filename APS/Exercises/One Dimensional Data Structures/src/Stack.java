/**
 * A last-in, first-out collection.
 *
 * @param <E> the type of elements in the stack
 */
public interface Stack<E>
{
    /**
     * @return whether the stack has no elements
     */
    boolean isEmpty();

    /**
     * @return the number of elements in the stack
     */
    int size();

    /**
     * Returns the top element without removing it.
     *
     * @return the top element
     * @throws java.util.NoSuchElementException if the stack is empty
     */
    E peek();

    /**
     * Removes all elements.
     */
    void clear();

    /**
     * Adds an element to the top of the stack.
     *
     * @param element the element to add
     */
    void push(E element);

    /**
     * Removes and returns the top element.
     *
     * @return the removed element
     * @throws java.util.NoSuchElementException if the stack is empty
     */
    E pop();
}
