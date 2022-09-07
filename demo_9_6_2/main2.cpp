#include <iostream>

using namespace std;

/*
 * 在设计时，常常希望基类仅仅作为其派生类的一个接口。
 * 这就是说，仅想对基类进行向上类型转换，使用它的接口，而不希望用户实际的创建一个基类的对象。
 * 同时创建一个纯虚函数允许接口中放置成员原函数，而不一定要提供一段可能对这个函数毫无意义的代码
 */
/*
 *  可以在基类中加入至少一个纯虚函数(pure virtual function),使得基类称为抽象类(abstract class).
 *  纯虚函数使用关键字 virtual，并在其后面加上=0。
 *  如果试图去实例化一个抽象类，编译器则会阻止这种操作。
 *  当继承一个抽象类的时候，必须实现所有的纯虚函数，否则由抽象类派生的类也是一个抽象类。
 *  Virtual void fun() = 0;告诉编译器在 vtable 中为函数保留一个位置，但在这个特定位置不放地址
 */


//抽象类 提供一个固定的流程 接口
class AbstractDrinking
{
public:
    virtual void Boil() = 0;
    virtual void Brew() = 0;
    virtual void PourInCup() = 0;
    virtual void PutSomething() = 0;

    //规定流程
    void MakeDrink()
    {
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};

class Coffee : public AbstractDrinking
{
public:
    virtual void Boil()
    {
        cout << "煮农夫山泉" << endl;
    }

    virtual void Brew()
    {
        cout << "泡咖啡" << endl;
    }

    virtual void PourInCup()
    {
        cout << "雀巢咖啡" << endl;
    }

    virtual void PutSomething()
    {
        cout << "加入糖" << endl;
    }
};

class Tea : public AbstractDrinking
{
public:
    virtual void Boil()
    {
        cout << "煮农夫山泉" << endl;
    }

    virtual void Brew()
    {
        cout << "泡茶" << endl;
    }

    virtual void PourInCup()
    {
        cout << "龙井茶叶" << endl;
    }

    virtual void PutSomething()
    {
        cout << "加入话梅" << endl;
    }
};

void DoBusiness(AbstractDrinking * drink)
{
    drink->MakeDrink();
    delete drink;
}

void test03()
{
    Coffee* c = new Coffee;
    DoBusiness(c);

    Tea* t = new Tea;
    DoBusiness(t);
}

/*
 * 接口类中只有函数原型定义，没有任何数据定义。
   多重继承接口不会带来二义性和复杂性问题。接口类只是一个功能声明，并不是功能实现，
   子类需要根据功能说明定义功能实现。 注意:除了析构函数外，其他声明都是纯虚函数
 */

//int main(int argc, char *argv[])
//{

//    test03();

//    return 0;
//}
