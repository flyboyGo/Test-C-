#include <iostream>

using namespace std;

///////////命名空间详解

namespace veryLongName
{
     int b = 100;
     void func()
     {
         cout << "hello namespace" << endl;
     }
}

void test07()
{
    int b = 200; //局部变量a
    //cout << "b = " << veryLongNmae::b << endl;
    //veryLongNmae::func();

    //使用veryLongName命名空间，此位置以下的变量、函数,优先到命名空间中寻找
    using namespace veryLongName;

    //出现的变量,先从veryLongName命名空间中寻找,找不到,从其他地方寻找(局部变量、全局变量、std标准命名空间)
    //以下代码可能出现变量命名的冲突
    cout << "b = " << b << endl; //访问的是局部变量中的b(局部变量的优先级高于命名空间种的变量(命名空间属于全局))
    cout << "b = " << veryLongName::b << endl; //访问的是命名空间中的b
    func();
}


int b = 450; //全局变量
void test08()
{
    //int b = 450; //error
    //指明  使用命名空间的具体成员,容易和其他变量冲突(同名的局部变量)
    //直接使用命名空间中的成员会和局部变量冲突(不和全局变量冲突)
    using veryLongName :: b;
    cout << "命名空间中的b = " << b << endl;//优先选择命名空间中的成员
    cout << "全局变量b = " << ::b << endl;

    //但是调用命名空间的其他成员,仍然需要指明命名空间
    veryLongName::func();
}

namespace I
{
   //函数重载
   void func(){cout << "无参的func" << endl;}
   //func_void
   void func(int a){cout << "int的func" << endl;}
   //func_int
   void func(int a,int b){cout << "int int的func" << endl;}
   //func_int_int

   //C语言不支持函数重载,因为C语言中函数名代表的是函数入口地址
   //C++中 函数名 + 参数 组合代表的是函数的入口地址

   int d = 490;
}
void test09()
{
    //using指明 使用I中的func会对 "所有的func" 起作用
    using I::func;

    func();
    func(1);
    func(1,2);
}



namespace J
{
   int d = 370;
}
void test10()
{
    using namespace I;
    using namespace J;

    //不同的命名空间含有同名的成员变量,使用时注意产生二义性
    //cout << "d = " << d << endl;//'d' is ambiguous

    //解决方法
    cout << "I中的d = " << J::d << endl;
    cout << "J中的d = " << I::d << endl;
}

//int main(int argc, char *argv[])
//{
//    //using指明 使用某个命名空间
//    test07();

//    //using指明 使用某个命名空间的某个具体成员
//    test08();

//    //using指明重载函数
//    test09();

//    //不同命名空间中的 同名成员 使用的时候注意二义性
//    test10();

//    /*总结
//     * 1、命名空间的定义(不能在 函数内 定义命名空间)
//     * 2、使用命名空间中的成员 最安全的方式 命名空间名::成员名
//     * 3、using namespace 命名空间名; 使用整个命名空间
//     * 4、单独 使用命名空间中的具体成员: using 命名空间名::成员名
//     */

//    return 0;
//}
