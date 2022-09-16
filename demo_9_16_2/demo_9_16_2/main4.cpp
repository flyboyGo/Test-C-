#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <stdlib.h>
#include <time.h>

using namespace std;

//���������㷨
/*
merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
merge �㷨 ����Ԫ�غϲ������洢����һ������
ע�� : �������������� "����" ��
@param beg1 ���� 1 ��ʼ������
@param end1 ���� 1 ����������
@param beg2 ���� 2 ��ʼ������
@param end2 ���� 2 ����������
@param dest Ŀ��������ʼ������
*/

void test09()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(50);
	v1.push_back(70);

	vector<int> v2;
	v2.push_back(20);
	v2.push_back(40);
	v2.push_back(60);
	v2.push_back(80);

	vector<int> v3;
	//Ԥ������v3�Ĵ�С
	v3.resize(v1.size() + v2.size());

	merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());

	for_each(v3.begin(), v3.end(), [](int val) {
		cout << val << " ";
	});
	cout << endl;
}

/*
sort(iterator beg, iterator end, _callback)
sort �㷨 ����Ԫ������
@param beg ���� 1 ��ʼ������
@param end ���� 1 ����������
@param _callback �ص���������ν�� ( ���� bool ���͵ĺ������� )
*/

/*
random_shuffle(iterator beg, iterator end)
random_shuffle �㷨 ��ָ����Χ�ڵ�Ԫ�������������
@param beg ������ʼ������
@param end ��������������
*/

void test10()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(50);
	v1.push_back(70);

	srand(time(NULL));
	random_shuffle(v1.begin(), v1.end());

	for_each(v1.begin(), v1.end(), [](int val) {
		cout << val << " ";
	});
	cout << endl;
}

/*
reverse(iterator beg, iterator end)
reverse �㷨 ��תָ����Χ��Ԫ��
@param beg ������ʼ������
@param end ��������������
*/

void test11()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(50);
	v1.push_back(70);

	for_each(v1.begin(), v1.end(), [](int val) {
		cout << val << " ";
	});
	cout << endl;

	reverse(v1.begin(), v1.end());
	for_each(v1.begin(), v1.end(), [](int val) {
		cout << val << " ";
	});
	cout << endl;
}


//int main(int argc, char* argv[])
//{
//
//	//test09();
//
//	//test10();
//
//	//test11();
//
//	return 0;
//}

