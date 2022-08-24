#include <iostream>
#include <string.h>

using namespace std;

//Person类的设计
class Person
{
     private:
         string name;
         int age;
     public:
         void InitPerson(string name, int age)
         {
             if(age > 100 || age < 0)
             {
                 cout << "年龄的赋值不合法" << endl;
                 return;
             }
             this->name = name;
             this->age = age;
         }
         int getAge(void)
         {
             return age;
         }
         void setAge(int age)
         {
             if(age > 100 || age < 0)
             {
                 cout << "年龄的赋值不合法" << endl;
                 return;
             }
             this->age = age;
         }
         string getName(void)
         {
             return name;
         }
         void setName(string name)
         {
             this->name = name;
         }
         void printPersonInfo(void)
         {
             cout << "姓名 : " << name << " ,年龄 : " << age << endl;
         }

};

void test02()
{
    //通过类 实例化 一个对象 (用Person定义一个变量)
    Person jack; //Person是类名称 抽象的 jack是一个对象 实例(实际存在)
    jack.InitPerson("flyboy",23);
    jack.printPersonInfo();
    //对象 只能借助 公有的方法 操作私有数据
    jack.setAge(24);
    jack.setName("李鹏飞");
    jack.printPersonInfo();
    cout << "姓名 :" << jack.getName() << endl;
    cout << "年龄 :" << jack.getAge() << endl;
}

//Cube类的设计
class Cube
{
      private:
          double length;
          double width;
          double height;
      public:
          void initCube(double length, double width, double height)
          {
              this->length = length;
              this->width = width;
              this->height = height;
          }

          void setLenght(double length)
          {
              this->length = length;
          }
          double getLength(void)const
          {
              return this->length;
          }
          void setWidth(double width)
          {
              this->width = width;
          }
          double getWidth(void)const //显式告诉编译器,此方法不修改数据
          {
              return this->width;
          }
          void setHeigth(double height)
          {
              this->height = height;
          }
          double getHeight(void)const
          {
              return this->height;
          }
          double getS(void)
          {
              return 2*(length * width + width * height + length * height);
          }
          double getV(void)
          {
              return length * width * height;
          }
          bool isEqual(const Cube &c) //类的内部没有权限之分
          {
              if((c.getLength() == this->getLength()) &&(c.getWidth() == this->getWidth()) && (c.getHeight() == this->getHeight()))
              {
                  return true;
              }
              else
              {
                  return false;
              }
          }

};

// 比较两个立方体是否相等
//全局参数
bool CubeCompare(const Cube& c1,  const Cube& c2)
{
    if (c1.getLength() == c2.getLength() && c1.getWidth() == c2.getWidth() && c1.getHeight()== c2.getHeight())
    {
        return true;
    }
    return false;
}

void test03()
{
    Cube c1, c2, c3;
    c1.initCube(1,2,3);
    cout << "c1的表面积 : " << c1.getS() << endl;
    cout << "c1的体积 : " << c1.getV() << endl;
    c2.initCube(1,2,3);
    c3.initCube(4,5,6);
    //比较立方体是否相等
    cout << c1.isEqual(c2) << endl;
    cout << c2.isEqual(c3) << endl;
    //全局函数比较立方体是否相等
    cout << CubeCompare(c1,c2) << endl;
}


//int main(int argc, char *argv[])
//{
//    //Person类
//    test02();

//    //Cube类
//    test03();

//    return 0;
//}
