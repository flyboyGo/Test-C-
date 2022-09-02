#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;
//��������صĸ���
/*
 * ��������أ����Ƕ����е���������½��ж��壬��������һ�ֹ��ܣ�����Ӧ��ͬ���������͡�
 * ��������ص�Ŀ�ģ��򻯲��� �����е������ ��Ӧ��ͬ����������
 * �﷨�������������ɹؼ��� operator�� �� "����" ����������
 * ���磺���� +������� ==> operator + ; ���� =������� ==> operator =
 * ע�⣺��������� ��Ҫ���� ������ı��ʲ��� (+�����ݵ���� ��Ҫ���س����ݵ����)
 */

//
class Person
{
//���ó���Ԫ����
friend ostream& operator<< (ostream &out, Person &person);
friend Person  operator+(Person &p1,Person &p2);

private:
    char *name;
    int num;
public:
    Person()
    {
        this->name = NULL;
        this->num = 0;
        cout << "�޲ι���" << endl;
    }

    Person(char *name, int num)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->num = num;
        cout << "�вι��캯��" << endl;
    }

    //��ͨ�ĳ�Ա����
    void printPerson()
    {
        cout << this->name << " " << this->num << endl;
    }

    //��Ա���� ������������ p1��this���� p2�ò�������
    Person operator+(Person &p2)
    {
        //num + num(��ֵ���)
        char *tmp_name = new char[strlen(this->name) + strlen(p2.name) + 1];
        strcpy(tmp_name, this->name);
        strcat(tmp_name, p2.name);

        //num + num(��ֵ���)
        int tmp_num = this->num + p2.num;
        Person tmp_person = Person(tmp_name, tmp_num);

        if(tmp_name != NULL)
        {
            delete [] tmp_name;
            tmp_name = NULL;
        }

        return tmp_person;
    }

    ~Person()
    {
        if(this->name != NULL)
        {
            delete [] this->name;
            this->name = NULL;
        }
        cout << "��������" << endl;
    }
};

//1��ȫ�ֺ�����Ϊ��Ԫ ������������<<
ostream& operator<< (ostream &out, Person &person) //out = cout, person = p
{
    //����ʵ�� �����ʽ
    out << person.name << " " << person.num << endl;

    //ÿ��ִ���� ����ֵ���Ϊout
    //����ֵΪ����
    return out;
}

void test01()
{
    Person p = Person("������", 24);
    //��ͨ�ĳ�Ա���� ������Ϣ
    p.printPerson();

    //coutĬ�������ʽ �޷�ʶ�� �Զ������ �����ʽ
    //cout << p << endl; //error
    //����������� ��Ҫ��������� <<

    //��������ص��÷�ʽһ
    operator<<(cout, p);

    //��������ص��÷�ʽ����
    //�Է�ʽһ�Ż� ȥ��operator,��һ������ ��������� << ����ߣ���һ������ ��������� << ���ұ�
    cout << p; //�ȼ��� operator<<(cout, p);

    //ȱ�ݣ��޷�����ʹ��
    //�Է�ʽ�����Ż� ���غ������з���ֵΪout����
    Person p2 = Person("flyboy", 23);
    cout << p  << p2;

}

//1.2��ȫ�ֺ�����Ϊ��Ԫ ������������+
Person operator+(Person &p1,Person &p2) //p1 p2
{
    //name + name (�ַ������)
    char *tmp_name = new char[strlen(p1.name) + strlen(p2.name) + 1];
    strcpy(tmp_name, p1.name);
    strcat(tmp_name, p2.name);

    //num + num(��ֵ���)
    int tmp_num = p1.num + p2.num;
    Person tmp_person = Person(tmp_name, tmp_num);

    if(tmp_name != NULL)
    {
        delete [] tmp_name;
        tmp_name = NULL;
    }

    return tmp_person;
}

void test02()
{
    Person p = Person("jack",18);
    Person p2 = Person("Nancy",16);
    cout << p ;
    cout << p2;

    Person p3 = operator+(p,p2);
    //�Ż���
    //Person p3 = p + p2;
    cout << p3 ;
}

//2����Ա���������������� +
void test03()
{
    Person p = Person("jack",18);
    Person p2 = Person("Nancy",16);
    Person p3 = p.operator+(p2);
    //�Ż���
    //Person p3 = p + p2;
    cout << p3;
}

int main(int argc, char *argv[])
{
    test01();

    test02();

    test03();

    return 0;
}
