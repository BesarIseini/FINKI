package Exercise1;

public class Developer extends Employee {

    private int overtimeHours;

    public Developer(String id, String name, double baseSalary, int overtimeHours) {
        super(id, name, baseSalary);
        this.overtimeHours = overtimeHours;
    }

    @Override
    public double calculateSalary() {
        return super.calculateSalary() + 300 * overtimeHours;
    }

    @Override
    public String toString() {
        return super.toString() + String.format(" overtime=%d", overtimeHours);
    }
}
