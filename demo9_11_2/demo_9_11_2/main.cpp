#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

class Fun
{
public:
    int myAdd(int x, int y)
    {
        return x + y;
    }

    //�غ�������()

    int operator()(int x, int y)
    {
        return x + y;
    }
};

void test01()
{
    Fun fun;
    cout << fun.myAdd(1, 3) << endl;

    cout << fun.operator ()(100, 300) << endl;

    //�Ż� fun��() ��� �ͻ��Զ�Ѱ��()�����
    cout << fun(1000, 3000) << endl;
    //�˴� fun(1000,3000) ����һ�������ĺ��� ����һ����������()��� ����()�������������
    //fun���Ǻ����� ֻ��fun(1000,2000) ������һ�������ĵ��� ���Խ�fun(1000,2000) ����������

    //�˴�Fun��������
    //Fun()��������
    cout << Fun()(100, 200) << endl;
}

//int main(int argc, char *argv[])
//{
//    test01();
//
//    return 0;
//}
