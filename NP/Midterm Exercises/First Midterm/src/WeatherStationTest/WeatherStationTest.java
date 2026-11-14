package WeatherStationTest;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Date;
import java.util.Scanner;
import java.util.stream.Collectors;

public class WeatherStationTest {
    public static void main(String[] args) throws ParseException {
        Scanner scanner = new Scanner(System.in);
        DateFormat df = new SimpleDateFormat("dd.MM.yyyy HH:mm:ss");
        int n = scanner.nextInt();
        scanner.nextLine();
        WeatherStation ws = new WeatherStation(n);
        while (true) {
            String line = scanner.nextLine();
            if (line.equals("=====")) {
                break;
            }
            String[] parts = line.split(" ");
            float temp = Float.parseFloat(parts[0]);
            float wind = Float.parseFloat(parts[1]);
            float hum = Float.parseFloat(parts[2]);
            float vis = Float.parseFloat(parts[3]);
            line = scanner.nextLine();
            Date date = df.parse(line);
            ws.addMeasurment(temp, wind, hum, vis, date);
        }
        String line = scanner.nextLine();
        Date from = df.parse(line);
        line = scanner.nextLine();
        Date to = df.parse(line);
        scanner.close();
        System.out.println(ws.total());
        try {
            ws.status(from, to);
        } catch (RuntimeException e) {
            System.out.println(e);
        }
    }
}

// vashiot kod ovde

class Measurement {
    private double temperature;
    private double humidity;
    private double wind;
    private double visibility;
    private Date date;

    public Measurement(double temperature, double wind, double humidity, double visibility, Date date) {
        this.temperature = temperature;
        this.wind = wind;
        this.humidity = humidity;
        this.visibility = visibility;
        this.date = date;
    }

    public double getTemperature() {
        return temperature;
    }

    public double getHumidity() {
        return humidity;
    }

    public double getWind() {
        return wind;
    }

    public double getVisibility() {
        return visibility;
    }

    public Date getDate() {
        return date;
    }

//    24.6 80.2 km/h 28.7% 51.7 km Tue Dec 17 23:40:15 CET 2013


    @Override
    public String toString() {
        return String.format("%.1f %.1f km/h %.1f%% %.1f km %s", temperature, wind, humidity, visibility,date.toString().replace("UTC", "GMT"));
    }
}

class WeatherStation {
    private int days;
    private ArrayList<Measurement> measurements = new ArrayList<>();

    public WeatherStation(int days) {
        this.days = days;
    }

    public void addMeasurment(float temperature, float wind, float humidity, float visibility, Date date) {

        boolean tooClose = measurements.stream().anyMatch(m -> Math.abs(date.getTime() - m.getDate().getTime()) < 2.5 * 60 * 1000);
        if(tooClose) return;

        long maxAge = days * 24L * 60 * 60 * 1000;
        measurements.removeIf(x -> date.getTime() - x.getDate().getTime() > maxAge);

        measurements.add(new Measurement(temperature, wind, humidity, visibility, date));
    }

    public int total() {
        return measurements.size();
    }

    public void status(Date from, Date to) {
        ArrayList<Measurement> filtered = measurements.stream().filter(m -> {
            long millis = m.getDate().getTime();
            long beforeMillis = from.getTime();
            long afterMillis = to.getTime();

            return beforeMillis <= millis && millis <= afterMillis;
        }).sorted(Comparator.comparingLong(m -> m.getDate().getTime())).collect(Collectors.toCollection(ArrayList::new));

        if (filtered.isEmpty()) throw new RuntimeException();


        filtered.forEach(System.out::println);
        double averageTemperature = filtered.stream().mapToDouble(Measurement::getTemperature).average().orElse(0);
        System.out.printf("Average temperature: %.2f%n", averageTemperature);

    }
}