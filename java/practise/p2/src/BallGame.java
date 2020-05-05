import java.awt.*;
import javax.swing.*;

public class BallGame extends JFrame {
    //加载图片
    Image ball = Toolkit.getDefaultToolkit().getImage("res/ball.png");
    Image desk = Toolkit.getDefaultToolkit().getImage("res/desk.jpg");

    double x = 100; //小球的横坐标
    double y = 100; //小球的纵坐标
    double speed = 10.0; //小球的速度
    boolean right = true; //小球的方向
    double degree = 3.14 / 3; //弧度, 此处是 60 度.


    //画窗口
    public void paint(Graphics g) {
        //System.out.println("*");
        g.drawImage(desk, 0, 0, null);     //画桌子
        g.drawImage(ball, (int)x, (int)y, null); //画球


        x = x + speed * Math.cos(degree); //通过角度方式计算 x 坐标
        y = y + speed * Math.sin(degree); //通过角度方式计算 y 坐标
        if(y > 500 - 40 - 30 || y < 40 + 40) { // 500 是窗口高度, 40是边框宽度, 30小球直径
            //而 y < 40 + 40中, 有个40是窗口边框宽度(注意,也需要算入),有个是图片桌球边框宽度.
            degree = -degree;
        }
        if(x < 40 || x > 856 - 40) {
            degree = degree + (3.14 / 2);
            //degree = 3.14 - degree
        }
//
//        if(right) {
//            x += speed;
//        }else {
//            x -= speed;
//        }
//
//        if(x > 856 - 40 - 30) { // 40 是桌子边框的宽度, 30是小球的直径.
//            right = false;
//        }else if(x < 40) {
//            right = true;
//        }
    }
    //弹出窗口
    void launchFrame() {
        setSize(856, 500);
        setLocation(50, 50);
        setVisible(true);

        //重画窗口
        while(true) {
            repaint();
            try {
                Thread.sleep(40); // 40 ms画一次,采用这个必须要搭配 try catch来使用.
            }catch(Exception e) {
                e.printStackTrace();  //捕获异常后打印错误
            }
        }
    }

    //main 方法是程序执行的入口
    public static void main(String[] args) {
        System.out.println("Starting game...");
        BallGame game = new BallGame();
        game.launchFrame();
    }
}
