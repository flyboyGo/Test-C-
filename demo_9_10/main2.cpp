#include <iostream>

using namespace std;

//异常变量的生命周期
/*
 *throw 的异常是有类型的，可以是数字、字符串、类对象。 throw 的异常是有类型的，catch 需严格匹配异常类型
 */

class MyException
{
public:
    MyException()
    {
        cout << "异常构造函数" << endl;
    }
    MyException(const MyException &ob)
    {
        cout << "异常拷贝构造" << endl;
    }
    ~MyException()
    {
        cout << "异常的析构" << endl;
    }
};

void test04(void)
{
    try
    {
        //MyException ob;
        //throw ob;

        throw new MyException;
    }
    catch(MyException e)
    {
        cout << "捕获到MyException异常" << endl;
    }
    catch(MyException * e)
    {
        cout << "捕获到MyException * 异常" << endl;

        delete e;
    }
}

/*
 * new指令从堆区申请空间 后调用构造函数完成内存空间初始化
 * 析构函数体的执行 是在delete指令释放指向的空间之前
 */

void test05()
{
    try
    {
//        MyException ob;
//        throw ob;

        throw MyException(); //抛出匿名对象 引用捕获  推荐使用
    }
    catch(MyException &e)
    {
        cout << "捕获到MyException &" << endl;
    }
}

//int main(int argc, char *argv[])
//{
//    //test04();

//    test05();

//    return 0;
//}
