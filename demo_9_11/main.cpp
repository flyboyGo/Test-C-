#include <iostream>

using namespace std;

//cin����չ

void test01()
{
    int data = 0;
    cin >> data;
    cout << "data = " << data << endl;

    char ch;
    cin >> ch;
    cout << "ch = " << ch << endl;

    //��ȡһ���ַ�cin.get()
    char ch1 = '\0';
    ch1 = cin.get(); // ��ȡһ���ַ�
    cout << "ch1 = " << ch1 << endl;

    //��ȡ�ַ���
    char name[128] = "";
    cin >> name; //�����ո񡢻س�������ȡ
    cout << "name = " << name << endl;

    //��ȡ�ַ���(���Դ��ո�)cin.getline();
    char name2[128]= "";
    cin.getline(name2,sizeof(name2)); // ���Ի�ȡ���ո���ַ��� �����س�����
    cout << "name2 = " << name2 << endl;
}

void test02()
{
    //cin.ignore() ����ǰn���ֽڵ�����
    char name[128] = "";
    cin.ignore(2);//����ǰ�����ֽ�
    cin >> name;
    cout << "name = " << name << endl;
}

void test03()
{
    //cin.putback() �����ݷŻػ�����
    char ch = 0;
    ch = cin.get();
    cout << "ch = " << ch << endl;

    cin.putback(ch);//��ch���ַ��Żػ�����

    char name[32] = "";
    cin >> name;
    cout << "name = " << name << endl;
}

void test04()
{
    //cin.peek() ֻ��͵��һ���ֽڵ�����
    char ch = 0;
    ch = cin.peek();
    cout << "͵������ch = " << ch << endl;

    char name[32] = "";
    cin >> name;
    cout << "name = " << name << endl;
}

//int main(int argc, char *argv[])
//{
//    //test01();

//    //test02();

//    //test03();

//    test04();

//    return 0;
//}
