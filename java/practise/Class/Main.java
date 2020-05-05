public class Main{
	String hel;
	Hello name;
	Main(){
		hel="Hello World!";
	}
	public static void main(String[] args){
		Main me= new Main(); //创建对象, Main()表示构造函数
		Hello Logan= new Hello();
		Logan.name="Logan!";
		me.name=Logan;
		System.out.println(me.hel+me.name.name);
	}
}
class Hello{
	String name;
}
