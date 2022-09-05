#include <iostream>

using namespace std;

//2、子类、父类中的构造、析构的顺序
/*
 * 继承中的构造和析构 子类对象在创建时会首先调用父类的构造函数 父类构造函
   数执行完毕后，才会调用子类的构造函数 当父类构造函数有参数时，需要在子类初始化列
 */
class Base
{
private:
    int a;
    int data;
public:
    Base()
    {
        cout << "父类的无参构造函数" << endl;
    }
    Base(int a)
    {
        this->a = a;
        cout << "父类的int 有参构造函数" << endl;
    }
    Base(int a,int data)
    {
        this->a = a;
        this->data = data;
        cout << "父类的int int有参构造函数" << endl;
    }
    ~Base()
    {
        cout << "父类的析构函数" << endl;
    }
};

class Other
{
public:
    Other()
    {
        cout << "对象成员的构造函数" << endl;
    }
    ~Other()
    {
        cout << "对象成员的析构函数" << endl;
    }
};

class Son : public Base
{
private:
    Other other;//对象成员
    int b;
public:
    Son()
    {
        cout << "子类的无参构造函数" << endl;
    }
    Son(int b)
    {
        this->b = b;
         cout << "子类的int 有参构造函数" << endl;
    }

    //子类必须用 初始化列表 显式的调用父类的有参构造
    //调用形式: 父类名称(参数)
    Son(int a,int b,int c):Base(a,c),b(b)
    {
        //this->b = b;
        cout << "子类的int int int有参构造函数" << endl;
    }

    ~Son()
    {
        cout << "子类的析构函数" << endl;
    }


};

void test01()
{
    Son son = Son();
}

/*
 * 总结：子类、父类中的构造、析构的顺序
  构造顺序： 父类（基类）构造 ------> 子类（派生类）构造
  析构顺序：子类（派生类）析构------> 父类 (基类) 析构
 */


//3、总结：子类、父类、子类对象成员中的构造、析构的顺序
/*
 *构造顺序： 父类（基类）构造 ------> 对象成员构造 ------> 子类（派生类）构造
  析构顺序：子类（派生类）析构------> 对象成员析构 -------> 父类 (基类) 析构
 */

//4、实例化子类对象时,子类默认会间接的调用父类的无参构造;子类也可 显式的调用父类的 有参构造
void test02()
{
    //实例化子类对象时,子类默认会间接的调用父类的无参构造,如果父类没有无参构造,程序会报错
    Son son = Son(100);

    //子类中如何 显式的调用父类的 有参构造
    //子类必须用 初始化列表 显式的调用父类的有参构造
    Son son2 = Son(100,200,300);
}

//int main(int argc, char *argv[])
//{
//    //test01();

//    test02();

//    return 0;
//}
