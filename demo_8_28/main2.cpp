#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

//静态成员  static修饰的成员 静态变量  静态方法
/*
 * 在类定义中，它的成员(包括成员变量和成员函数),这些成员可以用关键字static 声明为静态的,称为静态成员。
   不管这个类创建了多少个对象,静态成员只有一个拷贝,这个拷贝被所有属于这个类的对象共享。
   静态成员 属于类 而不是对象
 */

/*
 * 静态变量，是在"编译阶段"就分配空间，对象还没有创建时，就已经分配空间。
   静态成员变量必须在 类中声明，在类外定义。
   静态数据成员不属于某个对象，在为对象分配空间中 "不包括" 静态成员所占空间。
   静态数据成员可以通过类名或者对象名来引用。
 */

class MyData
{
private :
    int num; //普通成员变量
public :
    static int data; //静态成员变量(类中声明、类外定义,静态成员的大小不包括在类的大小中)
    MyData()
    {
    }

    MyData(int a, int b)
    {
    }

    MyData(const MyData &md)
    {
    }

    ~MyData()
    {
    }
};

//定义时不需要再加static
int  MyData::data = 100; //类外定义+初始化

void test09()
{
    //data是静态成员变量 是属于类 可以通过类名称直接访问
     cout << MyData::data<< endl; // 100

    //赋值
     MyData::data = 200;
     cout << MyData::data<< endl; // 200

     cout << sizeof(MyData) << endl; //4 类的大小

     //data静态变量 是所有对象 共享的 可以通过对象名访问
     MyData md;
     cout << md.data << endl; // 200
     md.data = 300;
     cout << md.data << endl; // 300
     cout << MyData::data<< endl; // 300

     //普通对象成员变量 属于对象的 只能通过对象名访问
}



//int main(int argc, char * argv[])
//{
//    //静态成员变量详解
//    test09();

//    return 0;
//}
