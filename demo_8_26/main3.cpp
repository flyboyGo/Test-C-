#include <iostream>

using namespace std;

class MyData
{
private :
    int num;
public :
    MyData()
    {
        cout << "无参构造函数" << endl;
    }

    //该有参构造函数 不允许隐式转换
    explicit MyData(int data)
    {
        this->num = data;
        cout << "有参构造函数" << endl;
    }
    ~MyData()
    {
        cout << "析构函数" << endl;
    }
    void showNum(void)
    {
        cout << " num = " << num << endl;
    }
};

//int main(int argc, char *argv[])
//{
//    //C++提供了关键字 explicit，禁止通过构造函数进行的隐式转换。
//    // explicit 用于修饰构造函数,防止隐式转化。 是针对单参数的构造函数(或者除了第一个参数外其余参数都有默认值的多参构造)而言
//    //声明为 explicit 的构造函数不能在隐式转换中使用
//    //MyData md = 10; //MyData md(10) == > MyData md = MyData(10)

//    MyData md2 = MyData(10);
//    md2.showNum();

//    return 0;
//}
