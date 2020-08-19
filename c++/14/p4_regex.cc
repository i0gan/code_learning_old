%:include <regex>
%:include <iostream>
%:include <string>
%:include <set>
using namespace std;

/*
	正则程序库（regex）
	stdregex是C用来表示「正则表达式」（regular expression）的库，
	于C11加入，它是class stdbasic_regex<>针对char类型的一个特化，
	还有一个针对wchar_t类型的特化为std::wregex

	正则文法（regex syntaxes）



std::regex默认使用是ECMAScript文法，这种文法比较好用，且威力强大，常用符号的意义如下：
符号 	意义
^ 	匹配行的开头
$ 	匹配行的结尾
. 	匹配任意单个字符
[…] 	匹配[]中的任意一个字符
(…) 	设定分组
\ 	转义字符
\d 	匹配数字[0-9]
\D 	\d 取反
\w 	匹配字母[a-z]，数字，下划线
\W 	\w 取反
\s 	匹配空格
\S 	\s 取反
+ 	前面的元素重复1次或多次
* 	前面的元素重复任意次
? 	前面的元素重复0次或1次
	前面的元素重复n次
{n,} 	前面的元素重复至少n次
{n,m} 	前面的元素重复至少n次，至多m次
| 	逻辑或
*/



// 检查是否为qq号
// 位数 5 ~ 11
// 非0 开头
bool judge_is_qq_1(string qq) {
	bool ret = false;
	if(qq.length() >= 5 && qq.length() <= 11) {
		if(qq[0] != '0') {
			auto pos = find_if(qq.begin(), qq.end(), [](const char & ch) {
				return ch < '0' || ch > '9';
			});
			if(pos == qq.end())
				ret = true;
		}
	}	
	return ret;
}
bool judge_is_qq_2(string qq) {

	//内容为1-9的数字, 长度为4 - 11
	regex qq_reg("[1-9]\\d{4,11}");
	return regex_match(qq, qq_reg);
}


void test_match_1() {
	string html("<html>h</html>");
	regex reg("<.*>.*</.*>");	
	bool ret = regex_match(html, reg);
	cout << ret;
}
void test_match_2() {
	string xml("<xml>value</xml>");
	bool ret = regex_match(xml, regex("<(.*)>.*</\\1>"));
	cout << ret;
}

void test_match_3() {
	string xml("<title>value</title>");
	bool ret = regex_match(xml, regex("<\\(.*\\)>.*</\\1>", regex_constants::basic));
	cout << ret;
}
void test_match_4() {
	// c++11原生字符
	regex reg(R"(<(.*)>.*</\1>)");
	auto ret = regex_match("<xml>value</xml>", reg);
	cout << ret;
}

/*
cmatch是class template std::match_result<>针对C字符的一个特化版本，若是string，便得用针对string的特化版本smatch。同时还支持其相应的宽字符版本wcmatch和wsmatch。
在regex_match()的第二个参数传入match_result便可获取匹配的结果，在例子中便将结果储存到了cmatch中，而cmatch又提供了许多函数可以对这些结果进行操作，大多方法都和string的方法类似，所以使用起来比较容易。
m[0]保存着匹配结果的所有字符，若想在匹配结果中保存有子串，则得在「正则表达式」中用()标出子串，所以这里多加了几个括号：
std::regex("<(.*)>(.*)</(\\1)>")
这样这些子串就会依次保存在m[0]的后面，即可通过m[1],m[2],...依次访问到各个子串。
*/
void show_match_1() {
	cmatch m;
	bool ret = regex_match("<xml>value</xml>", m, regex("<(.*)>(.*)</(\\1)>"));
	if(ret) {
		cout << m.str() << '\n';
		cout << m.length() << '\n';
		cout << m.position() << '\n';
	}
	cout << "----------------------\n";

	//遍历内容
	for(auto i = 0; i < m.size(); ++i) {
		cout << m[i].str() << " " << m.str(i) << '\n';
	}

	cout << "----------------------\n";
	for(auto pos = m.begin(); pos != m.end(); ++pos) {
		cout << *pos << endl;
	}
}
/*
「搜索」与「匹配」非常相像，其对应的函数为std::regex_search，也是个函数模板，用法和regex_match一样，不同之处在于「搜索」只要字符串中有目标出现就会返回，而非完全「匹配」。
*/
void test_search() {

	cmatch m;
	regex reg("<(.*)>(.*)</(\\1)>");
	auto ret = regex_search("123<xml>value</xml>456", m, reg);
	if(ret) {
		for (auto &e : m)
			cout << e << endl;
	}

	cout << "prefix: " << m.prefix() << endl;
	cout << "suffix: " << m.suffix() << endl;
}



/*
此处使用了regex_search函数的另一个重载形式（regex_match函数亦有同样的重载形式），实际上所有的子串对象都是从std::pair<>派生的，其first（即此处的prefix）即为第一个字符的位置，second（即此处的suffix）则为最末字符的下一个位置。
*/
void test_search_2() {
	regex reg("<(.*)>(.*)</(\\1)>");
	string data{"123<xml>value</xml>456<widget>center</widget>"
				"789<vertical>window</vertical>end"};
	smatch m;
	auto pos = data.cbegin();
	auto end = data.cend();
	for(; regex_search(pos, end, m, reg); pos = m.suffix().first) {
		cout << "------------------------\n";
		cout << m.str() << endl;
		cout << m.str(1) << endl;
		cout << m.str(2) << endl;
		cout << m.str(3) << endl;
	}

}

//分词（Tokenize）
void test_tokenize() {
	string mail("123@qq.com,456@gmail.com,789@163.com");
	regex reg(",");
	//此处的-1表示对于匹配的正则表达式之前的子序列感兴趣；
	//而若指定0，则表示对于匹配的正则表达式感兴趣
	sregex_token_iterator pos(mail.begin(), mail.end(), reg, -1);

	decltype(pos) end;
	for(; pos != end; ++pos)
		cout << pos->str() << endl;
}
// 替换(Replace)
void test_replace() {
	char data[] = "hel****ll**o, wo**l*d!";
	regex reg("\\*");
	cout << regex_replace(data, reg, "");
}

// 实例(Examples)
// 验证邮箱
void test_example_1() {
	string data = 
	"123@qq.vip.com, \
	 456@gmail.com, \
	 abc@me.com \
	 abc_@a.123.4.2 \
	 abc@163.com.cn.zn.vip";

	 regex reg("[a-zA-z0-9_]+@[a-zA-z0-9]+(\\.[a-zA-z]+){1,3}");
	 sregex_iterator pos(data.cbegin(), data.cend(), reg);
	 decltype(pos) end;
	 for(; pos != end; ++pos)
		cout << pos->str() << endl;
}
// 匹配ip
// 有这样一串IP地址，192.68.1.254 102.49.23.013 
// 10.10.10.10 2.2.2.2 8.109.90.30
// 要求：取出其中的IP地址，并按地址段顺序输出IP地址
void test_example_2() {
	string ip("192.168.1.254, 102.49.23.13 10.10.2.1 8.2.3.4, 54.29.33.45");
	cout << "ip: \n" << ip << endl;
	// 位数对齐
	ip = regex_replace(ip, regex("(\\d+)"), "00$1");
	cout << "对其后: \n" << ip << endl;
	// 去掉超过3位的零
	ip = regex_replace(ip, regex("0*(\\d{3})"), "$1");
	cout << "去0后: \n" << ip << endl;

	// 取出ip
	regex reg("\\s");
	sregex_token_iterator pos(ip.begin(), ip.end(), reg, -1);
	decltype(pos) end;
	set<string> ip_set;	
	for(; pos != end; ++pos)
		ip_set.insert(pos->str());

	// 输出排序后的结果
	cout << "结果:\n";
	for(auto e : ip_set) {
		//去掉多余的0
		cout << regex_replace(e, regex("0*(\\d+)"), "$1") << endl;
	}
}

int main(int, char **) {
	//show_match_1();
	//test_search();
	//test_search_2();
	//test_tokenize();
	//test_replace();
	//test_example_1();
	test_example_2();
	return 0;
}
