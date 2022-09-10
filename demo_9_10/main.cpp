#include <iostream>
#include <string.h>

using namespace std;

//�쳣�ĸ���
/*
 * �������쳣����0����������±�Խ�硢��Ҫ��ȡ���ļ������ڡ���ָ�롢�ڴ治��ȵȡ�
 * C++���쳣һ���׳� ��������� ���쳣 ����ֱ���˳�
 *
 * 1��C����ͨ������ֵ ���ж� ��һ��������� �ڶ������׺������������
 * 2��C++�׳��쳣 ������
 * �׳��쳣��throw
 * �����쳣��catch
 *
 * �쳣���ƺͺ������ƻ�������,���ǲ�׽��ʽ��ͨ���ϸ�����ƥ�䡣
 */

int myDiv(int a, int b)
{
    if(b == 0)
        throw 0.0;//�쳣
    return a/b;
}

void test01()
{
    try
    {
        int ret = myDiv(10,0);
        cout << "ret = " << ret << endl;
    }
    catch(int e)
    {
        cout << "����int���͵��쳣 e = " << e << endl;
    }
    catch(float) //�쳣��������ʡ��
    {
        cout << "����float���͵��쳣" << endl;
    }
    catch(char e)
    {
        cout << "����char���͵��쳣 e = " << e << endl;
    }
    catch(...)
    {
        cout << "�����������͵��쳣" << endl;
    }
}

//ջ����(unwinding)
/*
 * �쳣���׳��󣬴ӽ��� try ���𣬵��쳣������ǰ�����ڼ���ջ�Ϲ�������ж��󣬶��ᱻ�Զ�������
 * ������˳���빹���˳���෴����һ���̳�Ϊջ�Ľ���
 */

class Person
{
private:
    string name;
public:
    Person(string name)
    {
        this->name = name;
        cout << "Person " << name << "���캯��" << endl;
    }
    ~Person()
    {
        cout << "Person " << name << "��������" << endl;
    }
};

void testException(void)
{
    Person ob1("����");
    Person ob2("¬����");
    Person ob3("Ы��");
    Person ob4("����");
    throw 10;
}

void test02()
{
    try
    {
        testException();
    }
    catch(int)
    {
        cout << "�����쳣" << endl;
    }

    cout << "��������" << endl;
}

//�쳣�ӿ�����
/*
 * Ϊ�˼�ǿ����Ŀɶ��ԣ������ں����������г������׳��쳣���������ͣ�
 * ���磺void func() throw(A,B,C);������� func �ܹ���ֻ���׳����� A,B,C ���������͵��쳣��
      ����ں���������û�а����쳣�ӿ���������˺����������κ����͵��쳣��
   ����:void func() һ�������κ������쳣�ĺ���������Ϊ:void func() throw()
      ���һ���׳��������쳣�ӿ��������������׳����쳣,unexcepted �����ᱻ���ã�
      �ú���Ĭ����Ϊ���� terminate �����жϳ���
 */

void testException2()
{
    //�����ڲ������׳��κ��쳣
    //throw 10;
    //throw 3.14f;
    //throw "hello"; // char const * ����
}

void testException3() throw(int,char)
{
    //�����ڲ�ֻ���׳� �������쳣����,��������ж�
    //throw 10;
    //throw 'a';
    //throw "hello"; //error
}

void testException4() throw()
{
    //�����ڲ������׳��κ��쳣,��������ж�
    //throw 10;
}

void test03()
{
    try
    {
        testException4();
    }
    catch(int e)
    {
        cout << "����int���͵��쳣 e = " << e << endl;
    }
    catch(float) //�쳣��������ʡ��
    {
        cout << "����float���͵��쳣" << endl;
    }
    catch(char e)
    {
        cout << "����char���͵��쳣 e = " << e << endl;
    }
    catch(char const * e)
    {
        cout << "����char * ���͵��쳣 e = " << e << endl;
    }
}

//int main(int argc, char *argv[])
//{
//    //test01();

//    //test02();

//    test03();

//    return 0;
//}
