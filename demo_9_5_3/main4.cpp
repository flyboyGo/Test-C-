#include <iostream>

using namespace std;

//继承的动作  虚继承
//父类 ：虚基类
/* 语法格式
 *  class 子类 : virtual public 父类
 *  {
 *      ......
 *  }
 */

class animal
{
public:
    int data;
};
//sheep虚继承animal 其中animal是虚基类
class sheep : virtual public animal
{
public:

};
//camel虚继承animal 其中animal是虚基类
class camel : virtual public animal
{
public:

};

class alpaca :  public sheep, public camel
{
public:

};

/* vbptr(虚基类指针 vbptr指向虚基类表) 其中v是virtual虚拟 b是base基类 ptr指针
 * vbtable(虚基类表 虚基类表里面存放 的才是 data偏移量)
 * 总结: 之所以产生vbptr和vbtable 目的 保证不管多少个继承 虚基类的数据只有一份
 */

void test04()
{
    alpaca a = alpaca();
    a.data = 100;
    cout << a.data << endl;

    cout << sizeof(animal) << endl; //4
    cout << sizeof(sheep) << endl; // 8
    cout << sizeof(camel) << endl; // 8
    cout << sizeof(alpaca) << endl; // 12
}

int main(int argc, char *argv[])
{
    test04();

    return 0;
}
