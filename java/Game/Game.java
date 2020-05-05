import java.awt.*;
import javax.swing.*;
public class Game extends JFrame{
	Image ball= Toolkit.getDefaultToolkit().getImage("ball.png");
	Image desk= Toolkit.getDefaultToolkit().getImage("desk.jpg");
	double x=100; //position x
	double y=100; //position y
	double degree=3.14/3; //弧度60度

	boolean right=true; //方向
	//画窗口函数
	public void paint(Graphics g){
	//	System.out.println("Hello");
		g.drawImage(desk,0,0,null);
		g.drawImage(ball,(int)x,(int)y,null);
		x=x+10*Math.cos(degree);
		y=y+10*Math.sin(degree);
		if(y>500-40-30||y<40+40){ //500是窗口高度
			degree=(0-degree);
		}else if(x<40||x>856-40-30)
		{
			degree=3.14-degree;
		}
/*		if(right){
			x+=10;
		}else{
			x-=10;
		}
		if(x>856-40-30){
			right=false;
		}else if(x<40){
			right=true;
		}*/
	}
	//Load 窗口
	void launchFrame(){
		setSize(856,500);
		setLocation(50,50);
		setVisible(true);
		//重画窗口
		while(true){
		repaint();
			try{
				Thread.sleep(40); //40ms
			}catch(Exception e){
				e.printStackTrace();
			}
		}
	}
	public static void main(String[] args){
		Game game = new Game();
		game.launchFrame();
	}
}
