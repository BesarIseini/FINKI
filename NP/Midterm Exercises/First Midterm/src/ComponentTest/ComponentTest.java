//package ComponentTest;
//
//import java.util.ArrayList;
//import java.util.Collections;
//import java.util.Comparator;
//import java.util.Scanner;
//
//class Component {
//    private String color;
//    private int weight;
//    private ArrayList<Component> components = new ArrayList<>();
//
//
//    public Component(String color, int weight) {
//        this.color = color;
//        this.weight = weight;
//    }
//
//    public int getWeight() {
//        return weight;
//    }
//
//    public String getColor() {
//        return color;
//    }
//
//    void addComponent(Component component) {
//        components.add(component);
//        components.sort(Comparator.comparingInt(Component::getWeight).thenComparing(Component::getColor));
//    }
//}
//
//class Window {
//    String name;
//    ArrayList<Component> components = new ArrayList<>();
//
//
//}
//
//
//
//public class ComponentTest {
//    public static void main(String[] args) {
//        Scanner scanner = new Scanner(System.in);
//        String name = scanner.nextLine();
//        Window window = new Window(name);
//        Component prev = null;
//        while (true) {
//            try {
//                int what = scanner.nextInt();
//                scanner.nextLine();
//                if (what == 0) {
//                    int position = scanner.nextInt();
//                    window.addComponent(position, prev);
//                } else if (what == 1) {
//                    String color = scanner.nextLine();
//                    int weight = scanner.nextInt();
//                    Component component = new Component(color, weight);
//                    prev = component;
//                } else if (what == 2) {
//                    String color = scanner.nextLine();
//                    int weight = scanner.nextInt();
//                    Component component = new Component(color, weight);
//                    prev.addComponent(component);
//                    prev = component;
//                } else if (what == 3) {
//                    String color = scanner.nextLine();
//                    int weight = scanner.nextInt();
//                    Component component = new Component(color, weight);
//                    prev.addComponent(component);
//                } else if(what == 4) {
//                    break;
//                }
//
//            } catch (InvalidPositionException e) {
//                System.out.println(e.getMessage());
//            }
//            scanner.nextLine();
//        }
//
//        System.out.println("=== ORIGINAL WINDOW ===");
//        System.out.println(window);
//        int weight = scanner.nextInt();
//        scanner.nextLine();
//        String color = scanner.nextLine();
//        window.changeColor(weight, color);
//        System.out.println(String.format("=== CHANGED COLOR (%d, %s) ===", weight, color));
//        System.out.println(window);
//        int pos1 = scanner.nextInt();
//        int pos2 = scanner.nextInt();
//        System.out.println(String.format("=== SWITCHED COMPONENTS %d <-> %d ===", pos1, pos2));
//        window.swichComponents(pos1, pos2);
//        System.out.println(window);
//    }
//}
//
//// вашиот код овде