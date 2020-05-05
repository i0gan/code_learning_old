#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;
void t_01()//输入输出
{
	double a=0.12542;
	double b=12.34e2;
	std::cout << "original a=" << a << endl;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	std::cout << "a=" << a << endl;
	std::cout << "b=" << b << endl;
	std::cout << "Plz input a number b:";
	std::cin >>b;
	std::cout << "Number b is:" << b ;
	int c=1234;
	std::cout << "Hello World!\n"<< c << endl;
}
void t_02() //布尔
{
	char Hello[100] = "Hello World";
	bool a = true;
	bool b = false;
	std::cin >> Hello;
	std::cout << Hello << endl;
	std::cout << "a=" << a;
	std::cout << "b=" << b;
}
void t_03() //枚举和string
{
	enum Week { //枚举常量列表
	One = 1, Two = 2, Three = 3
	};
	string hell;
	hell = "Hello";
	std::cout << hell  << endl;
	std::cout << Two << endl;
}
void t_04()//常用数学函数
{
	double x = 1.44;
	std::cout << sqrt(x) << endl;
	std::cout << pow(x,0.5);
	//sqrt --平方根   double sqrt(double)       <cmath>
	//pow  --乘方     double pow(double,double) <cmath>
	//abs  --取int 的绝对值   int abs(int)      <cstdlib>
	//labs  --取long 的绝对值 long labs(long)   <cstdlib>
	//ceil --向上取整 double ceil(double)       <cmath>
	//floor --向下取整 double floor(double)     <cmath>
}
void t_05() //强制转换
{
	int a = 9, b = 2;
	double c = 0;
	c = a/b;
	std::cout << "1:  9/2= " << c << endl;
	c = static_cast<double>(a)/b;  //将a强制转换为double类型
	std::cout << "2:  9/2= " << c << endl;
	
	c = static_cast<int>(c);  //将a强制转换为double类型
	std::cout << "3:  c(int)= " << c << endl;

	c = double(2)/3;  //将a强制转换为double类型
	std::cout << "4:  3/2= " << c << endl;

	c = int(c);  //将a强制转换为double类型
	std::cout << "5:  c(int)= " << c << endl;
}
void t_06_0(double &a,double *b,double c)//引用
{
	a=1.0;
	*b=2.0;
	c=3.0;
	cout << "&a=" << a <<endl;
}	
void t_06()
{
	double a = 0, b = 0, c = 0;
	cout << "Unchanged:" << " (&int) a:" << a << "(*int) b:" << b << "(int) c:" << c << endl;
	t_06_0(a,&b,c);	
	cout << "Changed:" << ",(&int) a: " << a << ",(*int) b: " << b << ",(int) c: " << c << endl;
}
void t_07() //文件IO
{
	using namespace std;

	int a=0,b=0;
	std::ifstream in_stream;	//在<fstream>头文件里
	std::ofstream out_stream;
	std::string stream_in_file { "in_stream_file" };
	std::string stream_out_file { "out_stream_file" };

	in_stream.open(stream_in_file); //通过in_stream_file 获取输入
	out_stream.open(stream_out_file);//把输出内容放置到out_stream_file

	in_stream >> a >> b;
	out_stream << "Hello World!\n"
		   << "I am Logan!\n"
		   << "I wanna you to die!\n"
		   << "a:"
		   << a
		   << "\nb:"
		   << b
		   << endl;
	in_stream.close();
	out_stream.close();	
}
void t_08() // IO 2
{
	ifstream in_stream;
	ofstream out_stream;
	string stream_in_file { "in_stream_file" };
	string stream_out_file { "out_stream_file" };

	in_stream.open(stream_in_file);
	out_stream.open(stream_out_file);

	if(in_stream.fail()) // fail()   成功返回0 失败返回 1
	{
		cout << "Input stream file opening failed\n";
		exit(1); // 头文件<cstdlib>
	}else if(out_stream.fail())
	{
		cout << "Output stream file opening failed\n";
		exit(1);
	}
	
	string Text = "Hello Logan \n";
	string Text_02;
	//in_stream >> Text_02;
	//out_stream << Text << Text_02 << endl;
	
	cin >> Text;
	out_stream << Text;

	in_stream.close();
	out_stream.close();

}
void t_09() //把内容追加到文件末尾
{
	using namespace std;
	
	ofstream fout;
	fout.open("out_stream_file", ios::app); //ios 是一个特殊的常量,在iostream中有定义,加入参数即可在文件末尾追加内容
	if(fout.fail())
	{
		cout << "Input stream file opening failed!\n";
		exit(1);
	}
	fout << "Append Text: Hello !"
	     << "\n I am Logan !"
	     << endl;
	fout.close();

}
void t_10() //流I/O工具 (流函数格式化输出)
{
	//魔法配方
	//cout.with(4)//指定输出占字符宽度为4
	//cout.setf(ios::fixed);   //setf    --- set flag (设置标志)
	//cout.setf(ios::showpoint);
	//cout.precision(2);    2代表输出的浮点类型小数后2位
	
	//setf 格式化标志:
	/* ios::fixed	    不用e计数法来表示浮点数
	 * ios::scientifc   采用e来表示浮点数
	 * ios::showpoint   显示小数点
	 * ios::showpos     正数前添加'+'
	 * ios::right       通过调用函数width来指定某个域宽值.在某个域内右对齐
	 * ios::left        通过调用函数width来指定某个域宽值.在某个域内左对齐
	 * */
	
	
}
void t_11() //操纵元 setw && setprecision && endl
{
	//setw && setprecision  <iomanip>
	//setw 与 成员函数 width 所做的事一样
	cout << "setw\n";
	cout << "Start"	
	     << setw(2)
	     << 1
	     << setw(4)
	     << 2
	     << setw(8)
	     << 3
	     << endl;
	//流操纵元setprecistion与precision所做的事一样.但是对setprecistion的调用要放在插入操作符号<<之后.这和调用setw类似
	cout << "precisiton:\n";	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.setf(ios::showpos);
	cout << "\n$" << setprecision(3) << 10.2 <<endl
	     << "$" << 1.2 << endl;
}
//流作为函数实参
void t_12_1(ifstream &in_stream,ofstream &out_stream)
{
	string Text;
	in_stream >> Text;
	out_stream << Text;	
}
void t_12()
{
	ifstream fin;
	ofstream fout;
	fin.open("in_stream_file");
	fout.open("out_stream_file");
	if(fin.fail())
	{
		cout << "Input stream file opening failed!\n";
		exit(1);
	}else if(fout.fail())
	{
		cout << "Output stream file opening failed!\n";
		exit(1);
	}
	t_12_1(fin,fout);

	fin.close();
	fout.close();
	cout << "Program ended!\n";
}
int main(void)
{

	//t_01();
	//t_02();
	//t_03();
	//t_04();
	//t_05();
	//t_06();
	//t_07();
	//t_08();
	//t_09();
	//t_10();
	//t_11();
	//t_12();
	return 0;
}
