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
    // ���ַ�����ֵ�����ǳ�ʼ����
    //MyString str1 = 1;
    MyString str2(10);


    // Ԣ��ǳ���ȷ�����ַ�����ֵ
    MyString str3 = "abcd";
    MyString str4("abcd");
}
