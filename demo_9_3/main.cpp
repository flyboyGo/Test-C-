#include <iostream>

using namespace std;

class Data
{
friend ostream& operator<<(ostream &out, Data &data);
friend Data& operator--(Data &data);
friend Data operator--(Data &data, int);

private:
    int a;
    int b;
public:
    Data()
    {
        a = 0;
        b = 0;
        cout << "无参构造" << endl;
    }
    Data(int a, int b):a(a),b(b) //初始化列表
    {
//        this->a = a;
//        this->b = b;
        cout << "有参构造" << endl;
    }
    void showData(void)
    {
        cout << "a = " << a << " b = " << b << endl;
    }

    ~Data()
    {
        cout << "析构函数" << endl;
    }

    //成员函数 重载 前置++运算符 ++ob1
    //编译器  默认识别 operator++(a) 但是a可以用this代替 从而简化 operator++()
    Data& operator++()
    {
       //先加加
       this->a++;
       this->b++;

       //后使用
       return *this;
    }

    //成员函数 重载 后置++运算符 ob1++
    //编译器  默认识别 operator++(a,int) 但是a可以用this代替 从而简化 operator++(int)
    Data operator++(int)
    {
        //先使用(备份加之前的值)
        Data old = *this;

        //后加加
        this->a++;
        this->b++;

        //注意：不要返回局部变量的引用 局部变量会提前释放
        return old;
    }

};

//普通全局函数 作为类的友元 "重载" << 运算符
ostream& operator<<(ostream &out, Data &data)
{
    out << "a = " << data.a << " b = " << data.b;
    return out;
}

void test01()
{
    Data d1 = Data(10,20);
    Data d2 = Data(30,40);
    d1.showData();

    //重载运算符<< 输出自定义对象的信息
    operator<<(cout,d1);
    cout << d1 << d2 << endl;
}

/*
 * 例如当编译器看到++a(前置++)，它就调用 operator++(a),
 * 当编译器看到 a++（后置++），它就会去调用 operator++(a,int)
 */


//成员函数完成对++的重置
void test02()
{
    Data d1 = Data(10,20);
    //++d1
    cout << ++d1 << endl; // 等价于  d1.operator++();
    cout << d1.operator ++() << endl;

    Data d2 = Data(100,200);
    //d2++
    cout << d2 << endl;

    Data tmp = d2++; //等价于Data tmp = d2.operator ++(0);
    cout << tmp << endl;
    cout << d2 << endl;
}

//普通的全局函数完成对--的重置
//前置--
Data& operator--(Data &data)
{
    data.a--;
    data.b--;

    return data;
}

//后置--
Data operator--(Data &data, int)
{
    //可以将tmp定义为static 这样就可以返回变量的引用
    //因为函数结束static类型变量所在的空间不会被提前释放
    Data tmp = data;

    data.a--;
    data.b--;

    return tmp;
}

void test03()
{
    //前置
    Data d1 = Data(10,20);
    cout << operator--(d1) << endl;
    cout << --d1 << endl;

    //后置
    Data d2 = Data(100,200);
    //函数返回局部变量 必须申请临时变量接收数据 否者局部变量立刻释放空间
    Data tmp = d2--;//等价于 Data tmp = operator--(d2,0);
    cout << tmp << endl;
    cout << d2 << endl;

}

//注意：当成员函数 、普通全局函数都可以实现重载运算符时 优先选择成员函数!!!!!!

//int main(int argc, char *argv[])
//{
//    test01();

//    test02();

//    test03();

//    return 0;
//}
