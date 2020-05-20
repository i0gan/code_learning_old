/*
*           同一个类     同一个包     子类      所有类
* private:     *
* default:     *          *
* protected:   *          *         *
* public:      *          *         *         *
*
* 外部类采用set get来操作private成员
*
* */

public class TestEncapsulation {
    public static void main(String[] args) {
        Boy b = new Boy();
        b.sayHello();
        b.setAge(2);
        System.out.println(b.getAge());
    }
}

class Boy extends Human {
    void sayHello () {
        System.out.println(name);
        System.out.println(rev);
    }
}