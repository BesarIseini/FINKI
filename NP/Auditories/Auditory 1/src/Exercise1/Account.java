package Exercise1;

abstract public class Account {
    private static int nextAccountNumber = 1;

    private String name;
    private int accountNumber;
    private double currentAmount;

    public Account(double currentAmount, String name) {
        this.currentAmount = currentAmount;
        this.accountNumber = nextAccountNumber++;
        this.name = name;
    }

    public double getCurrentAmount() {
        return currentAmount;
    }

    public void addAmount(double amount) {
        currentAmount += amount;
    }

    public void withdrawAmount(double amount) {
        if(currentAmount < amount) {
            return;
        }

        currentAmount -= amount;
    }

    public String getName() {
        return name;
    }

    public int getAccountNumber() {
        return accountNumber;
    }
}
