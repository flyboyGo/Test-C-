#include <iostream>

using namespace std;


//自定义异常

class MyExceptionPlus : public exception
{
private:
    string my_Error;
public:
    MyExceptionPlus(const string errnoInfo)
    {
        this->my_Error = errnoInfo;
        cout << "异常构造函数string" << endl;
    }
    MyExceptionPlus(const char * errorInfo)
    {
        this->my_Error = string(errorInfo);
        cout << "异常构造函数char *" << endl;
    }

    MyExceptionPlus(const MyExceptionPlus &ob)
    {
        this->my_Error = ob.my_Error;
        cout << "异常拷贝构造" << endl;
    }

    virtual ~MyExceptionPlus()
    {
        cout << "异常析构函数" << endl;
    }

    //重写父类Exception中的what方法
    virtual const char * what()
    {
        return this->my_Error.c_str();
    }
};


class MyPersonPlus
{
private:
    int age;
public:
    MyPersonPlus(int age)
    {
        if(age < 0 || age > 150)
            throw MyExceptionPlus("age的大小范围无效");
        this->age = age;
    }
};

void test08()
{
    try
    {
        MyPersonPlus ob = MyPersonPlus(178);
    }
    catch(MyExceptionPlus e)
    {
        cout << e.what() << endl;
    }
}

int main(int argc, char *argv[])
{
    test08();

    return 0;
}
