#include <iostream>

using namespace std;

/*
 * 在c语言中,"分开来声明的,也就是说,语言本身并没有支持"数据"和"函数"之间的关联性我们把这种程序方法称为"程序性的",
   由一组“分布在各个以功能为导航的函数中”的算法驱动，它们处理的是共同的外部数据。

   c++实现了"封装",那么数据(成员属性)和操作(成员函数)是什么样的呢? "数据"和"处理数据的操作(函数)"是分开存储的。
   c++中的非静态数据成员直接内含在类对象中，就像 c struct 一样。
   成员函数(member function)虽然内含在 class 声明之内，却不出现在对象中。
   每一个非内联成员函数(non-inline member function)只会诞生一份函数实例.
 */

class Data
{
private :
    int num;
public :
    Data()
    {

    }
    Data(int num)
    {
        this->num = num;
    }

    Data(const Data &data)
    {
        this->num = data.num;
    }


    ~Data()
    {

    }

    int getNum()
    {
        return this->num;
    }

    //1. 当形参名和成员变量名一样时,this 指针可用来区分
    //形参名 与成员变量 相同
    void setNum(int num)
    {
        //形参num
        //成员num this->num
        //num = num; // 就近原则 形参num 赋值给 形参 num

        //将形参num 赋值给 对象中成员变量num
        this->num = num;
    }

};

void test01()
{
    Data d1;
    d1.setNum(10);
    cout << "d1.num : " << d1.getNum() << endl;

    Data d2;
    d2.setNum(20);
    cout << "d2.num : " << d2.getNum() << endl;

    Data d3;
    d3.setNum(30);
    cout << "d3.num : " << d3.getNum() << endl;
}

//C++的封装性：将数 和 方法 封装在一起
/*
 * 数据 和 方法 是分开存放的。
 * 每个对象 拥有独立的数据。
 * 每个对象 共享同一个方法。
 *
 * 普通成员变量 对象独有  静态成员变量 类拥有,对象共享
 * 成员函数(静态、非静态) 对象共享
 *
 * 当一个对象 调用setNum方法时 会在setNum方法中产生一个 this指针, 这个this指针指向所调用方法的对象
 */

//this指针的原理
/*
 * 通过上例我们知道，c++的数据和操作也是分开存储，并且每一个非内联成员函数、非静态成员函数(特指普通的成员函数)
 * 只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码
   那么问题是：这一块代码是如何区分那个对象调用自己的呢?
 */

/*
 * c++通过提供特殊的对象指针，this 指针，解决上述问题。this 指针指向被调用的
  成员函数所属的对象。 c++规定，this 指针是隐含在对象成员函数内的一种指
  针。当一个对象被创建后，它的每一个成员函数都含有一个系统自动生成的隐含指
  针 this，用以保存这个对象的地址，也就是说虽然我们没有写上 this 指针，编译
  器在编译的时候也是会加上的。因此 this 也称为“指向本对象的指针”，this 指针并
  不是对象的一部分，不会影响 sizeof(对象)的结果。 this 指针是 C++实现封装的一
  种机制，它将对象和该对象调用的成员函数连接在一起，在外部看来，每一个对象
  都拥有自己的函数成员。一般情况下，并不写 this，而是让系统进行默认设置。
  this 指针永远指向当前对象

  成员函数通过 this 指针即可知道操作的是那个对象的数据。This 指针是一种隐含
  指针，它隐含于每个类的非静态成员函数中。This 指针无需定义，直接使用即
  可。 注意：静态成员函数内部没有 this 指针，静态成员函数不能操作非静态成员变量
 */
/*
 * 注意:
 * 1、this 指针是隐含在对象成员函数内的一种指针
 * 2、this 指针指向被调用的成员函数的对象。
 * 3、成员函数通过 this 指针即可知道操作的是那个对象的数据
 * 4、This 指针是一种隐含指针，它隐含于每个类的非静态成员函数中
 * 5、This 指针无需定义，直接使用即可
 * 6、静态成员函数内部没有 this 指针，静态成员函数不能操作非静态成员变量(注意!!!!)
 *   (静态成员函数属于类 函数内部 没有this指针)
 */

class MyCout
{
public :
    //2. 通过this指针  返回对象本身的引用
    MyCout& myCout(char *str)
    {
        cout << str;
        return *this; //*this 代表的是 当前调用该函数的对象
    }
};

void test02()
{
    MyCout mc;

    mc.myCout("hello").myCout(" world").myCout(" again!");
}

int main(int argc, char *argv[])
{

    test01();

    //this指针的运用
    test02();

    return 0;
}
