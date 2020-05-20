/*
* 数组三个基本特点:
* 长度是确定的
* 元素类型相同
* 数组类型任意
* 数组就是对象
* 声明方式:
* 1: type[] arr_name; (推荐)
* 2: type arr_name[];
* */
public class Arr {
    public static void main(String[] args) {
        int[] arr1;
        String[] arr2 = new  String[3];
        User[] arr3 = null;  //声明
        arr3 = new User[10]; //分配空间,并没有创建10个对象
        arr2[0] = "老李";
        arr2[1] = "老王";
        arr2[2] = "老狗";
        for(int i = 0; i < arr2.length; ++i) {
            System.out.println(arr2[i]);
        }

        //遍历方法二
        for (String i: arr2) {
            System.out.println(i);
        }

        for(int i = 0; i < arr3.length; ++i) {
            arr3[i] = new User();
            arr3[i].setAge(i);
        }
        for (User u: arr3
             ) {
            System.out.println(u.getAge());
        }
    }
}

class User {
    private int age;
    private int name;
    public User () {
        System.out.println("创建User");
    }
    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }
}