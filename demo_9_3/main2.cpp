#include <iostream>

using namespace std;

class Person
{
private:
    int num;
public:
    Person(int num):num(num)
    {
        //this->num = num;
        cout << "�вι���num = " << num << endl;
    }

    void showPerson(void)
    {
        cout << "num = " << num << endl;
    }

    ~Person()
    {
        cout << "��������num = " << num << endl;
    }
};

void test04()
{
    Person p = Person(100);
    p.showPerson();

    Person *p2 = new  Person(100);
    p2->showPerson();
    //�Ӷ�������ռ�� ��Ҫ���ֶ�ͨ�� delete�ͷ��ڴ�ռ�
    delete p2;

}

//���һ������ָ�� ��� Person new���Ķ����ռ� �ͷſռ�
class SmartPointer
{
public:
    Person * pPerson;
public:
    SmartPointer(Person * p)
    {
        this->pPerson = p;
        cout << "�вι���"<< endl;
    }

    ~SmartPointer()
    {
        if(this->pPerson != NULL)
        {
            delete this->pPerson;
            this->pPerson = NULL;
        }
        cout << "��������"<< endl;
    }

    //��Ա���� ���� -> �����
    Person* operator->()
    {
       return this->pPerson;
    }

    //��Ա���� ���� * �����
    Person& operator*()
    {
        return *(this->pPerson);
    }
};

//����ָ��
void test05()
{
    //�����Զ��İ������ͷ� �ѿռ�(����ָ��ĸ���)
    SmartPointer pointer (new Person(200));

    //����Person���е�showPerson()
    //pointer.pPerson->showPerson();

    //��->���������
    //(pointer.operator ->())->showPerson();
    pointer->showPerson();

    //��*���������
    //(pointer.operator*()).showPerson();
    (*pointer).showPerson();

}

int main(int argc, char *argv[])
{
    //test04();

    test05();

    return 0;
}
