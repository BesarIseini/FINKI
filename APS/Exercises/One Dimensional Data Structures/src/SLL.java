public class SLL<E>
{
    private SLLNode<E> first;

    public SLL()
    {
        // Construct an empty SLL
        this.first = null;
    }

    public void deleteList()
    {
        first = null;
    }

    public int size()
    {
        int listSize = 0;
        SLLNode<E> iterator = first;
        while (iterator != null)
        {
            listSize++;
            iterator = iterator.succ;
        }
        return listSize;
    }

    @Override
    public String toString()
    {
        String ret = new String();
        if (first != null)
        {
            SLLNode<E> tmp = first;
            ret += tmp.element;
            while (tmp.succ != null)
            {
                tmp = tmp.succ;
                ret += "->" + tmp.element;
            }
        }
        else
            ret = "Prazna lista!!!";
        return ret;
    }

    public void insertFirst(E o)
    {
        SLLNode<E> ins = new SLLNode<E>(o, first);
        first = ins;
    }

    public void insertAfter(E o, SLLNode<E> node)
    {
        if (node == null)
        {
            System.out.println("Dadenot jazol e null");
            return;
        }
        SLLNode<E> ins = new SLLNode<E>(o, node.succ);
        node.succ = ins;
    }

    public void insertBefore(E o, SLLNode<E> before)
    {

        if (first != null)
        {
            SLLNode<E> iterator = first;
            if (first == before)
            {
                this.insertFirst(o);
                return;
            }

            while (iterator != null)
            {
                if (iterator.succ == before)
                {
                    SLLNode<E> newNode = new SLLNode<>(o, before);
                    iterator.succ = newNode;
                    return;
                }
                iterator = iterator.succ;
            }

            System.out.println("Elementot ne postoi vo listata");
        }
        else
        {
            System.out.println("Listata e prazna");
        }
    }

    public void insertLast(E o)
    {
        if (first == null)
        {
            insertFirst(o);
            return;
        }

        SLLNode<E> iterator = first;

        while (true)
        {
            if (iterator.succ == null)
            {
                iterator.succ = new SLLNode<>(o, null);
                return;
            }
            iterator = iterator.succ;
        }
    }

    public E deleteFirst()
    {
        if (first != null)
        {
            SLLNode<E> tmp = first;
            first = first.succ;
            return tmp.element;
        }
        else
        {
            System.out.println("Listata e prazna");
            return null;
        }
    }

    public E delete(SLLNode<E> node)
    {
        if (first != null)
        {
            SLLNode<E> iterator = first;
            if (first == node)
            {
                E tmp = this.deleteFirst();
                return tmp;
            }
            while (true)
            {
                SLLNode<E> nextNode = iterator.succ;
                if (nextNode == node)
                {
                    E element = nextNode.element;
                    //check if we are deleting the last node
                    iterator.succ = nextNode.succ;
                    return element;
                }
                iterator = iterator.succ;
            }
        }
        else
        {
            System.out.println("Listata e prazna");
            return null;
        }

    }

    private boolean isLast(SLLNode<E> node)
    {
        return node.succ == null;
    }

    public SLLNode<E> getFirst()
    {
        return first;
    }

    /**
     * Sets the first node of the list.
     *
     * @param first the new first node, or {@code null} for an empty list
     */
    public void setFirst(SLLNode<E> first)
    {
        this.first = first;
    }

    public SLLNode<E> find(E o)
    {
        if (first != null)
        {
            SLLNode<E> iterator = first;
            while (iterator != null)
            {
                if (iterator.element.equals(o))
                {
                    return iterator;
                }

                iterator = iterator.succ;
            }
            return null;
        }
        else
        {
            System.out.println("Listata e prazna");
        }
        return null;
    }

    public void merge(SLL<E> in)
    {
        if (first != null)
        {
            SLLNode<E> tmp = first;
            while (tmp.succ != null)
                tmp = tmp.succ;
            tmp.succ = in.getFirst();
        }
        else
        {
            first = in.getFirst();
        }
    }

    public void mirror()
    {
        if (first != null)
        {
            //m=nextsucc, p=tmp,q=next
            SLLNode<E> tmp = first;
            SLLNode<E> newsucc = null;
            SLLNode<E> next;

            while (tmp != null)
            {
                next = tmp.succ;
                tmp.succ = newsucc;
                newsucc = tmp;
                tmp = next;
            }
            first = newsucc;
        }
    }

}
