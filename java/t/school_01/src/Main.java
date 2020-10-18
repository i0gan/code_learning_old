import java.util.Scanner;
import java.lang.*;

public class Main
{
    public static class Triangle{
        double x1,y1,x2,y2,x3,y3;
        double a_length,b_length,c_length,average;
        double a_angle, b_angle, c_angle;
        public void cal_len(){
            a_length = Math.sqrt(Math.pow((x2 - x3),2) + Math.pow((y2-y3),2));
            b_length = Math.sqrt(Math.pow((x1 - x3),2) + Math.pow((y1-y3),2));
            c_length = Math.sqrt(Math.pow((x1 - x2),2) + Math.pow((y1-y2),2));
        }
        public void cal_angel(){
            a_angle=Math.toDegrees(Math.acos((Math.pow(a_length, 2) - Math.pow(b_length, 2)- Math.pow(c_length, 2))/(-2 * b_length * c_length)));
            b_angle=Math.toDegrees(Math.acos((Math.pow(b_length, 2) - Math.pow(a_length, 2)- Math.pow(c_length, 2))/(-2 * a_length * c_length)));
            c_angle=Math.toDegrees(Math.acos((Math.pow(c_length, 2) - Math.pow(b_length, 2)- Math.pow(a_length, 2))/(-2 * b_length * a_length)));
        }
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        Triangle first = new Triangle();
        System.out.println("输入三角形顶点A的坐标: ");
        first.x1 = sc.nextDouble();
        first.y1 = sc.nextDouble();
        System.out.println("输入三角形顶点B的坐标: ");
        first.x2 = sc.nextDouble();
        first.y2 = sc.nextDouble();1
        System.out.println("输入三角形顶点C的坐标: ");
        first.x3 = sc.nextDouble();
        first.y3 = sc.nextDouble();
        first.cal_len();
        first.cal_angel();
        System.out.printf("角A的角度为%.2f\n" , first.a_angle);
        System.out.printf("角B的角度为%.2f\n" , first.b_angle);
        System.out.printf("角C的角度为%.2f\n" , first.c_angle);
    }
}

