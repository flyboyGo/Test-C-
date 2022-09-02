#include "myarray.h"

MyArray::MyArray()
{
    //���������Ϊ100
    this->capacity = 100;
    //����ʵ�ʵĴ��Ԫ�صĸ���Ϊ0
    this->size = 0;
    //�������ݵ����� ����������ռ�
    this->address = new int[this->capacity];
}

MyArray::MyArray(int capacity)
{
    //���������Ϊָ������
    this->capacity = capacity;
    //����ʵ�ʵĴ��Ԫ�صĸ���Ϊ0
    this->size = 0;
    //�������ݵ����� ����������ռ�
    this->address = new int[this->capacity];
}

MyArray::~MyArray()
{
    if(this->address != NULL)
    {
        delete[] this->address;
        this->address = NULL;
    }
}

void MyArray::pushBack(int data)
{
    if(this->size == this->capacity)
    {
        this->address = (int *)realloc(this->address,(this->capacity * 2)*sizeof(int));
        this->capacity = this->capacity * 2;
        cout << "��������" << endl;
    }
    this->address[this->size] = data;
    this->size++;
}

int MyArray::getDataByPos(int pos)
{
    if(pos < 0 || (pos > this->size - 1))
    {
        cout << "λ�ò��Ϸ�" << endl;
        exit(-1);
    }
    else
    {
       return this->address[pos];
    } 
}

void MyArray::updateDataByPos(int pos, int data)
{
    if(pos < 0 || (pos > this->size - 1))
    {
        cout << "λ�ò��Ϸ�" << endl;
        exit(-1);
    }
    else
    {
        this->address[pos] = data;
    }
}

int MyArray::getCapacity()
{
    return this->capacity;
}

int MyArray::getSize()
{
    return this->size;
}

void MyArray::printfArray()
{
    for(int i = 0; i < this->size; i++)
    {
        cout << this->address[i] << " ";
    }
    cout << endl;
}
