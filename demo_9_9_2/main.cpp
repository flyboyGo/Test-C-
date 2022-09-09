#include "person.hpp"

//include��׼�ǰ���ͷ�ļ� �����ϲ������.cpp

using namespace std;

//��ģ���ͷ�ļ���Դ�ļ��ķ�������
void test01()
{
    //��ģ�� �ᾭ�����α���
    //��һ�α��� ��ģ�� ������롢�ڶ��α��� ��ģ��ĳ�Ա���õ�ʱ��
    //c++/c �����ļ�����
    //��ģ���.cpp �� .h���ļ� �����ԭ�� �ڵڶ��α���
    //����.cpp��.h ����һ��  �ļ����͸���Ϊ .hpp

    Person<string,int> ob("������",24);
    ob.showPerson();
}

#include "myarray.hpp"

//��Ż�������
void test02()
{
    MyArray<char> ob(5);
    ob.PushBack('h');
    ob.PushBack('e');
    ob.PushBack('l');
    ob.PushBack('l');
    ob.PushBack('o');
    ob.PrintArray();
    ob.PushBack('!');
    ob.PrintArray();

    MyArray<int> ob2(3);
    ob2.PushBack(123);
    ob2.PushBack(456);
    ob2.PushBack(678);
    ob2.PrintArray();
    ob2.PushBack(910);
    ob2.PrintArray();
}

class MyPerson
{
friend ostream& operator<<(ostream &out, MyPerson &ob);
private:
    string name;
    int age;
public:
    MyPerson()
    {
    }

    MyPerson(string name, int age)
    {
        this->name = name;
        this->age =age;
    }
};
ostream& operator<<(ostream &out, MyPerson &ob)
{
    out << "name = " << ob.name << ", age = " << ob.age;
}

//����Զ�������
void test03()
{
    MyArray<MyPerson> ob(3);
    ob.PushBack(MyPerson("����",25));
    ob.PushBack(MyPerson("Ы��",400));
    ob.PushBack(MyPerson("����",45));
    ob.PrintArray();
    ob.PushBack(MyPerson("����",37));
    ob.PrintArray();
}

//int main(int argc, char *argv[])
//{
//    //test01();

//    //test02();

//    test03();

//    return 0;
//}
