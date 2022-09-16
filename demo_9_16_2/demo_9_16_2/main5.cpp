#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <stdlib.h>
#include <time.h>

using namespace std;

//���ÿ������滻�㷨

/*
copy(iterator beg, iterator end, iterator dest)
copy �㷨 ��������ָ����Χ��Ԫ�ؿ�������һ������
@param beg ������ʼ������
@param end ��������������
@param dest Ŀ����ʼ������
*/

#include <iterator>

void test12()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(50);
	v1.push_back(70);

	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(),v1.end(),v2.begin());

	for_each(v2.begin(), v2.end(), [](int val) {
		cout << val << " ";
	});
	cout << endl;

	//copy��չ ��copy���
	//���������
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout," "));
}

/*
replace(iterator beg, iterator end, oldvalue, newvalue)
replace �㷨 ��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
@param beg ������ʼ������
@param end ��������������
@param oldvalue ��Ԫ��
@param newvalue ��Ԫ��
*/

void test13()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(50);
	v1.push_back(70);

	//�������е�30 �滻�� 3000
	replace(v1.begin(), v1.end(), 30, 3000);

	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	for_each(v1.begin(), v1.end(), [](int val) {
		cout << val << " ";
	});
	cout << endl;
}

/*
replace_if(iterator beg, iterator end, _callback, newvalue) �����滻
replace_if �㷨 ��������ָ����Χ����������Ԫ���滻Ϊ��Ԫ��
@param beg ������ʼ������
@param end ��������������
@param callback �����ص�����ν�� ( ���� Bool ���͵ĺ������� )
@param oldvalue ��Ԫ��
*/

bool myReplace(int val)
{
	return val > 30;
}
class MyReplace
{
public:
	bool operator()(int val)
	{
		return val > 30;
	}
};
void test14()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(50);
	v1.push_back(70);

	//�������еĴ���30 �滻�� 3000
	//��ͨ����
	replace_if(v1.begin(), v1.end(), myReplace, 3000);

	//��������
	replace_if(v1.begin(), v1.end(), MyReplace(), 3000);

	//�ڽ���������
	replace_if(v1.begin(), v1.end(), bind2nd(greater<int>(),30), 3000);

	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

/*
swap(container c1, container c2)
swap �㷨 ��������������Ԫ��
@param c1 ���� 1
@param c2 ���� 2
*/

int main(int argc, char* argv[])
{
	//test12();
	
	//test13();

	test14();

	return 0;
}