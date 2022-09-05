#include <iostream>

using namespace std;

class A
{
private:
    int a;
protected:
    int b;
private:
    int c;
};

class B : public A
{
public:
    int d;
    int e;
};

void test04(void)
{
    cout << sizeof(B) << endl; // 20
}


//int main(int argc, char * argv[])
//{
//    test04();

//    return 0;
//}
