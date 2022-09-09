#include <iostream>
#include <string>

using namespace std;

//类模板
/*
 * 类模板和函数模板的定义和使用类似，我们已经进行了介绍。有时，有两个或多个
 * 类，其功能是相同的，仅仅是数据类型不同。 类模板用于实现类所需数据的类型参数化
 */

template<class T1, class T2> //等价于 template<typename T1, typename T2>
class Data
{
friend void addData(Data<string,int> &ob);
private:
    T1 name;
    T2 num;
public:
    Data(T1 name, T2 num)
    {
        this->name = name;
        this->num = num;
        cout << "有参构造函数" << endl;
    }
    ~Data()
    {
        cout << "析构函数" << endl;
    }
    void showData(void)
    {
        cout << "name = " << this->name << ", num = " << this->num << endl;
    }
};

void test01()
{
    //注意：类模板不能进行类型自动推导，需要手动指明
    Data<string,int> d = Data<string,int>("德玛西亚之力",100);
    //等价于Data<string,int> d("德玛西亚之力",100);
    d.showData();

    Data<int,string> d2(200,"皇子");
    d2.showData();

    Data<int,int> d3(100,200);
    d3.showData();

    Data<string,string> d4("布隆","圣枪游侠");
    d4.showData();
}


//2、类模板作为函数参数 必须指明参数类型
//普通函数参数类型是确定的

void addData(Data<string,int> &ob)
{
    cout << "普通函数" << endl;
    ob.name +="_vip";
    ob.num += 2000;
    return;
}

void test02()
{
    Data<string,int> d("蝎子",300);
    addData(d);
    d.showData();
}

//3、类模板派生普通类
/*
 * 子类实例化的时候需要具体化的父类，子类需要知道父类的具体类型是什么样的
 * 这样 c++ 编译器才能知道给子类分配多少内存
 */
template <class T>
class Base
{
private:
    T num;
public:
    Base(T num)
    {
        cout << "有参构造" << endl;
        this->num = num;
    }

    ~Base()
    {
        cout << "析构函数" << endl;
    }

    void showNum(void)
    {
        cout << this->num << endl;
    }
};

//类模板 派生 普通类 必须给 基类 指定T的类型
class Son : public Base<int>
{
public:
    Son(int a):Base<int>(a)
    {
        cout << "Son的构造函数" << endl;
    }
};

class Son2 : public Base<string>
{
public:
    Son2(string a):Base<string>(a)
    {
        cout << "Son2的构造函数" << endl;
    }
};

void test03()
{
    Son ob = Son(100);
    ob.showNum();

    Son2 ob2 = Son2("hello");
    ob2.showNum();
}

//注意：父类共有函数操作私有成员，子类继承后，继承的共有函数可访问和操作隐藏的、继承自父类的私有成员变量。

//int main(int argc, char *argv[])
//{
//    //test01();

//    //test02();

//    test03();

//    return 0;
//}
