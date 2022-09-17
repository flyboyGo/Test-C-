#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>

using namespace std;

//���ü����㷨

/*
set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
set_intersection �㷨 ������ set ���ϵĽ���
ע�� : �������ϱ����� "��������"
@param beg1 ���� 1 ��ʼ������    @param end1 ���� 1 ����������
@param beg2 ���� 2 ��ʼ������    @param end2 ���� 2 ����������
@param dest Ŀ��������ʼ������   @return Ŀ�����������һ��Ԫ�صĵ�������ַ
*/

void test03()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(50);

	vector<int> v2;
	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(50);
	

	vector<int> v3;
	v3.resize(min(v1.size(),v2.size()));
	vector<int>::iterator myEnd;
	myEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

	for_each(v3.begin(), myEnd, [](int val) {cout << val << " ";});
	cout << endl;
}

/*
set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
set_union �㷨 ������ set ���ϵĲ���
ע�� : �������ϱ�������������
@param beg1 ���� 1 ��ʼ������   @param end1 ���� 1 ����������
@param beg2 ���� 2 ��ʼ������   @param end2 ���� 2 ����������
@param dest Ŀ��������ʼ������  @return Ŀ�����������һ��Ԫ�صĵ�������ַ
*/
void test04()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(50);

	vector<int> v2;
	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(50);
	v2.push_back(60);


	vector<int> v3;
	v3.resize(v1.size()+v2.size());
	vector<int>::iterator myEnd;
	myEnd = set_union(v2.begin(), v2.end(),v1.begin(), v1.end(), v3.begin());

	for_each(v3.begin(), myEnd, [](int val) {cout << val << " "; });
	cout << endl;
}


/*
set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
set_difference �㷨 ������ set ���ϵĲ
ע�� : �������ϱ�������������
@param beg1 ���� 1 ��ʼ������    @param end1 ���� 1 ����������
@param beg2 ���� 2 ��ʼ������    @param end2 ���� 2 ����������
@param dest Ŀ��������ʼ������   @return Ŀ�����������һ��Ԫ�صĵ�������ַ
*/
void test05()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(50);

	vector<int> v2;
	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(50);


	vector<int> v3;
	v3.resize(v2.size());
	vector<int>::iterator myEnd;
	myEnd = set_difference(v2.begin(), v2.end(),v1.begin(), v1.end(), v3.begin());

	for_each(v3.begin(), myEnd, [](int val) {cout << val << " "; });
	cout << endl;
}

//int main(int argc, char* argv[])
//{
//	//test03();
//
//	//test04();
//
//	test05();
//
//	return 0;
//}