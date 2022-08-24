#include <iostream>
#include <string.h>

using namespace std;

//Person������
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
                 cout << "����ĸ�ֵ���Ϸ�" << endl;
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
                 cout << "����ĸ�ֵ���Ϸ�" << endl;
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
             cout << "���� : " << name << " ,���� : " << age << endl;
         }

};

void test02()
{
    //ͨ���� ʵ���� һ������ (��Person����һ������)
    Person jack; //Person�������� ����� jack��һ������ ʵ��(ʵ�ʴ���)
    jack.InitPerson("flyboy",23);
    jack.printPersonInfo();
    //���� ֻ�ܽ��� ���еķ��� ����˽������
    jack.setAge(24);
    jack.setName("������");
    jack.printPersonInfo();
    cout << "���� :" << jack.getName() << endl;
    cout << "���� :" << jack.getAge() << endl;
}

//Cube������
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
          double getWidth(void)const //��ʽ���߱�����,�˷������޸�����
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
          bool isEqual(const Cube &c) //����ڲ�û��Ȩ��֮��
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

// �Ƚ������������Ƿ����
//ȫ�ֲ���
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
    cout << "c1�ı���� : " << c1.getS() << endl;
    cout << "c1����� : " << c1.getV() << endl;
    c2.initCube(1,2,3);
    c3.initCube(4,5,6);
    //�Ƚ��������Ƿ����
    cout << c1.isEqual(c2) << endl;
    cout << c2.isEqual(c3) << endl;
    //ȫ�ֺ����Ƚ��������Ƿ����
    cout << CubeCompare(c1,c2) << endl;
}


//int main(int argc, char *argv[])
//{
//    //Person��
//    test02();

//    //Cube��
//    test03();

//    return 0;
//}
