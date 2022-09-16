#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

//��������
//list����(˫������) �ĵ����� ����߱�ǰ�ơ����� �ṩ����˫�������

//vector ���˶�̬���� (������ʵ�����)
//deque  ˫�˶�̬���� (������ʵ�����)
//stack ջ���� (û�е�����)
//queue �������� (û�е�����)
//list �������� (˫�������)
//set��multiset ֻ�������� (���������)
//map��mutlimap ֻ�������� (���������)

//C++�е���������Ϊ������������������������������������


//���������� (���������������ػ�����չһԪ����Ԫ��������)

//������������Ϊ�������������������(ȡ��������)������ָ������������Ա����������

//��������
//��չ�����Ĳ����ӿ� (���뺯����һ������ ����չһ���ӿ� ���Դ�����������)
void myPrint(int val, int tmp)
{
	cout << val + tmp << " ";
}

//val �� for_each �ṩ�� tmp
//������2�������̳� binary_function(��Ԫ)
//������3����������ȡ 
//������4����operator() ����const����

class MyPrint : public binary_function<int,int,void>
{
public:
	void operator()(int val,int tmp) const
	{
		cout << "val = " << val << ",tmp =  " << tmp << endl;;
	}
};

void test05()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//������1���� bind2nd ���� bindlst �󶨲���
	for_each(v.begin(), v.end(), bind2nd(MyPrint(),1000));
	cout << endl;
	cout << "---------------" << endl;
	for_each(v.begin(), v.end(), bind1st(MyPrint(), 1000));
	cout << endl;

	//bind2nd��bind1st������  �󶨵Ĳ���λ�ò�ͬ
	//bind2nd ���������� �󶨵��ڶ�������
	//bind1st ���������� �󶨵���һ������
}

//ȡ��������
//note1  һԪȡ��
//note2  ��Ԫȡ��

//ȡ��������2�������̳�unary_function(һԪ)
//ȡ��������3��������ȡ
//ȡ��������4��const���� operator()
class MyGreaterThan3 : public unary_function<int,bool>
{
public:
	//һԪν��
	bool operator()(int val) const
	{
		return val > 3;
	}
};

void test06()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	//�ҳ�һ������3����
	vector<int>::iterator ret;
	ret = find_if(v.begin(),v.end(), MyGreaterThan3());
	if (ret != v.end())
	{
		cout << *ret << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
	
	//�ҳ���һ��С��3����
	//ȡ��������1��not1����
	ret = find_if(v.begin(), v.end(), not1(MyGreaterThan3()));
	if (ret != v.end())
	{
		cout << *ret << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
}

//��Ԫȡ��
class MyGreaterReverse : public binary_function<int,int,bool>
{
public:
	bool operator()(int val1,int val2) const
	{
		return val1 > val2;
	}
};

void test07()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	for_each(v.begin(), v.end(), [](int val) {
		cout << val << " ";
	});
	cout << endl;

	//Ĭ��С --> ��
	//sort(v.begin(),v.end());
	//����������� �� -- С
	//sort(v.begin(), v.end(), MyGreaterReverse());
	//ʹ��not2��MyGreaterReverseȡ�� С--->��
	//sort(v.begin(), v.end(), not2(MyGreaterReverse()));
	//ʹ��not2���ڽ���������ȡ��
	//greater �Ӵ�-->С   less��С-->��
	sort(v.begin(), v.end(), not2(greater<int>()));
	//sort(v.begin(), v.end(), not2(less<int>()));

	for_each(v.begin(), v.end(), [](int val) {
		cout << val << " ";
	});
}

//int main(int argc, char* argv[])
//{
//	//test05();
//
//	//test06();
//
//	test07();
//
//	return 0;
//}