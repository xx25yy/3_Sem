public class ResizeDemo {
    public static void main(String[] args) {
        Rectangle rectangle = new Rectangle(10, 5);

        System.out.println("Original Rectangle Info:");
        rectangle.displayInfo();

        rectangle.resizeWidth(15);
        rectangle.resizeHeight(8);

        System.out.println("\nUpdated Rectangle Info:");
        rectangle.displayInfo();
    }
}
