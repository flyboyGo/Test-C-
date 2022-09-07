#include <iostream>

using namespace std;

/*
 * �����ʱ������ϣ�����������Ϊ���������һ���ӿڡ�
 * �����˵������Ի��������������ת����ʹ�����Ľӿڣ�����ϣ���û�ʵ�ʵĴ���һ������Ķ���
 * ͬʱ����һ�����麯������ӿ��з��ó�Աԭ����������һ��Ҫ�ṩһ�ο��ܶ����������������Ĵ���
 */
/*
 *  �����ڻ����м�������һ�����麯��(pure virtual function),ʹ�û����Ϊ������(abstract class).
 *  ���麯��ʹ�ùؼ��� virtual��������������=0��
 *  �����ͼȥʵ����һ�������࣬�����������ֹ���ֲ�����
 *  ���̳�һ���������ʱ�򣬱���ʵ�����еĴ��麯���������ɳ�������������Ҳ��һ�������ࡣ
 *  Virtual void fun() = 0;���߱������� vtable ��Ϊ��������һ��λ�ã���������ض�λ�ò��ŵ�ַ
 */


//������ �ṩһ���̶������� �ӿ�
class AbstractDrinking
{
public:
    virtual void Boil() = 0;
    virtual void Brew() = 0;
    virtual void PourInCup() = 0;
    virtual void PutSomething() = 0;

    //�涨����
    void MakeDrink()
    {
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};

class Coffee : public AbstractDrinking
{
public:
    virtual void Boil()
    {
        cout << "��ũ��ɽȪ" << endl;
    }

    virtual void Brew()
    {
        cout << "�ݿ���" << endl;
    }

    virtual void PourInCup()
    {
        cout << "ȸ������" << endl;
    }

    virtual void PutSomething()
    {
        cout << "������" << endl;
    }
};

class Tea : public AbstractDrinking
{
public:
    virtual void Boil()
    {
        cout << "��ũ��ɽȪ" << endl;
    }

    virtual void Brew()
    {
        cout << "�ݲ�" << endl;
    }

    virtual void PourInCup()
    {
        cout << "������Ҷ" << endl;
    }

    virtual void PutSomething()
    {
        cout << "���뻰÷" << endl;
    }
};

void DoBusiness(AbstractDrinking * drink)
{
    drink->MakeDrink();
    delete drink;
}

void test03()
{
    Coffee* c = new Coffee;
    DoBusiness(c);

    Tea* t = new Tea;
    DoBusiness(t);
}

/*
 * �ӿ�����ֻ�к���ԭ�Ͷ��壬û���κ����ݶ��塣
   ���ؼ̳нӿڲ�����������Ժ͸��������⡣�ӿ���ֻ��һ�����������������ǹ���ʵ�֣�
   ������Ҫ���ݹ���˵�����幦��ʵ�֡� ע��:�������������⣬�����������Ǵ��麯��
 */

//int main(int argc, char *argv[])
//{

//    test03();

//    return 0;
//}
