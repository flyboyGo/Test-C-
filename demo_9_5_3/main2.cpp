#include <iostream>

using namespace std;

//��̳�
/*
 *�﷨��ʽ:
 * class ���� : �̳з�ʽ ������1 , �̳з�ʽ2 ������2 , ......
 * {
 *     ......
 * }
 * ��ʾ���� ���� ������1,������2,...��ͬ����������
 */

class Base1
{
public:
    int a;
    int b;
};

class Base2
{
public:
    int b;
};

class Son2:public Base1,public Base2
{
public:
    int c;
};

/*
 *��̳л����һЩ�����Ե����⣬ ���������������ͬ���ĺ������߱�������ô
  ͨ�����������ȥ����������������ʱ�Ͳ�����ȷ���׵��ôӻ���
  1���̳еİ汾���Ǵӻ��� 2���̳еİ汾��
  �������:���� ��ʾָ�� �����Ǹ�����İ汾
 */

void test02()
{
    Son2 son = Son2();
    son.a = 100;
    son.Base1::b = 200;
    son.Base2::b = 300;

    cout << son.a << " " << son.Base1::b << " " << son.Base2::b;
}


//int main(int argc, char *argv[])
//{
//    test02();

//    return 0;
//}
