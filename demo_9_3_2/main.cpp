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
        cout << "无参构造函数" << endl;
    }

    Person(int a, int b):a(a),b(b)
    {
        cout << "有参构造" << endl;
    }

    void showPerson(void)
    {
        cout << "a = " << a << " b = " << b << endl;
    }

    ~Person()
    {
        cout << "析构函数" << endl;
    }
};

//前提1：如果类中没有指针成员 不需要重载=运算符(默认浅拷贝就可以完成)
//前提2：类中 有指针成员 必须重载 = 运算符
void test01()
{
    Person p = Person(10,20);
    p.showPerson();

    //注意 旧对象 给新对象赋值 调用默认拷贝构造函数(单纯的赋值为浅拷贝)
    Person p2 = p;
    p2.showPerson();

    Person p3;
    p3 = p; // 此处才是调用的=赋值运算符(默认赋值=运算符为浅拷贝)
    p3.showPerson();
}


//int main(int argc, char *argv[])
//{
//    test01();
//    return 0;
//}
