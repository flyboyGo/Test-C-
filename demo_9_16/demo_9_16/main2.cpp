#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//�ڽ���������
/*
* STL �ڽ���һЩ�������󡣷�Ϊ:�����ຯ������,��ϵ�����ຯ�������߼�����
  ��º�������Щ�º����������Ķ����÷���һ�㺯����ȫ��ͬ����Ȼ���ǻ�����
  ������������ʱ���������к������ܡ�ʹ���ڽ�����������Ҫ����ͷ�ļ�
*/

void test03()
{
	//�ӷ��ڽ���������
	plus<int> p;
	cout << p(10, 20) << endl;
	cout << plus<int>()(100, 200) << endl;
}

void test04()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;

	//ʹ���ڽ��������� ���� �ı��������
	sort(v.begin(),v.end(),greater<int>());
}

//int main(int argc, char* argv[])
//{
//	//test03();
//
//	test04();
//	
//	return 0;
//}