#include <iostream>

using namespace std;

class MyGay;
//3��һ�������� ��Ϊ ��һ����Ե���Ԫ(һ��������г�Ա���� ���Է��� ��һ�����˽������)

class MyRoom
{
//��MyGay��������ΪMyRoom�����Ԫ��
//MyGay���� ���еĳ�Ա���� �����Է��� MyRoom˽������
friend class MyGay;

private:
    string dedRoom; //����
public:
    string sittingRoom; // ����
public:
    MyRoom()
    {
        this->dedRoom = "����";
        this->sittingRoom = "����";
    }
};

class MyGay
{
public:
    void visit(MyRoom &room)
    {
        cout << "�û��ѷ������ " << room.sittingRoom << endl;
        cout << "�û��ѷ������ " << room.dedRoom << endl;
    }
};

void test05()
{
    MyGay myGay;
    MyRoom room;
    myGay.visit(room);
}

int main(int argc, char *argv[])
{
    test05();
    return 0;
}
