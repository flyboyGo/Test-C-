#include <iostream>

using namespace std;

//�쳣��������������
/*
 *throw ���쳣�������͵ģ����������֡��ַ���������� throw ���쳣�������͵ģ�catch ���ϸ�ƥ���쳣����
 */

class MyException
{
public:
    MyException()
    {
        cout << "�쳣���캯��" << endl;
    }
    MyException(const MyException &ob)
    {
        cout << "�쳣��������" << endl;
    }
    ~MyException()
    {
        cout << "�쳣������" << endl;
    }
};

void test04(void)
{
    try
    {
        //MyException ob;
        //throw ob;

        throw new MyException;
    }
    catch(MyException e)
    {
        cout << "����MyException�쳣" << endl;
    }
    catch(MyException * e)
    {
        cout << "����MyException * �쳣" << endl;

        delete e;
    }
}

/*
 * newָ��Ӷ�������ռ� ����ù��캯������ڴ�ռ��ʼ��
 * �����������ִ�� ����deleteָ���ͷ�ָ��Ŀռ�֮ǰ
 */

void test05()
{
    try
    {
//        MyException ob;
//        throw ob;

        throw MyException(); //�׳��������� ���ò���  �Ƽ�ʹ��
    }
    catch(MyException &e)
    {
        cout << "����MyException &" << endl;
    }
}

//int main(int argc, char *argv[])
//{
//    //test04();

//    test05();

//    return 0;
//}
