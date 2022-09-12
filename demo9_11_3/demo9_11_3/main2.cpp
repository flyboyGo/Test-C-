#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include <exception>

using namespace std;

/*
* 3.1.2.4 string ƴ�Ӳ���
* 
string& operator+=(const char c);// ���� += ������
string& append(const char *s);// ���ַ��� s ���ӵ���ǰ�ַ�����β
string& append(const string &s);// ͬ operator+=()
string& append(int n, char c);// �ڵ�ǰ�ַ�����β��� n ���ַ�
*/

void test05()
{
	//string& operator+=(const string& str);// ���� += ������
	string str1 = "hello";
	string str2 = " world";
	str2 += str2;
	cout << str2 << endl;

	//string& operator+=(const char* str);// ���� += ������
	string str3 = "flight";
	str3 += " again";
	cout << str3 << endl;

	//string& append(const char *s, int n);// ���ַ��� s ��ǰ n ���ַ����ӵ���ǰ�ַ�����β
	string str4 = "hi";
	str4.append("boy and gird",4);
	cout << str4 << endl;

	//string& append(const string &s, int pos, int n);// ���ַ��� s �д� pos ��ʼ�� n ���ַ����ӵ���ǰ�ַ�����β
	string str5 = "again";
	string str6 = " flight";
	str5.append(str6,0,7);
	cout << str5 << endl;

}

/*
* 3.1.2.5 string ���Һ��滻

int find(const char* s, int pos, int n) const; // �� pos λ�ò��� s ��ǰ n ���ַ���һ��λ��
int find(const char c, int pos = 0) const; // �����ַ� c ��һ�γ���λ��

int rfind(const string& str, int pos = npos) const;// ���� str ���һ��λ�� ,�� pos ��ʼ����
int rfind(const char* s, int pos = npos) const;// ���� s ���һ�γ���λ�� , ��pos ��ʼ����
int rfind(const char* s, int pos, int n) const;// �� pos ���� s ��ǰ n ���ַ����һ��λ��
int rfind(const char c, int pos = 0) const; // �����ַ� c ���һ�γ���λ��


string& replace(int pos, int n, const char* s); // �滻�� pos ��ʼ�� n ���ַ�Ϊ�ַ��� 
*/
void test06()
{
	//int find(const string& str, int pos = 0) const; // ���� str ��һ�γ���λ�� ,�� pos ��ʼ����
	string str = "hello world";
	string tmp = "world";
	cout << str.find(tmp,0) << endl;

	//int find(const char* s, int pos = 0) const; // ���� s ��һ�γ���λ�� , �� pos��ʼ����
	string str1 = "hello world flight world";
	//������pos��ȱʡ���� ����ʡ�� Ĭ��Ϊ0
	cout << str1.find("world", 0) << endl;

	//string& replace(int pos, int n, const string& str); // �滻�� pos ��ʼ n ���ַ�Ϊ�ַ��� str
	str1.replace(6,5,"hi");
	cout << str1 << endl;

	//���󣺽��ַ��������е� go �� *** Ƶ��
	string str2 = "go go boy and gird";
	cout << str2.length() << endl;
	while (1)
	{
		int pos = 0; //���Ѱ�ҵ���λ��
		int ret = str2.find("go",pos);
		if (ret > str2.length() - 1)
		{
			break;
		}
		else
		{
			pos = ret; //�����ַ����ҵ���ʼλ��
			str2.replace(ret,strlen("go"),"***");
		}
	}
	cout << str2 << endl;
}

/*
* 3.1.2.6 string �Ƚϲ���
* 
compare ������ > ʱ���� 1 �� < ʱ���� -1 �� == ʱ���� 0 ��
�Ƚ����ִ�Сд���Ƚ�ʱ�ο��ֵ�˳����Խǰ���ԽС����д�� A ��Сд�� a С��
   
   
*/

void test07()
{

	string str = "hello world";
	string str2 = "hello";
	//int compare(const string& s) const;// ���ַ��� s �Ƚ�
	cout << str.compare(str2) << endl; //1

	//int compare(const char* s) const;// ���ַ��� s �Ƚ�
	cout << str.compare("hi") << endl;// -1

	cout << str.compare("hello world") << endl;
}

/*
* 3.1.2.7 string �Ӵ���ȡ
string substr(int pos = 0, int n = npos) const;// ������ pos ��ʼ�� n ���ַ�
��ɵ��ַ���
*/
void test08()
{
	string str = "hello world again";
	string str2 = str.substr(6,5);
	cout << str2 << endl;

	//�����������ָ�������ַ�����ȡ����
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
* 3.1.2.8 string �����ɾ������
string& insert(int pos, const char* s); // �����ַ���
string& insert(int pos, const string& str); // �����ַ���
string& insert(int pos, int n, char c);// ��ָ��λ�ò��� n ���ַ� c
string& erase(int pos, int n = npos);// ɾ���� Pos ��ʼ�� n ���ַ�
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

	//����ַ���
	str.erase(0,str.length());
	cout << str.length() << endl;
}

/*
* 3.1.2.9 string �� c-style �ַ���ת��
*/
void test10()
{
	string str1; //����
	const char * str2 = "hello str";

	//��char * ת���� string (ֱ�����)
	str1 = str2;
	cout << str1 << endl;

	string str3 = "hello str3";
	//���ܽ�string ת���� char * �������string�е�c_str�������
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