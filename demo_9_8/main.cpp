#include <iostream>

using namespace std;

void swapInt(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
    return;
}

void swapChar(char &a, char &b)
{
    char tmp = a;
    a = b;
    b = tmp;
    return;
}

void test01()
{
    int data = 10, data2 = 20;
    cout << "data = " << data << ",data2 = " << data2 << endl;
    swapInt(data,data2);
    cout << "data = " << data << ",data2 = " << data2 << endl;

    char data3 = 'a', data4 = 'w';
    cout << "data3 = " << data3 << ",data4 = " << data4 << endl;
    swapChar(data3,data4);
    cout << "data3 = " << data3 << ",data4 = " << data4 << endl;

}

//����ģ�� template�ǹؼ���
//class �� typename һ�µ�
//T ��ϵͳ�Զ��Ƶ� �� �û�ָ��

//��ͨ����
void mySwap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
    cout << "��ͨ����" << endl;
    return;
}

//����ģ��
template<typename T> void mySwap(T &a, T &b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
   cout << "����ģ��" << endl;
}


void test02()
{
    int data = 10, data2 = 20;
    cout << "data = " << data << ",data2 = " << data2 << endl;
    mySwap(data,data2);//ϵͳ�Զ��Ƶ���TΪint
    cout << "data = " << data << ",data2 = " << data2 << endl;

    char data3 = 'a', data4 = 'w';
    cout << "data3 = " << data3 << ",data4 = " << data4 << endl;
    mySwap(data3,data4);//ϵͳ�Զ��Ƶ���TΪchar
    cout << "data3 = " << data3 << ",data4 = " << data4 << endl;
}

void test03()
{
    int data = 10, data2 = 20;
    cout << "data = " << data << ",data2 = " << data2 << endl;
    //�û���ʽָ��T������
    mySwap<int>(data,data2);
    cout << "data = " << data << ",data2 = " << data2 << endl;

    //����ģ�� �� ��ͨ ���� ������ʶ��ʱ ����ѡ����ͨ����
    mySwap(data,data2);
    cout << "data = " << data << ",data2 = " << data2 << endl;

    //����ģ�����ͨ����ģ�� ������ʶ�� ���ѡ����ģ�� ��ʾ���ú���ģ�� ��<>
    mySwap<>(data,data2);
    cout << "data = " << data << ",data2 = " << data2 << endl;

}



//int main(int argc, char *argv[])
//{
//    //test01();

//    //test02();

//    test03();

//    return 0;
//}
