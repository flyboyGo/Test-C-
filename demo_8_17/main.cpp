#include <iostream>

using namespace std;

///////////命名空间基础知识点

int a = 10; //全局变量
void test01()
{
    int a = 20;//局部变量
    cout << "局部变量a = " << a << endl; //优先选择性局部变量
    //局部变量的优先级较高,隐藏了全局变量
    //全局、局部同时存在,想要使用全局变量,C语言实现非常麻烦(使用变量的地址)

    // :: 作用域运算符(C++独有)
    cout << "全局变量a = " << ::a << endl; //使用全局变量
}

//定义一个名为A的命名空间(变量、函数)
namespace A
{
     int b = 30;
}
namespace B
{
     int b = 40;
}
//命名空间是全局的,命名空间中嵌套的命名空间也是全局的(注意!!!!)
namespace C
{
     int b = 1000;
     namespace D
     {
         int b = 2000;
     }
}
void test02()
{
    // cout << "b = " << b << endl; // 错误,未说明b归属的命名空间

    // A::a a是属于A中的数据
    cout << "b = " << A::b << endl;
    // B::a a是属于B中的数据
    cout << "b = " << B::b << endl;
    //如果想要使用命名空间中的数据,必须指明所归属的空间名称，无论他的命名是否唯一
}

void test03()
{
    cout << "C中的b = " << C::b << endl;
    cout << "D中的b = " << C::D::b <<endl;
}


namespace E
{
     int a = 100;
     int b = 200;
}
//如果命名空间E存在,将C添加到已有的命名空间E中
//如果命名空间E不存在,创建命名空间E,其中包含数据c
namespace  E
{
     int c = 300;
}
void test04()
{
      cout << "E中的c = " << E::c << endl;
}


namespace F
{
       int a = 10000;// 变量
       void func()//函数
       {
            cout << "func遍历a = " << F::a << endl;
            cout << "func遍历a = " << a << endl; //位于同一个命名空间中的成员，相会调用时可以不用声明归属的命名空间
       }
}

void test05()
{
    //变量的使用
    cout << "F中的a = " << F::a << endl;

    //函数的调用
    F::func();
}

namespace G
{
     int a = 10000;
     void func();
}

//命名空间中的成员函数(需要在所归属的命名空间中声明函数)
void G::func() //成员函数在外部定义的时候,必须加上作用域
{
       cout << "func遍历a = " << a << endl;
}

void test06()
{
    G::func();
}

//无名的命名空间
namespace
{
   int w = 30000;
}

namespace H
{
     int a = 500;
}

//int main(int argc, char *argv[])
//{
//    //1、::作用域运算符(表明 数据、方法的归属问题)
//    test01();

//    //2、命名空间出现的目的是解决命名冲突
//    //3、命名空间只能在全局范围内定义
//    test02();

//    //4、命名空间可以嵌套
//    test03();

//    //5、命名空间是开发的,随时可以吧新的成员加入已有的命名空间中(常用功能)
//    test04();

//    //6、命名空间不仅可以存放变量,还可以存放函数
//    test05();

//    //7、命名空间中的函数,可以在 "命名空间外部" 定义
//    test06();

//    //8、无名的命名空间,意味着命名空间中的标识符只能在 "本文件中" 访问,
//       //相当于给这个标识符加上一个 "static" ,使得其可以作为内部连接

//    cout << "无名空间中的w = " << w << endl;

//    //9、命名空间的别名
//    namespace otherH = H; //other为H的别名
//    cout << "使用H的别名otherH输出a = " << otherH::a << endl;

//    return 0;
//}
