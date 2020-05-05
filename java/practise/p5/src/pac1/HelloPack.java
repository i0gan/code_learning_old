package pac1;

public class HelloPack {
    int id;
    String name;
    public HelloPack(int id, String name) {
        this.id = id;
        this.name = name;
    }
    public void print() {
        System.out.printf("id: %d name: %s \n", id, name);
    }
}
