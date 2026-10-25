package Exercise1;

public class Company {
    private String name;
    private Employee [] employees;
    private int count;

    public Company(String name, int capacity) {
        this.name = name;
        this.count = 0;
        this.employees = new Employee[capacity];
    }

    public void hire(Employee e) {
        if(count < employees.length) {
            employees[count++] = e;
        }
    }


    public void printAll() {
        System.out.printf("=== %s ===%n", this.name);
        for (int i = 0; i < count; i++) {
            System.out.println(employees[i]);
        }
    }

    public void printStatistics() {
        int developers = 0, teamLeads = 0, interns = 0, others = 0;

        for(int i = 0; i < count; i++) {
            if(employees[i] instanceof TeamLead) {
                teamLeads++;
            } else if(employees[i] instanceof Developer) {
                developers++;
            } else if(employees[i] instanceof  Intern) {
                interns++;
            } else {
                others++;
            }
        }

        System.out.printf("Developers: %d, Team leads: %d, Interns: %d, Others: %d%n",
                developers, teamLeads, interns, others);

    }

    public double totalPayroll() {
        double payroll = 0;
        for(int i = 0; i < count; i++) {
            payroll += employees[i].calculateSalary();
        }
        return payroll;
    }

    public double averageSalary() {
        if (count == 0) return 0;
        return totalPayroll() / count;
    }


    public Employee highestPaid() {
        if (count == 0) return null;
        Employee highestPaid = employees[0];
        for(int i = 1; i < count; i++) {
            if(employees[i].calculateSalary() > highestPaid.calculateSalary()) {
                highestPaid = employees[i];
            }
        }

        return highestPaid;
    }


    public int countAbove(double threshold) {
        int count = 0;

        for(int i = 0; i < this.count; i++) {
            if(employees[i].calculateSalary() > threshold) count++;
        }

        return count;
    }
}
