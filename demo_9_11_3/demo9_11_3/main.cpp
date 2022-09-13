#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include <exception>

using namespace std;

/*
* 
3.1.2 string类的构造、赋值、存取

3.1.2.1 string 构造函数
string();//创建一个空的字符串 例如: string str;
string(const string& str);//使用一个 string 对象初始化另一个 string 对象
string(const char* s);//使用字符串 s 初始化
string(int n, char c);//使用 n 个字符 c 初始化 
*/

//构造函数
void test01()
{
	//string(const char* s);//使用字符串 s 初始化
	string str = string("hello world");
	cout << str << endl;

	//string(int n, char c);//使用 n 个字符 c 初始化 
	string str2 = string(10, 'H');
	cout << str2 << endl;

	//string(const string & str);//使用一个 string 对象初始化另一个 string 对象
	string str3 = str2;
	cout << str3 << endl;
}

/*
* 3.1.2.2 string 基本赋值操作
string& operator=(const char* s);//char* 类型字符串 赋值给当前的字符串
string& operator=(const string &s);// 把字符串 s 赋给当前的字符串
string& operator=(char c);// 字符赋值给当前的字符串

string& assign(const char *s);// 把字符串 s 赋给当前的字符串
string& assign(const char *s, int n);// 把字符串 s 的前 n 个字符赋给当前的字符串
string& assign(const string &s);// 把字符串 s 赋给当前字符串
string& assign(int n, char c);// 用 n 个字符 c 赋给当前字符串
string& assign(const string &s, int start, int n);// 将 s 从 start 开始 n 个字符赋值给字符串
*/

//赋值操作 运算符 = 重载
void test02()
{

	string str = string("hello");
	//string& operator=(const string & s);// 把字符串(对象) s 赋给当前的字符串
	string str2;
	str2 = str;
	cout << str2 << endl;

	//string& operator=(const char* s);//char* 类型字符串 赋值给当前的字符串
	string str3;
	str3 = "hello again";
	cout << str3 << endl;

	//string& operator=(char c);// 字符赋值给当前的字符串
	string str4;
	str4 = 'a';
	cout << str4 << endl;
}

//赋值操作 成员函数
void test03()
{
	//string& assign(const char* s);// 把字符串 s 赋给当前的字符串
	string str;
	str.assign("hello");
	cout << str << endl;

	//string& assign(const char* s, int n);// 把字符串 s 的前 n 个字符赋给当前的字符串
	string str2;
	str2.assign("hello again", 7);
	cout << str2 << endl;

	//string& assign(const string & s);// 把字符串 s 赋给当前字符串
	string str3;
	str3.assign(str);
	cout << str3 << endl;

	//string& assign(int n, char c);// 用 n 个字符 c 赋给当前字符串
	string str4;
	str4.assign(10,'s');
	cout << str4 << endl;
	 
	//string& assign(const string & s, int start, int n);// 将 s 从 start 开始 n 个字符赋值给字符串
	string str5;
	str5.assign("flight again",2,8);

}

/*
* 3.1.2.3 string 存取字符操作
char& operator[](int n);// 通过 [] 方式取字符
char& at(int n);// 通过 at 方法获取字符
*/

//存取操作
void test04()
{
	string str = "hello world";
	cout << str[1] << endl;
	cout << str.at(3) << endl;

	string str2 = "flight";
	str2[1] = 'L';
	cout << str2 << endl;
	str2.at(4) = 'H';
	cout << str2 << endl;

	//[] 和 at的区别
	//如果越界 [] 不抛出异常
	//如果越界 at 会抛出异常
	try
	{
		str[100] = 'G';
		//str.at(1000) = 'G';
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}


//int main(int argc, char * argv[])
//{
//	//test01();
//
//	//test02();
//
//	//test03();
//
//	test04();
//
//	return 0;
//}