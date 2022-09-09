#include <iostream>

using namespace std;

//C++的类型转换

//静态转换 static_cast
/*
 * 用于类层次结构中基类（父类）和派生类（子类）之间指针或引用的转换。
 * 进行上行转换（把派生类的指针或引用转换成基类表示）是安全的；
 * 进行下行转换（把基类指针或引用转换成派生类表示）时，由于没有动态类型检查，所以是不安全的。
 * 用于基本数据类型之间的转换，如把 int 转换成 char，把 char 转换成int。这种转换的安全性也要开发人员来保证
 */

class Animal{};
class Dog:public Animal{};
class Other{};

void test01()
{
    //static_cast 作用于 基本类型
    char ch = 'a';
    double d = static_cast<double>(ch);
    cout << d << endl;

    //static_cast 作用于 自定义类型(结构体 类)
    //关系的类之间(父、子类)
    //上行转换 安全
    Animal* ob =static_cast<Animal *> (new Dog);
    //下行转换 不安全
    Dog* ob2 = static_cast<Dog *>(new Animal);

    //static_cast 不能作用于 不相关的类之间转换
    //Animal * ob3 = static_cast<Animal *>(new Other); // error
    //Animal * ob3 = (Animal *)(new Other); //不报错 但非常危危险
}


//动态转换 dynamic_cast
/*
 * dynamiccast 主要用于类层次间的上行转换和下行转换；
 * 在类层次间进行上行转换时,dynamiccast 和 staticcast 的效果是一样的；
   在进行下行转换时，dynamiccast 具有类型检查的功能，比 static_cast 更安全；
 */
void test02()
{
    //1、dynamic_cast不支持基本数据类型
    //char ch = 'a';
    //double d = dynamic_cast<double>(ch); //error

    //2、dynamic_cast 上行转换 (父类指针 指向 子类空间 安全)
    Animal * p1 = dynamic_cast<Animal *>(new Dog);

    //3、dynamic_cast 下行转换 (子类指针 指向 父类空间 不安全)
    //Dog * p2 = dynamic_cast<Dog *>(new Animal); //不支持 不安全的转换

    //4、dynamic_cast 不支持 没有关系的 类型转换

}

//常量转换 const_cast
/*
 *  该运算符用来修改类型的 const 属性。
 *  常量指针被转化成非常量指针，并且仍然指向原来的对象；
    常量引用被转换成非常量引用，并且仍然指向原来的对象；

    注意:不能直接对非指针和非引用的变量使用 const_cast 操作符去直接移除它的const
 */

void test03()
{

    const int *p = NULL;
    int *p1 = const_cast<int *> (p);

    int *p2 = NULL;
    const int * p3 = const_cast<const int *>(p2);

    //const_cast 不支持 非指针、非引用的转换
    const int a = 100;
    //int b = const_cast<int>(a); //error

    int data = 100;
    //常引用 转换成 普通引用
    const int &ob = data;
    int &ob2 = const_cast<int &> (ob);
}


//重新解释转换(reinterpret_cast) 类似于 强制类型转换
/*
 * 这是最不安全的一种转换机制，最有可能出问题。
 * 主要用于将一种数据类型从一种类型转换为另一种类型。
 * 它可以将一个指针转换成一个整数，也可以将一个整数转换成一个指针.
 */

void test04()
{
    //不支持 基本数据类型
    float ch = 3.14f;
    //double d = reinterpret_cast<double>(ch); //error

    //没有关系的类之间的操作 允许操作
    Animal *p1 = reinterpret_cast<Animal *>(new Other); //非常危险的操作
}

int main(int argc, char *argv[])
{
    //test01();

    //test02();

    //test03();

    test04();

    return 0;
}
