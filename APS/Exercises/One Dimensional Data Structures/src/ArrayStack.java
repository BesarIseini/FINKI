import java.util.NoSuchElementException;

/**
 * A fixed-capacity, array-backed LIFO stack.
 *
 * @param <E> the type of elements stored in the structure
 */
public class ArrayStack<E> implements Stack<E>
{
    private E[] elems; // The elements occupy elems[0...depth-1].
    private int depth; // Number of elements in the stack.

    @SuppressWarnings("unchecked")
    public ArrayStack(int maxDepth)
    {
        // Construct an empty stack.
        elems = (E[]) new Object[maxDepth];
        depth = 0;
    }

    public boolean isEmpty()
    {
        // Return whether the stack is empty.
        return (depth == 0);
    }

    public E peek()
    {
        // Return the top element without removing it.
        if (isEmpty())
            throw new NoSuchElementException();
        return elems[depth - 1];
    }

    public void clear()
    {
        // Remove all elements from the stack.
        for (int i = 0; i < depth; i++)
        {
            elems[i] = null;
        }
        depth = 0;
    }

    public void push(E x)
    {
        // Add x to the top of the stack.
        if (depth == elems.length)
        {
            throw new ArrayIndexOutOfBoundsException();
        }

        elems[depth] = x;
        depth++;
    }

    public int size()
    {
        // Return the number of elements in the stack.
        return depth;
    }

    public E pop()
    {
        // Remove and return the top element.
        if (depth == 0)
            throw new NoSuchElementException();

        E topmost = elems[depth - 1];
        elems[depth - 1] = null;
        depth--;
        return topmost;
    }
}
