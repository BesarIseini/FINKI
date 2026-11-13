package ExerciseA;

import com.sun.jdi.Value;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

// ===================== Part A: your classes =====================
//
// Write ValidationResult, Validator, User and UserValidation here.

/*
TODO: your Part A code here
*/


final class ValidationResult {
    private final List <String> errorMessages;

    private ValidationResult(List <String> errorMessages) {
        this.errorMessages = List.copyOf(errorMessages);
    }


    public static ValidationResult ok() {
        return new ValidationResult(List.of());
    }

    public static ValidationResult error(String message) {
        if(message == null || message.isEmpty()) throw new IllegalArgumentException();

        return new ValidationResult(List.of(message));
    }

    public static ValidationResult of(List<String> errors) {
        if(errors == null) throw new IllegalArgumentException();


        return new ValidationResult(errors);
    }

    public boolean isValid() {
        return errorMessages.isEmpty();
    }

    public List<String> getErrors() {
        return errorMessages;
    }


}





@FunctionalInterface
interface Validator<T> {
    ValidationResult validate(T value);

    default Validator<T> and(Validator<? super T> other) {
        if(other == null) throw new IllegalArgumentException();

        return value -> {
            ValidationResult s = validate(value);
            if(s.isValid()) {
                return other.validate(value);
            }
            return s;
        };
    }

    static <T> Validator<T> notNull() {
        return value -> value == null ? ValidationResult.error("must not be null") : ValidationResult.ok();
    }

    static Validator<String> minLength(int min) {
        if(min < 0) throw new IllegalArgumentException();
        return value -> {
            if(value == null) {
                return ValidationResult.error("must not be null");
            } else if (value.length() < min) {
                return ValidationResult.error(String.format("must have at least %d characters", min));
            }
            return ValidationResult.ok();
        };
    }

    static Validator<Integer> range (int min, int max) {
        if(max < min) throw new IllegalArgumentException();
        return value -> {
            if(value == null) {
                return ValidationResult.error("must not be null");
            } else if (min > value || value > max) {
                return ValidationResult.error(String.format("must be between %d and %d", min, max));
            }
            return ValidationResult.ok();
        };
    }
}

class User {
    private String name;
    private Integer age;
    private String email;

    public User(String name, Integer age, String email) {
        this.age = age;
        this.email = email;
        this.name = name;
    }

    public Integer getAge() {
        return age;
    }

    public String getName() {
        return name;
    }

    public String getEmail() {
        return email;
    }
}


//4. Class UserValidation
//Implement a UserValidation class with the following static method:
//
//public static ValidationResult validate(User user)
//The method must validate the user's three fields according to the following rules, in the specified order:
//
//name – first check that it is not null, then that it contains at least 3 characters.
//age – first check that it is not null, then that it is between 18 and 120 (inclusive).
//email – first check that it is not null, then that it contains at least 5 characters, and finally that
// it contains the @ character. Define the last check using a lambda expression; when it fails,
// return the error must contain @.
//Note:
//
//Use the appropriate validators from Validator<T> for each field and combine them with and.
// This ensures that only the first error for each field is reported. For example,
// if email has only two characters and does not contain @, report the length error, not the @ error as well.
//Validate all three fields, even if an earlier field is invalid. Collect their errors in the order name, age, email.
//Prefix every error with the field name followed by :, for example name: must not be null or email: must contain @.
//If all fields are valid, return a successful result without errors.
//If user is null, throw IllegalArgumentException.


class UserValidation {
    public static ValidationResult validate(User user) {
        if(user == null) throw new IllegalArgumentException();
        String name = user.getName();
        Integer age = user.getAge();
        String email = user.getEmail();

        Validator<String> containsAt = value -> value.contains("@")
                ? ValidationResult.ok()
                : ValidationResult.error("must contain @");

        ValidationResult n = Validator.<String>notNull().and(Validator.minLength(3)).validate(name);
        ValidationResult a = Validator.<Integer>notNull().and(Validator.range(18,120)).validate(age);
        ValidationResult e = Validator.<String>notNull().and(Validator.minLength(5)).and(containsAt).validate(email);

        List<String> list = new ArrayList<>();
        for (String error : n.getErrors()) list.add("name: " + error);
        for (String error : a.getErrors()) list.add("age: " + error);
        for (String error : e.getErrors()) list.add("email: " + error);

        return ValidationResult.of(list);





    }
}

// ===================== Test harness (do not modify) =====================
//
// Reads commands from standard input (one per line) and calls your classes.
// Validators have a name (e.g. V) and a type: STR (Validator<String>) or INT (Validator<Integer>).
// NULL means null. Values must not contain spaces.

public class Lab2 {
    private static final Map<String, Validator<?>> vals = new HashMap<>();
    private static final Map<String, String> types = new HashMap<>();

    private static String show(ValidationResult r) {
        return r.isValid() ? "Valid" : "Invalid: " + r.getErrors();
    }

    private static boolean missing(String name) {
        if (!vals.containsKey(name)) {
            System.out.println("No validator " + name);
            return true;
        }
        return false;
    }

    private static Validator<String> strAtom(String tok) {
        if (tok.equals("NOTNULL")) return Validator.<String>notNull();
        if (tok.startsWith("MINLEN:")) return Validator.minLength(Integer.parseInt(tok.substring(7)));
        if (tok.equals("HASAT")) {
            return s -> s.contains("@") ? ValidationResult.ok() : ValidationResult.error("must contain @");
        }
        throw new IllegalStateException("unknown atom " + tok);
    }

    private static Validator<Integer> intAtom(String tok) {
        if (tok.equals("NOTNULL")) return Validator.<Integer>notNull();
        if (tok.startsWith("RANGE:")) {
            String[] r = tok.split(":");
            return Validator.range(Integer.parseInt(r[1]), Integer.parseInt(r[2]));
        }
        throw new IllegalStateException("unknown atom " + tok);
    }

    private static String strValue(String t) {
        return t.equals("NULL") ? null : t;
    }

    private static Integer intValue(String t) {
        return t.equals("NULL") ? null : Integer.valueOf(t);
    }

    private static List<String> errorList(String t) {
        List<String> list = new ArrayList<>();
        if (!t.equals("-")) list.addAll(Arrays.asList(t.split(",")));
        return list;
    }

    @SuppressWarnings("unchecked")
    private static void run(String[] p) {
        switch (p[0]) {
            //   VAL <name> <STR|INT> <expr>   a chain of atoms joined with '>' (= .and(next))
            //        STR atoms: NOTNULL, MINLEN:<n>, HASAT (a lambda: "must contain @"), OBJNOTNULL (Validator<Object>.notNull())
            //        INT atoms: NOTNULL, RANGE:<min>:<max>
            case "VAL": {
                String[] toks = p[3].split(">");
                if (p[2].equals("STR")) {
                    Validator<String> v = null;
                    for (String tok : toks) {
                        if (tok.equals("OBJNOTNULL")) {
                            v = v.and(Validator.<Object>notNull());          // Validator<Object> where Validator<? super String> is expected
                        } else {
                            Validator<String> next = strAtom(tok);
                            v = (v == null) ? next : v.and(next);
                        }
                    }
                    vals.put(p[1], v);
                } else {
                    Validator<Integer> v = null;
                    for (String tok : toks) {
                        Validator<Integer> next = intAtom(tok);
                        v = (v == null) ? next : v.and(next);
                    }
                    vals.put(p[1], v);
                }
                types.put(p[1], p[2]);
                System.out.println("Defined " + p[1] + " (" + p[2] + ")");
                break;
            }
            case "CHECK": {
                if (missing(p[1])) break;
                ValidationResult r = types.get(p[1]).equals("STR")
                        ? ((Validator<String>) vals.get(p[1])).validate(strValue(p[2]))
                        : ((Validator<Integer>) vals.get(p[1])).validate(intValue(p[2]));
                System.out.println(show(r));
                break;
            }
            case "AND_NULL":
                if (missing(p[1])) break;
                ((Validator<String>) vals.get(p[1])).and(null);
                System.out.println("No exception");
                break;
            case "MODIFY": {
                if (missing(p[1])) break;
                ValidationResult r = types.get(p[1]).equals("STR")
                        ? ((Validator<String>) vals.get(p[1])).validate(strValue(p[2]))
                        : ((Validator<Integer>) vals.get(p[1])).validate(intValue(p[2]));
                r.getErrors().add("x");
                System.out.println("Modified");
                break;
            }
            case "RESULT_OK":
                System.out.println("ok: " + show(ValidationResult.ok()));
                break;
            case "RESULT_OK_MODIFY":
                ValidationResult.ok().getErrors().add("x");
                System.out.println("Modified");
                break;
            case "RESULT_ERROR":
                System.out.println("error: " + show(ValidationResult.error(p[1].equals("NULL") ? null : p[1].equals("EMPTY") ? "" : p[1])));
                break;
            case "RESULT_ERROR_MODIFY":
                ValidationResult.error(p[1]).getErrors().add("x");
                System.out.println("Modified");
                break;
            case "RESULT_OF":
                System.out.println("of: " + show(ValidationResult.of(errorList(p[1]))));
                break;
            case "RESULT_OF_COPY": {
                List<String> src = errorList(p[1]);
                ValidationResult r = ValidationResult.of(src);
                src.add("late");
                if (src.size() > 1) src.set(0, "changed");
                System.out.println("after change: " + show(r));
                break;
            }
            case "RESULT_OF_MODIFY":
                ValidationResult.of(errorList(p[1])).getErrors().add("x");
                System.out.println("Modified");
                break;
            case "RESULT_OF_NULL":
                ValidationResult.of(null);
                System.out.println("No exception");
                break;
            case "USER":
                System.out.println(show(UserValidation.validate(new User(strValue(p[1]), intValue(p[2]), strValue(p[3])))));
                break;
            case "USER_NULL":
                UserValidation.validate(null);
                System.out.println("No exception");
                break;
            default:
                System.out.println("Unknown command");
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = in.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty()) continue;
            String[] p = line.split("\\s+");
            if (p[0].equals("END")) break;
            try {
                run(p);
            } catch (IllegalArgumentException e) {
                System.out.println("IllegalArgumentException");
            } catch (UnsupportedOperationException e) {
                System.out.println("UnsupportedOperationException");
            }
        }
    }
}
