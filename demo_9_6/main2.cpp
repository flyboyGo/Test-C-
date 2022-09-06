#include <iostream>

using namespace std;


//虚函数的应用案例(基类指针、引用 作为函数的参数)

class Base
{
public:
    virtual void sleep(void)
    {
        cout << "父类睡觉" << endl;
    }
};

class Son : public Base
{
public:
    virtual void sleep(void)
    {
        cout << "睡觉轻" << endl;
    }
};

class Son2 : public Base
{
public:
    virtual void sleep(void)
    {
        cout << "睡觉入打雷" << endl;
    }
};

class Son3 : public Base
{
public:
    virtual void sleep(void)
    {
        cout << "睡觉鼾声很重" << endl;
    }
};

class Son4 : public Base
{
public:
    virtual void sleep(void)
    {
        cout << "睡觉鼾声如战鼓" << endl;
    }
};

//已基类指针作为函数的参数 函数可以操作该基类派生出的任意子类对象
void sleepFun(Base &ob)
{
    ob.sleep();
}

void test05()
{
    Son son = Son();
    Son2 son2 = Son2();
    Son3 son3 = Son3();
    Son4 son4 = Son4();
    sleepFun(son);
    sleepFun(son2);
    sleepFun(son3);
    sleepFun(son4);
}

int main(int argc, char *argv[])
{
    test05();

    return 0;
}
