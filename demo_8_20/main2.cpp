#include <iostream>

using namespace std;

void test07()
{
    int data = 10;
    int &a = data; //a就是data的别名
    //编译器内存转换: int * const a = &data;

    a = 100; // 等价于 data = 100
    //*a = 100; //*a == data
}

#include <stdlib.h>
#include <string.h>
//C语言方式
void myStr(char** pStr) //pStr = &str
{
    *pStr = (char*)malloc(sizeof(char)*20);
    strcpy(*pStr,"hello world");
    return;
}
//C++方式
void myStr2(char* &my_str) // char* &my_str = str; my_str等价于str
{
    my_str = (char*)malloc(sizeof(char)*20);
    strcpy(my_str,"hello world");
    return;
}

void test08()
{
    char *str = NULL;
    //需求,封装一个函数 从堆区 给str申请一个空间 并赋值为 "hello wolrd"
    //myStr(&str);
    myStr2(str);
    cout << "str = " << str << endl;
    free(str);
    str = NULL;
}


typedef struct
{
    int age;
    char name[32];
}STU;

void myPrintStu(STU tmp) //普通结构体变量作为形参 开销太大
{
    cout << "姓名: " << tmp.name << " 年龄: " << tmp.age << endl;
}
//常引用,无法更改引用指向的数据，保证数安全
void myPrintStuPlus(const STU &tmp) //STU &tmp = stu; tmp是stu的别名 tmp没有开辟独立空间
{
    //tmp.age = 100; // read-only
    cout << "姓名: " << tmp.name << " 年龄: " << tmp.age << endl;
}

void test09()
{
    STU stu = {23, "lucy"};

    //需求定义一个函数 遍历stu
    //myPrintStu(stu);
    myPrintStuPlus(stu);

}

void test10()
{
    //给常量10取别名 为num
    //int & 针对的是int, 10是const int类型
    //int &num = 10;
    //const int & 针对的是const int, 10是const int类型
    const int &num = 10;

    cout << "num = " << num << endl;
}

int main(int argc, char *argv[])
{
    /* 引用的本质
     * 引用的本质在c++内部实现是一个常量指针. Type& ref = val; // Type* const ref = &val
     * c++编译器在编译过程中使用常量指针作为引用的内部实现，
     * 因此引用所占用的空间大小与指针相同，只是这个过程是编译器内部实现，用用户不可见
     */
    test07();

    //指针的引用
    test08();


    //常引用(常量引用)
    /*
     * [const 引用使用场景] 常量引用主要用在函数的形参，尤其是类的拷贝/复制构造
       函数。 将函数的形参定义为常量引用的好处: 引用不产生新的变量，减少形参与实
       参传递时的开销。 由于引用可能导致实参随形参改变而改变，将其定义为常量引
       用可以消除这种副作用。 如果希望实参随着形参的改变而改变，那么使用一般的
       引用，如果不希望实参随着形参改变，那么使用常引用。
     */
    test09();

    //常量的引用
    test10();

    return 0;
}
