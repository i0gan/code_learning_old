import javax.swing.JFrame; //窗口类
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
/*
* 飞机游戏的主窗口
*
* */
class MyFrame extends JFrame{
    public void lauchFrame() {
        this.setTitle("飞机大战"); //设置标题
        this.setVisible(true);   //设置是否可以看见
        this.setSize(100, 1000);
        this.setLocation(500, 500);

        //实现关闭退出
        this.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }
}
public class Game_1 {
    public static void main (String[] args) {
        MyFrame myframe = new MyFrame();
        myframe.lauchFrame();
    }
}
