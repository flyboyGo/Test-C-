#include <iostream>
#include <string.h>

using namespace std;

class Room; //Room��ǰ���� ֻ��˵��Room�������� ����������Room����Щ��Ա
            //�������: Room�к����Ķ��������������·� ֻ���������� �����ⶨ��


//2�����ĳ����Ա���� ��Ϊ ��һ�������Ԫ һ����������
//��GoodGay�е�visit��Ա������ΪRoom����Ԫ���� visit�Ϳ��Է���Room�е�˽������

class GoodGay
{
public:
    void visit(Room &room);
};


//C++�й涨 ��Ԫ���Է��� ˽������
/*��Ԫ���﷨
 * friend �ؼ���ֻ������������ �����ࡢ���Ա������ȫ�ֺ�����������Ϊ��Ԫ��
 * ��Ԫ����������ĳ�Ա������ this ָ�� ��Ԫ�����ɷ��ʶ��������Ա���ԣ�����˽�����ԡ�
 */

//������
class Room
{
//��GoodGayVisit������Ϊ�����Ԫ����
//GoodGayVisit���Է��� �������е�����(����˽������) ����������ĳ�Ա
friend void GoodGayVisit(Room &room);

//��GoodGay���е�visit��Ա������ΪRoom����Ԫ����
//һ���ǵü����������
friend void GoodGay::visit(Room &room);

private:
    string dedRoom; //����
public:
    string sittingRoom; // ����
public:
    Room()
    {
        this->dedRoom = "����";
        this->sittingRoom = "����";
    }
};

//�û��� ���� �ҵķ���
//1����ͨ��ȫ�ֺ��� ��Ϊ ��(Room)����Ԫ
void GoodGayVisit(Room &room)
{
    cout << "�û��ѷ������ " << room.sittingRoom << endl;
    cout << "�û��ѷ������ " << room.dedRoom<< endl;
}

void test03()
{
    Room myRoom;
    GoodGayVisit(myRoom);
}


void test04()
{
    GoodGay goodGay;
    Room room;
    goodGay.visit(room);
}

//���ⶨ���Ա����
void GoodGay::visit(Room &room)
{
    cout << "�û��ѷ������ " << room.sittingRoom << endl;
    cout << "�û��ѷ������ " << room.dedRoom<< endl;
}

//int main(int argc, char *argv[])
//{
//    test03();

//    //test04();

//    return 0;
//}
