#include <iostream>

using namespace std;

class Person
{
private:
    int a;
    int b;
public:
    Person()
    {
        cout << "�޲ι��캯��" << endl;
    }

    Person(int a, int b):a(a),b(b)
    {
        cout << "�вι���" << endl;
    }

    void showPerson(void)
    {
        cout << "a = " << a << " b = " << b << endl;
    }

    ~Person()
    {
        cout << "��������" << endl;
    }
};

//ǰ��1���������û��ָ���Ա ����Ҫ����=�����(Ĭ��ǳ�����Ϳ������)
//ǰ��2������ ��ָ���Ա �������� = �����
void test01()
{
    Person p = Person(10,20);
    p.showPerson();

    //ע�� �ɶ��� ���¶���ֵ ����Ĭ�Ͽ������캯��(�����ĸ�ֵΪǳ����)
    Person p2 = p;
    p2.showPerson();

    Person p3;
    p3 = p; // �˴����ǵ��õ�=��ֵ�����(Ĭ�ϸ�ֵ=�����Ϊǳ����)
    p3.showPerson();
}


//int main(int argc, char *argv[])
//{
//    test01();
//    return 0;
//}
