#include <iostream>

using namespace std;

//1、多态的概述
/*
 * 多态是C++面向对象编程的特征之一
 * 多态的分类：静态多态(静态联编)、动态多态(动态联编)
 * 静态多态(静态联编)：函数的入口地址 是在 编译阶段 确定 (运算符重载、函数重载) 早绑定
 * 动态多态(动态联编)：函数的入口地址 是在 运行阶段 确定 (虚函数) 晚绑定
 */

//2、引入

class Animal
{
public:
    //虚函数 只要涉及到继承 子类中同名函数都是 虚函数
    //虚函数 本质 是一个函数指针变量
    virtual void sleep(void)
    {
        cout << "Animal 动物睡觉" << endl;
    }
};

class Cat:public Animal
{
public:

    virtual void sleep(void)
    {
        cout << "Cat 猫睡觉" << endl;
    }
};

void test01()
{
//    Cat cat = Cat();
//    cat.sleep();
//    cat.Animal::sleep();

    //用基类(指针或引用) 保存 子类对象 (向上转换)
    Animal *animal = new Cat;
    animal->sleep(); //调用的是基类的sleep

    Cat cat;
    Animal &animal2 = cat;
    animal->sleep(); //调用的是基类的sleep

    //用子类(指针或引用) 保存 基类对象 (向下转换) (不安全)
    //Cat *cat = new Animal; //error
    //cat->sleep();

    //总结:用基类指针、引用 只能访问 子类对象中 基类部分 数据
}


void test02()
{
    //需求：使用基类指针、引用 保存 子类对象 ，且可以访问、操作子类成员方法(虚函数)
    /*
     * 虚函数 使用virtual修饰成员函数 该成员函数就是虚函数。
     * 此时类中生成：vfptr、vftable
     * vfptr虚函数指针 指向的是虚函数表(vftable)
     * vftable表存放的是 虚函数所代表的函数入口地址
     */
    Animal *animal = new Cat;
    animal->sleep();
}

void test03()
{
    //虚函数 本质 是一个函数指针变量
    //1、如果 拥有虚函数的 Animal没有涉及到到继承 函数指针变量 就指向自身的sleep()
    Animal ob;
    ob.sleep();
}

void test04()
{
    //2、如果 拥有虚函数的 Animal涉及到到继承 函数指针变量 就指向子类中同名的sleep()
    Animal ob;
    ob.sleep();

    /*
     * 总结:
     * 当虚函数涉及到继承的时候 子类会 继承 父类的 (虚函数指针vfptr 虚函数表vftable).
     * 编译器会将虚函数入口地址 更新成子类 同名(返回值、参数都相同) 的函数地址
     * 如果基类指针、引用 访问虚函数的时候 就会 间接的调用 子类的虚函数
     */
}


//int main(int argc, char *argv[])
//{

//    //test01();

//    //test02();

//    //test03();

//    test04();

//    return 0;
//}
