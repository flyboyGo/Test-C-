#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//��������
/*
* ���غ������ò��������࣬����󳣳�Ϊ��������function object������������
��Ϊ���ƺ����Ķ���Ҳ�зº���(functor),��ʵ�������ء�()����������ʹ�������
����������������
*/

//ν��
/*
* ����ֵ����Ϊbool����ͨ��������������(�º���) ����ν��
* �����ͨ�������º��� ��һ������ �ͽ���һԪν��
* �����ͨ�������º��� �ж������� �ͽ�����Ԫν��
*/

//��ͨ������ΪһԪν��
bool greaterThan20(int val)
{
	return val > 20;
}
//�º�����ΪһԪν��
class MyGreaterThan20
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}
};

void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;

	//�����ҳ���һ������20����
	vector<int>::iterator ret;
	//��ͨ�������
	//ret = find_if(v.begin(), v.end(), greaterThan20);
	//�º������
	ret = find_if(v.begin(), v.end(), MyGreaterThan20());
	if (ret != v.end())
	{
		cout << *ret << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
}

//��Ԫν��
//��ͨ������Ϊ��Ԫν��
bool myGreater(int val1, int val2)
{
	return val1 > val2;
}

//�º�����Ϊ��Ԫν��
class MyGreater
{
public:
	bool operator()(int val1, int val2)
	{
		return val1 > val2;
	}
};

void test02()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;

	//�Ӵ�-->С ����
	//��ͨ����
	//sort(v.begin(), v.end(), myGreater);
	//�º���
	sort(v.begin(), v.end(), MyGreater());

	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;
}

//int main(int argc, char* argv[])
//{
//	//test01();
//
//	test02();
//
//	return 0;
//}