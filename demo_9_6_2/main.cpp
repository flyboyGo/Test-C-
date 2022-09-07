#include <iostream>

using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "animal构造" << endl;
    }

    //虚函数 本质是函数指针 不涉及继承时 指向自身函数(sleep)

    //纯虚函数
    //1、如果一个类中由纯虚函数 那么这个类 就是抽象类;抽象类一般作为基类 用于被继承 作扩展使用
    //2、抽象类 不能实例化对象
    virtual void sleep(void) = 0; //纯虚函数

    //虚析构函数
    virtual ~Animal()
    {
        cout << "animal析构" << endl;
    }
};

class Cat : public Animal
{
public:
    Cat()
    {
        cout << "猫咪构造" << endl;
    }

    //虚函数 涉及到继承 指针指向子类的sleep函数
    virtual void sleep(void)
    {
        cout << "猫咪睡觉" << endl;
    }

    virtual ~Cat()
    {
        cout << "猫咪析构" << endl;
    }
};

void test01()
{
    //通过基类的指针、引用 访问子类的成员函数
    Animal *p = new Cat;
    p->sleep();

    //出现的问题：只能释放父类析构 无法释放子类的析构
    //解决方法: 虚析构函数
    //虚析构作用：通过基类指针、引用释放子类的所有空间
    //虚析构：在虚析构函数前 加virtual修饰
    delete p;
    //delete p 调用的是子类的析构函数 子类调用完 系统会自动调用 父类析构
}

void test02()
{
    //Animal 抽象类 不能实例化对象
    //Animal ob; // error
}

//int main(int argc, char *argv[])
//{

//    test01();

//    return 0;
//}
