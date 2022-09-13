#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

//deque���� ˫�˶�̬����
/*
* Vector �����ǵ��򿪿ڵ������ڴ�ռ䣬deque ����һ��˫�򿪿ڵ��������Կ�
�䡣��ν��˫�򿪿ڣ���˼�ǿ�����ͷβ���˷ֱ���Ԫ�صĲ����ɾ����������
Ȼ��vector ����Ҳ������ͷβ���˲���Ԫ�أ���������ͷ������Ч�����޷�������

Deque ������ vector �������Ĳ��죬
һ���� deque ����ʹ�ó�����ʱ���ͷ�˽���Ԫ�صĲ����ɾ������(������Ϊ�������Ĵ�С �ı�������ĵ�ʱ��)��
������ deque û�������ĸ����Ϊ���Ƕ�̬���Էֶ������ռ���϶��ɣ���ʱ��������һ���µĿռ䲢��������

 Deque ����һ��һ�εĶ����������ռ乹�ɡ�һ���б�Ҫ�� deque ǰ�˻���β�������µĿռ䣬
 ������һ�����������Ŀռ䣬������deque ��ͷ�˻���β�ˡ�
 Deque ���Ĺ�������ά����Щ�ֶ��������ڴ�ռ�������Եļ��󣬲��ṩ�����ȡ�Ľӿڣ�
 �ܿ����������ÿռ䣬���ƣ��ͷŵ��ֻأ����۾��Ǹ��ӵĵ������ܹ���

 ��Ȼ deque �Ƿֶ������ڴ�ռ䣬��ô�ͱ�����������ƣ�ά�����������ļ���
 ���ݽṹ����Ƽ���������ǰ�����˲�����Ϊ������
 Deque �����ʵ��Զ�� vector �� list ����öࡣ 
 Deque ��ȡһ����ν��map(ע�⣬���� STL �� map ����)��Ϊ���أ�������ν�� map ��һС����������
 ��ռ䣬����ÿһ��Ԫ��(�˴���Ϊһ�����)����һ��ָ�룬ָ����һ���������ڴ�ռ䣬������������
 ���������� deque �Ĵ洢�ռ�����塣
*/


//deque������API

/*
* 3.3.3.1 deque ���캯��
deque<T> deqT;// Ĭ�Ϲ�����ʽ
deque(const deque &deq);// �������캯����
*/

void printfDequeInt(deque<int> &d)
{
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	//deque(n, elem);// ���캯���� n �� elem ����������
	deque<int> d = deque<int>(5, 10);
	printfDequeInt(d);

	//deque(beg, end);// ���캯���� [beg, end) �����е�Ԫ�ؿ���������
	deque<int> d2 = deque<int>(d.begin() + 1, d.end() - 1);
	printfDequeInt(d2);
}

/*
* 3.3.3.2 deque ��ֵ����
assign(beg, end);// �� [beg, end) �����е����ݿ�����ֵ������
swap(deq);// �� deq �뱾���Ԫ�ػ���
*/
void test02()
{
	//assign(n, elem);// �� n �� elem ������ֵ������
	deque<int> d = deque<int>();
	d.assign(6,7);
	printfDequeInt(d);

	//deque& operator=(const deque &deq); // ���صȺŲ�����
	deque<int> d2 = d;
	printfDequeInt(d);

	deque<int> d3 = deque<int>(5, 1);
	deque<int> d4 = deque<int>(5, 2);
	d3.swap(d4);
	printfDequeInt(d3);
	printfDequeInt(d4);
}


/*
* 3.3.3.3 deque ��С����
deque.size();// ����������Ԫ�صĸ���
deque.empty();// �ж������Ƿ�Ϊ��
deque.resize(num);// ����ָ�������ĳ���Ϊ num, �������䳤������Ĭ��ֵ�����λ�á�
                     ���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
deque.resize(num, elem); // ����ָ�������ĳ���Ϊ num, �������䳤������ elem ֵ�����λ�� , 
                            ���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
*/


/*
* 3.3.3.4 deque ˫�˲����ɾ������
*/

void test03()
{
	deque<int> d;

	//push_back(elem);// ������β�����һ������
	d.push_back(3);
	d.push_back(4);
	d.push_back(5);
	printfDequeInt(d);

	//push_front(elem);// ������ͷ������һ������
	d.push_front(2);
	d.push_front(1);
	printfDequeInt(d);

	//pop_back();// ɾ���������һ������
	d.pop_back();
	d.pop_back();
	printfDequeInt(d);

	//pop_front();// ɾ��������һ������
	d.pop_front();
	printfDequeInt(d);

	cout << "�����Ƿ�Ϊ�գ�" << d.empty() << endl; // 0

	cout << "�����Ĵ�С��" << d.size() << endl; // 0
}

/*
3.3.3.5 deque ���ݴ�ȡ
*/
void test04()
{
	deque<int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);
	d.push_back(5);
	printfDequeInt(d);

	//at(idx);// �������� idx ��ָ�����ݣ���� idx Խ�磬�׳� out_of_range ��
	cout << d.at(2) << endl;
	//operator[];// �������� idx ��ָ�����ݣ���� idx Խ�磬���׳��쳣��ֱ�ӳ���
	cout << d[3] << endl;
	//front();// ���ص�һ�����ݡ�
	cout << d.front() << endl;
	//back();// �������һ������
	cout << d.back() << endl;

	//���Խ��и�ֵ����
	d.at(2) = 4;
	d[3] = 3;
	d.front() = 5;
	d.back() = 1;
	printfDequeInt(d);
}

/*
3.3.3.6 deque �������
insert(pos,elem);// �� pos λ�ò���һ�� elem Ԫ�صĿ��������������ݵ�λ�á�
insert(pos,n,elem);// �� pos λ�ò��� n �� elem ���ݣ��޷���ֵ��
insert(pos,beg,end);// �� pos λ�ò��� [beg,end) ��������ݣ��޷���ֵ��
*/

void test05()
{
	deque<int> d;
	d.insert(d.begin(),1);
	d.insert(d.begin() + 1, 1, 2);
	d.insert(d.begin() + 2, d.begin(), d.end());
	printfDequeInt(d);
}

/*
3.3.3.7 deque ɾ������
clear();// �Ƴ���������������
erase(beg,end);// ɾ�� [beg,end) ��������ݣ�������һ�����ݵ�λ�á�
erase(pos);// ɾ�� pos λ�õ����ݣ�������һ�����ݵ�λ�á�
*/

void test06()
{
	deque<int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);
	d.push_back(5);
	printfDequeInt(d);
	d.erase(d.begin() + 1, d.end() - 1);
	printfDequeInt(d);
	d.erase(d.begin());
	printfDequeInt(d);
	d.clear();
	printfDequeInt(d);
}

//int main(int argc, char* argv[])
//{
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
//	test06();
//
//	return 0;
//}