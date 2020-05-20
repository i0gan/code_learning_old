package xyz.lyxf;
/**
 * 方法重写
 * "==": 方法名, 形参列表相同
 * "<=" 返回值类型和声明异常类型,子类小于等于父类
 * ">=" 访问权限,子类大于等于父类
 */

class Person {
    String name;
}
class Student extends Person {
    String marjor;
}

class Vehicle {
    public void run() {
        System.out.println("run");
    }
    public void stop() {
        System.out.println("stop");
    }
    public Person WhoDrivevehicle() {
        return new Person();
    }
}

class Horse extends Vehicle {
    public void run()  { //重写父类run函数.
        System.out.println("四蹄翻飞");
    }

    //重写的返回参数大于基类, Student > person
    public Student WhoDrivevehicle() {
        return new Student();
    }

}

public class MyClass {
    public static void main(String[] args) {
        Horse h = new Horse();
        h.run();
        h.stop();
        Student s = h.WhoDrivevehicle();
        s.marjor = "开马车..";

    }
}
