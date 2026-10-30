package Exercise1;

public class Intern extends Employee {

    int months;

    public Intern(String id, String name, double baseSalary, int months) {
        super(id, name, baseSalary);
        this.months = months;
    }

    @Override
    public double calculateSalary() {
        double salary = super.calculateSalary();
        if (months >= 6) {
            salary *= 0.8;
        } else {
            salary *= 0.6;
        }
        return salary;
    }

    @Override
    public String toString() {
        return super.toString() + String.format(" months=%d", months);
    }
}
