package MyOwnNodes;

public class Node {
    protected int value;
    protected Node succ;

    public Node(int value) {
        this.succ = null;
        this.value = value;
    }
}
