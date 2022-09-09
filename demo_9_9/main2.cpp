#include <iostream>
#include <string>

using namespace std;

//��ģ��ĳ�Ա��������������������ʵ��

//�ϸ���˵����ģ������� ����Person ����Person<T1,T2>
template<class T1,class T2> class Person
{
private:
    T1 name;
    T2 age;
public:
    //�������� ���ⶨ��
    Person(T1 name,T2 age);
    void showPerson(void);
    ~Person(void);
};

//���ⶨ��
template<class T1, class T2>
Person<T1,T2>::Person(T1 name, T2 age)
{
    cout << "�вι���" << endl;
    this->name = name;
    this->age = age;
}

template<class T1, class T2>
void Person<T1,T2>::showPerson()
{
    cout << "name = " << this->name << ", age = " << this->age << endl;
}

template<class T1, class T2>
Person<T1,T2>::~Person()
{
    cout << "��������" << endl;
}

void test04()
{
    Person<string,int> ob("������",24);
    ob.showPerson();

    Person<int,int> ob2(176,24);
    ob2.showPerson();
}

//int main(int argc, char *argv[])
//{
//    test04();

//    return 0;
//}
