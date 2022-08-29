#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Data
{
private :
    static int count;
public :
    Data()
    {
        count++;
        cout << "无参构造函数" << endl;
    }

    Data(const Data &data)
    {
        count++;
        cout << "拷贝构造函数" << endl;
    }

    int getStaticCount()
    {
        return count;
    }

    ~Data()
    {
        count--;
        cout << "析构函数" << endl;
    }
};

int Data::count = 0;

//静态成员变量 统计 实例化对象的 个数
void test01()
{
    Data d1;
    Data d2;
    cout << "对象的个数 ：" << d1.getStaticCount() << endl;
    Data d3;
    Data d4;
    cout << "对象的个数 ：" << d1.getStaticCount() << endl;
    Data d5 = d4;
    Data d6(d5);
    cout << "对象的个数 ：" << d1.getStaticCount() << endl;
}

/*
 * 静态成员实现单例模式 单例模式是一种常用的软件设计模式。
 * 在它的核心结构中只包含一个被称为单例的特殊类。
 * 通过单例模式可以保证系统中一个类只有一个实例而且该实例易于外界访问，从而方便对实例个数的控制并节约系统资源。
   如果希望在系统中某个类的对象只能存在一个，单例模式是最好的解决方案。
 */

/*
 * Singleton（单例）：在单例类的内部实现只生成一个，同时它提供一个静态的 getInstance()工厂方法，
   让客户可以访问它的唯一实例；为了防止在外部对其实例化，将其默认构造函数和拷贝构造函数设计为私有；
   在单例类内部定义了一个Singleton 类型的静态对象，作为外部共享的唯一实例。
 */
class Person
{
private:
    int age;
    char * name;
    //1、定义一个静态的 对象指针变量 保存唯一的实例
    static Person* singlePerson;
    static int count;
private:
    //3、防止 该类实例化其他对象 将构造函数全部 私有化
    Person()
    {
        cout << "无参构造" << endl;
    }

    Person(char * name, int age)
    {
        this->age = age;
        this->name = (char*)malloc(sizeof(strlen(name) + 1));
        strcpy(this->name,name);
        cout << "有参构造函数" << endl;
    }

    Person(const Person &p)
    {
        this->name = (char*)malloc(sizeof(strlen(p.name) + 1));
        strcpy(this->name,p.name);
        this->age = p.age;
        cout << "拷贝构造函数" << endl;
    }

public :
    //2、提供一个静态方法 获得单例指针
    static Person * getSinglePerson(void)
    {
        return singlePerson;
    }

    //功能函数
    void PrintCount(void)
    {
        this->count++;
        cout << "打印报告次数 :" << this->count << endl;
    }

    ~Person()
    {
        cout << "析构函数" << endl;
    }
};

Person * Person::singlePerson = new Person("flyboy",23);
int Person::count = 0;

void test02()
{
    Person * p = Person::getSinglePerson();
    p->PrintCount();
    p->PrintCount();
    Person * p2 = Person::getSinglePerson();
    p->PrintCount();
    p->PrintCount();
    p->PrintCount();
}

int main(int argc, char *argv[])
{

    //静态成员变量的使用实例
    test01();

    //单例模式设计(重要)
    test02();

    return 0;
}
