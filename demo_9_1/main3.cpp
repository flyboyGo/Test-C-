#include <iostream>

using namespace std;

class MyGay;
//3、一个类整体 作为 另一个类对的友元(一个类的所有成员函数 可以访问 另一个类的私有数据)

class MyRoom
{
//将MyGay类整体作为MyRoom类的友元类
//MyGay类中 所有的成员函数 都可以访问 MyRoom私有数据
friend class MyGay;

private:
    string dedRoom; //卧室
public:
    string sittingRoom; // 客厅
public:
    MyRoom()
    {
        this->dedRoom = "卧室";
        this->sittingRoom = "客厅";
    }
};

class MyGay
{
public:
    void visit(MyRoom &room)
    {
        cout << "好基友访问你的 " << room.sittingRoom << endl;
        cout << "好基友访问你的 " << room.dedRoom << endl;
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
