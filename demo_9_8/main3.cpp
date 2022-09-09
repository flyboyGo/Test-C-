#include <iostream>

using namespace std;

//4、函数模板具体化

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
        cout << "构造函数" << endl;
    }
    ~Person(void)
    {
        cout << "析构函数" << endl;
    }

    // > 运算符重载(方法二)
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

//方法一：提供函数模板 具体化
template<> Person& myMax<Person>(Person &p1, Person &p2)
{
    return p1.a > p2.a ? p1 : p2;
}

//方法二：重载 > 运算符 使用成员函数


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
