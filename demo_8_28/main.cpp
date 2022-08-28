#include <iostream>
#include <string.h>
#include <malloc.h>

using namespace std;

//new��delete�Ӷѿռ�������ռ䡢��malloc��realloc��calloc�ıȽ�
/*
 * 1) malloc��ʹ��ǰ ����Ա����ȷ������ĳ��ȡ�
 * 2) malloc�� ����һ�� void ָ��, c++ ������ void ��ֵ�������κ�ָ�룬����ǿת��
   3) malloc�� ���������ڴ�ʧ�ܣ����Ա����жϷ���ֵ��ȷ���ڴ����ɹ���
   4) �û���ʹ�ö���֮ǰ�����ס������ʼ��,���캯�����ܱ���ʾ���ó�ʼ��(���캯�����ɱ���������),�û��п������ǵ����Զ����ʼ������
      �ص�:
      malloc��ֻ�Ὺ�ٿռ� ��������ù��캯����ɿռ�ĳ�ʼ����
      freeֻ���ͷſռ�  �������������������ɶ������ǰ��������(�ص�!!!)
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
    // �����ڴ�
    Person* person = (Person*)malloc(sizeof(Person));
    if(person == NULL)
    {
       return;
    }

    // ���ó�ʼ������
    person->Init("flyboy", 24);

    //��ӡ�������Ϣ
    person->ShowData();

    // �������
    person->Clean();

    // �ͷ� person ����
    free(person);

}

/////////////////////////new��delete��ʹ��

void test02()
{
    //��������
    int *p = NULL;

    //����ռ䡢��ʼ��
    //��ͳ��ʽ
    // p = (int*)malloc(sizeof(int));
    //*p = 100;

    p = new int(100); //�ȼ��� p = new int;(����ռ�) *p = 100;(��ʼ��)
    cout << "*p = " << *p << endl;

    //�ͷſռ�
    //free(p); //��ͳ��ʽ
    delete(p);

}

void test03()
{
    int *arr = NULL;

    //����ռ䡢��ʼ��
    //arr = (int *)malloc(sizeof(int) * 5); //(����ռ�)
    //arr[0] = 1;,....,arr[4] = 5; //(��ʼ��) ��ͳ��ʽ

    arr = new int[5]{1,2,3,4,5}; //�ȼ���arr = new int[5]; arr[0] = 1;....;arr[4] = 5;

    //��ӡ����
    for(int i = 0; i < 5; i++)
    {
        cout << "*arr[" << i << "] : " << arr[i] << endl;
    }

    //�ͷſռ�
    //free(arr);
    delete [] arr; //newʱʹ����[]  �ͷ�ʱҲ��Ҫ��[]

}

void test04()
{
    //char *arr = new char[32]{"hello"}; //error �ַ������� ���ص�ʱ��һ��Ԫ�صĵ�ַ ����Ϊconst char *
    //������Ϣ from const char * to char

    //char *arr = new char[32]{'h','e','l','l','o'};//̫����

    //�Ľ���ʽ
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
        cout << "�޲ι��캯��" << endl;
    }

    Data(char* name, int age)
    {
        strcpy(m_name,name);
        m_age = age;
        cout << "�вι��캯��" << endl;
    }

    Data(const Data &data )
    {
        cout << "�������캯��" << endl;
    }

    ~Data()
    {
        cout << "��������" << endl;
    }

    void showData(void)
    {
        cout << m_name << " " << m_age << endl;
    }
};

void test05()
{
    //new�Ӷ�������Ŀռ� ���صĶ��ǵ�ַ
    //new ����Data����ռ� �������ɹ� �ͻ� �Զ�����  Data�Ĺ��캯��
    Data *p = new Data;
    Data *p2 = new Data("flyboy",24);

    //p�б����ֵ�ǵ�ַ ��p��ָ�����  ���p2����ͨ���� ʹ��.
    p2->showData();

    //delete �ȵ�����������  ���ͷŶ����ռ�
    delete p;
    delete p2;

}

void test06()
{
    //��������ı��ʻ�������  ֻ�������е�Ԫ���Ƕ���
    //�������� arr������  ÿ��Ԫ����Data��ʵ��������
    //������������ʱ�� ϵͳ���Զ��������е�ÿ��Ԫ�� ���ù��캯��

    //�Զ������޲ι��캯��
    Data arr[5];

    //������ö��������е�Ԫ�ص����вι��� ������Ϊ�� ��ʽ �����вι��캯��
    //�����вι��캯��
    //��ʼ������ �����вι���  δ��ʼ�������Զ�����Ĭ�Ϲ���(�޲ι���)
    Data arr2[5] = { Data("flyboy",24),Data("������", 18)};
    arr2[0].showData();
    arr2[1].showData();
    arr2[2].showData();
}

void test07()
{
    //��һ�ַ�ʽ
    Data * arr = new Data[5]; //�����޲ι���
    delete [] arr;

    //�ڶ��ַ�ʽ
    //��ʼ��Ԫ�ص����вι���  δ��ʼ����Ԫ�ص����޲ι���
    Data * arr2 = new Data[5]{Data("flyboy",18), Data("������",23)};
    (*(arr2)).showData();
    (*(arr2+1)).showData();
     arr2[2].showData();  //*(arr+i) �ȼ��� arr[i]
    (arr2+3)->showData(); //�����е�Ԫ���ǵ�ַ ֱ��ָ���Ա����

    delete [] arr2;
}

void test08()
{
    Data *data = new Data("������",23);
    data->showData();

    //void* ����ָ����Ա����������͵�ָ��
    //void * d = data;

    /*
     * �����һ�� void*ָ��ִ�� delete �������⽫���ܳ�Ϊһ���������
     * ��Ϊvoid���� Ҳ�������� ϵͳ�޷����� �����͵�ָ�� �ҵ���ʵ��������
     * ���޷��ҵ����е���������,��ִ����
     */

    delete data;

}

//int main(int argc, char *argv[])
//{
//    //malloc��free��C���Գ��÷�ʽ��ɶ���Ĵ���
//    test01();

//    //new��delete�ڻ��������е�ʹ��
//    test02();

//    //new��delete�ڻ������� ���� �е�ʹ��
//    test03();
//    test04();//ע���ַ������ʹ��

//    //new��delete��������е�ʹ��
//    test05();

//    //��������Ĵ���
//    test06(); //��ͳ��ʽ
//    test07(); //new��delete����ķ�ʽ

//    //delete void* ���ܻ����
//    test08();

//    return 0;
//}
