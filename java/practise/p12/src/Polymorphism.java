/**
 * 多态: 一个基类可以管理子类的重写函数
 */

public class Polymorphism {
    public static void main(String[] args) {
        Dog d = new Dog();
        Cat c = new Cat();
        animalShout(d);
        animalShout(c);
    }
    static void animalShout(Animal a) {
        a.shout();
    }
}

class Animal {
    public void shout() {
        System.out.println("叫了一声");
    }
}
class Dog extends Animal {
    public void shout() {
        System.out.println("狗叫了");
    }
}
class Cat extends  Animal {
    public void shout() {
        System.out.println("猫叫了");
    }
}