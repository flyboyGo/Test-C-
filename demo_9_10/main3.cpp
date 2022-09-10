#include <iostream>

using namespace std;

//�쳣�Ķ�̬ʹ��
// �쳣����
class BaseException
{
public:
    virtual void printError(){};
};

// ��ָ���쳣
class NullPointerException : public BaseException
{
public:
     virtual void printError()
     {
        cout << "��ָ���쳣!" << endl;
     }
};

// Խ���쳣
class OutOfRangeException : public BaseException
{
public:
      virtual void printError()
      {
           cout << "Խ���쳣!" << endl;
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

//��׼�쳣��ʹ��
class MyPerson
{
private:
    int age;
public:
    MyPerson(int age)
    {
        if(age < 0 || age > 150)
            throw out_of_range("age��С��Ч");
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
        cout << "�쳣��Ϣ" << e.what() << endl;
    }
}

//int main(int argc, char *argv[])
//{
//    //test06();

//    test07();

//    return 0;
//}
