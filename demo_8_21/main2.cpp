#include <iostream>

using namespace std;

/*
 *��������(C++�Ķ�̬��һ������)
 * ��ô�� c++��Ҳ��һ�����Ƶ�������֣�ͬһ���������ڲ�ͬ�����¿��Ծ��в�ͬ�ĺ��塣
   �ڴ�ͳ c �����У�������������Ψһ�ģ������в��������ͬ���ĺ�����
   �� c++�����������ͬ���ĺ���,���������Ϊ�������ء�

   �������ص����壺����Ϊ�˷����ʹ�ú�������

   ʵ�ֺ������ص������� ͬһ�������� ����������ͬ �������Ͳ�ͬ ����˳��ͬ(���β����޹�)��

   ע�⣺��������ֵ���Ͳ���Ϊ�������ص�����
        �������غ�Ĭ�ϲ���һ��ʹ��,��Ҫ����ע�����������Ĳ���
 */

void myFunc(void)
{
    cout << "�޲� ��myFunc" << endl;
}
void myFunc(int a)
{
    cout << "int ��myFunc" << endl;
}
void myFunc(char a)
{
    cout << "char ��myFunc" << endl;
}
void myFunc(char a, int b)
{
    cout << "char��int ��myFunc" << endl;
}
void myFunc(int a, char b)
{
    cout << "int��char ��myFunc" << endl;
}

void test05()
{
    myFunc();      // �޲�
    myFunc(1);     // int
    myFunc('a');   // char
    myFunc(1,'a'); // int char
    myFunc('a',1); // char int
}
void myFunc02(int a)
{
    cout << "int��myFunc2" << endl;
}
void myFunc02(int a, int b = 10) // Ĭ�ϲ���
{
    cout << "int��int��myFunc2" << endl;
}

void test06()
{
    // myFunc02(int a) �� myFunc02(int a, int b = 10)����ʶ��
    //myFunc02(10); //�����Բ���
}

int main(int argc, char *argv[])
{
    test05();
    test06();
}
