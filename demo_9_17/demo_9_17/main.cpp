#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>

using namespace std;

/*
accumulate(iterator beg, iterator end, value)
accumulate �㷨 ��������Ԫ���ۼ��ܺ�
@param beg ������ʼ������  @param end ��������������
@param value �ۼ�ֵ
*/

void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	cout << "sum = " << accumulate(v.begin(),v.end(),0) << endl;
}

/*
fill(iterator beg, iterator end, value)
fill �㷨 �����������Ԫ��
@param beg ������ʼ������   @param end ��������������
@param value t ���Ԫ��
*/

void test02()
{
	vector<int> v;
	//Ԥ�����ô�С
	v.resize(5);
	fill(v.begin(),v.end(),100);

	for_each(v.begin(), v.end(), [](int val) {
		cout << val << " ";
	});
	cout << endl;
}


//int main(int argc, char* argv[])
//{
//	test01();
//
//	test02();
//
//	return 0;
//}