#include <iostream>

using namespace std;

//非自动继承的函数
/*
 * 不是所有的函数都能自动从基类继承到派生类中。构造函数和析构函数用来处理对
   象的创建和析构操作，构造和析构函数只知道对它们的特定层次的对象做什么，也
   就是说构造函数和析构函数不能被继承，必须为每一个特定的派生类分别创建。
   另外  operator=(深拷贝) 也不能被继承，因为它完成类似构造函数的行为。也就是说尽管我
   们知道如何由=右边的对象如何初始化=左边的对象的所有成员，但是这个并不意
   味着对其派生类依然有效。 在继承的过程中，如果没有创建这些函数，编译器会自动生成它们。
 */

//继承中静态成员特性
/*
 * 静态成员函数和非静态成员函数的共同点:
   1. 他们 都可以 被继承到 派生类中。
   2. 如果重新定义一个静态成员函数，所有在基类中的其他重载函数会被隐藏。
   3. 如果我们改变基类中一个函数的特征，所有使用该函数名的基类版本都会被隐藏
 */

class Base
{
public:
    static int num;
    static int data;

    static void showData(void)
    {
        cout << "父类中的data = " << data << endl;
    }
};

int Base::num = 100;
int Base::data = 200;

class Son : public Base
{
public:
    static int data; //父类和子类 静态成员同名

    static void showData(void)
    {
        cout << "子类类中的data = " << data << endl;
    }
};

int Son::data = 300;


void test01()
{
    //从Base类中访问
    cout << Base::num << endl;

    cout << Son::num << endl;

    //父类 和 子类 静态成员变量同名 在子类中 访问子类中的静态成员变量(子类默认访问子类中的静态成员变量)
    cout << Son::data << endl;

    //父类 和 子类 静态成员变量同名 在子类中 访问父类中的静态成员变量
    cout << Son::Base::data << endl;

    //父类 和 子类 静态成员函数同名 在子类中 访问子类中的静态成员函数(子类默认访问子类中的静态成员函数)
    Son::showData();

    //父类 和 子类 静态成员函数同名 在子类中 访问父类中的静态成员函数
    Son::Base::showData();

}

//int main(int argc, char *argv[])
//{

//    test01();

//    return 0;
//}
