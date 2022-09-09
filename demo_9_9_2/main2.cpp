#include <iostream>

using namespace std;

//提前声明PersonPlus类
template <class T1,class T2>
class PersonPlus;

//提前声明函数模板 告诉编译器printPersonPlus2函数模板是存在的
template<class T1,class T2>
void printPersonPlus2(PersonPlus<T1,T2> &ob);

template <class T1,class T2>
class PersonPlus
{
//1、友元函数在类中定义 (友元不属于该类的成员函数)
    friend void printPersonPlus(PersonPlus<T1,T2> &ob)
    {
        cout << "name = " << ob.name << ", age = " << ob.age << endl;
    }
//2、友元函数在类外定义 必须告诉编译器 该友元函数是模板
    friend void printPersonPlus2<>(PersonPlus<T1,T2> &ob);

private:
    T1 name;
    T2 age;
public:
    PersonPlus(T1 name,T2 age);
};

template<class T1, class T2>
PersonPlus<T1,T2>::PersonPlus(T1 name, T2 age)
{
    this->name = name;
    this->age = age;
}

//友元 函数模板
template<class T1,class T2>
void printPersonPlus2(PersonPlus<T1,T2> &ob)
{
    cout << "name = " << ob.name << ", age = " << ob.age << endl;
}

int main(int argc, char* argv[])
{
    PersonPlus<string,int> ob("李鹏飞",24);
    //通过友元 访问类模板中的数据
    printPersonPlus(ob);
    printPersonPlus2(ob);

    return 0;
}


