#include <iostream>
#include <string.h>

using namespace std;

//异常的概述
/*
 * 常见的异常：除0溢出、数组下标越界、所要读取的文件不存在、空指针、内存不足等等。
 * C++的异常一旦抛出 如果不捕获 该异常 程序直接退出
 *
 * 1、C语言通过返回值 来判断 第一：容易疏忽 第二：容易和正常结果混淆
 * 2、C++抛出异常 并捕获
 * 抛出异常：throw
 * 捕获异常：catch
 *
 * 异常机制和函数机制互不干涉,但是捕捉方式是通过严格类型匹配。
 */

int myDiv(int a, int b)
{
    if(b == 0)
        throw 0.0;//异常
    return a/b;
}

void test01()
{
    try
    {
        int ret = myDiv(10,0);
        cout << "ret = " << ret << endl;
    }
    catch(int e)
    {
        cout << "捕获到int类型的异常 e = " << e << endl;
    }
    catch(float) //异常变量可以省略
    {
        cout << "捕获到float类型的异常" << endl;
    }
    catch(char e)
    {
        cout << "捕获到char类型的异常 e = " << e << endl;
    }
    catch(...)
    {
        cout << "捕获到其他类型的异常" << endl;
    }
}

//栈解旋(unwinding)
/*
 * 异常被抛出后，从进入 try 块起，到异常被抛掷前，这期间在栈上构造的所有对象，都会被自动析构。
 * 析构的顺序与构造的顺序相反，这一过程称为栈的解旋
 */

class Person
{
private:
    string name;
public:
    Person(string name)
    {
        this->name = name;
        cout << "Person " << name << "构造函数" << endl;
    }
    ~Person()
    {
        cout << "Person " << name << "析构函数" << endl;
    }
};

void testException(void)
{
    Person ob1("德玛");
    Person ob2("卢锡安");
    Person ob3("蝎子");
    Person ob4("皇子");
    throw 10;
}

void test02()
{
    try
    {
        testException();
    }
    catch(int)
    {
        cout << "捕获到异常" << endl;
    }

    cout << "其他工作" << endl;
}

//异常接口声明
/*
 * 为了加强程序的可读性，可以在函数声明中列出可能抛出异常的所有类型，
 * 例如：void func() throw(A,B,C);这个函数 func 能够且只能抛出类型 A,B,C 及其子类型的异常。
      如果在函数声明中没有包含异常接口声明，则此函数可以抛任何类型的异常，
   例如:void func() 一个不抛任何类型异常的函数可声明为:void func() throw()
      如果一个抛出了它的异常接口声明所不允许抛出的异常,unexcepted 函数会被调用，
      该函数默认行为调用 terminate 函数中断程序
 */

void testException2()
{
    //函数内部可以抛出任何异常
    //throw 10;
    //throw 3.14f;
    //throw "hello"; // char const * 类型
}

void testException3() throw(int,char)
{
    //函数内部只能抛出 声明的异常类型,否则程序中断
    //throw 10;
    //throw 'a';
    //throw "hello"; //error
}

void testException4() throw()
{
    //函数内部不能抛出任何异常,否则程序中断
    //throw 10;
}

void test03()
{
    try
    {
        testException4();
    }
    catch(int e)
    {
        cout << "捕获到int类型的异常 e = " << e << endl;
    }
    catch(float) //异常变量可以省略
    {
        cout << "捕获到float类型的异常" << endl;
    }
    catch(char e)
    {
        cout << "捕获到char类型的异常 e = " << e << endl;
    }
    catch(char const * e)
    {
        cout << "捕获到char * 类型的异常 e = " << e << endl;
    }
}

//int main(int argc, char *argv[])
//{
//    //test01();

//    //test02();

//    test03();

//    return 0;
//}
