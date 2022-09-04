#include <iostream>
#include "mystring.h"

using namespace std;

void test01()
{
    MyString str = MyString("hello");
    MyString str2 = MyString(" world");

    cout << str << str2 << endl;
}

void test02()
{
    MyString str = MyString();
    cin >> str;
    cout << str << endl;
    cout << "size : "<< str.getStrSize()<< endl;
}

void test03()
{
    MyString str = MyString("flight");
    cout << str[3] << endl;

    //重载[] 运算符 返回值必须是左值 才能写操作
    //重载[] 运算符 的返回值必须是字符的引用 指针常量
    str[3] = 'G';
    cout << str << endl;
}

void test04()
{
     MyString str = MyString("flight");
     MyString str2 = MyString();
     MyString str3 = MyString();
     str3 = str2 = str;//(默认赋值语句 浅拷贝) 成员函数完成 =重载 实现深拷贝
     cout << str2 << " " << str3 << endl;
}

void test05()
{
    MyString str = MyString();
    MyString str2 = MyString();
    cout << str.getStrSize() << endl;
    cout << str2.getStrSize() << endl;
    str2 = str = "flight again";
    cout << str.getStrSize() << endl;
    cout << str2.getStrSize() << endl;
}

void test06()
{
    MyString str = MyString("hello ");
    MyString str2 = MyString("world ");
    MyString str3 = MyString("again");

    //将str、str2中的字符串拼接成一个全新的对象
    MyString str4 = str + str2 + str3;
    cout << str4 << endl;

     MyString str5 = MyString("flight ");
     MyString str6 = str5 + "again " + "again";
     cout << str6 << endl;

}

void test07()
{
    MyString str = MyString("hello");
    MyString str2 = MyString("hi");
    if(str == str2)
        cout << "相等" << endl;
    else
        cout << "不相等" << endl;

    if(str == "yes")
        cout << "相等" << endl;
    else
        cout << "不相等" << endl;
}

int main(int argc, char *argv[])
{
    //test01();

    //test02();

    //test03();

    //test04();

    //test05();

    //test06();

    test07();

    return 0;
}
