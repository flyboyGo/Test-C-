#include <iostream>

using namespace std;


//�麯����Ӧ�ð���(����ָ�롢���� ��Ϊ�����Ĳ���)

class Base
{
public:
    virtual void sleep(void)
    {
        cout << "����˯��" << endl;
    }
};

class Son : public Base
{
public:
    virtual void sleep(void)
    {
        cout << "˯����" << endl;
    }
};

class Son2 : public Base
{
public:
    virtual void sleep(void)
    {
        cout << "˯�������" << endl;
    }
};

class Son3 : public Base
{
public:
    virtual void sleep(void)
    {
        cout << "˯����������" << endl;
    }
};

class Son4 : public Base
{
public:
    virtual void sleep(void)
    {
        cout << "˯��������ս��" << endl;
    }
};

//�ѻ���ָ����Ϊ�����Ĳ��� �������Բ����û����������������������
void sleepFun(Base &ob)
{
    ob.sleep();
}

void test05()
{
    Son son = Son();
    Son2 son2 = Son2();
    Son3 son3 = Son3();
    Son4 son4 = Son4();
    sleepFun(son);
    sleepFun(son2);
    sleepFun(son3);
    sleepFun(son4);
}

int main(int argc, char *argv[])
{
    test05();

    return 0;
}
