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
        cout << "�޲ι���" << endl;
    }

    MyPerson(char * name,int age)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name,name);

        this->age = age;

        cout << "�вι���" << endl;
    }

    MyPerson(const MyPerson &mp)
    {
        //����ռ�
        this->name = new char[strlen(mp.name) + 1];
        //��������
        strcpy(this->name,mp.name);
        this->age = mp.age;
        cout << "�������캯��" << endl;
    }

    ~MyPerson()
    {
        cout << "��������" << endl;
        if(this->name != NULL)
        {
            delete [] this->name;
            this->name = NULL;
        }
    }

    //��Ա���� ��� = ����������� ʵ�����
    MyPerson& operator=(MyPerson &mp)
    {
        if(this->name != NULL) // ˵��this->name �Ѿ���ָ��ռ�
        {
            //�ͷſռ�
            delete [] this->name;
            this->name = NULL;
        }
        //����ռ�
        this->name = new char[strlen(mp.name) + 1];
        //��������
        strcpy(this->name,mp.name);
        this->age = mp.age;

        return *this;
    }

    //��Ա���� ��� == ����������� ʵ�ֶ�����ж�
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

    //��Ա���� ��� != ����������� ʵ�ֶ�����ж�
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

//ָ����Ϊ��ĳ�Ա
/*ע�⣺
 * 1���������캯�� �����Զ��� (Ĭ�Ͽ��������� ǳ����)
 * 2���������� =����� (Ĭ�� =�������ǳ����)
 */
void test02()
{
    MyPerson p = MyPerson("������",24);
    p.showPersonInfo();

    MyPerson p2 = p; //���ÿ������캯��
    p2.showPersonInfo();

    MyPerson p3;
    p3 = p; //��ʱ = �����ֻ�Ǽ򵥵ĸ�ֵ ��ǳ����
    p3.showPersonInfo();

    MyPerson p4;
    p4 = p;//p4.operator =(p); ��ʱ = ������ѱ����� ����ʵ�����
    p4.showPersonInfo();

    MyPerson p5,p6;
    //�������� ��������
    p6 = p5 = p4; //*this�ȼ���p5  this��ʱ�������p5�ĵ�ַ
    p5.showPersonInfo();
    p6.showPersonInfo();
}

//��Ա������ɶ� ==��!= �����������
void test03()
{
    MyPerson p = MyPerson("jack", 23);
    MyPerson p2 = MyPerson("lucy", 25);
    MyPerson p3 = MyPerson("jack",23);

    if(p ==p3)
        cout << "���" << endl;
    if(p == p2)
    {
        cout << "���" << endl;
    }
    else
    {
        cout << "�����" << endl;
    }

    if(p != p2)
         cout << "�����" << endl;
}

//int main(int argc, char *argv[])
//{
//    test02();

//    test03();

//    return 0;
//}
