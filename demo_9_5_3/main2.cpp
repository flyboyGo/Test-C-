#include <iostream>

using namespace std;

//多继承
/*
 *语法格式:
 * class 子类 : 继承方式 父类名1 , 继承方式2 父类名2 , ......
 * {
 *     ......
 * }
 * 表示子类 是由 父类名1,父类名2,...共同派生出来的
 */

class Base1
{
public:
    int a;
    int b;
};

class Base2
{
public:
    int b;
};

class Son2:public Base1,public Base2
{
public:
    int c;
};

/*
 *多继承会带来一些二义性的问题， 如果两个基类中有同名的函数或者变量，那么
  通过派生类对象去访问这个函数或变量时就不能明确到底调用从基类
  1、继承的版本还是从基类 2、继承的版本？
  解决方法:就是 显示指定 调用那个基类的版本
 */

void test02()
{
    Son2 son = Son2();
    son.a = 100;
    son.Base1::b = 200;
    son.Base2::b = 300;

    cout << son.a << " " << son.Base1::b << " " << son.Base2::b;
}


//int main(int argc, char *argv[])
//{
//    test02();

//    return 0;
//}
