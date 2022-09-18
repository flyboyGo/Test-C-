#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
* 文件的类型
* 1、文本文件：文件以文本的ASCLL码的形式存储在计算机中
* 2、二进制文件：文件以文本的二进制形式存储在计算机中,用户一般不能直接读懂它们
* 
* 操作文件的三大类
* 1、ofstream：写操作
* 2、ifstream：读操作
* 3、fstream：读写操作
*/

//文本文件  写文件
void test01()
{
	//1、包含头文件 fstream

	//2、创建流对象
	ofstream ofs;

	//3、指定文件的打开方式
	ofs.open("test.txt",ios::out);

	//4、写文件
	ofs << "姓名：李鹏飞  年龄：25" << endl;
	ofs << "性别：男  籍贯：江苏盐城" << endl;

	//5、关闭文件
	ofs.close();
}

//文本文件 读文件
void test02()
{
	//1、包含头文件 fstream

	//2、创建流对象
	ifstream ifs;

	//3、指定文件的打开方式并判断是否成功
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败!" << endl;
		return;
	}

	//4、读文件
	//第一种方式
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}

	//第二种方式
	//char buf[100] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf <<endl;
	//}

	//第三种方式
	string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;;
	}

	//第四种方式
	//char c;
	//while ((c = ifs.get()) != EOF) // EOF end of file
	//{
	//	cout << c;
	//}

	//5、关闭文件
	ifs.close();
}

//int main(int argc, char* argv[])
//{
//    //test01();
//
//	test02();
//
//	return 0;
//}