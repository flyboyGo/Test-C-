#include <iostream>
#include <string.h>
#include <malloc.h>

using namespace std;
//构造函数调用规则
/*
 *默认情况下，c++编译器至少为我们写的类增加 3 个函数
 *  1．默认构造函数(无参，函数体为空)
    2．默认析构函数(无参，函数体为空)
    3．默认拷贝构造函数，对类中 非静态 成员属性简单值拷贝(浅拷贝)
    注意:
       如果用户定义了普通构造(非拷贝)，c++不在提供默认无参构造，但是会提供 默认拷贝构造
       如果用户定义 拷贝构造函数, c++不会再提供任何  默认构造函数(构造函数、拷贝构造函数)

    总结:
       对于构造函数： 用户一般实现 无参构造函数、有参构造函数、拷贝构造函数、析构函数

 */
class DataPlus
{
     private :
        int num;
     public :
        //构造函数(无参)
        DataPlus()
        {
            num = 1;
            cout << "无参构造函数" << endl;
        }
        //构造重载
        //构造函数(有参数)
        DataPlus(int num)
        {
            this->num = num;
            cout << "有参构造函数" << endl;
        }

        //拷贝构造函数
        DataPlus(const DataPlus &ob) //自身类型对象的常引用
        {
            this->num = ob.num;
            cout << "拷贝构造函数" << endl;
        }

        void setNum(int num)
        {
            this->num = num;
        }
        int getNum()
        {
            return this->num;
        }

        //析构函数(没有返回值，不能有void，不能有参数，不能重载)
        ~DataPlus()
        {
            cout << "析构函数" << num << endl;
        }

};

//深拷贝、浅拷贝
/*
 * 同一类型的对象之间可以赋值，使得两个对象的成员变量的值相同，
 * 两个对象仍然是独立的两个对象，这种情况被称为浅拷贝.
 * 一般情况下，浅拷贝没有任何副作用但是当类中有指针，并且指针指向动态分配的内存空间，
 * 析构函数做了动态内存释放的处理，会导致内存问题
 */
/*
 *    深拷贝 当类中有指针，并且此指针有动态分配空间，析构函数做了释放处
      理，往往需要自定义拷贝构造函数，自行给指针动态分配空间，深拷贝。
 */
class Person
{
      private :
         char * name; // 注意重点
         int age;
      public :
         Person()
         {
             name = NULL;
             age = 0;
             cout << "无参构造" << endl;
         }

         Person(char * name, int age)
         {
             //为name申请空间
             this->name = (char*)malloc(sizeof(char)*(strlen(name)+1));
             if(this->name == NULL)
             {
                 cout << "构造失败" << endl;
             }
             else
             {
                 cout << "空间申请成功!" << endl;
                 strcpy(this->name,name);
             }
             this->age = age;
             cout << "有参构造函数" << endl;
         }

         char * getName()const
         {
             return this->name;
         }

         int getAge()const
         {
             return this->age;
         }

         //拷贝构造函数(自定义的拷贝构造函数解决浅拷贝问题) jack = lucy
         Person(const Person &p)
         {
             cout << "拷贝构造函数" << endl;
             this->name = (char*)malloc(sizeof(char)*(strlen(p.getName())+1));
             if(this->name == NULL)
             {
                 cout << "拷贝构造失败" << endl;
             }
             else
             {
                 cout << "空间申请成功!" << endl;
                 strcpy(this->name,p.getName());
                 this->age = p.getAge();
             }
         }

         ~Person()
         {
             if(this->name != NULL)
             {
                 free(this->name);
                 this->name = NULL;
             }
             cout << "析构函数,空间已被释放" << endl;
         }

         void showPersonInfo(void)
         {
             cout << "name = " << this->name << " age = " << this->age << endl;
         }

};

/*
 *C++中关于在类定义的内部 允许访问该类的实例化对象的私有变量的问题
 * a． 在C++的类的成员函数中，允许直接访问该类的对象的私有成员变量。
   b． 在类的成员函数中可以访问 "同类型" 实例化对象的私有变量。
   c． 拷贝构造函数里，可以直接访问另外一个 "同类型" 实例化对象（引用）的私有成员。
   d． 类的成员函数可以直接访问作为其参数的同类型实例化对象的私有成员。
*/
void test01()
{
    Person lucy = Person("李鹏飞", 24);
    lucy.showPersonInfo();

    //浅拷贝的问题(多次释放同一块堆区空间)
    //调用系统默认的拷贝构造函数(单纯的值拷贝,属于浅拷贝)
    //通过自定义 拷贝构造函数 完成深拷贝的动作 可以解决问题
    Person jack = lucy;
    cout << "jack.name: " <<jack.getName() << " jack.age: " << jack.getAge() << endl;

}

class Data
{
    private :
        int m_a;
        int m_b;
        int m_c;
    public :
        Data()
        {
            cout << "无参构造!" << endl;
        }


        Data(int a, int b, int c):m_a(a),m_b(b),m_c(c) //参数初始化列表 格式: 成员名(形参名),... 顺序无关
        {
//            this->m_a = a;
//            this->m_b = b;
//            this->m_c = c;
            //等价于m_a(a),m_b(b),m_c(c)
            cout << "有参构造!" << endl;
        }

        Data(const Data& data)
        {
            cout << "拷贝构造!" << endl;
        }

        ~Data()
        {
            cout << "析构函数" << endl;
        }

        void showData()
        {
            cout <<"m_a: " << m_a << " m_b: " << m_b << " m_c: " << m_c << endl;
        }

};


void test02()
{
    Data data = Data(1,2,3);
    data.showData();
}


//int main(int argc, char *argv[])
//{
//    //构造函数调用规则 深拷贝、浅拷贝
//    test01();

//    //参数初始化列表 初始化成员属性
//    //注意：初始化成员列表(参数列表)只能在构造函数使用。
//    test02();

//    return 0;
//}
