#include "mystring.h"


MyString::MyString()
{
    this->str = NULL;
    this->size = 0;
    cout << "无参构造" << endl;
}

MyString::MyString(const char *str)
{
    cout << "有参构造函数" << endl;
    if(str != NULL)
    {
        this->str = new char[strlen(str) + 1];
        strcpy(this->str,str);
        this->size = strlen(this->str);
    }
}

MyString::MyString(const MyString &mStr)
{
    cout << "拷贝构造函数" << endl;
    this->str = new char[strlen(mStr.str) + 1];
    strcpy(this->str,mStr.str);
    this->size = strlen(this->str);
}

MyString::~MyString()
{
    cout << "析构函数" << endl;
    if(this->str != NULL)
    {
        delete [] this->str;
        this->str = NULL;
    }
}

//获取字符串的长度
int MyString::getStrSize()
{
    return this->size;
}

//成员函数完成对 []运算符的 重载 并返回字符的引用& 指针常量
char& MyString::operator[](int index)
{
    if(index > 0 || index < this->size)
    {
        return this->str[index];
    }
}

//成员函数完成对 =运算符的 重载 实现深拷贝 并返回对象的引用 实现迭代操作
MyString &MyString::operator=(const MyString &mStr)
{
    //先将this->str原先指向的内存空间释放
    if(this->str != NULL)
    {
        delete [] this->str;
        this->str = NULL;
    }

    this->str = new char[strlen(mStr.str) + 1];
    strcpy(this->str,mStr.str);
    this->size = strlen(this->str);

    return *this;
}

//成员函数完成对 =运算符的 重载 实现深拷贝 并返回字符串常量 实现迭代操作
const char *MyString::operator=(const char * str)
{
    if(this->str != NULL)
    {
        delete [] this->str;
        this->str = NULL;
    }

    this->str = new char[strlen(str) + 1];
    strcpy(this->str,str);
    this->size = strlen(str);

    return str;
}


//全局普通友元函数完成对 <<运算符的 重载
ostream& operator<<(ostream &out, MyString &mStr)
{
    out << mStr.str;
    return out;
}

//全局普通友元函数完成对 >>运算符的 重载
istream& operator>>(istream &in, MyString &mStr)
{
    //将原来指向的空间数据擦除
    if(mStr.str != NULL)
    {
        delete [] mStr.str;
    }

    //获取键盘输入的字符串
    char buf[1024] = "";
    in >> buf;//先得到键盘输入的数据 然后根据buf的实际大小 开辟空间

    mStr.str = new char[strlen(buf) + 1];
    strcpy(mStr.str, buf);
    mStr.size = strlen(buf);

    return in;
}


