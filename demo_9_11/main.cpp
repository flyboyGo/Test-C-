#include <iostream>

using namespace std;

//cin的拓展

void test01()
{
    int data = 0;
    cin >> data;
    cout << "data = " << data << endl;

    char ch;
    cin >> ch;
    cout << "ch = " << ch << endl;

    //获取一个字符cin.get()
    char ch1 = '\0';
    ch1 = cin.get(); // 获取一个字符
    cout << "ch1 = " << ch1 << endl;

    //获取字符串
    char name[128] = "";
    cin >> name; //遇到空格、回车结束获取
    cout << "name = " << name << endl;

    //获取字符串(可以带空格)cin.getline();
    char name2[128]= "";
    cin.getline(name2,sizeof(name2)); // 可以获取带空格的字符串 遇到回车结束
    cout << "name2 = " << name2 << endl;
}

void test02()
{
    //cin.ignore() 忽略前n个字节的数据
    char name[128] = "";
    cin.ignore(2);//忽略前两个字节
    cin >> name;
    cout << "name = " << name << endl;
}

void test03()
{
    //cin.putback() 将数据放回缓冲区
    char ch = 0;
    ch = cin.get();
    cout << "ch = " << ch << endl;

    cin.putback(ch);//将ch的字符放回缓冲区

    char name[32] = "";
    cin >> name;
    cout << "name = " << name << endl;
}

void test04()
{
    //cin.peek() 只能偷窥一个字节的数据
    char ch = 0;
    ch = cin.peek();
    cout << "偷窥数据ch = " << ch << endl;

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
