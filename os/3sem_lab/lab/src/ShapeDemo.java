

public class ShapeDemo {
    public static void main(String[] args) {
        Shape[] shapes = new Shape[3];
        shapes[0] = new Circle("Circle", 5.0);
        shapes[1] = new Triangle("Triangle", 4.0, 6.0);
        shapes[2] = new Square("Square", 3.0);

        for (Shape shape : shapes) {
            shape.draw();
            shape.erase();
            System.out.println();
        }
    }
}
