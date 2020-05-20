package xyz.lyxf;
import java.lang.Object;
/*
* toString()
*
* */
class Obj {

}
class Obj2 {
    public String toString() { //重写toString
        return "My String";
    }
}
public class MyObject {
    public static void main(String[] args) {
        MyObject obj = new MyObject();
        //public String toString() {
        //        return getClass().getName() + "@" + Integer.toHexString(hashCode());
        //}
        System.out.println(obj.toString()); //toString是Object中的一个函数
        System.out.println(new Obj());
        System.out.println(new Obj2()); //重写后的toString
    }
}
