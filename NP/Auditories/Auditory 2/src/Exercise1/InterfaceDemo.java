package Exercise1;

public class InterfaceDemo {
    public static void main(String[] args) {

        // --- Example 1: Interface with arguments ---
        Operation op1 = new Addition();
        System.out.println("Addition: " + op1.apply(5, 3));

        Operation op2 = new Operation() {
            @Override
            public int apply(int a, int b) {
                return a * b;
            }
        };
        System.out.println("Multiplication: " + op2.apply(5, 3));

        Operation op3 = (a, b) -> a - b;
        System.out.println("Subtraction: " + op3.apply(5, 3));

        // --- Example 2: Interface without arguments ---
        MessageProvider m1 = new StaticMessage();
        System.out.println(m1.getMessage());

        MessageProvider m2 = new MessageProvider() {
            @Override
            public String getMessage() {
                return "Hello from an anonymous class!";
            }
        };
        System.out.println(m2.getMessage());

        MessageProvider m3 = () -> "Hello from a lambda!";
        System.out.println(m3.getMessage());
    }
}