package SubtitlesTest;

import java.io.InputStream;
import java.util.ArrayList;
import java.util.Scanner;

class Entry {
    private int sequence;
    private int startTime;
    private int endTime;
    private String text;

    public Entry(int sequence, int startTime, int endTime, String text) {
        this.sequence = sequence;
        this.startTime = startTime;
        this.endTime = endTime;
        this.text = text;
    }

    public void shiftMs(int ms) {
        startTime += ms;
        endTime += ms;
    }

    public static int convertStringToTime(String[] parts) {
        int hours = Integer.parseInt(parts[0]) * 60 * 60 * 1000;
        int minutes = Integer.parseInt(parts[1])  * 60 * 1000;
        int seconds = Integer.parseInt(parts[2])  * 1000;
        int milliseconds = Integer.parseInt(parts[3]);

        return hours + minutes + seconds + milliseconds;
    }




    public static String convertTimeToString(int ms) {

        int hours   = ms / (60 * 60 * 1000);
        int minutes = ms / (60 * 1000) % 60;
        int seconds = ms / (1000) % 60;
        int millis  = ms % 1000;

        return String.format("%02d:%02d:%02d,%03d",  hours, minutes,  seconds,  millis);
    }



    public static Entry create(int number, String [] parts, String text) {



        String [] firstTime = parts[0].split("[:,]");
        String [] secondTime  = parts[2].split("[:,]");;



        return new Entry(number, convertStringToTime(firstTime), convertStringToTime(secondTime), text);
    }

    @Override
    public String toString() {

        String sb = sequence + "\n" +
                Entry.convertTimeToString(startTime) +
                " --> " +
                Entry.convertTimeToString(endTime) + "\n" +
                text;
        return sb;
    }
}

class Subtitles {
    ArrayList<Entry> entries = new ArrayList<>();

    public Subtitles() {

    }

    int loadSubtitles(InputStream inputStream) {
        Scanner input = new Scanner(inputStream);
        String line;
        int count = 0;

        while (input.hasNext()) {
            line = input.nextLine();
            if(line.isEmpty()) continue;

            int number = Integer.parseInt(line);
            String times = input.nextLine();



            String [] parts = times.split("\\s+");

            StringBuilder text = new StringBuilder();
            while (input.hasNextLine()) {
                line = input.nextLine();
                if (line.trim().isEmpty()) break;
                text.append(line).append("\n");
            }

            entries.add(Entry.create(number, parts, text.toString()));


            count++;
        }

        return count;
    }

    public void print() {
        entries.forEach(System.out::println);
    }

    public void shift(int shift) {
        for (Entry entry : entries) {
            entry.shiftMs(shift);
        }
    }
}

public class SubtitlesTest {
    public static void main(String[] args) {
        Subtitles subtitles = new Subtitles();
        int n = subtitles.loadSubtitles(System.in);
        System.out.println("+++++ ORIGINIAL SUBTITLES +++++");
        subtitles.print();
        int shift = n * 37;
        shift = (shift % 2 == 1) ? -shift : shift;
        System.out.println(String.format("SHIFT FOR %d ms", shift));
        subtitles.shift(shift);
        System.out.println("+++++ SHIFTED SUBTITLES +++++");
        subtitles.print();
    }
}

// Вашиот код овде
