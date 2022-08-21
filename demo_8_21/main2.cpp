#include <iostream>

using namespace std;

/*
 *函数重载(C++的多态的一个特性)
 * 那么在 c++中也有一种类似的现象出现，同一个函数名在不同场景下可以具有不同的含义。
   在传统 c 语言中，函数名必须是唯一的，程序中不允许出现同名的函数。
   在 c++中是允许出现同名的函数,这种现象称为函数重载。

   函数重载的意义：就是为了方便的使用函数名。

   实现函数重载的条件： 同一个作用域 参数个数不同 参数类型不同 参数顺序不同(与形参名无关)。

   注意：函数返回值类型不作为函数重载的依据
        函数重载和默认参数一起使用,需要额外注意二义性问题的产生
 */

void myFunc(void)
{
    cout << "无参 的myFunc" << endl;
}
void myFunc(int a)
{
    cout << "int 的myFunc" << endl;
}
void myFunc(char a)
{
    cout << "char 的myFunc" << endl;
}
void myFunc(char a, int b)
{
    cout << "char、int 的myFunc" << endl;
}
void myFunc(int a, char b)
{
    cout << "int、char 的myFunc" << endl;
}

void test05()
{
    myFunc();      // 无参
    myFunc(1);     // int
    myFunc('a');   // char
    myFunc(1,'a'); // int char
    myFunc('a',1); // char int
}
void myFunc02(int a)
{
    cout << "int的myFunc2" << endl;
}
void myFunc02(int a, int b = 10) // 默认参数
{
    cout << "int、int的myFunc2" << endl;
}

void test06()
{
    // myFunc02(int a) 和 myFunc02(int a, int b = 10)都能识别
    //myFunc02(10); //二义性产生
}

int main(int argc, char *argv[])
{
    test05();
    test06();
}
