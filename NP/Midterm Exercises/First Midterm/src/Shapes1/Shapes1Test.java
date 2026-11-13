package Shapes1;


import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;


class Canvas implements Comparable<Canvas> {
    private int squares;
    private String id;
    private ArrayList<Integer> squaresList;

    Canvas(int squares, String id, ArrayList<Integer> squaresList) {
        this.squares = squares;
        this.id = id;
        this.squaresList = squaresList;
    }

    public static Canvas create(String line) {
        String [] parts = line.trim().split("\\s+");
        ArrayList<Integer> squaresList = new ArrayList<>();
        int squares = 0;
        String id = parts[0];

        for(int i = 1; i < parts.length; i++) {
            squares++;
            squaresList.add(Integer.parseInt(parts[i]));
        }

        return new Canvas(squares, id, squaresList);
    }

    public int getSquares() {
        return squares;
    }

    public int getSquarePerimeter(int id) {
        return this.squaresList.get(id) * 4;
    }

    public int getTotalSquarePerimeter() {
        int sum = 0;
        for(int i = 0; i < squaresList.size(); i++) {
            sum += getSquarePerimeter(i);
        }
        return sum;
    }

    public int getTotalSquaresPerimeterStream() {
        return squaresList.stream().mapToInt(value -> value * 4).sum();
    }

    @Override
    public int compareTo(Canvas o) {
        return Integer.compare(getTotalSquaresPerimeterStream(), o.getTotalSquaresPerimeterStream());
    }

    @Override
    public String toString() {
        return String.format("%s %d %d", id, squares, getTotalSquaresPerimeterStream());
    }
}

class ShapesApplication {

    private ArrayList<Canvas> list;

    public ShapesApplication() {
        this.list = new ArrayList<>();
    }



    int readCanvases(InputStream inputStream) {
        Scanner br = new Scanner(inputStream);
        while(br.hasNext()) {
            list.add(Canvas.create(br.nextLine()));
        }


        return list.stream().mapToInt(Canvas::getSquares).sum();

    }

    public void printLargestCanvasTo(PrintStream out) {
        //Comparator.comparing(Canvas::getTotalSquaresPerimeterStream)
        Canvas newList = list.stream().max(Comparator.comparing(Canvas::getTotalSquaresPerimeterStream)).get();

        out.println(newList);
    }
}


public class Shapes1Test {

    public static void main(String[] args) {
        ShapesApplication shapesApplication = new ShapesApplication();

        System.out.println("===READING SQUARES FROM INPUT STREAM===");
        System.out.println(shapesApplication.readCanvases(System.in));
        System.out.println("===PRINTING LARGEST CANVAS TO OUTPUT STREAM===");
        shapesApplication.printLargestCanvasTo(System.out);

    }
}