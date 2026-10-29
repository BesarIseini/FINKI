package Exercise2;

public class Calculator {
    private static final char MULTIPLY = '*';
    private static final char DIVIDE = '/';
    private static final char PLUS = '+';
    private static final char MINUS = '-';

    private double result;

    Calculator() {
        result = 0;
    }


    public double getResult() {
        return result;
    }

    public String init() {
        return String.format("result = %f", result);
    }

    public String execute(char operator, double value) throws UnknownOperatorException {
        if(operator == PLUS) {
            result += value;
        } else if (operator == MINUS) {
            result -= value;
        } else if (operator == MULTIPLY) {
            result *= value;
        } else if (operator == DIVIDE) {
            result /= value;
        } else {
            throw new UnknownOperatorException(operator);
        }

        return String.format("result %c %f = %f", operator, value, result);
    }

    class UnknownOperatorException extends Exception {
        public UnknownOperatorException(char operator) {
            super(String.format("Unknow operator %c!", operator));
        }
    }


    @Override
    public String toString() {
        return String.format("updated result = %f", result);
    }
}
