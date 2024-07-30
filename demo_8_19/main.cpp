#include <iostream>

using namespace std;

////////////C++对const的增强

//支持C99的编译器中,可以使用变量定义数组

extern int num; //声明
void test01()
{
    /*
     *const修饰的全局变量 默认是内部链接(只在当前源文件有效 不能直接用于其他源文件)
     *const int num = 100;
     *如果必须用在其他源文 使用只读的全局变量 必须加extern将num转换成外部链接
     */
    cout << "全局num = " << num << endl;
}


const int w = 1000;
typedef struct Stu
{
    int age;
    char name[20];
}Stu;

void test02()
{
    ////C++中的const全局变量
    /*
     * c++中全局 const 当声明 extern 或者对 变量取地址时，编译器会分配存储地址，变量存储在只读数据段。
     * 两个都受到了  只读数据段 的保护,不可修改
     */

    //取地址
    int* pw = (int*)&w;
    //*pw = 3500; // error  变量存储在只读数据段。
    cout << "*pw = " << *pw << endl;
    cout << "w = " << w << endl;



    /////C++中的const的局部变量
    /*
     * 1、对于基础数据类型,也就是 const int data = 10 这种,编译器会把它放到符号表中,
     *    不分配内存。
     */
    const int data = 10;
    //data = 100; //error data只读
    cout << "data = " << data << endl;

    /*2、对于基础数据类型,也就是 const int data = 10 这种，
     *   编译器会把它放到符号表中,不分配内存,当对其取地址时,会分配内存空间。
     */
    int* p = (int*)&data;
    *p = 2000; // 内存空间内容修改成功!
    cout << "*p = " << *p << endl; //从空间中取值 2000

    cout << "data = " << data << endl;//从符号常量表中取值 data内存空间未修改 100

    /*
     *3、对于基础数据类型，如果用一个变量初始化const变量,如果 const int a = b,那么也是会给 a 分配内存空间。
     */
    int b = 100;
    const int a = b; //系统直接为const int a 开辟空间,此时a无符号表

    int* pa = (int*)&a;
    *pa = 3000;
    cout << "*pa = " << *pa << endl; // 3000
    cout << "a = " << a << endl; // 3000

    /*
     * 4、对于自定数据类型，比如类对象、结构体，那么系统也会分配内存
     */
     const Stu student = {23,"flyboy"};
     //student.age = 24; // error 不可以直接赋值
     cout << "student's age is " << student.age << ", name " << student.name << endl;
     Stu* pStu = (Stu*)&student;
     pStu->age = 24;
     cout << "student's age is " << student.age << ", name " << student.name << endl;

}

#define MAX 1024
const short my_max = 1024;

void func(short i)
{
    cout << "short函数" << endl;
}

void func(int i)
{
    cout << "int函数" << endl;
}

void test03()
{
    func(MAX); //int函数

    func(my_max); //short函数
}

void test04()
{
    //作用范围  是当前的符合语句(大括号内有效)
    const int my_num = 10;

    //作用范围 当前位置 到文件结束
    #define MY_NUM 10
}

namespace A
{
    //const可以作为成员
    const int my_a1 = 100;

    //my_a2属于文件(作用范围 当前位置 到文件结束),不属于命名空间A
    #define my_a2 200
}
void test05()
{
    cout << "my_a1 = " << A::my_a1 << endl;
    //cout << "my_a2 = " << A::my_a2 << endl; // error
    cout << "my_a2 = " << my_a2 << endl;
}

int main(int argc, char *argv[])
{
    test01();


    /*C语言中Const的详解
     * 常量的引进是在c++早期版本中，当时标准C规范正在制定。那时，尽管C委员会决定在C中引入const,
     * 但是，他们c中的const理解为"一个不能改变的普通变量"，也就是认为const应该是一个只读变量，
     * 既然是变量那么就会给const分配内存，并且在c 中const是一个 "只读变量",
     * c语言中 const修饰的 "全局只读变量" 是外部连接的。如果这么写:
     *
      *重点注意变量所在的内存是否可以进行相关操作(读、写)!!!!!!!!!
      *C语言的const修饰的全局变量,默认是(外部链接的),外部链接:其他源文件可以使用
      *C语言中const修饰变量名,说明变量名只读(用户不能通过变量名进行重新赋值),本质上是还是变量,只是具有常量的一些性质
      *但是如果知道只读变量名(局部,全局不可以)的地址,可以通过地址间接的修改变量名所对应的空间内容
      *(全局只读变量放在文字常量区,此区内存只读;局部只读变量,放在栈区,栈区的内存可读可写)
      *(全局变量放在全局区,此区可读可写;文字常量区与全局区严格是一个内存空间,由于可读性的原因,被分为两块)
      *(当全局变量被const修饰,它开的内存空间位置从全局区到文字常量区)
      *
      * 总结:
      * 1、const修改全局变量num 变量名只读 内存空间在文字常量区(只读)、不能通过num的地址修改内存空间的内容
      * 2、const修改局部变量data 变量名只读  内存空间栈区 (可读可写), 可以通过data地址 间接data地址 间接的修改内存空间的内容
      */


    /*C++中const的深入理解
     *在 c++中，一个 const 不必创建内存空间，而在 c 中，一个 const 总是需要一块内 存空间。
     *在 c++中，是否为 const 常量分配内存空间依赖于如何使用。
     * 一般说来， 如果一个 const 仅仅用来把一个名字用一个值代替(就像使用#define 一样)，那么该存储局空间就不必创建。
     * 如果存储空间没有分配内存的话，在进行完数据类型 检查后，为了代码更加有效，值也许会折叠到代码中。
     * 不过，取一个 const 地址, 或者把它定义为 extern,则会为该 const 创建内存空间。
     * 在 c++中，出现在所有函 数之外的 const 作用于当前文件(也就是说它在该文件外不可见)，默认为内部连接，
     * c++中其他的标识符一般默认为外部连接。
     */

    test02();

    /*
     * 尽量以const替代#define
     * const 和#define 区别总结:
     * 1．const 有类型，可进行编译器类型安全检查。 #define 无类型，不可进行类型检查.
     * 2．const 有作用域，而#define 不重视作用域,默认定义处到文件结尾.如果定义在指定作用域下有效的常量,那么#define就不能用。
     * 3. 宏常量不可以命名空间的成员
     */

    test03();
    test04();
    test05();

    return 0;
}

