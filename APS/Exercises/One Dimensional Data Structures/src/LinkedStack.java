

import java.util.NoSuchElementException;

/**
 * An unbounded LIFO stack backed by singly linked nodes.
 *
 * @param <E> the type of elements stored in the structure
 */
public class LinkedStack<E> implements Stack<E>
{
    // The top points to the first node of the linked stack.
    private SLLNode<E> top;
    int size;

    public LinkedStack()
    {
        // Construct an empty stack.
        top = null;
        size = 0;
    }

    public String toString()
    {
        SLLNode<E> current = top;
        StringBuilder s = new StringBuilder();
        while (current != null)
        {
            s.append(current.element);
            s.append(" ");
            current = current.succ;
        }
        return s.toString();
    }

    public boolean isEmpty()
    {
        // Return whether the stack is empty.
        return (top == null);
    }

    public void clear()
    {
        // Remove all elements from the stack.
        top = null;
        size = 0;
    }

    public E peek()
    {
        // Return the top element without removing it.
        if (isEmpty())
            throw new NoSuchElementException();
        return top.element;
    }

    public void push(E x)
    {
        // Add x to the top of the stack.
        top = new SLLNode<E>(x, top);
        size++;
    }

    public int size()
    {
        // Return the number of elements in the stack.
        return size;
    }

    public E pop()
    {
        // Remove and return the top element.
        if (isEmpty())
            throw new NoSuchElementException();
        E topElem = top.element;
        top = top.succ;
        size--;
        return topElem;
    }

}
