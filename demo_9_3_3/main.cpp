#include <iostream>
#include "mystring.h"

using namespace std;

void test01()
{
    MyString str = MyString("hello");
    MyString str2 = MyString(" world");

    cout << str << str2 << endl;
}

void test02()
{
    MyString str = MyString();
    cin >> str;
    cout << str << endl;
    cout << "size : "<< str.getStrSize()<< endl;
}

void test03()
{
    MyString str = MyString("flight");
    cout << str[3] << endl;

    //����[] ����� ����ֵ��������ֵ ����д����
    //����[] ����� �ķ���ֵ�������ַ������� ָ�볣��
    str[3] = 'G';
    cout << str << endl;
}

void test04()
{
     MyString str = MyString("flight");
     MyString str2 = MyString();
     MyString str3 = MyString();
     str3 = str2 = str;//(Ĭ�ϸ�ֵ��� ǳ����) ��Ա������� =���� ʵ�����
     cout << str2 << " " << str3 << endl;
}

void test05()
{
    MyString str = MyString();
    MyString str2 = MyString();
    cout << str.getStrSize() << endl;
    cout << str2.getStrSize() << endl;
    str2 = str = "flight again";
    cout << str.getStrSize() << endl;
    cout << str2.getStrSize() << endl;
}

void test06()
{
    MyString str = MyString("hello ");
    MyString str2 = MyString("world ");
    MyString str3 = MyString("again");

    //��str��str2�е��ַ���ƴ�ӳ�һ��ȫ�µĶ���
    MyString str4 = str + str2 + str3;
    cout << str4 << endl;

     MyString str5 = MyString("flight ");
     MyString str6 = str5 + "again " + "again";
     cout << str6 << endl;

}

void test07()
{
    MyString str = MyString("hello");
    MyString str2 = MyString("hi");
    if(str == str2)
        cout << "���" << endl;
    else
        cout << "�����" << endl;

    if(str == "yes")
        cout << "���" << endl;
    else
        cout << "�����" << endl;
}

int main(int argc, char *argv[])
{
    //test01();

    //test02();

    //test03();

    //test04();

    //test05();

    //test06();

    test07();

    return 0;
}
