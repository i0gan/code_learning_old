package lyxf.xyz;
class Father {
    public int value;
    public Father() {
        System.out.println("create father class");
    }
    public void fun() {
        value = 100;
        System.out.println("Father class: " + value);
    }
    {
        System.out.println("Fahter static code");
    }
}
class Child extends Father{
    public int value;
    public Child() {
        super(); //默认调用父类构造器, 没写编译器自动加入
        System.out.println("create child class");
    }
    public void fun() {
        super.fun(); //调用父类函数
        value = 200; //没有对父类进行覆盖
        System.out.println("Child class: " + value + "Father value: " + super.value);
    }
    {
        System.out.println("Child static code");
    }
}
public class Super {
    public static void main(String[] args) {
        Child c = new Child();
        c.fun();
    }
}
