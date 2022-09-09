#include <iostream>

using namespace std;

//4������ģ����廯

class Person
{
friend ostream& operator<<(ostream &out,Person &p);
public:
    int a;
    int b;
public:
    Person(int a,int b)
    {
        this->a = a;
        this->b = b;
        cout << "���캯��" << endl;
    }
    ~Person(void)
    {
        cout << "��������" << endl;
    }

    // > ���������(������)
    bool operator>(Person &ob)
    {
        return (this->a) > ob.a;
    }
};

ostream& operator<<(ostream &out,Person &p)
{
    out << "a = " << p.a << ", b = " << p.b;
}


template<typename T> T& myMax(T &a, T &b)
{
    return a > b ? a : b;
}

//����һ���ṩ����ģ�� ���廯
template<> Person& myMax<Person>(Person &p1, Person &p2)
{
    return p1.a > p2.a ? p1 : p2;
}

//������������ > ����� ʹ�ó�Ա����


void test06()
{
    int data1 = 10, data2 = 20;
    cout <<  myMax(data1,data2) << endl;

    Person p = Person(10,20);
    Person p2 = Person(20,30);

    cout << myMax(p,p2) << endl;
}


int main(int argc, char *argv[])
{
    test06();

    return 0;
}
