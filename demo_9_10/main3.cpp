#include <iostream>

using namespace std;

//异常的多态使用
// 异常基类
class BaseException
{
public:
    virtual void printError(){};
};

// 空指针异常
class NullPointerException : public BaseException
{
public:
     virtual void printError()
     {
        cout << "空指针异常!" << endl;
     }
};

// 越界异常
class OutOfRangeException : public BaseException
{
public:
      virtual void printError()
      {
           cout << "越界异常!" << endl;
      }
};

void doWork()
{
     throw NullPointerException();
}

void test06()
{
   try
    {
      doWork();
    }
   catch (BaseException& ex)
    {
       ex.printError();
    }
}

//标准异常的使用
class MyPerson
{
private:
    int age;
public:
    MyPerson(int age)
    {
        if(age < 0 || age > 150)
            throw out_of_range("age大小无效");
        this->age = age;
    }
};

void test07()
{
    try
    {
        MyPerson ob = MyPerson(200);
    }
    catch(exception &e)
    {
        cout << "异常信息" << e.what() << endl;
    }
}

//int main(int argc, char *argv[])
//{
//    //test06();

//    test07();

//    return 0;
//}
