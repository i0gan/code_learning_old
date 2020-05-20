public class Casting {
    public static void main(String[] args) {
        Animal d = new Dog(); //自动向上转型
        d.shout();
        Dog d2 = (Dog)d; //强制转回来
        d2.run();
        Cat cat = (Cat)d;
        //cat.eat(); //不能调用
    }
}

class Animal {
    public void shout() {
        System.out.println("叫了");
    }
}
class Dog  extends  Animal {
    int age;
    public void shout() {
        System.out.println("狗叫了");
    }
    public void run() {
        System.out.println("狗跑了");
    }
}
class Cat extends  Animal {
    public void eat() {
        System.out.println("猫吃东西");
    }
}

final class TestFinal {   //final 修饰类:  该类不能被继承
    final int a = 0;      //final 修饰变量: 变量只能被赋值一次
    final void study() {  //final 修饰函数: 该函数不能被子类重写
    }
}