package SkillsMatcher;//package midterms.m1;

import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

class Candidate {
    private String id;
    private ArrayList<String> skills = new ArrayList<>();


    public Candidate(String id) {
        this.id = id;
    }

    void addSkill(String skill) {
        skills.add(skill);
    }

    public ArrayList<String> getSkills() {
        return skills;
    }

    public long countMatches(List<String> required) {
        return required.stream().filter(s -> skills.contains(s)).count();
    }

    public static Candidate create(String line) {
        String [] parts = line.trim().split("\\s+");
        String id = parts[0];

        Candidate c = new Candidate(id);

        for (int i = 1; i < parts.length; i++) {
            c.addSkill(parts[i]);
        }

        return c;
    }

    public String getId() {
        return id;
    }
}

class SkillsMatcher {
    List<String> requiredSkills;
    List<Candidate> candidates = new ArrayList<>();

    SkillsMatcher(List<String> requiredSkills) {
        this.requiredSkills = requiredSkills;
    }

    public void evaluateCandidates(InputStream is, OutputStream os) {
        BufferedReader br = new BufferedReader(new InputStreamReader(is));

        br.lines().forEach(l -> candidates.add(Candidate.create(l)));

        candidates.sort(Comparator.comparingLong((Candidate c) -> c.countMatches(requiredSkills)).reversed());

        PrintWriter pw = new PrintWriter(os);
        candidates.forEach(c -> pw.printf("%s %d%n", c.getId(), c.countMatches(requiredSkills)));
        pw.flush();
    }

}


public class SkillsMatcherTest {

    public static void wtf(Scanner in) throws FileNotFoundException {
        PrintWriter pw = new PrintWriter(new FileOutputStream("input.txt"));
        while (in.hasNextLine()) {
            pw.println(in.nextLine());
        }
        pw.flush();
        pw.close();
        in.close();
    }

    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(System.in);


        List<String> required = Arrays.stream(sc.nextLine().split(";"))
                .collect(Collectors.toList());


        wtf(sc);

        SkillsMatcher matcher = new SkillsMatcher(required);


        matcher.evaluateCandidates(new FileInputStream("input.txt"), System.out);
    }
}
