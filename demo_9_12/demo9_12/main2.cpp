#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printfVectorIntPlus(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//reserve(int len);// ����Ԥ�� len ��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�
void test08()
{
	// reserve(int len);// ����Ԥ�� len ��Ԫ�س��ȣ����ı�������Ԫ�صĸ��� ���ı�Ԫ�ص�����),
	// Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�
	vector<int> v;
	//һ���� �����ռ� ���� �ռ�Ԥ��
	v.reserve(100);

	int* p = NULL;
	int count = 0;
	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			count++;
			p = &v[0];
		}
	}
	cout << "��Ѱ�ռ�Ĵ���: " << count << endl;
	
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	
}

/*
* 3.2.4.4 vector ���ݴ�ȡ����
at(int idx); // �������� idx ��ָ�����ݣ���� idx Խ�磬�׳� out_of_range �쳣��
operator[];// �������� idx ��ָ�����ݣ�Խ��ʱ������ֱ�ӱ���, ���׳� out_of_range �쳣��
front();// ���������е�һ������Ԫ��
back();// �������������һ������Ԫ��
*/
void test09()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	cout << v.at(1) << endl;
	cout << v[3] << endl;
	cout << v.front() << endl;
	cout << v.back() << endl;

	//���Խ��и�ֵ����
    v.at(1) = 6;
	v[2] = 7;
	v.front() = 5;
	v.back() = 0;
	printfVectorIntPlus(v);
}

/*
* 3.2.4.5 vector �����ɾ������
push_back(ele); // β������Ԫ�� ele
*/
void test10()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	printfVectorIntPlus(v);

	//insert(const_iterator pos, int count,ele);// ������ָ��λ�� pos ���� count��Ԫ�� ele.
	v.insert(v.begin() + 2, 3, 100);
	printfVectorIntPlus(v);

	//pop_back();// ɾ�����һ��Ԫ��
	v.pop_back();
	printfVectorIntPlus(v);

	//erase(const_iterator start, const_iterator end);// ɾ���������� start �� end ֮���Ԫ��
	v.erase(v.begin() + 2,v.end() -1);
	printfVectorIntPlus(v);
	//������Ԫ�صĸ��������仯 �����������������仯
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	//erase(const_iterator pos);// ɾ��������ָ���Ԫ��
	//������Ԫ�صĸ��������仯 �����������������仯
	v.erase(v.begin());
	printfVectorIntPlus(v);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	//clear();// ɾ������������Ԫ��
	//������Ԫ�صĸ��������仯 �����������������仯
	v.clear();
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	printfVectorIntPlus(v);

}

int main(int argc, char* argv[])
{
	//test08();

	//test09();

	test10();

	return 0;
}