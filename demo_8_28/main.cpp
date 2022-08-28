#include <iostream>
#include <string.h>
#include <malloc.h>

using namespace std;

//new、delete从堆空间中申请空间、与malloc、realloc、calloc的比较
/*
 * 1) malloc等使用前 程序员必须确定对象的长度。
 * 2) malloc等 返回一个 void 指针, c++ 不允许将 void 赋值给其他任何指针，必须强转。
   3) malloc等 可能申请内存失败，所以必须判断返回值来确保内存分配成功。
   4) 用户在使用对象之前必须记住对它初始化,构造函数不能被显示调用初始化(构造函数是由编译器调用),用户有可能忘记调用自定义初始化函数
      重点:
      malloc等只会开辟空间 但不会调用构造函数完成空间的初始化，
      free只会释放空间  但不会调用析构函数完成对象结束前的清理工作(重点!!!)
 */


class Person{
public:
      Person(char * name, int age)
      {
              mAge = age;
              pName = (char*)malloc(strlen(name)+1);
              strcpy(pName, name);
      }

      void Init(char * name, int age)
      {
           mAge = age;
           pName = (char*)malloc(strlen(name)+1);
           strcpy(pName, name);
     }

     void ShowData(void)
     {
         cout << "name: " << this->pName << " age: " << this->mAge << endl;
     }

     void Clean()
     {
          if (pName != NULL)
          {
                   free(pName);
          }
     }

     public:
           int mAge;
           char* pName;
};

void test01()
{
    // 分配内存
    Person* person = (Person*)malloc(sizeof(Person));
    if(person == NULL)
    {
       return;
    }

    // 调用初始化函数
    person->Init("flyboy", 24);

    //打印对象的信息
    person->ShowData();

    // 清理对象
    person->Clean();

    // 释放 person 对象
    free(person);

}

/////////////////////////new、delete的使用

void test02()
{
    //基本类型
    int *p = NULL;

    //分配空间、初始化
    //传统方式
    // p = (int*)malloc(sizeof(int));
    //*p = 100;

    p = new int(100); //等价于 p = new int;(申请空间) *p = 100;(初始化)
    cout << "*p = " << *p << endl;

    //释放空间
    //free(p); //传统方式
    delete(p);

}

void test03()
{
    int *arr = NULL;

    //分配空间、初始化
    //arr = (int *)malloc(sizeof(int) * 5); //(分配空间)
    //arr[0] = 1;,....,arr[4] = 5; //(初始化) 传统方式

    arr = new int[5]{1,2,3,4,5}; //等价于arr = new int[5]; arr[0] = 1;....;arr[4] = 5;

    //打印数据
    for(int i = 0; i < 5; i++)
    {
        cout << "*arr[" << i << "] : " << arr[i] << endl;
    }

    //释放空间
    //free(arr);
    delete [] arr; //new时使用了[]  释放时也需要加[]

}

void test04()
{
    //char *arr = new char[32]{"hello"}; //error 字符串常量 返回的时第一个元素的地址 类型为const char *
    //错误信息 from const char * to char

    //char *arr = new char[32]{'h','e','l','l','o'};//太繁琐

    //改进方式
    char *arr = new char[32];
    strcpy(arr,"hello");

    cout << arr << endl;

    delete []arr;
}


class Data
{
private:
    char m_name[32];
    int m_age;
public:
    Data()
    {
        cout << "无参构造函数" << endl;
    }

    Data(char* name, int age)
    {
        strcpy(m_name,name);
        m_age = age;
        cout << "有参构造函数" << endl;
    }

    Data(const Data &data )
    {
        cout << "拷贝构造函数" << endl;
    }

    ~Data()
    {
        cout << "析构函数" << endl;
    }

    void showData(void)
    {
        cout << m_name << " " << m_age << endl;
    }
};

void test05()
{
    //new从堆区申请的空间 返回的都是地址
    //new 按照Data申请空间 如果申请成功 就会 自动调用  Data的构造函数
    Data *p = new Data;
    Data *p2 = new Data("flyboy",24);

    //p中保存的值是地址 即p的指针变量  如果p2是普通变量 使用.
    p2->showData();

    //delete 先调用析构函数  再释放堆区空间
    delete p;
    delete p2;

}

void test06()
{
    //对象数组的本质还是数组  只是数组中的元素是对象
    //对象数组 arr是数组  每个元素是Data类实例化对象
    //定义对象数组的时候 系统会自动给数组中的每个元素 调用构造函数

    //自动调用无参构造函数
    Data arr[5];

    //如果想让对象数组中的元素调用有参构造 必须人为的 显式 调用有参构造函数
    //调用有参构造函数
    //初始化部分 调用有参构造  未初始化部分自动调用默认构造(无参构造)
    Data arr2[5] = { Data("flyboy",24),Data("李鹏飞", 18)};
    arr2[0].showData();
    arr2[1].showData();
    arr2[2].showData();
}

void test07()
{
    //第一种方式
    Data * arr = new Data[5]; //调用无参构造
    delete [] arr;

    //第二种方式
    //初始化元素调用有参构造  未初始化的元素调用无参构造
    Data * arr2 = new Data[5]{Data("flyboy",18), Data("李鹏飞",23)};
    (*(arr2)).showData();
    (*(arr2+1)).showData();
     arr2[2].showData();  //*(arr+i) 等价与 arr[i]
    (arr2+3)->showData(); //数组中的元素是地址 直接指向成员函数

    delete [] arr2;
}

void test08()
{
    Data *data = new Data("李鹏飞",23);
    data->showData();

    //void* 万能指针可以保存所有类型的指针
    //void * d = data;

    /*
     * 如果对一个 void*指针执行 delete 操作，这将可能成为一个程序错误，
     * 因为void类型 也叫无类型 系统无法根据 无类型的指针 找到类实例化对象
     * 更无法找到其中的析构函数,并执行它
     */

    delete data;

}

//int main(int argc, char *argv[])
//{
//    //malloc、free等C语言常用方式完成对象的创建
//    test01();

//    //new、delete在基本类型中的使用
//    test02();

//    //new、delete在基本类型 数组 中的使用
//    test03();
//    test04();//注意字符数组的使用

//    //new、delete在类对象中的使用
//    test05();

//    //对象数组的创建
//    test06(); //传统方式
//    test07(); //new、delete申请的方式

//    //delete void* 可能会出错
//    test08();

//    return 0;
//}
