#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class MyPerson
{
private:
    char * name;
    int age;
public:
    MyPerson()
    {
        name = NULL;
        cout << "无参构造" << endl;
    }

    MyPerson(char * name,int age)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name,name);

        this->age = age;

        cout << "有参构造" << endl;
    }

    MyPerson(const MyPerson &mp)
    {
        //申请空间
        this->name = new char[strlen(mp.name) + 1];
        //拷贝内容
        strcpy(this->name,mp.name);
        this->age = mp.age;
        cout << "拷贝构造函数" << endl;
    }

    ~MyPerson()
    {
        cout << "析构函数" << endl;
        if(this->name != NULL)
        {
            delete [] this->name;
            this->name = NULL;
        }
    }

    //成员函数 完成 = 运算符的重载 实现深拷贝
    MyPerson& operator=(MyPerson &mp)
    {
        if(this->name != NULL) // 说明this->name 已经有指向空间
        {
            //释放空间
            delete [] this->name;
            this->name = NULL;
        }
        //申请空间
        this->name = new char[strlen(mp.name) + 1];
        //拷贝内容
        strcpy(this->name,mp.name);
        this->age = mp.age;

        return *this;
    }

    //成员函数 完成 == 运算符的重载 实现对象的判断
    bool operator==(MyPerson &mp)
    {
        if((strcmp(this->name,mp.name) == 0) && (this->age == mp.age))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //成员函数 完成 != 运算符的重载 实现对象的判断
    bool operator!=(MyPerson &mp)
    {
        if((strcmp(this->name,mp.name) != 0) || (this->age != mp.age))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void showPersonInfo(void)
    {
        cout << name << " " << age << endl;
    }

};

//指针作为类的成员
/*注意：
 * 1、拷贝构造函数 必须自定义 (默认拷贝构造是 浅拷贝)
 * 2、必须重载 =运算符 (默认 =运算符是浅拷贝)
 */
void test02()
{
    MyPerson p = MyPerson("李鹏飞",24);
    p.showPersonInfo();

    MyPerson p2 = p; //调用拷贝构造函数
    p2.showPersonInfo();

    MyPerson p3;
    p3 = p; //此时 = 运算符只是简单的赋值 是浅拷贝
    p3.showPersonInfo();

    MyPerson p4;
    p4 = p;//p4.operator =(p); 此时 = 运算符已被重载 可以实现深拷贝
    p4.showPersonInfo();

    MyPerson p5,p6;
    //迭代操作 返回引用
    p6 = p5 = p4; //*this等价与p5  this此时保存的是p5的地址
    p5.showPersonInfo();
    p6.showPersonInfo();
}

//成员函数完成对 ==、!= 运算符的重载
void test03()
{
    MyPerson p = MyPerson("jack", 23);
    MyPerson p2 = MyPerson("lucy", 25);
    MyPerson p3 = MyPerson("jack",23);

    if(p ==p3)
        cout << "相等" << endl;
    if(p == p2)
    {
        cout << "相等" << endl;
    }
    else
    {
        cout << "不相等" << endl;
    }

    if(p != p2)
         cout << "不相等" << endl;
}

//int main(int argc, char *argv[])
//{
//    test02();

//    test03();

//    return 0;
//}
