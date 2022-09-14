#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

//��������
/*
* Queue ��һ���Ƚ��ȳ�(First In First Out,FIFO)�����ݽṹ�������������ڣ�
  queue���������һ������Ԫ�أ�����һ���Ƴ�Ԫ�ء�

  Queue ����Ԫ�صĽ�����������ϡ��Ƚ��ȳ�����������ֻ�� queue �Ķ���Ԫ�أ���
  �л��ᱻ���ȡ�á�Queue ���ṩ�������ܣ�Ҳ���ṩ��������
*/

/*
* 3.5.3 queue  ���� API

3.5.3.1 queue ���캯��
queue<T> queT;//queue ����ģ����ʵ�֣� queue �����Ĭ�Ϲ�����ʽ��
queue(const queue &que);// �������캯��

3.5.3.2 queue ��ȡ�������ɾ������
push(elem);// ����β���Ԫ��
pop();// �Ӷ�ͷ�Ƴ���һ��Ԫ��
back();// �������һ��Ԫ��
front();// ���ص�һ��Ԫ��

3.5.3.3 queue ��ֵ����
queue& operator=(const queue &que);// ���صȺŲ�����

3.5.3.4 queue ��С����
empty();// �ж϶����Ƿ�Ϊ��
size();// ���ض��еĴ�С
*/

void test02()
{
	queue<int> q = queue<int>();
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);

	cout << "�����Ƿ�Ϊ�գ�" << q.empty() << endl;
	cout << "���еĴ�С��" << q.size() << endl;

	cout << "��ͷԪ�أ�" << q.front() << endl;
	cout << "��βԪ�أ�" << q.back() << endl;

	cout << "��������" << endl;
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

//int main(int argc, char* argv[])
//{
//	test02();
//
//	return 0;
//}