#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

class Fun
{
public:
    int myAdd(int x, int y)
    {
        return x + y;
    }

    //重函数调用()

    int operator()(int x, int y)
    {
        return x + y;
    }
};

void test01()
{
    Fun fun;
    cout << fun.myAdd(1, 3) << endl;

    cout << fun.operator ()(100, 300) << endl;

    //优化 fun和() 结合 就会自动寻找()运算符
    cout << fun(1000, 3000) << endl;
    //此处 fun(1000,3000) 不是一个真正的函数 而是一个对象名和()结合 调用()重载运算符而已
    //fun不是函数名 只是fun(1000,2000) 类似于一个函数的调用 所以将fun(1000,2000) 叫做防函数

    //此处Fun是类名称
    //Fun()匿名对象
    cout << Fun()(100, 200) << endl;
}

//int main(int argc, char *argv[])
//{
//    test01();
//
//    return 0;
//}
