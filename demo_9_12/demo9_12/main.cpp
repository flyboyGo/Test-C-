#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//1��vector ������
/*
* Vector ά��һ�����Կռ䣬���Բ���Ԫ�ص��ͱ���Σ���ָͨ�붼������Ϊ
  vector �ĵ���������Ϊ vector ����������Ҫ�Ĳ�����Ϊ���� operaroe, operator->,
  operator++, operator--, operator+, operator-, operator+=, operator-=, ��ָͨ�������߱��� 
  Vector ֧�������ȡ������ָͨ��������������������
  ���� vector �ṩ����������ʵ����� (Random Access Iterators). 
  ���������������������д���µĴ��룺 Vector::iterator it1; Vector::iterator it2; 
  it1 ���ͱ���ʵ���� Int,it2 ���ͱ���ʵ���� Teacher*
*/

//2��vector���������� >= Ԫ�صĸ��� ԭ��vector��δ����ѻ���
void test01()
{
	vector<int> v;
	int i = 0;
	for (i = 0; i < 100; i++)
		v.push_back(i);
	cout << "v������capacity: " << v.capacity() << endl;
	cout << "v�Ĵ�Сsize:" << v.size() << endl;
}

//3��vector ���˶�̬����

//4��vector ��Ѱ��ַ�Ĵ���

void test02()
{
	vector<int> v;
	int* p = NULL;
	int count = 0; //��¼��Ѱ��ַ�Ĵ���

	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		if (p != &v[0]) //���p������&a[0] ˵����Ѱ��һ�οռ�
		{
			count++;
			p = &v[0];
		}
	}

	cout << "��Ѱ��ַ�Ĵ���: " << count << endl;
}

//5��vector��δ����ѻ���(�˽�)
void test03()
{
	vector <int>  v;
	cout << "capacity =" << v.capacity() << ", size = " << v.size() << endl; // 0 0
	int* p = NULL;
	int count = 0;
	for (int i = 0; i < 1000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			cout << "-------------" << count++ << "---------------" << endl;
			p = &v[0];
		}
		cout << "capacity =" << v.capacity() << ", size = " << v.size() << endl;
	}
}

//6��vector�����ݽṹ

//7��vector�ĳ���API

/*
* 3.2.4.1 vector ���캯��
  vector<T> v; // ����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
*/

void printfVectorInt(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test04()
{
	//vector(n, elem);// ���캯���� n �� elem ����������
	vector<int> v = vector<int>(10, 5);
	printfVectorInt(v);

	//vector(v.begin(), v.end());// �� v[begin(), end()) �����е�Ԫ�ؿ���������
	vector<int> v2 = vector<int>(v.begin()+2, v.end()-2);
	printfVectorInt(v2);

	// vector(const vector &vec);// �������캯����
	vector<int> v3 = vector<int>(v2);
	printfVectorInt(v3);
}

/*
* 3.2.4.2 vector ���ø�ֵ����
*/

void test05()
{
	vector<int> v = vector<int>(5,0);
	vector<int> v2;

	//vector& operator=(const vector &vec);// ���صȺŲ�����
	v2 = v;
	printfVectorInt(v2);

	//assign(n, elem);// �� n �� elem ������ֵ������
	vector<int> v3;
	v3.assign(5,4);
	printfVectorInt(v3);

	//assign(beg, end);// �� [beg, end) �����е����ݿ�����ֵ������
	vector<int> v4;
	v4.assign(v3.begin(), v3.end());
	printfVectorInt(v4);

	//swap(vec);// �� vec �뱾���Ԫ�ػ�����
	vector<int> v5 = vector<int>(5, 8);
	vector<int> v6 = vector<int>(5, 1);
	printfVectorInt(v5);
	printfVectorInt(v6);
	v5.swap(v6);
	printfVectorInt(v5);
	printfVectorInt(v6);
}

/*
* 3.2.4.3 vector ��С����
size();// ����������Ԫ�صĸ���
capacity();// ����������
*/

void test06()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//empty();// �ж������Ƿ�Ϊ��
	cout << v.empty() << endl;

	//resieze() ֻ������������Ԫ�صĸ��� ����ı�����������
	 
	//resize(int num);// ����ָ�������ĳ���Ϊ num ���������䳤������Ĭ��ֵ�����λ
	//�á����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
	printfVectorInt(v);
	v.resize(6);
	printfVectorInt(v); // 10 20 30 40 50 0
	v.resize(3);
	printfVectorInt(v); // 10 20 30

	//resize(int num, elem);// ����ָ�������ĳ���Ϊ num ���������䳤������ elem ֵ��
	//����λ�á����������̣���ĩβ���������� > �ȵ�Ԫ�ر�ɾ����
	v.resize(5,70);
	printfVectorInt(v); // 10 20 30 70 70
	v.resize(2);
	printfVectorInt(v); // 10 20

	//reserve(int len);// ����Ԥ�� len ��Ԫ�س��ȣ����ı�������Ԫ�صĸ��� ���ı�Ԫ�ص�����),
	//Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	v.reserve(10);
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
}

//������������������(ʹ��resize swap)
void test07()
{
	vector<int> v;
	for (int i = 0; i < 1000; i++)
	{
		v.push_back(i);
	}
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	v.resize(10); //�����޸����������� ֻ���޸�������Ԫ�ص�����
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;

	//ʹ��swap��������������
	//��v��ʵ��Ԫ�صĸ��� ���Ƹ� ��������
	//�������� �� v���� �����ռ�
	vector<int>(v).swap(v);
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
}

//int main(int argc, char* argv[])
//{
//
//	//test01();
//
//	//test02();
//
//	//test03();
//
//	//test04();
//
//	//test05();
//
//	//test06();
//
//	test07();
//
//	return 0;
//}