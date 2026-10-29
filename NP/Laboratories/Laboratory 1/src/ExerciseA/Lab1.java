package ExerciseA;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// ===================== Part A: solution classes =====================

/*
TODO: your code here
*/

abstract class Ticket {
    private final String plate;
    private final int minutes;


    protected Ticket(String plate, int minutes) throws IllegalArgumentException {
        if(plate == null || plate.trim().isEmpty() || minutes <= 0) {
            throw new IllegalArgumentException("Invalid Argument.");
        }
        this.plate = plate;
        this.minutes = minutes;
    }

    public int getMinutes() {
        return minutes;
    }

    public String getPlate() {
        return plate;
    }

    public abstract double price();

    @Override
    public String toString() {
        return plate;
    }
}


class HourlyTicket extends Ticket {

    public HourlyTicket(String plate, int minutes) throws IllegalArgumentException {
        super(plate, minutes);
    }

    @Override
    public double price() {
        return Math.ceil(getMinutes() / 60.0) * 50;
    }
}

class DailyTicket extends Ticket {

    public DailyTicket(String plate, int minutes) throws IllegalArgumentException {
        super(plate, minutes);
    }

    @Override
    public double price() {
        int days = (int) Math.ceil(getMinutes() / 1440.0);
        return days * 300;
    }
}

class LotFullException extends Exception {
    public LotFullException() {
        super("Full");
    }
}




class ParkingLot {
    private Ticket[] tickets;
    private int ticketCount = 0;;
    private int capacity;


    public ParkingLot(int capacity) throws IllegalArgumentException {
        if(capacity <= 0) throw new IllegalArgumentException("Invalid Argument");

        tickets = new Ticket[capacity];
        this.capacity = capacity;

    }


    public void addTicket(Ticket ticket) throws LotFullException {
        if(ticket == null) throw new IllegalArgumentException();

        if(capacity == ticketCount) throw new LotFullException();

        tickets[ticketCount++] = ticket;

    }

    public int getTicketCount() {
        return ticketCount;
    }

    public double totalRevenue() {
        double revenue = 0;

        for(int i = 0; i < ticketCount; i++) {
            revenue += tickets[i].price();
        }

        return revenue;
    }






}

// ===================== Main: command interpreter =====================
//
// Reads commands from standard input (one per line) and calls the matching constructor / method.
//
//   LOT <capacity>                  new ParkingLot(capacity)
//   NEW_HOURLY <plate> <minutes>    new HourlyTicket(plate, minutes)   -> prints type, plate, minutes, price()
//   NEW_DAILY  <plate> <minutes>    new DailyTicket(plate, minutes)    -> prints type, plate, minutes, price()
//   ADD_HOURLY <plate> <minutes>    lot.addTicket(new HourlyTicket(plate, minutes))
//   ADD_DAILY  <plate> <minutes>    lot.addTicket(new DailyTicket(plate, minutes))
//   ADD_NULL                        lot.addTicket(null)
//   COUNT                           lot.getTicketCount()
//   REVENUE                         lot.totalRevenue()
//   END                             stop reading
//
// In <plate>, the word NULL means a null plate and the word EMPTY means the empty string "".

public class Lab1 {
    private static ParkingLot lot = null;

    private static String plateArg(String token) {
        if (token.equals("NULL")) return null;
        if (token.equals("EMPTY")) return "";
        return token;
    }

    private static void addToLot(Ticket ticket) {
        // 'ticket' may be null (ADD_NULL) or the constructor may already have failed (handled by the caller)
        try {
            lot.addTicket(ticket);
            System.out.println("Added");
        } catch (LotFullException e) {
            System.out.println("LotFullException");
        } catch (IllegalArgumentException e) {
            System.out.println("IllegalArgumentException");
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = in.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty()) continue;
            String[] p = line.split("\\s+");
            String cmd = p[0];
            if (cmd.equals("END")) break;

            switch (cmd) {
                case "LOT":
                    try {
                        lot = new ParkingLot(Integer.parseInt(p[1]));
                        System.out.println("Lot created (capacity " + p[1] + ")");
                    } catch (IllegalArgumentException e) {
                        System.out.println("IllegalArgumentException");
                    }
                    break;

                case "NEW_HOURLY":
                case "NEW_DAILY":
                    try {
                        Ticket t = cmd.equals("NEW_HOURLY")
                                ? new HourlyTicket(plateArg(p[1]), Integer.parseInt(p[2]))
                                : new DailyTicket(plateArg(p[1]), Integer.parseInt(p[2]));
                        System.out.println((cmd.equals("NEW_HOURLY") ? "HourlyTicket " : "DailyTicket ")
                                + t.getPlate() + " " + t.getMinutes() + " " + t.price());
                    } catch (IllegalArgumentException e) {
                        System.out.println("IllegalArgumentException");
                    }
                    break;

                case "ADD_HOURLY":
                case "ADD_DAILY":
                    if (lot == null) {
                        System.out.println("No lot created");
                        break;
                    }
                    Ticket ticket;
                    try {
                        ticket = cmd.equals("ADD_HOURLY")
                                ? new HourlyTicket(plateArg(p[1]), Integer.parseInt(p[2]))
                                : new DailyTicket(plateArg(p[1]), Integer.parseInt(p[2]));
                    } catch (IllegalArgumentException e) {
                        System.out.println("IllegalArgumentException");
                        break;
                    }
                    addToLot(ticket);
                    break;

                case "ADD_NULL":
                    if (lot == null) {
                        System.out.println("No lot created");
                    } else {
                        addToLot(null);
                    }
                    break;

                case "COUNT":
                    System.out.println(lot == null ? "No lot created" : "Count: " + lot.getTicketCount());
                    break;

                case "REVENUE":
                    System.out.println(lot == null ? "No lot created" : "Revenue: " + lot.totalRevenue());
                    break;

                default:
                    System.out.println("Unknown command");
            }
        }
    }
}