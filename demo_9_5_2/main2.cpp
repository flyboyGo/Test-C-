#include <iostream>

using namespace std;

//5、父类、子类中的 "同名成员" 的处理

class Father
{
private:
    int num;
public:
    Father()
    {
        cout << "父类的无参构造" << endl;
    }

    Father(int num)
    {
        this->num = num;
        cout << "父类有参构造int" << endl;
    }

    ~Father(void)
    {
        cout << "父类析构函数" << endl;
    }

    //3、子类可以借助父类的公有方法 间接的操作 父类的私有数据(不可以地数据)
    int getNum(void)
    {
        return this->num;
    }

    void func(void)
    {
        cout << "父类中的void func" << endl;
    }

    void func(int a)
    {
        cout << "父类中的void func int" << endl;
    }

};

class Sons : public Father
{
private:
    int num;
public:
    Sons()
    {
        cout << "子类的无参构造" << endl;
    }

    Sons(int num,int num2):Father(num2)
    {
        this->num = num;
        cout << "子类的有参构造 int int" << endl;
    }
    ~Sons(void)
    {
        cout << "子类的析构函数" << endl;
    }

    void showNum(void)
    {
        //1、当父类和子类 成员变量同名时 在子类中是就近原则 选择的是本作用域的子类成员
        //2、如果在子类中 必须使用父类中同名成员 必须加上父类的作用域

        cout << "父类中的num = " << Father::getNum() << endl;
        cout << "子类中的num = " << this->num << endl;
    }

    //4、一旦子类 实现了 父类中的同名的成员函数 将会屏蔽所有父类同名成员函数
    void func(void)
    {
        cout << "子类类中的void func" << endl;
    }

    void func(int a)
    {
        cout << "子类中的void func int" << endl;
    }
};

void test03()
{
    Sons sons = Sons(10,20);
    sons.showNum();
}

void test04()
{
    //子类会继承父类中的所有成员变量、成员函数(构造和析构除外)
    //为什么构造和析构除外? 父类的构造、析构 只有父类自己知道该怎么做(构造、析构 系统会自动调用)

    //一旦子类 实现了 父类中的同名的成员函数 将会屏蔽所有父类中同名成员函数
    Sons sons = Sons(10,20);
    sons.func();
    sons.func(100);

    //如果用户 必须要调用父类 的同名函数 必须加作用域
    sons.Father::func();
    sons.Father::func(100);
}

int main(int argc, char *argv[])
{
    //test03();

    test04();

    return 0;
}
