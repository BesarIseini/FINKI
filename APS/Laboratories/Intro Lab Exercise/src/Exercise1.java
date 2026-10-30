import java.util.Scanner;


class Employee {
    private String id;
    private String name;
    private double baseSalary;

    public Employee(String id, String name, double baseSalary) {
        this.id = id;
        this.name = name;
        this.baseSalary = baseSalary;
    }

    public double calculateSalary() {
        return baseSalary;
    }

    @Override
    public String toString() {
        return String.format("%s %s salary=%.2f", id, name, calculateSalary());
    }

    public double getBaseSalary() {
        return baseSalary;
    }

    public String getName() {
        return name;
    }

    public String getId() {
        return id;
    }
}

class Intern extends Employee {

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


class Developer extends Employee {

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


class TeamLead extends Developer {

    private int teamSize;

    public TeamLead(String id, String name, double baseSalary, int overtimeHours, int teamSize) {
        super(id, name, baseSalary, overtimeHours);
        this.teamSize = teamSize;
    }

    @Override
    public double calculateSalary() {
        double salary = super.calculateSalary();
        salary += 1000 * teamSize;

        if(teamSize >= 5) {
            salary *= 1.05;
        }

        return salary;
    }


    @Override
    public String toString() {
        return super.toString() + String.format(" team=%d", teamSize);
    }
}


class Company {
    private String name;
    private Employee[] employees;
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
            } else if(employees[i] instanceof Intern) {
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


public class Exercise1 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        input.nextLine();

        Company company = new Company("FINKI Soft", n);

        for(int i = 0; i < n; i++) {
            String [] line = input.nextLine().split(" ");
            String type = line[0];
            String id = line[1];
            String name = line[2];
            double base = Double.parseDouble(line[3]);


            if(type.equals("E")) {
                Employee e = new Employee(id, name, base);
                company.hire(e);
            } else if(type.equals("D")) {
                int overtimeHours = Integer.parseInt(line[4]);
                Developer d = new Developer(id, name, base, overtimeHours);
                company.hire(d);
            } else if (type.equals("L")) {
                int overtimeHours = Integer.parseInt(line[4]);
                int teamSize = Integer.parseInt(line[5]);
                TeamLead l = new TeamLead(id, name, base, overtimeHours, teamSize);
                company.hire(l);
            } else {
                int months = Integer.parseInt(line[4]);
                Intern intern = new Intern(id, name, base, months);
                company.hire(intern);
            }

        }

        int threshhold = input.nextInt();

        company.printAll();
        company.printStatistics();
        System.out.printf("Total payroll: %.2f%n", company.totalPayroll());
        System.out.printf("Average salary: %.2f%n", company.averageSalary());
        Employee highestPaid = company.highestPaid();
        System.out.printf("Highest paid: %s %s (%.2f)%n", highestPaid.getId(), highestPaid.getName(), highestPaid.calculateSalary());
        System.out.printf("Employees with salary above %d.00: %d%n", threshhold, company.countAbove(threshhold));
    }
}
