package MyOwnNodes;

public class NodeList {
    private Node first;

    public NodeList() {
        this.first = null;
    }

    public void insertFirst(int a) {
        Node added = new Node(a);

        added.succ = first;
        first = added;
    }

    public void insertLast(int a) {
        Node added = new Node(a);

        if(first == null) {
            insertFirst(a);
            return;
        } else {
            Node curr = first;
            while(curr.succ != null) {
                curr = curr.succ;
            }
            curr.succ = added;
        }
    }
    public void test(int a) {
        a += 10;
    }

    public int size() {
        int counter = 0;
        Node curr = first;

        while(curr != null) {
            counter++;
            curr = curr.succ;
        }

        return counter;
    }

    public void deleteFirst() {
        if(first == null) return;;
        first = first.succ;
    }

    public void deleteLast() {
        Node curr = first;
        if(size() < 2) {
            deleteFirst();
            return;
        }

//curr != null => i < n
//curr.succ != null => i < n - 1
//curr.succ.succ != null => i < n - 2
        while (curr.succ.succ != null) {
            curr = curr.succ;
        }

        curr.succ = null;


    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        Node curr = first;
        while(curr != null) {

            sb.append(curr.value);
            if(curr.succ != null) {
                sb.append("->");
            }

            curr = curr.succ;
        }
        return sb.toString();
    }
}
