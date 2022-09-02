#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;
//运算符重载的概述
/*
 * 运算符重载，就是对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型。
 * 运算符重载的目的：简化操作 让已有的运算符 适应不同的数据类型
 * 语法：函数的名字由关键字 operator及 其 "紧跟" 的运算符组成
 * 比如：重载 +号运算符 ==> operator + ; 重载 =号运算符 ==> operator =
 * 注意：重载运算符 不要更改 运算符的本质操作 (+是数据的相加 不要重载成数据的相减)
 */

//
class Person
{
//设置成友元函数
friend ostream& operator<< (ostream &out, Person &person);
friend Person  operator+(Person &p1,Person &p2);

private:
    char *name;
    int num;
public:
    Person()
    {
        this->name = NULL;
        this->num = 0;
        cout << "无参构造" << endl;
    }

    Person(char *name, int num)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->num = num;
        cout << "有参构造函数" << endl;
    }

    //普通的成员函数
    void printPerson()
    {
        cout << this->name << " " << this->num << endl;
    }

    //成员函数 完成运算符重载 p1用this代替 p2用参数代替
    Person operator+(Person &p2)
    {
        //num + num(数值相加)
        char *tmp_name = new char[strlen(this->name) + strlen(p2.name) + 1];
        strcpy(tmp_name, this->name);
        strcat(tmp_name, p2.name);

        //num + num(数值相加)
        int tmp_num = this->num + p2.num;
        Person tmp_person = Person(tmp_name, tmp_num);

        if(tmp_name != NULL)
        {
            delete [] tmp_name;
            tmp_name = NULL;
        }

        return tmp_person;
    }

    ~Person()
    {
        if(this->name != NULL)
        {
            delete [] this->name;
            this->name = NULL;
        }
        cout << "析构函数" << endl;
    }
};

//1、全局函数作为友元 完成运算符重载<<
ostream& operator<< (ostream &out, Person &person) //out = cout, person = p
{
    //重新实现 输出格式
    out << person.name << " " << person.num << endl;

    //每次执行完 返回值输出为out
    //返回值为引用
    return out;
}

void test01()
{
    Person p = Person("李鹏飞", 24);
    //普通的成员函数 遍历信息
    p.printPerson();

    //cout默认输出方式 无法识别 自定义对象 输出格式
    //cout << p << endl; //error
    //解决上述问题 需要重载运算符 <<

    //运算符重载调用方式一
    operator<<(cout, p);

    //运算符重载调用方式二：
    //对方式一优化 去掉operator,第一个参数 放在运算符 << 的左边，第一个参数 放在运算符 << 的右边
    cout << p; //等价于 operator<<(cout, p);

    //缺陷：无法迭代使用
    //对方式二的优化 重载函数体中返回值为out引用
    Person p2 = Person("flyboy", 23);
    cout << p  << p2;

}

//1.2、全局函数作为友元 完成运算符重载+
Person operator+(Person &p1,Person &p2) //p1 p2
{
    //name + name (字符串相加)
    char *tmp_name = new char[strlen(p1.name) + strlen(p2.name) + 1];
    strcpy(tmp_name, p1.name);
    strcat(tmp_name, p2.name);

    //num + num(数值相加)
    int tmp_num = p1.num + p2.num;
    Person tmp_person = Person(tmp_name, tmp_num);

    if(tmp_name != NULL)
    {
        delete [] tmp_name;
        tmp_name = NULL;
    }

    return tmp_person;
}

void test02()
{
    Person p = Person("jack",18);
    Person p2 = Person("Nancy",16);
    cout << p ;
    cout << p2;

    Person p3 = operator+(p,p2);
    //优化后
    //Person p3 = p + p2;
    cout << p3 ;
}

//2、成员函数完成运算符重载 +
void test03()
{
    Person p = Person("jack",18);
    Person p2 = Person("Nancy",16);
    Person p3 = p.operator+(p2);
    //优化后
    //Person p3 = p + p2;
    cout << p3;
}

int main(int argc, char *argv[])
{
    test01();

    test02();

    test03();

    return 0;
}
