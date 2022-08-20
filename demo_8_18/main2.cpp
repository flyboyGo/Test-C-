#include <iostream>

using namespace std;

/////C++对结构体的增强、bool类型的增加、三目运算符的增强

struct stu
{
    int age;
    char name[32];

    //成员函数
    void walk(void)
    {
        cout << name << " 散步" << endl;
    }
};

void test02()
{
    //C++中可以不使用关键字struct
    struct stu li = {100, "李鹏飞"};
    stu jack = {100, "李鹏飞"};
    cout << "姓名: " << li.name << " 年龄: " << li.age << endl;
}

void test03()
{
    struct stu fly = {23,"flyboy"};
    fly.walk();
}

void test04()
{
     bool mybool;
     cout << "sizeof(bool)" << sizeof(mybool) << endl;
     mybool = true;
     cout << "mybool = " << mybool << endl; // 1

     mybool = false;
     cout << "mybool = " << mybool << endl; // 0

     mybool = -10;
     cout << "mybool = " << mybool << endl; // 1
}

void test05()
{
    int a = 10;
    int b = 20;
    cout << "c++中:%d = " << (a > b ? a : b) << endl;

    //a > b ? a : b整体结果是变量本身 左值 (可以被赋值)

    a > b ? a : b = 100; // b = 100;
}

//int main(int argc, char *argv[])
//{
//    //1、C中定义结构体需要使用struct关键字,C++中不需要使用
//    test02();

//    //2、C++中结构体中可以定义成员函数,C中只能定义成员变量
//    //C++调用成员函数
//    test03();

//    //3、bool类型增加
//        //标准c++的 bool_类型有两种内建的常量true(转换为整数1)和 false(转换为整数0)表示状态。
//        //这三个名字都是关键字。bool_类型只有两个值，true(1 值)，false(O值)
//        //bool_类型占1个字节大小给bool_类型赋值时，非О值会自动转换为true(1),0值会自动转换false(0)

//        //C语言在C99标准之前是没有bool关键字的,C99之后引入<stdbool.h>即可使用和C++一样的bool类型
//    test04();

//    //4、三目运算符功能更增强
//        //C语言中三目运算表达式返回值为变量的数据值,是数值,也为右值,不能被赋值
//        //C++语言中三目运算表达式返回值为变量本身(引用),为左值,可以被赋值
//    test05();
//    /*
//     *[左值和右值概念]在c++中可以放在赋值操作符左边的是左值，可以放到赋值操作符右面的是右值。
//     * 有些变量即可以当左值，也可以当右值。
//     * 左值为Lvalue，L代表 Location，表示内存可以寻址，可以赋值。
//     * 右值为Rvalue，R代表 Read,就是可以知道它的值。比如:int temp = 10;
//     * temp在内存中有地址，10没有，但是可Read到它的值
//     */

//    return 0;
//}
