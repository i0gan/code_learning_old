// 类的基本用法 1
public class MyClass {
    int id;
    String name;
    int age;
    MyClass() {
        id = 0;
        name = "none";
        age = 0;
    }
    MyClass(int id, String name, int age) {
        this.id = id;
        this.name = name;
        this.age = age;
    }

    static { //在初始化类的时候,就先执行静态块,然后才能执行构造函数.
        System.out.println("Class init...");
    }

    public static void main(String[] args) {
        MyClass stu = new MyClass();
        stu.id = 0;
        stu.age = 17;
        stu.name = "老李";

        MyClass stu2 = new MyClass(1, "小二", 18);

        System.out.printf("id: %d name: %s age: %d\n", stu.id, stu.name, stu.age);
        System.out.printf("id: %d name: %s age: %d\n", stu2.id, stu2.name, stu2.age);

    }
}
