#include "person.hpp"

//include标准是包含头文件 基本上不会包含.cpp

using namespace std;

//类模板的头文件、源文件的分离问题
void test01()
{
    //类模板 会经过两次编译
    //第一次编译 类模板 本身编译、第二次编译 类模板的成员调用的时候
    //c++/c 独立文件编译
    //类模板的.cpp 和 .h分文件 出错的原因 在第二次编译
    //建议.cpp与.h 放在一起  文件类型更改为 .hpp

    Person<string,int> ob("李鹏飞",24);
    ob.showPerson();
}

#include "myarray.hpp"

//存放基本数据
void test02()
{
    MyArray<char> ob(5);
    ob.PushBack('h');
    ob.PushBack('e');
    ob.PushBack('l');
    ob.PushBack('l');
    ob.PushBack('o');
    ob.PrintArray();
    ob.PushBack('!');
    ob.PrintArray();

    MyArray<int> ob2(3);
    ob2.PushBack(123);
    ob2.PushBack(456);
    ob2.PushBack(678);
    ob2.PrintArray();
    ob2.PushBack(910);
    ob2.PrintArray();
}

class MyPerson
{
friend ostream& operator<<(ostream &out, MyPerson &ob);
private:
    string name;
    int age;
public:
    MyPerson()
    {
    }

    MyPerson(string name, int age)
    {
        this->name = name;
        this->age =age;
    }
};
ostream& operator<<(ostream &out, MyPerson &ob)
{
    out << "name = " << ob.name << ", age = " << ob.age;
}

//存放自定义数据
void test03()
{
    MyArray<MyPerson> ob(3);
    ob.PushBack(MyPerson("皇子",25));
    ob.PushBack(MyPerson("蝎子",400));
    ob.PushBack(MyPerson("火男",45));
    ob.PrintArray();
    ob.PushBack(MyPerson("寒冰",37));
    ob.PrintArray();
}

//int main(int argc, char *argv[])
//{
//    //test01();

//    //test02();

//    test03();

//    return 0;
//}
