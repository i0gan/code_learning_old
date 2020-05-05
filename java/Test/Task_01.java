class HelloWorld		//定义数据类型
{
	public static void main(String[] args)
	{
		byte a=1;
		short b=2;
		int c=3;
		long d=4l;
		float e=5.0f;
		double f=6.0d;		//byte and short will be int in computing by defualt
		char h='a';
		boolean i=false;	//变量作用范围只在当前打括号有效还有括号
		System.out.println("byte:"+a);
		System.out.println("short:"+b);
		System.out.println("int:"+c);
		System.out.println("long:"+d);
		System.out.println("float:"+e);
		System.out.println("double:"+f);
		System.out.println("char:"+h);
		System.out.println("boolean:"+i);
	}
}
