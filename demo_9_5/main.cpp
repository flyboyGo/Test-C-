#include <iostream>

using namespace std;

/*
 * c++最重要的特征是代码重用，通过继承机制可以利用已有的数据类型来定义新的
   数据类型，新的类不仅拥有旧类的成员，还拥有新定义的成员。 一个 B 类继承于
   A 类，或称从类 A 派生类 B。这样的话，类 A 成为基类（父类）， 类 B 成为派生
   类（子类）。 派生类中的成员，包含两大部分： 一类是从基类继承过来的，一类
   是自己增加的成员。 从基类继承过过来的表现其共性，而新增的成员体现了其个性。
 */

//继承或派生的格式
/*
 * 派生类定义格式：
     Class 派生类名 : 继承方式 基类名{
        派生类新增的数据成员和成员函数
     }

    三种继承方式： public ： 公有继承 private ： 私有继承 protected ： 保护继承

    从继承源上分：
    单继承：指每个派生类只直接继承了一个基类的特征
    多继承：指多个基类派生出一个派生类的继承关系,多继承的派生类直接继承了不止一个基类的特征
 */

/*注意点:
 * 派生类继承基类，派生类拥有基类中全部成员变量和成员方法（除了构造和析构之外的成员方法），
 * 但是在派生类中，继承的成员并不一定能直接访问，不同的继承方式会导致不同的访问权限
 */

//设置一个父类
class Base
{
public:
    int a;
private:
    int b;
protected:
    int c;
};

//设置一个子类(公共继承)
class Son:public Base
{
public:
    //父类中的public 数据在子类中 也是public
    //父类中的private 数据在子类中 是不可见的
    //父类中的protected 数据在子类中 是protected

    //子类的内部
    void setData(void)
    {
        this->a = 100; //类外部可以访问
        //this->b = 200; //error 不可见 子类外部无法访问
        this->c = 300; //类外部也无法访问
    }

};

void test01()
{
    //子类的外部
    Son son = Son();
    son.setData();

    cout << "a = " << son.a << endl;
    //cout << "b = " << son.b << endl;
    //cout << "c = " << son.c << endl;

}

/*
 * 总结： public继承
     父类中的public数据  在子类中 也是public
     父类中的private数据 在子类中 是不可见的
     父类中的protected数据 在子类中 是protected的
    （public 继承  父类中的私有数据 在子类 不可见 其他保持原样）
 */


//设置一个子类(保护继承)
class Son2:protected Base
{
    //父类中的public 数据在子类中 也是protected
    //父类中的private 数据在子类中 是不可见的
    //父类中的protected 数据在子类中 是protected
public:
    void setData(void)
    {
        this->a = 100; //类外部不可以访问
        //this->b = 200;//error 不可见 子类外部无法访问
        this->c = 300;//类外部不可以访问
    }
};

void test02(void)
{
    Son2 son = Son2();
    son.setData();

    //cout << "a = " << son.a << endl;
    //cout << "b = " << son.b << endl;
    //cout << "c = " << son.c << endl;
}

/*总结：  protected继承
    父类中的public数据  在子类中 也是protected
    父类中的private数据 在子类中 是不可见的
    父类中的protected数据 在子类中 是protected的
   （保护继承  父类的私有数据 在子类中 不可见  其他数据 都变保护）
 */


//设置一个子类(私有继承)
class Son3:private Base
{
    //父类中的public 数据在子类中 也是private
    //父类中的private 数据在子类中 是不可见的
    //父类中的protected 数据在子类中 是private
public:
    void setData(void)
    {
        this->a = 100; //类外部不可以访问
        //this->b = 200;//error 不可见 类外部无法访问
        this->c = 300;//类外部不可以访问
    }
};

void test03(void)
{
    Son3 son = Son3();
    son.setData();

    //cout << "a = " << son.a << endl;
    //cout << "b = " << son.b << endl;
    //cout << "c = " << son.c << endl;
}

/*
 * 总结： private私有继承
   父类中的public数据  在子类中 也是private
   父类中的private数据 在子类中 是不可见的
   父类中的protected数据 在子类中 是private的
  （私有继承  父类中的私有数据在子类中 不可见  其他变成私有）
 */

//int main(int argc, char *argv[])
//{
//    test01();

//    test02();

//    test03();

//    return 0;
//}
