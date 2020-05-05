
C语言里可以用printf(),%f来实现浮点数的格式化输出，用cout呢
下面的方法是在网上找到的，如果各位有别的办法谢谢留下...

iomanip.h是I/O流控制头文件,就像C里面的格式化输出一样.以下是一些常的:

dec 置基数为10 相当于"%d"
hex 置基数为16 相当于"%X"
oct 置基数为8 相当于"%o"
setfill(c) 设填充字符为c
setprecision(n)   设显示小数精度为n位
setw(n) 设域宽为n个字符
setioflags(ios::fixed)   固定的浮点显示
setioflags(ios::scientific) 指数表示
setiosflags(ios::left) 左对齐
setiosflags(ios::right) 右对齐
setiosflags(ios::skipws 忽略前导空白
setiosflags(ios::uppercase) 16进制数大写输出
setiosflags(ios::lowercase) 16进制小写输出
setiosflags(ios::showpoint) 强制显示小数点
setiosflags(ios::showpos)   强制显示符号

#include <iomanip>
use namespace std;

double d=11.23456;
cout<<d<<endl;                                                  //直接输出只能输出6位数，包括整数部分和小数部分
cout<<setprecision(3)<<d<<endl;               //精度为3，输出3位数
cout<<setiosflags(ios::fixed)<<d<<endl;//精度为3，定点输出，输出3位小数
cout<<setiosflags(ios::fixed)<<setprecision(7)<<d<<endl;//位数不够，末尾添0

输出结果：
11.2346
11.2
11.23456
11.2345600

 

C++格式化输出浮点数

view plaincopy to clipboardprint?
01.#include <iostream>  
02.using std::cout;  
03.using std::endl;  
04.using std::fixed;  
05.using std::scientific;  
06. 
07.int main()  
08.{  
09.   double x = 0.001234567;  
10.   double y = 1.946e9;  
11. 
12.   cout << "Displayed in default format:" << endl << x << '\t' << y << endl;  
13. 
14.   cout << "\nDisplayed in scientific format:" << endl << scientific << x << '\t' << y << endl;  
15. 
16.   cout << "\nDisplayed in fixed format:" << endl << fixed << x << '\t' << y << endl;  
17.   return 0;  
18.} 
#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
using std::scientific;

int main()
{
   double x = 0.001234567;
   double y = 1.946e9;

   cout << "Displayed in default format:" << endl << x << '\t' << y << endl;

   cout << "\nDisplayed in scientific format:" << endl << scientific << x << '\t' << y << endl;

   cout << "\nDisplayed in fixed format:" << endl << fixed << x << '\t' << y << endl;
   return 0;
}

Displayed in default format:
0.00123457      1.946e+009

Displayed in scientific format:
1.234567e-003   1.946000e+009

Displayed in fixed format:
0.001235        1946000000.000000

view plaincopy to clipboardprint?
01.#include <iostream.h>  
02. 
03.main(void)  
04.{  
05.  float a=100100.0, b=0.08;  
06.  cout.setf(ios::right|ios::scientific|ios::showpoint);  
07.  cout.width(20);     
08.  cout <<(-a*b);  
09.    
10.  return 0;  
11.} 
#include <iostream.h>

main(void)
{
  float a=100100.0, b=0.08;
  cout.setf(ios::right|ios::scientific|ios::showpoint);
  cout.width(20);  
  cout <<(-a*b);
  return 0;
}

-8.008000e+003

view plaincopy to clipboardprint?
01.#include <iostream>  
02.#include <iomanip>  
03.#include <limits>  
04.using std::cout;  
05.using std::endl;  
06.using std::setprecision;  
07.using std::numeric_limits;  
08. 
09.int main() {  
10.  const double pi = 3.14;  
11.  cout << endl;  
12. 
13.  for(double radius = .2 ; radius <= 3.0 ; radius += .2)  
14.    cout << "radius = " 
15.    << setprecision(numeric_limits<double>::digits10 + 1)  
16.    << std::scientific << radius<< "  area = " 
17.         << std::setw(10) << setprecision(6)<< std::fixed << pi * radius * radi  
18.us << endl;  
19.  return 0;  
20.} 
#include <iostream>
#include <iomanip>
#include <limits>
using std::cout;
using std::endl;
using std::setprecision;
using std::numeric_limits;

int main() {
  const double pi = 3.14;
  cout << endl;

  for(double radius = .2 ; radius <= 3.0 ; radius += .2)
    cout << "radius = "
    << setprecision(numeric_limits<double>::digits10 + 1)
    << std::scientific << radius<< "  area = "
         << std::setw(10) << setprecision(6)<< std::fixed << pi * radius * radi
us << endl;
  return 0;
}

radius = 2.0000000000000001e-001  area =   0.125600
radius = 4.0000000000000002e-001  area =   0.502400
radius = 6.0000000000000009e-001  area =   1.130400
radius = 8.0000000000000004e-001  area =   2.009600
radius = 1.0000000000000000e+000  area =   3.140000
radius = 1.2000000000000000e+000  area =   4.521600
radius = 1.3999999999999999e+000  area =   6.154400
radius = 1.5999999999999999e+000  area =   8.038400
radius = 1.7999999999999998e+000  area =  10.173600
radius = 1.9999999999999998e+000  area =  12.560000
radius = 2.1999999999999997e+000  area =  15.197600
radius = 2.3999999999999999e+000  area =  18.086400
radius = 2.6000000000000001e+000  area =  21.226400
radius = 2.8000000000000003e+000  area =  24.617600

view plaincopy to clipboardprint?
01.#include <iostream>
02.#include <iomanip>
03.#include <string>
04. 
05.using namespace std;
06. 
07.int main( ) {  
08. 
09.   ios_base::fmtflags flags = cout.flags( );  
10. 
11.   double pi = 3.14285714;  
12. 
13.   cout << "pi = " << setprecision(5) << pi << '\n';  
14. 
15.   cout.flags(flags);  
16.} 
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main( ) {

   ios_base::fmtflags flags = cout.flags( );

   double pi = 3.14285714;

   cout << "pi = " << setprecision(5) << pi << '\n';

   cout.flags(flags);
}

pi = 3.1429

view plaincopy to clipboardprint?
01.#include <iostream>  
02.#include <iomanip>  
03.#include <math.h>  
04.using namespace std;  
05.int main()  
06.{  
07.   double root2 = sqrt( 2.0 );  
08.   int places;  
09. 
10.   cout << setiosflags( ios::fixed)  
11.        << "Square root of 2 with precisions 0-9.\n" 
12.        << "Precision set by the " 
13.        << "precision member function:" << endl;  
14. 
15.   for ( places = 0; places <= 9; places++ ) {  
16.      cout.precision( places );  
17.      cout << root2 << '\n';  
18.   }  
19. 
20.   cout << "\nPrecision set by the " 
21.        << "setprecision manipulator:\n";  
22. 
23.   for ( places = 0; places <= 9; places++ )  
24.      cout << setprecision( places ) << root2 << '\n';  
25. 
26.   return 0;  
27.} 
