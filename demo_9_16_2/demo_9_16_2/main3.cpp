#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

using namespace std;

/*
count(iterator beg, iterator end, value);��ֵͳ��
count �㷨 ͳ��Ԫ�س��ִ���
@param beg ������ʼ������
@param end ��������������
@param value �ص���������ν�� ( ���� bool ���͵ĺ������� )
@return int ����Ԫ�ظ���
*/

void test07()
{
	vector<int> v;
	v.push_back(30);
	v.push_back(40);
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	cout << "����Ϊ��" << count(v.begin(), v.end(), 30) << endl;
}

/*
count_if(iterator beg, iterator end, _callback); ����ͳ��
count_if �㷨 ͳ��Ԫ�س��ִ���
@param beg ������ʼ������
@param end ��������������
@param callback �ص���������ν��(���� bool ���͵ĺ�������)
@return int ����Ԫ�ظ���
*/

bool myGreaterThan30(int val)
{
	return val > 30;
}

class MyGreater
{
public:
	bool operator()(int val)
	{
		return val > 30;
	}
};

void test08()
{
	vector<int> v;
	v.push_back(40);
	v.push_back(10);
	v.push_back(20);
	v.push_back(40);

	//��ͨ����ʵ��
	cout << count_if(v.begin(), v.end(), myGreaterThan30) << endl;
	//��������(�º���)
	cout << count_if(v.begin(), v.end(), MyGreater()) << endl;
	//�ڽ���������
	cout << count_if(v.begin(), v.end(), bind2nd(greater<int>(),30)) << endl;
}

//int main(int argc, char* argv[])
//{
//	//test07();
//
//	test08();
//
//	return 0;
//}