#include <iostream>

using namespace std;

///////////C++对语法的增强

//重复定义(C++中编译失败,C中可以编译成功)
//int a = 10; //已赋值 定义
//int a;      //同名 且未赋值 声明


//函数参数没有声明类型(C++中编译失败,C中可以编译成功)
//void func2(i)
//{
//    printf("i = %s\n", i);
//}


//C++严格的类型转换
enum COLOR
{
    green,
    red,
    yello
};

void test01()
{
    enum COLOR mycolor = green;
    printf("mycolor = %d\n", mycolor);// 0

    //mycolor = 10; //报错,非法声明
    printf("mycolor = %d\n", mycolor); // 0

    enum COLOR mycolor2 = red;
    printf("mycolor = %d\n", mycolor2); //  1

}

//int main(int argc, char *argv[])
//{
//    //1、C++语法检查增强
//    //重复声明
//    //int a = 10; //已赋值 定义
//    //int a;      //同名 且未赋值 声明

//    //2、C++中所有的变量和函数都必须有数据类型
//    //func2("hello");

//    //3、更严格的类型转换
//    test01();

//    return 0;
//}
