package Exercise1;

import java.util.NoSuchElementException;
import java.util.Scanner;

/**
 * A last-in, first-out collection.
 *
 * @param <E> the type of elements in the stack
 */

interface Stack<E>
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


/**
 * An unbounded LIFO stack backed by singly linked nodes.
 *
 * @param <E> the type of elements stored in the structure
 */
class LinkedStack<E> implements Stack<E>
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



public class Exercise1 {

    public static void main(String[] args) {
        LinkedStack<String> stack = new LinkedStack<String>();
        Scanner input = new Scanner(System.in);


       boolean correct = true;

        while(true) {
            String function = input.nextLine();

            if(!stack.isEmpty()) {
                String savedFunction = stack.peek();

                if(function.contains("end")) {
                    if(savedFunction.charAt(savedFunction.length() - 1) == function.charAt(function.length() - 1)) {
                        stack.pop();
                        continue;
                    } else {
                        correct = false;
                        break;
                    }
                }
            } else {
                if(function.contains("end")) {
                    correct = false;
                    break;
                }
            }



            if(function.equals("x")) {
                break;
            }

            stack.push(function);
        }


        if(!stack.isEmpty()) correct = false;

        System.out.println(correct ? "Valid" : "Invalid");
    }



}
