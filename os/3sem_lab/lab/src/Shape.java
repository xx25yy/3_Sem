

class Shape {
    protected String name;

    public Shape(String name) {
        this.name = name;
    }

    public void draw() {
        System.out.println("Drawing a " + name);
    }

    public void erase() {
        System.out.println("Erasing a " + name);
    }
}
