#include <iostream>

using namespace std;

class MyString{
public:
     explicit MyString(int n)
     {
      cout << "MyString(int n)!" << endl;
     }

     MyString(const char* str)
     {
       cout << "MyString(const char* str)" << endl;
     }
};

int main(int argc, char *argv[])
{
    // 给字符串赋值？还是初始化？
    //MyString str1 = 1;
    MyString str2(10);


    // 寓意非常明确，给字符串赋值
    MyString str3 = "abcd";
    MyString str4("abcd");
}
