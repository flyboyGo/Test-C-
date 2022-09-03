#include "mystring.h"


MyString::MyString()
{
    this->str = NULL;
    this->size = 0;
    cout << "�޲ι���" << endl;
}

MyString::MyString(const char *str)
{
    cout << "�вι��캯��" << endl;
    if(str != NULL)
    {
        this->str = new char[strlen(str) + 1];
        strcpy(this->str,str);
        this->size = strlen(this->str);
    }
}

MyString::MyString(const MyString &mStr)
{
    cout << "�������캯��" << endl;
    this->str = new char[strlen(mStr.str) + 1];
    strcpy(this->str,mStr.str);
    this->size = strlen(this->str);
}

MyString::~MyString()
{
    cout << "��������" << endl;
    if(this->str != NULL)
    {
        delete [] this->str;
        this->str = NULL;
    }
}

//��ȡ�ַ����ĳ���
int MyString::getStrSize()
{
    return this->size;
}

//��Ա������ɶ� []������� ���� �������ַ�������& ָ�볣��
char& MyString::operator[](int index)
{
    if(index > 0 || index < this->size)
    {
        return this->str[index];
    }
}

//��Ա������ɶ� =������� ���� ʵ����� �����ض�������� ʵ�ֵ�������
MyString &MyString::operator=(const MyString &mStr)
{
    //�Ƚ�this->strԭ��ָ����ڴ�ռ��ͷ�
    if(this->str != NULL)
    {
        delete [] this->str;
        this->str = NULL;
    }

    this->str = new char[strlen(mStr.str) + 1];
    strcpy(this->str,mStr.str);
    this->size = strlen(this->str);

    return *this;
}

//��Ա������ɶ� =������� ���� ʵ����� �������ַ������� ʵ�ֵ�������
const char *MyString::operator=(const char * str)
{
    if(this->str != NULL)
    {
        delete [] this->str;
        this->str = NULL;
    }

    this->str = new char[strlen(str) + 1];
    strcpy(this->str,str);
    this->size = strlen(str);

    return str;
}


//ȫ����ͨ��Ԫ������ɶ� <<������� ����
ostream& operator<<(ostream &out, MyString &mStr)
{
    out << mStr.str;
    return out;
}

//ȫ����ͨ��Ԫ������ɶ� >>������� ����
istream& operator>>(istream &in, MyString &mStr)
{
    //��ԭ��ָ��Ŀռ����ݲ���
    if(mStr.str != NULL)
    {
        delete [] mStr.str;
    }

    //��ȡ����������ַ���
    char buf[1024] = "";
    in >> buf;//�ȵõ�������������� Ȼ�����buf��ʵ�ʴ�С ���ٿռ�

    mStr.str = new char[strlen(buf) + 1];
    strcpy(mStr.str, buf);
    mStr.size = strlen(buf);

    return in;
}


