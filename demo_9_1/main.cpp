#include <iostream>

using namespace std;

//const修饰成员函数
/*
 * 用 const 修饰的成员函数时, const 修饰 this 指针指向的内存区域，成员函数体
   内不可以修改本类中的任何普通成员变量,当成员变量类型符前用  mutable修饰时 例外
 */

class Data
{
private:
    int num;
    mutable int data;

public:
    Data()
    {
        cout << "无参构造" << endl;
    }
    Data(int num, int data)
    {
        this->num = num;
        this->data = data;
         cout << "有参构造" << endl;
    }
    Data(const Data &data)
    {
       this->num = data.num;
        this->data = data.data;
         cout << "拷贝构造" << endl;
    }
    ~Data()
    {
         cout << "析构函数" << endl;
    }

    //编译器认为 普通成员函数 存在修改成员变量的 可能性
    //常对象 只能调用修饰const修饰的 常函数
    void setNum(int num) const
    {
        // error 常函数中不能修改成员变量 除非成员用 mutable 修饰，而常对象只能调用常函数，间接的导致了这样的结果
        // this->num = num;
    }
    // 除非成员用 mutable 修饰
    void setData(int data) const
    {
        this->data = data;
    }


    //const 修饰的成员函数时 const 修饰 this 指针指向的内存区域
    //成员函数体内不可以修改本类中的任何普通成员变量
    int printNum(void) const
    {

        //this->num = 1000; // error num read-only

        return this->num;
    }
    //当成员变量类型符前用  mutable修饰时 例外
    int printData(void) const
    {

        this->data = 2000;
        return this->data;
    }

};

void test01()
{
    Data d1 = Data(100,200);
    cout << "Data的num : " << d1.printNum() << endl;
    cout << "Data的Data : " << d1.printData() << endl;
}

/*
 * const 修饰对象(常对象) 常对象只能调用 const 的成员函数
 * 常对象可访问 const 或非 const 数据成员，不能修改，除非成员用 mutable 修饰
 */

void test02()
{
    Data d1 = Data (10,20);
    d1.setData(2000);
    d1.setNum(3000);
    cout << "data : " << d1.printData() << endl;
    cout << "num : " << d1.printNum() << endl;
}


//int main(int argc, char *argv[])
//{
//    //const修饰成员函数
//    test01();

//    //const修饰对象,常对象 只能调用常函数遍历 成员数据
//    test02();

//    return 0;
//}
