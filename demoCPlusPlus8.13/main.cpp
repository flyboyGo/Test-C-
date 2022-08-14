#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>
#include <string.h>

//宏常量
#define Day 7

int main()
{
	cout << "hello world" << endl;

/*
* 变量
* 作用:给一段指定的内存空间起名,方便操作这段内存
* 意义:方便我们管理内存空间
* 语法:数据类型  变量名 = 初始值;
*
*/
	int a = 10;
	cout << "a = " << a << endl;

/*
* 常量
* 作用:用于记录程序中不可更改的数据
* C++定义常量两种方式
* 1、#define 宏常量: #define 常量名 常量值
*    通常在文件上方定义，表示一个常量
* 2、const修饰的变量 const 数据类型 常量名 = 常量值
*    通常在变量定义前加关键字const, 修饰该变量为常量，不可修改
*/

	cout << "一周的天数: " << Day << endl;
	//Day = 7; //错误,表达式的左值必须是可修改的值;因为Day是常量,一旦修改就会报错

	const int Month = 12;
	//Month = 13; //错误,表达式的左值必须是可修改的值;因为const修饰的Month变量也称为常量,一旦修改就会报错

	cout << "一年总共有: " << Month << " 个月份" << endl;

/* 
* 关键字(标识符)
* 作用:关键字是C++中预先保留的单词
*       在定义变量或者常量时候,不要使用关键字,否则会引起歧义
*/


/*
* 标识符命名规则
* 作用:C++规定给标识符(常量、变量)命名时,有一条自己的规则
* 1、标识符不能是关键字
* 2、标识符只能是字母、数字、下划线组成
* 3、第一个字符必须是字母或下划线
* 4、标识符中字母区分大小写
*   建议:给标识符命名时,争取做到见名知意
*/

/* 
* 数据类型
* 意义:给变量分配合适的内存空间
* C++中表能够示整型的有多种方式short(2个字节)、int(4个字节)、long(Windows中四个字节、Linux中4或8字节)、longlong(8个字节)
* 区别在于所占内存空间大小不同,会直接导致取值范围不同!
*/


/*
* sizeof关键字
* 作用:利用sizeof关键字统计数据类型所在内存空间大小
* 语法: sizeof(数据类型/变量)
*/
	int aSize = 10;
	cout << "所在空间大小为: " << sizeof(int) << endl;
	cout << "所在空间大小为: " << sizeof(aSize) << endl;

	short bSize = 10;
	cout << "所在空间大小为: " << sizeof(short) << endl;
	cout << "所在空间大小为: " << sizeof(bSize) << endl;

/*
* 实型(浮点型)
* 作用:用于表示小数
* 浮点型变量分为两种
* 1、单精度float (4个字节,7位有效数字(整数部分也算有效数字))
* 2、双精度double (8个字节,15~16位有效数字)
* 二者的区别在于表示的有效数字范围不同
*/

	//系统中浮点数默认为double
	//默认情况下,输出一个小数,只会显示6位有效数字(整数部分也算有效数字)

	float c = 3.1415926f; //如果初始化变量时,数值后面不加f,默认为double，赋值给float类型变量c时,需要类型转换,
	                 //可能会导致精度损失
	double d = 3.1415926;
	cout << "单精度a为: " << c << endl;
	cout << "单精度b为: " << d << endl;


/*
* 科学计数法
*/
	float e1 = 3e2; // 3 * 10^2;
	cout << "e1 = " << e1 << endl; // 300

	float e2 = 3e-2; // 3 * 0.1^2 == 3 * 10 ^-2
	cout << "e2 = " << e2 << endl; // 0.03



/*
* 重点注意!!!!!!!!
* C语言中浮点型一般分为float单精度型、double双精度型、long double长精度型，
* 单精度浮点型小数点后面有效数字为6~7位和双精度浮点型小数点后面有效数字为15~16位
* 默认情况下,输出一个小数,只会显示6位有效数字(整数部分不包括)
*/
	printf("%lf\n", e1); // 300.000000
	printf("%f\n", e1);  // 300.000000

/*
* 其实这个问题就是错的，printf中根本没有%lf格式输出这一说
* printf 的 "%f" 说明符既可以输出 float 类型,又可以输出 double 类型
*(根据"默认提升"规则,在 printf 函数的可变参数列表中，float 类型会被提升为 double 类型,printf只会看到双精度)
* scanf 对于 float 类型必需使用 "%f" ，double 类型必须使用 "%lf"
* printf 中没有定义 "%lf" ，很多系统可能会接受它。为确保可移植性，坚持使用 "%f" 
*/



/*
* 字符型
* 作用:字符型变量用于单个字符
*  1、在显示字符型变量时，用单引号将字符括起来，不要用双引号
*  2、单引号内只能有一个字符，不可以是字符串(如果有多个字符,只会保留最后一个字符)
*  3、C和C++中字符型变量只占用1个字节。
   4、字符型变量并不是把字符本身放到内存中存储，而是将对应的ASCII编码放入到存储单元
*/

	char ch = 'a';
	cout << "ch = " << ch << endl;
	cout << "ch = " << (int)ch << endl; // 97
	cout << "字符类型所在内存空间: " << sizeof(char) << endl; // 1


/*
* 转义字符
* 作用: 用于表示一些不能显示出来的ASCLL字符
* 现阶段我们常用的转义字符有: 
*    \n  换行(LF) ，将当前位置移到下一行开头 
*    \r  回车(CR) ，将当前位置移到本行开头 
*    \\t 水平制表(HT) （跳到下一个TAB位置） 作用:整齐的输出数据
*    \\  代表一个反斜线字符"\" 
*    \0  数字0
*    
*/

	cout << "hello\nworld" << endl;
	//cout << "\" << endl; //报错
	cout << "/" << endl;   // /
	cout << "\\" << endl;  // \

	cout << "aaa\taa" << endl;
	cout << "aaaa\taa" << endl;// \t前的字符如果小于8, \t前的字符 + \t后的空格一共为8个字符
	cout << "aaaa\t\taa" << endl;
	cout << "aaaaaaaa\taa" << endl; // \t前的字符如果大于等于8,会在后面直接空出8个字符


/*
* 字符串类型
* 作用:用于表示一串字符
* 1、C风格字符串:  char 变量名[] = "字符串值";
* 2、C++风格字符串: string 变量名 = "字符串值";
*/

	//1、C风格字符串
	char str[] = "hello world";
	cout << str << endl;

	const char* sstr = "hello";
	printf("%s\n", "hello");
	printf("%s\n", sstr);
	cout << sstr << endl;

	//2、C++风格字符串
	//包含一格头文件 #include <string>
	string str2 = "hello world again";
	cout << str2 << endl;


/*
* 布尔类型 bool
* 作用: 布尔树类型代表真或假的值
* bool类型只有两个值
*   true -- 真 (本质是1)
*   false -- 假 (本质是0)
* 
* bool类型占1个字节大小
* 
* C++中非0都表示为真, 0表示为假(C语言一样)
*/

	bool flag = 1; // bool flag = 1;
	cout << "flag = " << flag << endl; // 1

	bool flag3 = 5; 
	cout << "flag3 = " << flag3 << endl; // 1

	bool flag4 = -2;
	cout << "flag4 = " << flag4 << endl; // 1

	bool flag2 = false; // bool flag = 0;
	cout << "flag2 = " << flag2 << endl; // 0

	cout << "flag所在空间大小 = " << sizeof(bool) << endl;


/*
* 数据输入
* 作用: 用于从键盘获取数据
* 关键字:cin
* 语法 cin >> 变量
*/

	//1、整型
	//int data = 0;
	//cout << "请给整型变量 data 赋值" << endl;
	//cin >> data;
	//cout << "整型变量data = " << data << endl;

	//2、浮点型
	//float data2 = 0.0f;
	//cout << "请给浮点型变量 data2 赋值" << endl;
	//cin >> data2;
	//cout << "浮点变量data2 = " << data2 << endl;

	//3、字符型
	//char data3 = '0';
	//cout << "请给字符型变量 data3 赋值" << endl;
	//cin >> data3;
	//cout << "字符变量data3 = " << data3 << endl;

	//4、字符串型
	//string data4 = "";
	//cout << "请给字符串型变量 data4 赋值" << endl;
	//cin >> data4;
	//cout << "字符串变量data4 = " << data4 << endl;

	//5、布尔型 (bool类型非0的值都表示为真true(1))
	bool data5 = false;
	cout << "请给布尔型变量 data5 赋值" << endl;
	cin >> data5;
	cout << "布尔变量data5 = " << data5 << endl;

	return 0;
}
