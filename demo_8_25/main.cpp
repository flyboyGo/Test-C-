#include <iostream>

using namespace std;

//1、类的扩展知识
class Data //类有大小,但不分配空间
{
     private :
          //成员变量 占据类的大小
          int num; //4B
     public :
          //成员函数 不占据类的大小(不包括在当前类的大小中)
          void setNum(int data)
          {
              this->num = data;
          }
          int getNum()
          {
              return num;
          }

          //2、成员函数在 类中声明  类外定义
          void myPrintf(); //alt + enter 自动在类外部定义函数
};

//Data类的成员函数
void Data :: myPrintf()
{
    cout << num << endl;
}

void test01()
{

    printf("%d\n", sizeof(Data)); //4B

    Data data;
    data.setNum(100);
    data.myPrintf();
}

//3、类的定义在头文件 成员函数 位于源文件当中(采取分文件的方式)
#include "mydata.h"
void test02()
{
    myData md;
    md.setNum(200);
    cout << "num = " << md.getNum() << endl;
}

//4、构造函数和析构函数概述
/*
 * 构造函数和析构函数，这两个函数将会被编译器自动调用，完成对象初始化和对象清理工作。
   无论你是否喜欢，对象的初始化和清理工作是编译器强制我们要做的事情。
   注意:
   即使你不提供初始化操作和清理操作，编译器也会给你增加默认的操作，
   只是这个默认初始化操作不会做任何事，所以编写类就应该顺便提供初始化函数
 */
/*
 * 构造函数主要作用在于创建对象时为对象的成员属性赋值，构造函数由编译器自动调用,无须手动调用.
   析构函数主要用于对象销毁前系统自动调用，执行一些清理工作.
 */

//5、构造函数的定义
/*
 *  构造函数语法： 构造函数函数名和类名相同，没有返回值，不能有void，但可以有参数
 *  析构函数语法： 析构函数函数名在类名前加 " ~ ",没有返回值，不能有void，不能有参数，不能重载
 */
/*构造函数的分类
 *按参数分类: 分为无参构造函数、有参构造函数
 *按类型分类: 普通构造函数、拷贝构造函数(赋值构造函数)
 */

class DataPlus
{
     private :
        int num;
     public :
        //构造函数(无参)
        DataPlus()
        {
            num = 1;
            cout << "无参构造函数" << endl;
        }
        //构造重载
        //构造函数(有参数)
        DataPlus(int num)
        {
            this->num = num;
            cout << "有参构造函数" << endl;
        }

        //拷贝构造函数
        DataPlus(const DataPlus &ob) //自身类型对象的常引用
        {
            this->num = ob.num;
            cout << "拷贝构造函数" << endl;
        }

        void setNum(int num)
        {
            this->num = num;
        }
        int getNum()
        {
            return this->num;
        }

        //析构函数(没有返回值，不能有void，不能有参数，不能重载)
        ~DataPlus()
        {
            cout << "析构函数" << num << endl;
        }

};
void test03()
{
    //类实例化对象 系统自动调用构造函数、析构函数
    DataPlus dp;
    cout << "num = " << dp.getNum() << endl;

    //函数结束后 局部对象dp 被释放 系统自动调用析构
}

//6、构造函数的调用
void test04()
{
    //调用无参构造函数 或 默认构造 (隐式调用构造函数)
    DataPlus dp; //局部对象 位于 栈区！！！！！
    cout << "num = " << dp.getNum() << endl;

    //调用无参构造函数 (显式调用构造函数)
    DataPlus dp2 = DataPlus();
    cout << "num = " << dp2.getNum() << endl;

    //调用有参构造函数 (隐式调用构造函数)
    DataPlus dp3(2);
    cout << "num = " << dp3.getNum() << endl;

    //调用有参构造函数 (显式调用构造函数)
    DataPlus dp4 = DataPlus(3);
    cout << "num = " << dp4.getNum() << endl;

    //隐式转换的方式 调用有参构造函数(针对于 只有一个数据成员)(建议不要使用)
    DataPlus dp5 = 30; //转化为  DataPlus dp5 = DataPlus(30);
    cout << "num = " << dp5.getNum() << endl;

    //同一作用域下，构造函数执行的先后顺序 与 析构函数执行的先后顺序  相反(全局、局部对象都一致)

    //匿名对象(当前语句结束 匿名对象立即释放,在下一条语句执行之前)
    DataPlus();
    DataPlus(40);

}

//全局对象 位于 全局区
//全局对象实例化 早于 局部对象实例化
DataPlus dp6(100);
DataPlus dp7(200);

//7、拷贝构造函数的调用( 旧对象 初始化 新对象 才会调用拷贝构造函数)
void test05()
{
    DataPlus dp(500);
    cout << "dp.num = " << dp.getNum() << endl;

    //此时系统调用拷贝构造函数(如果用户 不实现拷贝构造函数 系统将调用默认的拷贝构造函数)
    //调用默认的拷贝构造函数:单纯的整体赋值(浅拷贝)
    //如果用实现了 拷贝构造函数 系统将调用用户实现的拷贝构造函数
    DataPlus dp2 = dp; // 等价于 DataPlus dp2 (dp);
    cout << "dp2.num = " << dp2.getNum() << endl;

    //拷贝构造函数不同的调用方式
    //1、隐式调用拷贝函数
    DataPlus dp3(dp);

    //2、现式调用拷贝函数
    DataPlus dp4 = DataPlus(dp);

    //3、=隐式转换调用
    DataPlus dp5 = dp;

}

void test06()
{
    DataPlus dp(370); //调用有参构造
    DataPlus dp2; //调用无参构造

    dp2 = dp; //单纯的对象赋值，不调用拷贝构造函数

    cout << dp.getNum() << endl;
    cout << dp2.getNum() << endl;
}

int main(int argc, char *argv[])
{
    //类的大小
    test01();

    //类的分文件定义
    test02();

    //构造函数和析构函数
    test03();

    //构造函数的不同调用方式
    test04();

    //拷贝构造函数
    test05();
    test06();

    return 0;
}

