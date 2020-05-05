package xyz.lyxf;
class Person {
    //注意变量默认为public

    private int nouse;
    protected String name; //保护形式
    public int age;
    public void rest() {
        System.out.println("I wanna a rest!");
    }
}
class Student extends Person { //继承Person
    String major;
    public void study() {
        System.out.println("I wanna study ten hours!");
    }
}

public class MyClass {
    public static void main(String[] args) {
        Student std = new Student();
        std.age = 16;
        std.name = "I0gan";
        std.major = "English";
        // std.nouse = 1; //不能使用
        std.study();
        std.rest();

        //instanceof 关键字: 判断某个对象是不是属于某个Class
        System.out.println( std instanceof  Student);
        System.out.println( std instanceof  Person);
        System.out.println( new Person() instanceof  Student);
    }
}
