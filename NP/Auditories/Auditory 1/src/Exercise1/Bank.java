package Exercise1;

import java.util.ArrayList;
import java.util.List;

public class Bank {
    List<Account> accounts = new ArrayList<Account>();

    private void addAccount(Account account) {
        accounts.add(account);
    }

    private double totalAssets() {
        double sum = 0;
        for(Account account: accounts) {
            sum += account.getCurrentAmount();
        }
        return sum;
    }

    public void addInterest() {
        for(Account account: accounts) {

        }
    }
}
