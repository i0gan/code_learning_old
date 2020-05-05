import java.util.Scanner;

/*
这是一个计算阶层的一个比较功能的class,比较递归方式与普通循环的方式计算效率
*/
public class P3 {
    public static void main(String[] args) {
        System.out.print("Plz input a num:");
        Scanner s = new Scanner(System.in);
        int num = s.nextInt(); //获取输入为Int类型
        //以递归方式进行运算
        long t1 = System.currentTimeMillis();
        System.out.println("Result: " + factorialLoop1(num));
        long t2 = System.currentTimeMillis();
        System.out.printf("递归耗时: %s %n", t2 - t1);

        //以循环方式进行运算
        t1 = System.currentTimeMillis();
        System.out.println("Result: " + factorialLoop2(num));
        t2 = System.currentTimeMillis();
        System.out.printf("普通耗时: %s %n", t2 - t1);
    }

    //采用递归方式进行运算
    static int factorialLoop1(int num) { //采用递归方式实现阶层运算
        if(num == 1) {
            return 1;
        }
        return num * factorialLoop1(num - 1);
    }

    //采用循环方式进行运算
    static int factorialLoop2(int num) {
        long result = 1;
        while(num > 1) {
            result *= num * (num - 1);
            num -= 2;
        }
        return num;
    }
}

