#include <iostream>

using namespace std;

//5�����ࡢ�����е� "ͬ����Ա" �Ĵ���

class Father
{
private:
    int num;
public:
    Father()
    {
        cout << "������޲ι���" << endl;
    }

    Father(int num)
    {
        this->num = num;
        cout << "�����вι���int" << endl;
    }

    ~Father(void)
    {
        cout << "������������" << endl;
    }

    //3��������Խ�������Ĺ��з��� ��ӵĲ��� �����˽������(�����Ե�����)
    int getNum(void)
    {
        return this->num;
    }

    void func(void)
    {
        cout << "�����е�void func" << endl;
    }

    void func(int a)
    {
        cout << "�����е�void func int" << endl;
    }

};

class Sons : public Father
{
private:
    int num;
public:
    Sons()
    {
        cout << "������޲ι���" << endl;
    }

    Sons(int num,int num2):Father(num2)
    {
        this->num = num;
        cout << "������вι��� int int" << endl;
    }
    ~Sons(void)
    {
        cout << "�������������" << endl;
    }

    void showNum(void)
    {
        //1������������� ��Ա����ͬ��ʱ ���������Ǿͽ�ԭ�� ѡ����Ǳ�������������Ա
        //2������������� ����ʹ�ø�����ͬ����Ա ������ϸ����������

        cout << "�����е�num = " << Father::getNum() << endl;
        cout << "�����е�num = " << this->num << endl;
    }

    //4��һ������ ʵ���� �����е�ͬ���ĳ�Ա���� �����������и���ͬ����Ա����
    void func(void)
    {
        cout << "�������е�void func" << endl;
    }

    void func(int a)
    {
        cout << "�����е�void func int" << endl;
    }
};

void test03()
{
    Sons sons = Sons(10,20);
    sons.showNum();
}

void test04()
{
    //�����̳и����е����г�Ա��������Ա����(�������������)
    //Ϊʲô�������������? ����Ĺ��졢���� ֻ�и����Լ�֪������ô��(���졢���� ϵͳ���Զ�����)

    //һ������ ʵ���� �����е�ͬ���ĳ�Ա���� �����������и�����ͬ����Ա����
    Sons sons = Sons(10,20);
    sons.func();
    sons.func(100);

    //����û� ����Ҫ���ø��� ��ͬ������ �����������
    sons.Father::func();
    sons.Father::func(100);
}

int main(int argc, char *argv[])
{
    //test03();

    test04();

    return 0;
}
