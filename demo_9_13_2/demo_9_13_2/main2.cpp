#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

//����������
class MyAdd
{
public:
	//�����ǳ�Ա���� ��������  operator()
	int operator()(int a, int b)
	{
		cout << "������operator() int int" << endl;
		return a + b;
	}

	int operator()(int a, int b, int c)
	{
		cout << "������operator() int int int" << endl;
		return a + b + c;
	}
};

void test05()
{
	MyAdd ob1;
	cout << ob1.operator()(1, 10) << endl;
	//������Ż����������
	//�ϸ����壺ob1�Ƕ��� �� () ��ϵ���operator()��Ա����
	//ob1(1, 10) ob1�����Ƕ����Ǻ����� ֻ����ʽ��������
	//����������
	cout << ob1(1, 10) << endl;

	cout << MyAdd()(100, 200) << endl;
}

//lambda���ʽ
void printfVectorInt(vector<int> &v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
}

//ָ����ӡ��ʽ
void myPrint(int val)
{
	cout << val << " ";
}

void test06()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//����һ������v���� ��ͨ����
	printfVectorInt(v);

	//������������v���� ϵͳ�㷨for_each
	for_each(v.begin(),v.end(),myPrint);
	cout << endl;

	//������������v���� lambda���ʽ 
	//[]��ʾ������ ()�����б� {}������
	for_each(v.begin(), v.end(), [](int val) {
		cout << val << " ";
	});
}

int main(int argc, char* argv[])
{
	test05();

	return 0;
}