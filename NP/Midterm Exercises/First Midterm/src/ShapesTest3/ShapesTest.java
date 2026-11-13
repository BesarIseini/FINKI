package ShapesTest3;

import java.util.ArrayList;
import java.util.Scanner;



enum Color {
    RED, GREEN, BLUE
}

interface Scalable {
    void scale(float scaleFactor);
}

interface Stackalbe {
    float weight();
}


abstract class Shape implements Scalable, Stackalbe {
    protected String id;
    protected Color color;

    public Shape(String id, Color color) {
        this.id = id;
        this.color = color;
    }

    String getId() {
        return id;
    }

    abstract public void scale(float scaleFactor);

    abstract public float weight();

    protected String format(String type) {
        return String.format("%s: %-5s%-10s%10.2f", type, id, color, weight());
    }
}

class Circle extends Shape {
    private float radius;

    public Circle(String id, Color color, float radius) {
        super(id, color);
        this.radius = radius;
    }

    @Override
    public void scale(float scaleFactor) {
        radius *= scaleFactor;
    }

    @Override
    public float weight() {
        return (float) Math.PI * radius * radius;
    }

//    C: [id:5 места од лево] [color:10 места од десно] [weight:10.2 места од десно]
    @Override
    public String toString() {
        return format("C");
    }
}

class Rectangle extends Shape {
    private float width;
    private float height;

    public Rectangle(String id, Color color, float width, float height) {
        super(id, color);
        this.width = width;
        this.height = height;
    }


    @Override
    public void scale(float scaleFactor) {
        height *= scaleFactor;
        width *= scaleFactor;
    }

    @Override
    public float weight() {
        return width * height;
    }

    public String toString() {
        return format("R");
    }
}

class Canvas {
    private ArrayList<Shape> shapes = new ArrayList<>();
    public Canvas() {

    }

    void insertElement(Shape s) {
        float shapeArea = s.weight();
        for(int i = 0; i < shapes.size(); i++) {
            if(shapeArea > shapes.get(i).weight()) {
                shapes.add(i, s);
                return;
            }
        }
        shapes.add(s);
    }

    public void add(String id, Color color, float radius) {
        insertElement(new Circle(id, color, radius));
    }

    public void add(String id, Color color, float width, float height) {
        insertElement(new Rectangle(id, color, width, height));
    }

    void scale(String id, float scaleFactor) {
        for(int i = 0; i < shapes.size(); i++) {
            if(shapes.get(i).getId().equals(id)) {
                Shape s = shapes.remove(i);
                s.scale(scaleFactor);
                insertElement(s);
                return;
            }
        }
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Shape shape : shapes) {
            sb.append(shape).append("\n");
        }
        return sb.toString();
    }
}

public class ShapesTest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Canvas canvas = new Canvas();
        while (scanner.hasNextLine()) {
            String line = scanner.nextLine();
            String[] parts = line.split(" ");
            int type = Integer.parseInt(parts[0]);
            String id = parts[1];
            if (type == 1) {
                Color color = Color.valueOf(parts[2]);
                float radius = Float.parseFloat(parts[3]);
                canvas.add(id, color, radius);
            } else if (type == 2) {
                Color color = Color.valueOf(parts[2]);
                float width = Float.parseFloat(parts[3]);
                float height = Float.parseFloat(parts[4]);
                canvas.add(id, color, width, height);
            } else if (type == 3) {
                float scaleFactor = Float.parseFloat(parts[2]);
                System.out.println("ORIGNAL:");
                System.out.print(canvas);
                canvas.scale(id, scaleFactor);
                System.out.printf("AFTER SCALING: %s %.2f\n", id, scaleFactor);
                System.out.print(canvas);
            }

        }
    }
}


