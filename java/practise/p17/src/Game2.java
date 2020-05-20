import javax.swing.JFrame;
import java.awt.event.WindowEvent;
import java.awt.event.WindowAdapter;

class MyFrame extends JFrame {
    public void lauchFrame (){
        this.setTitle("飞机大战");
        this.setVisible(true);
        this.setSize(500, 500);
        //定义内部类来实现关闭事件
        this.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }
}
public class Game2 {
    public static void main(String[] args) {
        MyFrame myFrame = new MyFrame();
        myFrame.lauchFrame();
    }
}
