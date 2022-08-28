#include <iostream>

using namespace std;

class MyPlus
{
private :
    int num; //普通成员变量
public :
    const static int data; //静态成员变量(类中声明、类外定义,静态成员的大小不包括在类的大小中)

    //普通成员函数 调用 依赖于 对象
    int getData(void)
    {
        return data;
    }

    //静态成员函数  属于类 而不属于对象
    static int getStaticData(void)
    {
        //num = 200; //静态成员函数不能访问非静态成员变量
        return data;
    }
};

//定义时不需要再加static
//静态变量即使在类中声明为私有变量,但任然需要在类外被定义、初始化
const int MyPlus::data = 250; //类外定义+初始化

void test11()
{
    /*
     * 如果一个类的成员，既要实现共享，又要实现不可改变，那就用 static const 修饰。
     * 定义静态 const 数据成员时，最好在类内部初始化
     */
    cout << "静态成员常量 : " << MyPlus::getStaticData() << endl;

    //重新赋值
    //MyPlus::data = 120; //error const修饰data, data是只读的

}

int main(int argc, char * argv[])
{
    test11();
    return 0;
}
