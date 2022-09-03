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
        cout << "有参构造num = " << num << endl;
    }

    void showPerson(void)
    {
        cout << "num = " << num << endl;
    }

    ~Person()
    {
        cout << "析构函数num = " << num << endl;
    }
};

void test04()
{
    Person p = Person(100);
    p.showPerson();

    Person *p2 = new  Person(100);
    p2->showPerson();
    //从堆区申请空间后 需要我手动通过 delete释放内存空间
    delete p2;

}

//设计一个智能指针 解决 Person new出的堆区空间 释放空间
class SmartPointer
{
public:
    Person * pPerson;
public:
    SmartPointer(Person * p)
    {
        this->pPerson = p;
        cout << "有参构造"<< endl;
    }

    ~SmartPointer()
    {
        if(this->pPerson != NULL)
        {
            delete this->pPerson;
            this->pPerson = NULL;
        }
        cout << "析构函数"<< endl;
    }

    //成员函数 重载 -> 运算符
    Person* operator->()
    {
       return this->pPerson;
    }

    //成员函数 重载 * 运算符
    Person& operator*()
    {
        return *(this->pPerson);
    }
};

//智能指针
void test05()
{
    //需求：自动的帮我们释放 堆空间(智能指针的概念)
    SmartPointer pointer (new Person(200));

    //调用Person类中的showPerson()
    //pointer.pPerson->showPerson();

    //对->运算符重载
    //(pointer.operator ->())->showPerson();
    pointer->showPerson();

    //对*运算符重载
    //(pointer.operator*()).showPerson();
    (*pointer).showPerson();

}

int main(int argc, char *argv[])
{
    //test04();

    test05();

    return 0;
}
