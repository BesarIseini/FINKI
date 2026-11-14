package Applicant;

import java.util.Scanner;

/**
 * I partial exam 2016
 */
public class ApplicantEvaluationTest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String name = scanner.nextLine();
        int creditScore = scanner.nextInt();
        int employmentYears = scanner.nextInt();
        boolean hasCriminalRecord = scanner.nextBoolean();
        int choice = scanner.nextInt();
        Applicant applicant = new Applicant(name, creditScore, employmentYears, hasCriminalRecord);
        Evaluator.TYPE type = Evaluator.TYPE.values()[choice];
        Evaluator evaluator = null;
        try {
            evaluator = EvaluatorBuilder.build(type);
            System.out.println("Applicant");
            System.out.println(applicant);
            System.out.println("Evaluation type: " + type.name());
            if (evaluator.evaluate(applicant)) {
                System.out.println("Applicant is ACCEPTED");
            } else {
                System.out.println("Applicant is REJECTED");
            }
        } catch (InvalidEvaluation invalidEvaluation) {
            System.out.println("Invalid evaluation");
        }
    }
}

class Applicant {
    private String name;

    private int creditScore;
    private int employmentYears;
    private boolean hasCriminalRecord;

    public Applicant(String name, int creditScore, int employmentYears, boolean hasCriminalRecord) {
        this.name = name;
        this.creditScore = creditScore;
        this.employmentYears = employmentYears;
        this.hasCriminalRecord = hasCriminalRecord;
    }

    public String getName() {
        return name;
    }

    public int getCreditScore() {
        return creditScore;
    }

    public int getEmploymentYears() {
        return employmentYears;
    }

    public boolean hasCriminalRecord() {
        return hasCriminalRecord;
    }

    @Override
    public String toString() {
        return String.format("Name: %s\nCredit score: %d\nExperience: %d\nCriminal record: %s\n",
                name, creditScore, employmentYears, hasCriminalRecord ? "Yes" : "No");
    }
}

interface Evaluator {
    enum TYPE {
        NO_CRIMINAL_RECORD,
        MORE_EXPERIENCE,
        MORE_CREDIT_SCORE,
        NO_CRIMINAL_RECORD_AND_MORE_EXPERIENCE,
        MORE_EXPERIENCE_AND_MORE_CREDIT_SCORE,
        NO_CRIMINAL_RECORD_AND_MORE_CREDIT_SCORE,
        INVALID // should throw exception
    }

    boolean evaluate(Applicant applicant);
}

class EvaluatorBuilder {

    private static final Evaluator NO_CRIMINAL = a -> !a.hasCriminalRecord();
    private static final Evaluator EXPERIENCE  = a -> a.getEmploymentYears() >= 10;
    private static final Evaluator CREDIT      = a -> a.getCreditScore() >= 500;

    private static Evaluator and(Evaluator x, Evaluator y) {
        return a -> x.evaluate(a) && y.evaluate(a);
    }

    public static Evaluator build(Evaluator.TYPE type) throws InvalidEvaluation {
        switch (type) {
            case NO_CRIMINAL_RECORD:
                return  NO_CRIMINAL;
            case MORE_EXPERIENCE:
                return EXPERIENCE;
            case MORE_CREDIT_SCORE:
                return CREDIT;
            case NO_CRIMINAL_RECORD_AND_MORE_EXPERIENCE:
                return and(NO_CRIMINAL, EXPERIENCE);
            case MORE_EXPERIENCE_AND_MORE_CREDIT_SCORE:
                return and(EXPERIENCE, CREDIT);
            case NO_CRIMINAL_RECORD_AND_MORE_CREDIT_SCORE:
                return and(NO_CRIMINAL, CREDIT);
            default: throw new InvalidEvaluation();
        }
    }
}

class InvalidEvaluation extends Exception {
    public InvalidEvaluation() {
        super();
    }
}


// имплементација на евалуатори овде


