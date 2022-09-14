#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

//ջ����
/*
* stack ��һ���Ƚ����(First In Last Out,FILO)�����ݽṹ����ֻ��һ�����ڣ���ʽ
��ͼ��ʾ��stack ������������Ԫ�أ��Ƴ�Ԫ�أ�ȡ��ջ��Ԫ�أ����ǳ������
�⣬û���κ������������Դ�ȡ stack ������Ԫ�ء�����֮��stack �������б���
��Ϊ�� ��Ԫ������ջ�Ĳ�����Ϊ:push,��Ԫ���Ƴ� stack �Ĳ�����Ϊ pop

* �Ƚ��ȳ������ݽṹ
* push��ջ��pop��ջ��top��Զָ��ջ��Ԫ��
* ջ����û�е�����(�ص㣡������)
*/

/*
* 3.4.3 stack ���� API
3.4.3.1 stack ���캯��
stack<T> stkT;//stack ����ģ����ʵ�֣� stack �����Ĭ�Ϲ�����ʽ��
3.4.3.2 stack ��ֵ����
3.4.3.3 stack ���ݴ�ȡ����
3.4.3.4 stack ��С����
*/
void test01()
{
	stack<int> s;
	//push(elem);// ��ջ�����Ԫ��
	s.push(10);
	s.push(20);
	s.push(30);

	//size();// ���ض�ջ�Ĵ�С
	//empty();// �ж϶�ջ�Ƿ�Ϊ��
	cout << "size = " << s.size() << endl;
	cout << "�Ƿ�Ϊ�� = " << s.empty() << endl;

	//pop();// ��ջ���Ƴ���һ��Ԫ��
	s.pop();

	//stack(const stack &stk);// �������캯��
	stack<int> s2 = stack<int>(s);

	//top();// ����ջ��Ԫ��
	cout << s2.top() << endl;

	//stack& operator=(const stack &stk);// ���صȺŲ�����
	stack<int> s3 = s2;
	cout << s3.top() << endl;
}

//int main(int argc, char* argv[])
//{
//	test01();
//
//	return 0;
//}