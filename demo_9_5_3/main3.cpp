#include <iostream>

using namespace std;

//ע��:��̳����ײ��� "���μ̳�"

/*���μ̳�(���й�ͬ������)
 * ����������̳�ͬһ�����������ĳ����ͬʱ�̳������������࣬���ּ̳б���Ϊ���μ̳У�������ʯ�ͼ̳С�
 */

class Animal
{
public:
    int data;
};

class Sheep : public Animal
{
public:

};

class Camel : public Animal
{
public:

};

class Alpaca : public Sheep, public Camel
{
public:

};

void test03()
{
    Alpaca a = Alpaca();
    //a.data; // ���������� data�̳��� Sheep ���� Camel

    //��һ�ַ�ʽ�� ����������
    a.Sheep::data = 100;
    a.Camel::data = 200;

    cout << sizeof(Alpaca) << endl; // 8
}

//int main(int argc, char *argv[])
//{
//    test03();

//    return 0;
//}
