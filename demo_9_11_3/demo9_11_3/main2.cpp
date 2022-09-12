#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include <exception>

using namespace std;

/*
* 3.1.2.4 string 拼接操作
* 
string& operator+=(const char c);// 重载 += 操作符
string& append(const char *s);// 把字符串 s 连接到当前字符串结尾
string& append(const string &s);// 同 operator+=()
string& append(int n, char c);// 在当前字符串结尾添加 n 个字符
*/

void test05()
{
	//string& operator+=(const string& str);// 重载 += 操作符
	string str1 = "hello";
	string str2 = " world";
	str2 += str2;
	cout << str2 << endl;

	//string& operator+=(const char* str);// 重载 += 操作符
	string str3 = "flight";
	str3 += " again";
	cout << str3 << endl;

	//string& append(const char *s, int n);// 把字符串 s 的前 n 个字符连接到当前字符串结尾
	string str4 = "hi";
	str4.append("boy and gird",4);
	cout << str4 << endl;

	//string& append(const string &s, int pos, int n);// 把字符串 s 中从 pos 开始的 n 个字符连接到当前字符串结尾
	string str5 = "again";
	string str6 = " flight";
	str5.append(str6,0,7);
	cout << str5 << endl;

}

/*
* 3.1.2.5 string 查找和替换

int find(const char* s, int pos, int n) const; // 从 pos 位置查找 s 的前 n 个字符第一次位置
int find(const char c, int pos = 0) const; // 查找字符 c 第一次出现位置

int rfind(const string& str, int pos = npos) const;// 查找 str 最后一次位置 ,从 pos 开始查找
int rfind(const char* s, int pos = npos) const;// 查找 s 最后一次出现位置 , 从pos 开始查找
int rfind(const char* s, int pos, int n) const;// 从 pos 查找 s 的前 n 个字符最后一次位置
int rfind(const char c, int pos = 0) const; // 查找字符 c 最后一次出现位置


string& replace(int pos, int n, const char* s); // 替换从 pos 开始的 n 个字符为字符串 
*/
void test06()
{
	//int find(const string& str, int pos = 0) const; // 查找 str 第一次出现位置 ,从 pos 开始查找
	string str = "hello world";
	string tmp = "world";
	cout << str.find(tmp,0) << endl;

	//int find(const char* s, int pos = 0) const; // 查找 s 第一次出现位置 , 从 pos开始查找
	string str1 = "hello world flight world";
	//方法中pos是缺省参数 可以省略 默认为0
	cout << str1.find("world", 0) << endl;

	//string& replace(int pos, int n, const string& str); // 替换从 pos 开始 n 个字符为字符串 str
	str1.replace(6,5,"hi");
	cout << str1 << endl;

	//需求：将字符串中所有的 go 用 *** 频闭
	string str2 = "go go boy and gird";
	cout << str2.length() << endl;
	while (1)
	{
		int pos = 0; //标记寻找到的位置
		int ret = str2.find("go",pos);
		if (ret > str2.length() - 1)
		{
			break;
		}
		else
		{
			pos = ret; //更新字符查找的起始位置
			str2.replace(ret,strlen("go"),"***");
		}
	}
	cout << str2 << endl;
}

/*
* 3.1.2.6 string 比较操作
* 
compare 函数在 > 时返回 1 ， < 时返回 -1 ， == 时返回 0 。
比较区分大小写，比较时参考字典顺序，排越前面的越小。大写的 A 比小写的 a 小。
   
   
*/

void test07()
{

	string str = "hello world";
	string str2 = "hello";
	//int compare(const string& s) const;// 与字符串 s 比较
	cout << str.compare(str2) << endl; //1

	//int compare(const char* s) const;// 与字符串 s 比较
	cout << str.compare("hi") << endl;// -1

	cout << str.compare("hello world") << endl;
}

/*
* 3.1.2.7 string 子串提取
string substr(int pos = 0, int n = npos) const;// 返回由 pos 开始的 n 个字符
组成的字符串
*/
void test08()
{
	string str = "hello world again";
	string str2 = str.substr(6,5);
	cout << str2 << endl;

	//案例：将：分割的所有字符串提取出来
	int pos = 0;
	while (1)
	{
		int ret = str.find(" ",pos);
		if (ret > str.length() - 1 || ret < 0)
		{
			string tmp = str.substr(pos, str.length() - pos);
			cout << tmp << endl;
			break;
		}
		string tmp = str.substr(pos,ret - pos);
		cout << tmp << endl;
		pos = ret + 1;
	}
}

/*
* 3.1.2.8 string 插入和删除操作
string& insert(int pos, const char* s); // 插入字符串
string& insert(int pos, const string& str); // 插入字符串
string& insert(int pos, int n, char c);// 在指定位置插入 n 个字符 c
string& erase(int pos, int n = npos);// 删除从 Pos 开始的 n 个字符
*/

void test09()
{
	string str = "hello";
	str.insert(5, "world");
	cout << str << endl;

	str.insert(10,5,'*');
	cout << str << endl;

	str.erase(10,5);
	cout << str << endl;

	//清空字符串
	str.erase(0,str.length());
	cout << str.length() << endl;
}

/*
* 3.1.2.9 string 和 c-style 字符串转换
*/
void test10()
{
	string str1; //对象
	const char * str2 = "hello str";

	//将char * 转换成 string (直接完成)
	str1 = str2;
	cout << str1 << endl;

	string str3 = "hello str3";
	//不能将string 转换成 char * 必须借助string中的c_str方法完成
	//char* str4 = str3;
	char * str4 = const_cast<char *>(str3.c_str());
	cout << str4 << endl;
}

int main(int argc, char* argv[])
{
	//test05();

	//test06();

	//test07();

	//test08();

	//test09();

	test10();

	return 0;
}