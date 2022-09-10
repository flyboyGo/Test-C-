#include <iostream>

using namespace std;


//�Զ����쳣

class MyExceptionPlus : public exception
{
private:
    string my_Error;
public:
    MyExceptionPlus(const string errnoInfo)
    {
        this->my_Error = errnoInfo;
        cout << "�쳣���캯��string" << endl;
    }
    MyExceptionPlus(const char * errorInfo)
    {
        this->my_Error = string(errorInfo);
        cout << "�쳣���캯��char *" << endl;
    }

    MyExceptionPlus(const MyExceptionPlus &ob)
    {
        this->my_Error = ob.my_Error;
        cout << "�쳣��������" << endl;
    }

    virtual ~MyExceptionPlus()
    {
        cout << "�쳣��������" << endl;
    }

    //��д����Exception�е�what����
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
            throw MyExceptionPlus("age�Ĵ�С��Χ��Ч");
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
