#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include <exception>

using namespace std;

/*
* 
3.1.2 string��Ĺ��졢��ֵ����ȡ

3.1.2.1 string ���캯��
string();//����һ���յ��ַ��� ����: string str;
string(const string& str);//ʹ��һ�� string �����ʼ����һ�� string ����
string(const char* s);//ʹ���ַ��� s ��ʼ��
string(int n, char c);//ʹ�� n ���ַ� c ��ʼ�� 
*/

//���캯��
void test01()
{
	//string(const char* s);//ʹ���ַ��� s ��ʼ��
	string str = string("hello world");
	cout << str << endl;

	//string(int n, char c);//ʹ�� n ���ַ� c ��ʼ�� 
	string str2 = string(10, 'H');
	cout << str2 << endl;

	//string(const string & str);//ʹ��һ�� string �����ʼ����һ�� string ����
	string str3 = str2;
	cout << str3 << endl;
}

/*
* 3.1.2.2 string ������ֵ����
string& operator=(const char* s);//char* �����ַ��� ��ֵ����ǰ���ַ���
string& operator=(const string &s);// ���ַ��� s ������ǰ���ַ���
string& operator=(char c);// �ַ���ֵ����ǰ���ַ���

string& assign(const char *s);// ���ַ��� s ������ǰ���ַ���
string& assign(const char *s, int n);// ���ַ��� s ��ǰ n ���ַ�������ǰ���ַ���
string& assign(const string &s);// ���ַ��� s ������ǰ�ַ���
string& assign(int n, char c);// �� n ���ַ� c ������ǰ�ַ���
string& assign(const string &s, int start, int n);// �� s �� start ��ʼ n ���ַ���ֵ���ַ���
*/

//��ֵ���� ����� = ����
void test02()
{

	string str = string("hello");
	//string& operator=(const string & s);// ���ַ���(����) s ������ǰ���ַ���
	string str2;
	str2 = str;
	cout << str2 << endl;

	//string& operator=(const char* s);//char* �����ַ��� ��ֵ����ǰ���ַ���
	string str3;
	str3 = "hello again";
	cout << str3 << endl;

	//string& operator=(char c);// �ַ���ֵ����ǰ���ַ���
	string str4;
	str4 = 'a';
	cout << str4 << endl;
}

//��ֵ���� ��Ա����
void test03()
{
	//string& assign(const char* s);// ���ַ��� s ������ǰ���ַ���
	string str;
	str.assign("hello");
	cout << str << endl;

	//string& assign(const char* s, int n);// ���ַ��� s ��ǰ n ���ַ�������ǰ���ַ���
	string str2;
	str2.assign("hello again", 7);
	cout << str2 << endl;

	//string& assign(const string & s);// ���ַ��� s ������ǰ�ַ���
	string str3;
	str3.assign(str);
	cout << str3 << endl;

	//string& assign(int n, char c);// �� n ���ַ� c ������ǰ�ַ���
	string str4;
	str4.assign(10,'s');
	cout << str4 << endl;
	 
	//string& assign(const string & s, int start, int n);// �� s �� start ��ʼ n ���ַ���ֵ���ַ���
	string str5;
	str5.assign("flight again",2,8);

}

/*
* 3.1.2.3 string ��ȡ�ַ�����
char& operator[](int n);// ͨ�� [] ��ʽȡ�ַ�
char& at(int n);// ͨ�� at ������ȡ�ַ�
*/

//��ȡ����
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

	//[] �� at������
	//���Խ�� [] ���׳��쳣
	//���Խ�� at ���׳��쳣
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