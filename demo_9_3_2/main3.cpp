#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Fun
{
public:
    int my_add(int x, int y)
    {
        return x + y;
    }

    //����()����
    //��һ�� ()�����صķ��� �ڶ��� ()�Ǳ���Ҫ����
    int operator()(int x,int y)
    {
        return x + y;
    }
};

//��()����������� ��������
void test04()
{
    Fun fun = Fun();
    cout << fun.my_add(100,200) << endl;

    cout << fun.operator ()(100,200) << endl;
    //�Ż�fun��() ��� �ͻ��Զ�Ѱ��() �����
    cout << fun(100,200) << endl;
    //�˴�fun(100,200) ����һ�������ĺ��� ������һ���������()��� ����()�������������
    //fun���Ǻ����� ֻ�� fun(100,200) ����һ����������
    //���Խ�fun(100,200)���� "�º���"

    //�˴���Fun��������
    //Fun()��������
    cout << Fun()(100,200) << endl;//�ȼ��� ��������(100,200)

}


//��Ҫ����&&��||
//��Ϊ�û��޷�ʵ�� && ��||�Ķ�·����
//&&��·���ԣ� A && B ���AΪ�� B������ִ��
//||��·���ԣ� A && B ���AΪ�� B������ִ��



int main(int argc, char *argv[])
{
    test04();
    return 0;
}
