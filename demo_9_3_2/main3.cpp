#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Fun
{
public:
    int my_add(int x, int y)
    {
        return x + y;
    }

    //重载()符号
    //第一个 ()是重载的符号 第二个 ()是表明要传参
    int operator()(int x,int y)
    {
        return x + y;
    }
};

//对()运算符的重载 、防函数
void test04()
{
    Fun fun = Fun();
    cout << fun.my_add(100,200) << endl;

    cout << fun.operator ()(100,200) << endl;
    //优化fun和() 结合 就会自动寻找() 运算符
    cout << fun(100,200) << endl;
    //此处fun(100,200) 不是一个真正的函数 仅仅是一个对象民和()结合 调用()重载运算符而已
    //fun不是函数名 只是 fun(100,200) 类似一个函数调用
    //所以将fun(100,200)叫做 "仿函数"

    //此处的Fun是类名称
    //Fun()匿名对象
    cout << Fun()(100,200) << endl;//等价于 匿名对象(100,200)

}


//不要重载&&、||
//因为用户无法实现 && 、||的短路特性
//&&短路特性： A && B 如果A为假 B将不会执行
//||短路特性： A && B 如果A为真 B将不会执行



int main(int argc, char *argv[])
{
    test04();
    return 0;
}
