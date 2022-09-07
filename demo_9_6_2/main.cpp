#include <iostream>

using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "animal����" << endl;
    }

    //�麯�� �����Ǻ���ָ�� ���漰�̳�ʱ ָ��������(sleep)

    //���麯��
    //1�����һ�������ɴ��麯�� ��ô����� ���ǳ�����;������һ����Ϊ���� ���ڱ��̳� ����չʹ��
    //2�������� ����ʵ��������
    virtual void sleep(void) = 0; //���麯��

    //����������
    virtual ~Animal()
    {
        cout << "animal����" << endl;
    }
};

class Cat : public Animal
{
public:
    Cat()
    {
        cout << "è�乹��" << endl;
    }

    //�麯�� �漰���̳� ָ��ָ�������sleep����
    virtual void sleep(void)
    {
        cout << "è��˯��" << endl;
    }

    virtual ~Cat()
    {
        cout << "è������" << endl;
    }
};

void test01()
{
    //ͨ�������ָ�롢���� ��������ĳ�Ա����
    Animal *p = new Cat;
    p->sleep();

    //���ֵ����⣺ֻ���ͷŸ������� �޷��ͷ����������
    //�������: ����������
    //���������ã�ͨ������ָ�롢�����ͷ���������пռ�
    //��������������������ǰ ��virtual����
    delete p;
    //delete p ���õ���������������� ��������� ϵͳ���Զ����� ��������
}

void test02()
{
    //Animal ������ ����ʵ��������
    //Animal ob; // error
}

//int main(int argc, char *argv[])
//{

//    test01();

//    return 0;
//}
