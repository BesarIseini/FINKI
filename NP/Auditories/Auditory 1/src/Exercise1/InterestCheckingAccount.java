package Exercise1;

public class InterestCheckingAccount extends Account implements InterestBearingAccount {
    public static final double INTEREST_RATE = 0.03;

    public InterestCheckingAccount(double currentAmount, String name) {
        super(currentAmount, name);
    }

    @Override
    public void addInterest() {
        addAmount(getCurrentAmount() * INTEREST_RATE);
    }



}
