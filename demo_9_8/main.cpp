#include <iostream>

using namespace std;

void swapInt(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
    return;
}

void swapChar(char &a, char &b)
{
    char tmp = a;
    a = b;
    b = tmp;
    return;
}

void test01()
{
    int data = 10, data2 = 20;
    cout << "data = " << data << ",data2 = " << data2 << endl;
    swapInt(data,data2);
    cout << "data = " << data << ",data2 = " << data2 << endl;

    char data3 = 'a', data4 = 'w';
    cout << "data3 = " << data3 << ",data4 = " << data4 << endl;
    swapChar(data3,data4);
    cout << "data3 = " << data3 << ",data4 = " << data4 << endl;

}

//函数模板 template是关键字
//class 与 typename 一致的
//T 是系统自动推导 或 用户指定

//普通函数
void mySwap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
    cout << "普通函数" << endl;
    return;
}

//函数模板
template<typename T> void mySwap(T &a, T &b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
   cout << "函数模板" << endl;
}


void test02()
{
    int data = 10, data2 = 20;
    cout << "data = " << data << ",data2 = " << data2 << endl;
    mySwap(data,data2);//系统自动推到出T为int
    cout << "data = " << data << ",data2 = " << data2 << endl;

    char data3 = 'a', data4 = 'w';
    cout << "data3 = " << data3 << ",data4 = " << data4 << endl;
    mySwap(data3,data4);//系统自动推到出T为char
    cout << "data3 = " << data3 << ",data4 = " << data4 << endl;
}

void test03()
{
    int data = 10, data2 = 20;
    cout << "data = " << data << ",data2 = " << data2 << endl;
    //用户显式指定T的类型
    mySwap<int>(data,data2);
    cout << "data = " << data << ",data2 = " << data2 << endl;

    //函数模板 和 普通 函数 都可以识别时 优先选择普通函数
    mySwap(data,data2);
    cout << "data = " << data << ",data2 = " << data2 << endl;

    //函数模板和普通函数模板 都可以识别 如何选择函数模板 显示调用函数模板 加<>
    mySwap<>(data,data2);
    cout << "data = " << data << ",data2 = " << data2 << endl;

}



//int main(int argc, char *argv[])
//{
//    //test01();

//    //test02();

//    test03();

//    return 0;
//}
