#include <iostream>

using namespace std;

//��ǰ����PersonPlus��
template <class T1,class T2>
class PersonPlus;

//��ǰ��������ģ�� ���߱�����printPersonPlus2����ģ���Ǵ��ڵ�
template<class T1,class T2>
void printPersonPlus2(PersonPlus<T1,T2> &ob);

template <class T1,class T2>
class PersonPlus
{
//1����Ԫ���������ж��� (��Ԫ�����ڸ���ĳ�Ա����)
    friend void printPersonPlus(PersonPlus<T1,T2> &ob)
    {
        cout << "name = " << ob.name << ", age = " << ob.age << endl;
    }
//2����Ԫ���������ⶨ�� ������߱����� ����Ԫ������ģ��
    friend void printPersonPlus2<>(PersonPlus<T1,T2> &ob);

private:
    T1 name;
    T2 age;
public:
    PersonPlus(T1 name,T2 age);
};

template<class T1, class T2>
PersonPlus<T1,T2>::PersonPlus(T1 name, T2 age)
{
    this->name = name;
    this->age = age;
}

//��Ԫ ����ģ��
template<class T1,class T2>
void printPersonPlus2(PersonPlus<T1,T2> &ob)
{
    cout << "name = " << ob.name << ", age = " << ob.age << endl;
}

int main(int argc, char* argv[])
{
    PersonPlus<string,int> ob("������",24);
    //ͨ����Ԫ ������ģ���е�����
    printPersonPlus(ob);
    printPersonPlus2(ob);

    return 0;
}


