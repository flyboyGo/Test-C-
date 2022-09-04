#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class MyString
{
friend ostream& operator<<(ostream &out, MyString &mStr);
friend istream& operator>>(istream &in, MyString &mStr);
private:
    char * str;
    int size;
public:
    MyString();
    MyString(const char * str);
    MyString(const MyString &mStr);
    ~MyString(void);

    int getStrSize(void);
    char& operator[](int index);
    MyString& operator=(const MyString &mStr);
    const char * operator=(const char * str);
    MyString operator+(const MyString &mStr);
    MyString operator+(const char * str);
    bool operator==(const MyString &mStr);
    bool operator==(const char * str);
};

#endif // MYSTRING_H
