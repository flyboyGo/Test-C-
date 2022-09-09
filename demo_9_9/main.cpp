#include <iostream>
#include <string>

using namespace std;

//��ģ��
/*
 * ��ģ��ͺ���ģ��Ķ����ʹ�����ƣ������Ѿ������˽��ܡ���ʱ������������
 * �࣬�书������ͬ�ģ��������������Ͳ�ͬ�� ��ģ������ʵ�����������ݵ����Ͳ�����
 */

template<class T1, class T2> //�ȼ��� template<typename T1, typename T2>
class Data
{
friend void addData(Data<string,int> &ob);
private:
    T1 name;
    T2 num;
public:
    Data(T1 name, T2 num)
    {
        this->name = name;
        this->num = num;
        cout << "�вι��캯��" << endl;
    }
    ~Data()
    {
        cout << "��������" << endl;
    }
    void showData(void)
    {
        cout << "name = " << this->name << ", num = " << this->num << endl;
    }
};

void test01()
{
    //ע�⣺��ģ�岻�ܽ��������Զ��Ƶ�����Ҫ�ֶ�ָ��
    Data<string,int> d = Data<string,int>("��������֮��",100);
    //�ȼ���Data<string,int> d("��������֮��",100);
    d.showData();

    Data<int,string> d2(200,"����");
    d2.showData();

    Data<int,int> d3(100,200);
    d3.showData();

    Data<string,string> d4("��¡","ʥǹ����");
    d4.showData();
}


//2����ģ����Ϊ�������� ����ָ����������
//��ͨ��������������ȷ����

void addData(Data<string,int> &ob)
{
    cout << "��ͨ����" << endl;
    ob.name +="_vip";
    ob.num += 2000;
    return;
}

void test02()
{
    Data<string,int> d("Ы��",300);
    addData(d);
    d.showData();
}

//3����ģ��������ͨ��
/*
 * ����ʵ������ʱ����Ҫ���廯�ĸ��࣬������Ҫ֪������ľ���������ʲô����
 * ���� c++ ����������֪���������������ڴ�
 */
template <class T>
class Base
{
private:
    T num;
public:
    Base(T num)
    {
        cout << "�вι���" << endl;
        this->num = num;
    }

    ~Base()
    {
        cout << "��������" << endl;
    }

    void showNum(void)
    {
        cout << this->num << endl;
    }
};

//��ģ�� ���� ��ͨ�� ����� ���� ָ��T������
class Son : public Base<int>
{
public:
    Son(int a):Base<int>(a)
    {
        cout << "Son�Ĺ��캯��" << endl;
    }
};

class Son2 : public Base<string>
{
public:
    Son2(string a):Base<string>(a)
    {
        cout << "Son2�Ĺ��캯��" << endl;
    }
};

void test03()
{
    Son ob = Son(100);
    ob.showNum();

    Son2 ob2 = Son2("hello");
    ob2.showNum();
}

//ע�⣺���๲�к�������˽�г�Ա������̳к󣬼̳еĹ��к����ɷ��ʺͲ������صġ��̳��Ը����˽�г�Ա������

//int main(int argc, char *argv[])
//{
//    //test01();

//    //test02();

//    test03();

//    return 0;
//}
