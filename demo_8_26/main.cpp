#include <iostream>
#include <string.h>
#include <malloc.h>

using namespace std;
//���캯�����ù���
/*
 *Ĭ������£�c++����������Ϊ����д�������� 3 ������
 *  1��Ĭ�Ϲ��캯��(�޲Σ�������Ϊ��)
    2��Ĭ����������(�޲Σ�������Ϊ��)
    3��Ĭ�Ͽ������캯���������� �Ǿ�̬ ��Ա���Լ�ֵ����(ǳ����)
    ע��:
       ����û���������ͨ����(�ǿ���)��c++�����ṩĬ���޲ι��죬���ǻ��ṩ Ĭ�Ͽ�������
       ����û����� �������캯��, c++�������ṩ�κ�  Ĭ�Ϲ��캯��(���캯�����������캯��)

    �ܽ�:
       ���ڹ��캯���� �û�һ��ʵ�� �޲ι��캯�����вι��캯�����������캯������������

 */
class DataPlus
{
     private :
        int num;
     public :
        //���캯��(�޲�)
        DataPlus()
        {
            num = 1;
            cout << "�޲ι��캯��" << endl;
        }
        //��������
        //���캯��(�в���)
        DataPlus(int num)
        {
            this->num = num;
            cout << "�вι��캯��" << endl;
        }

        //�������캯��
        DataPlus(const DataPlus &ob) //�������Ͷ���ĳ�����
        {
            this->num = ob.num;
            cout << "�������캯��" << endl;
        }

        void setNum(int num)
        {
            this->num = num;
        }
        int getNum()
        {
            return this->num;
        }

        //��������(û�з���ֵ��������void�������в�������������)
        ~DataPlus()
        {
            cout << "��������" << num << endl;
        }

};

//�����ǳ����
/*
 * ͬһ���͵Ķ���֮����Ը�ֵ��ʹ����������ĳ�Ա������ֵ��ͬ��
 * ����������Ȼ�Ƕ������������������������Ϊǳ����.
 * һ������£�ǳ����û���κθ����õ��ǵ�������ָ�룬����ָ��ָ��̬������ڴ�ռ䣬
 * �����������˶�̬�ڴ��ͷŵĴ����ᵼ���ڴ�����
 */
/*
 *    ��� ��������ָ�룬���Ҵ�ָ���ж�̬����ռ䣬�������������ͷŴ�
      ��������Ҫ�Զ��忽�����캯�������и�ָ�붯̬����ռ䣬�����
 */
class Person
{
      private :
         char * name; // ע���ص�
         int age;
      public :
         Person()
         {
             name = NULL;
             age = 0;
             cout << "�޲ι���" << endl;
         }

         Person(char * name, int age)
         {
             //Ϊname����ռ�
             this->name = (char*)malloc(sizeof(char)*(strlen(name)+1));
             if(this->name == NULL)
             {
                 cout << "����ʧ��" << endl;
             }
             else
             {
                 cout << "�ռ�����ɹ�!" << endl;
                 strcpy(this->name,name);
             }
             this->age = age;
             cout << "�вι��캯��" << endl;
         }

         char * getName()const
         {
             return this->name;
         }

         int getAge()const
         {
             return this->age;
         }

         //�������캯��(�Զ���Ŀ������캯�����ǳ��������) jack = lucy
         Person(const Person &p)
         {
             cout << "�������캯��" << endl;
             this->name = (char*)malloc(sizeof(char)*(strlen(p.getName())+1));
             if(this->name == NULL)
             {
                 cout << "��������ʧ��" << endl;
             }
             else
             {
                 cout << "�ռ�����ɹ�!" << endl;
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
             cout << "��������,�ռ��ѱ��ͷ�" << endl;
         }

         void showPersonInfo(void)
         {
             cout << "name = " << this->name << " age = " << this->age << endl;
         }

};

/*
 *C++�й������ඨ����ڲ� ������ʸ����ʵ���������˽�б���������
 * a�� ��C++����ĳ�Ա�����У�����ֱ�ӷ��ʸ���Ķ����˽�г�Ա������
   b�� ����ĳ�Ա�����п��Է��� "ͬ����" ʵ���������˽�б�����
   c�� �������캯�������ֱ�ӷ�������һ�� "ͬ����" ʵ�����������ã���˽�г�Ա��
   d�� ��ĳ�Ա��������ֱ�ӷ�����Ϊ�������ͬ����ʵ���������˽�г�Ա��
*/
void test01()
{
    Person lucy = Person("������", 24);
    lucy.showPersonInfo();

    //ǳ����������(����ͷ�ͬһ������ռ�)
    //����ϵͳĬ�ϵĿ������캯��(������ֵ����,����ǳ����)
    //ͨ���Զ��� �������캯�� �������Ķ��� ���Խ������
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
            cout << "�޲ι���!" << endl;
        }


        Data(int a, int b, int c):m_a(a),m_b(b),m_c(c) //������ʼ���б� ��ʽ: ��Ա��(�β���),... ˳���޹�
        {
//            this->m_a = a;
//            this->m_b = b;
//            this->m_c = c;
            //�ȼ���m_a(a),m_b(b),m_c(c)
            cout << "�вι���!" << endl;
        }

        Data(const Data& data)
        {
            cout << "��������!" << endl;
        }

        ~Data()
        {
            cout << "��������" << endl;
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
//    //���캯�����ù��� �����ǳ����
//    test01();

//    //������ʼ���б� ��ʼ����Ա����
//    //ע�⣺��ʼ����Ա�б�(�����б�)ֻ���ڹ��캯��ʹ�á�
//    test02();

//    return 0;
//}
