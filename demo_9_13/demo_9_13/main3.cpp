#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

//��������
//list����(˫������) �ĵ����� ����߱�ǰ�ơ����� �ṩ����˫�������

//vector ���˶�̬���� (������ʵ�����)
//deque  ˫�˶�̬���� (������ʵ�����)
//stack ջ���� (û�е�����)
//queue �������� (û�е�����)
//list �������� (˫�������)

void printfListInt(list<int>& L)
{
	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

/*3.6.4 list  ���� API
* 
* 3.6.4.1 list ���캯��
list<T> lstT;//list ���ò���ģ����ʵ�� , �����Ĭ�Ϲ�����ʽ��
list(beg,end);// ���캯���� [beg, end) �����е�Ԫ�ؿ���������
list(n,elem);// ���캯���� n �� elem ����������
list(const list &lst);// �������캯����
*/

/*
* 3.6.4.2 list ����Ԫ�ز����ɾ������
push_back(elem);// ������β������һ��Ԫ��
pop_back();// ɾ�����������һ��Ԫ��
push_front(elem);// ��������ͷ����һ��Ԫ��
pop_front();// ��������ͷ�Ƴ���һ��Ԫ��
insert(pos,elem);// �� pos λ�ò� elem Ԫ�صĿ��������������ݵ�λ�á�
insert(pos,n,elem);// �� pos λ�ò��� n �� elem ���ݣ��޷���ֵ��
insert(pos,beg,end);// �� pos λ�ò��� [beg,end) ��������ݣ��޷���ֵ��
clear();// �Ƴ���������������
erase(beg,end);// ɾ�� [beg,end) ��������ݣ�������һ�����ݵ�λ�á�
erase(pos);// ɾ�� pos λ�õ����ݣ�������һ�����ݵ�λ�á�
remove(elem);// ɾ�������������� elem ֵƥ���Ԫ�ء�
*/

void test03()
{
	list<int> L = list<int>();
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	L.push_back(50);
	printfListInt(L);

	//������+n  ֻ��������ʵ�����֧��
	//list�����ĵ�������˫�������
	//L.insert(L.begin() + 2,3,50); //error
	list<int>::iterator it = L.begin();
	//++  ������ʵ����� �Լ� ˫������� ��֧��
	it++; it++;
	L.insert(it, 3, 50);
	printfListInt(L);

	//remove(elem);// ɾ�������������� elem ֵƥ���Ԫ�ء�
	L.remove(50); //ɾ�����������е�Ԫ��50
	printfListInt(L);
}


/*
* 3.6.4.3 list ��С����
size();// ����������Ԫ�صĸ���
empty();// �ж������Ƿ�Ϊ��
resize(num);// ����ָ�������ĳ���Ϊ num ��
�������䳤������Ĭ��ֵ�����λ�á�
���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
resize(num, elem);// ����ָ�������ĳ���Ϊ num ��
�������䳤������ elem ֵ�����λ�á�
���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
*/

/*
* 3.6.4.4 list ��ֵ����
assign(beg, end);// �� [beg, end) �����е����ݿ�����ֵ������
assign(n, elem);// �� n �� elem ������ֵ������
list& operator=(const list &lst);// ���صȺŲ�����
swap(lst);// �� lst �뱾���Ԫ�ػ�����
*/


/*
* 3.6.4.5 list ���ݵĴ�ȡ
front();// ���ص�һ��Ԫ�ء�
back();// �������һ��Ԫ�ء�
*/

/*
* 3.6.4.6 list ��ת����
reverse();// ��ת�������� lst ���� 1,3,5 Ԫ�أ����д˷����� lst �Ͱ��� 5,3,1
Ԫ�ء�
sort(); //list ����(Ĭ�ϴ�С��������)
*/

void test04()
{
	list<int> L = list<int>();
	L.push_back(50);
	L.push_back(20);
	L.push_back(10);
	L.push_back(40);
	L.push_back(30);
	printfListInt(L);

	L.reverse();
	printfListInt(L);

	//sort��ϵͳ�ṩ���㷨 ��֧�� ������ʵ�����(��֧��list)
	//list��������ʹ��ϵͳ�㷨 list���Լ��ṩ�㷨
	//sort(L.begin(),L.end());
	L.sort(); 
	printfListInt(L);
}

int main(int argc, char* argv[])
{
	//test03();

	test04();

	return 0;
}