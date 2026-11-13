package ShapesExtended;

import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.DoubleSummaryStatistics;
import java.util.List;

abstract class Shape {
    protected double size;

    public Shape(double size) {
        this.size = size;
    }

    public abstract double area();

    public static Shape create(String type, double size) {
        switch (type) {
            case "S": return new Square(size);
            case "C": return new Circle(size);
            default:  throw new IllegalArgumentException("Unknown type: " + type);
        }
    }

}

class Square extends Shape {
    public Square(double size) {
        super(size);
    }

    @Override
    public double area() {
        return size * size;
    }
}

class Circle extends Shape {
    public Circle(double size) {
        super(size);
    }

    @Override
    public double area() {
        return size * size * Math.PI;
    }
}

class Canvas {
    private List<Shape> shapes = new ArrayList<>();
    private String id;

    public Canvas(String id) {
        this.id = id;
    }


    public static Canvas create(String line, double maxArea) throws InvalidCanvasException {
        String [] parts = line.trim().split("\\s+");
        String canvasId = parts[0];
        Canvas c = new Canvas(canvasId);

        for(int i = 1; i < parts.length; i += 2) {
            Shape s = Shape.create(parts[i], Double.parseDouble(parts[i + 1]));
            if (s.area() > maxArea) throw new InvalidCanvasException(canvasId, maxArea);
            c.shapes.add(s);
        }

        return c;
    }

    public double getTotalArea() {
        return shapes.stream().mapToDouble(Shape::area).sum();
    }

    @Override
    public String toString() {


        long circles = shapes.stream().filter(x -> x instanceof Circle).count();
        long squares = shapes.size() - circles;
        DoubleSummaryStatistics dss = new DoubleSummaryStatistics();
//        double max = shapes.stream().mapToDouble(Shape::area).max().orElse(0);
//        double min = shapes.stream().mapToDouble(Shape::area).min().orElse(0);
//        double average = shapes.stream().mapToDouble(Shape::area).average().orElse(0);
        shapes.forEach(x -> dss.accept(x.area()));

        return String.format("%s %d %d %d %.2f %.2f %.2f", id, shapes.size(), circles, squares, dss.getMin(), dss.getMax(), dss.getAverage());
    }


}


class ShapesApplication {
    private double maxArea;
    List<Canvas> canvases = new ArrayList<>();

    public ShapesApplication (double maxArea) {
        this.maxArea = maxArea;
    }

    void readCanvases (InputStream inputStream) {
        BufferedReader bf = new BufferedReader(new InputStreamReader(inputStream));

        bf.lines()
                .filter(l -> !l.trim().isEmpty())
                .forEach(l -> {
                    try {
                        canvases.add(Canvas.create(l, maxArea));
                    } catch (InvalidCanvasException e) {
                        System.out.println(e.getMessage());
                    }
                });
    }

    void printCanvases(OutputStream os) {
        PrintWriter pw = new PrintWriter(os);
        canvases.stream().sorted(Comparator.comparingDouble(Canvas::getTotalArea).reversed()).forEach(pw::println);
        pw.flush();
    }

}

class InvalidCanvasException extends Exception {
    public InvalidCanvasException(String canvasId, double maxArea) {
        super(String.format("Canvas %s has a shape with area larger than %.2f", canvasId, maxArea));
    }
}

public class Shapes2Test {

    public static void main(String[] args) {

        ShapesApplication shapesApplication = new ShapesApplication(10000);

        System.out.println("===READING CANVASES AND SHAPES FROM INPUT STREAM===");
        shapesApplication.readCanvases(System.in);

        System.out.println("===PRINTING SORTED CANVASES TO OUTPUT STREAM===");
        shapesApplication.printCanvases(System.out);


    }
}