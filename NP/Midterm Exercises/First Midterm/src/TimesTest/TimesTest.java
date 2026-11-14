package TimesTest;

import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;


class InvalidTimeException extends Exception {
    public InvalidTimeException(String line) {
        super(line);
    }
}

class UnsupportedFormatException extends Exception {
    public UnsupportedFormatException(String line) {
        super(line);
    }
}

class Time {
    private int hour;
    private int minutes;

    public Time(int hour, int minutes) {
        this.hour = hour;
        this.minutes = minutes;
    }

    public int getHour() {
        return hour;
    }

    public int getMinutes() {
        return minutes;
    }

    public static Time create(String line) throws UnsupportedFormatException, InvalidTimeException {
        String [] parts = line.split("[:.]");
        if (parts.length != 2) throw new UnsupportedFormatException(line);

        int hours, minutes;
        try {
            hours = Integer.parseInt(parts[0]);
            minutes = Integer.parseInt(parts[1]);
        } catch (NumberFormatException e) {
            throw new UnsupportedFormatException(line);
        }

        if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59)
            throw new InvalidTimeException(line);
        return new Time(hours, minutes);
    }

    public String format(boolean militaryTime) {
        if(militaryTime) {
            return String.format("%2d:%02d", hour, minutes);
        }

        int hours = hour;
        String text;

        if(hours < 1) {
            hours += 12;
            text = "AM";
        } else if (hours < 12) {
            text = "AM";
        } else if (hours < 13) {
            text = "PM";
        } else {
            hours -= 12;
            text = "PM";
        }

        return String.format("%2d:%02d %s", hours, minutes, text);
    }
}




class TimeTable {
    ArrayList<Time> times = new ArrayList<>();

    public TimeTable() {

    }

    void readTimes(InputStream inputStream) throws InvalidTimeException, UnsupportedFormatException {
        Scanner sc = new Scanner(inputStream);
        while (sc.hasNext()) {
            times.add(Time.create(sc.next()));   // earlier times stay added if this throws
        }

    }

    void writeTimes(OutputStream outputStream, TimeFormat format) {
        final boolean militaryTime = format == TimeFormat.FORMAT_24;



        PrintWriter pw = new PrintWriter(outputStream);

        times.sort(Comparator.comparingInt(Time::getHour).thenComparingInt(Time::getMinutes));
        times.forEach(t -> pw.println(t.format(militaryTime)));

        pw.flush();
    }
}



public class TimesTest {

    public static void main(String[] args) {
        TimeTable timeTable = new TimeTable();
        try {
            timeTable.readTimes(System.in);
        } catch (UnsupportedFormatException e) {
            System.out.println("UnsupportedFormatException: " + e.getMessage());
        } catch (InvalidTimeException e) {
            System.out.println("InvalidTimeException: " + e.getMessage());
        }
        System.out.println("24 HOUR FORMAT");
        timeTable.writeTimes(System.out, TimeFormat.FORMAT_24);
        System.out.println("AM/PM FORMAT");
        timeTable.writeTimes(System.out, TimeFormat.FORMAT_AMPM);
    }

}

enum TimeFormat {
    FORMAT_24, FORMAT_AMPM
}