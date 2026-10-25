package Exercise1;

public class TeamLead extends Developer {

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
