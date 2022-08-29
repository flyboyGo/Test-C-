#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Data
{
private :
    static int count;
public :
    Data()
    {
        count++;
        cout << "�޲ι��캯��" << endl;
    }

    Data(const Data &data)
    {
        count++;
        cout << "�������캯��" << endl;
    }

    int getStaticCount()
    {
        return count;
    }

    ~Data()
    {
        count--;
        cout << "��������" << endl;
    }
};

int Data::count = 0;

//��̬��Ա���� ͳ�� ʵ��������� ����
void test01()
{
    Data d1;
    Data d2;
    cout << "����ĸ��� ��" << d1.getStaticCount() << endl;
    Data d3;
    Data d4;
    cout << "����ĸ��� ��" << d1.getStaticCount() << endl;
    Data d5 = d4;
    Data d6(d5);
    cout << "����ĸ��� ��" << d1.getStaticCount() << endl;
}

/*
 * ��̬��Աʵ�ֵ���ģʽ ����ģʽ��һ�ֳ��õ�������ģʽ��
 * �����ĺ��Ľṹ��ֻ����һ������Ϊ�����������ࡣ
 * ͨ������ģʽ���Ա�֤ϵͳ��һ����ֻ��һ��ʵ�����Ҹ�ʵ�����������ʣ��Ӷ������ʵ�������Ŀ��Ʋ���Լϵͳ��Դ��
   ���ϣ����ϵͳ��ĳ����Ķ���ֻ�ܴ���һ��������ģʽ����õĽ��������
 */

/*
 * Singleton�����������ڵ�������ڲ�ʵ��ֻ����һ����ͬʱ���ṩһ����̬�� getInstance()����������
   �ÿͻ����Է�������Ψһʵ����Ϊ�˷�ֹ���ⲿ����ʵ����������Ĭ�Ϲ��캯���Ϳ������캯�����Ϊ˽�У�
   �ڵ������ڲ�������һ��Singleton ���͵ľ�̬������Ϊ�ⲿ�����Ψһʵ����
 */
class Person
{
private:
    int age;
    char * name;
    //1������һ����̬�� ����ָ����� ����Ψһ��ʵ��
    static Person* singlePerson;
    static int count;
private:
    //3����ֹ ����ʵ������������ �����캯��ȫ�� ˽�л�
    Person()
    {
        cout << "�޲ι���" << endl;
    }

    Person(char * name, int age)
    {
        this->age = age;
        this->name = (char*)malloc(sizeof(strlen(name) + 1));
        strcpy(this->name,name);
        cout << "�вι��캯��" << endl;
    }

    Person(const Person &p)
    {
        this->name = (char*)malloc(sizeof(strlen(p.name) + 1));
        strcpy(this->name,p.name);
        this->age = p.age;
        cout << "�������캯��" << endl;
    }

public :
    //2���ṩһ����̬���� ��õ���ָ��
    static Person * getSinglePerson(void)
    {
        return singlePerson;
    }

    //���ܺ���
    void PrintCount(void)
    {
        this->count++;
        cout << "��ӡ������� :" << this->count << endl;
    }

    ~Person()
    {
        cout << "��������" << endl;
    }
};

Person * Person::singlePerson = new Person("flyboy",23);
int Person::count = 0;

void test02()
{
    Person * p = Person::getSinglePerson();
    p->PrintCount();
    p->PrintCount();
    Person * p2 = Person::getSinglePerson();
    p->PrintCount();
    p->PrintCount();
    p->PrintCount();
}

int main(int argc, char *argv[])
{

    //��̬��Ա������ʹ��ʵ��
    test01();

    //����ģʽ���(��Ҫ)
    test02();

    return 0;
}
