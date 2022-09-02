#include <iostream>
#include <string.h>

using namespace std;

class Room; //Room向前声明 只能说明Room这个类存在 但不能描述Room有那些成员
            //解决方法: Room中函数的定义放在所有类的下方 只在类中声明 在类外定义


//2、类的某个成员函数 作为 另一个类的友元 一共有两个类
//让GoodGay中的visit成员函数作为Room的友元函数 visit就可以访问Room中的私有数据

class GoodGay
{
public:
    void visit(Room &room);
};


//C++中规定 友元可以访问 私有数据
/*友元的语法
 * friend 关键字只出现在声明处 其他类、类成员函数、全局函数都可声明为友元。
 * 友元函数不是类的成员，不带 this 指针 友元函数可访问对象任意成员属性，包括私有属性。
 */

//房间类
class Room
{
//将GoodGayVisit函数作为类的友元函数
//GoodGayVisit可以访问 类中所有的数据(包括私有数据) 但它不是类的成员
friend void GoodGayVisit(Room &room);

//让GoodGay类中的visit成员函数作为Room的友元函数
//一定记得加类的作用域
friend void GoodGay::visit(Room &room);

private:
    string dedRoom; //卧室
public:
    string sittingRoom; // 客厅
public:
    Room()
    {
        this->dedRoom = "卧室";
        this->sittingRoom = "客厅";
    }
};

//好基友 访问 我的房间
//1、普通的全局函数 作为 类(Room)的友元
void GoodGayVisit(Room &room)
{
    cout << "好基友访问你的 " << room.sittingRoom << endl;
    cout << "好基友访问你的 " << room.dedRoom<< endl;
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

//类外定义成员函数
void GoodGay::visit(Room &room)
{
    cout << "好基友访问你的 " << room.sittingRoom << endl;
    cout << "好基友访问你的 " << room.dedRoom<< endl;
}

//int main(int argc, char *argv[])
//{
//    test03();

//    //test04();

//    return 0;
//}
