package Exercise1;

import java.util.Scanner;

public class Exercise1test {

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
