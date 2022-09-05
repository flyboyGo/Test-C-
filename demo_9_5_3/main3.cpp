#include <iostream>

using namespace std;

//注意:多继承容易产生 "菱形继承"

/*菱形继承(具有共同的祖先)
 * 两个派生类继承同一个基类而又有某个类同时继承者两个派生类，这种继承被称为菱形继承，或者钻石型继承。
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
    //a.data; // 产生二义性 data继承于 Sheep 还是 Camel

    //第一种方式： 加作用域解决
    a.Sheep::data = 100;
    a.Camel::data = 200;

    cout << sizeof(Alpaca) << endl; // 8
}

//int main(int argc, char *argv[])
//{
//    test03();

//    return 0;
//}
