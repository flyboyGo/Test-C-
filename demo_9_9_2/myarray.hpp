#ifndef MYARRAY_H
#define MYARRAY_H

#include <iostream>
#include <string>

using namespace std;

template<class T>
class MyArray
{
private:
    T *addr;
    int capacity;
    int size;
public:
    MyArray(int capacity);
    MyArray(const MyArray &arr);
    ~MyArray(void);

    void PushBack(const T &val);
    void PrintArray(void);
};

#endif // MYARRAY_H

template<class T>
MyArray<T>::MyArray(int capacity)
{
    //ע�⣺
    //�����Զ����������� new Person[3]  �����е�ÿ��Ԫ�� ����Ĭ�ϵ����޲ι��캯��
    this->addr = new T [capacity];
    this->capacity = capacity;
    this->size = 0;
    cout << "���캯��" << endl;
}

template<class T>
MyArray<T>::MyArray(const MyArray &ob)
{
    this->capacity = ob.capacity;
    this->addr = new T [ob.capacity];
    this->size = ob.size;
    strcpy(this->addr,ob.addr);
//    for(int i = 0; i < ob.size; i++)
//    {
//        this->addr[i] = ob.addr[i];
//    }
    cout << "�������캯��" << endl;
}

template<class T>
MyArray<T>::~MyArray()
{
    if(this->addr != NULL)
    {
        delete [] this->addr;
        this->addr = NULL;
    }
    cout << "��������" << endl;
}

template<class T>
void MyArray<T>::PushBack(const T &val)
{
    if(this->capacity == this->size)
    {
        this->addr = (T *)realloc(this->addr,sizeof(T)*(this->capacity * 2));
        this->capacity = this->capacity * 2;
        cout << "��������,���ݳɹ�" << endl;
    }

    this->addr[this->size] = val;
    this->size++;
}

template<class T>
void MyArray<T>::PrintArray()
{
    for(int i = 0; i < this->size; i++)
    {
        //�������Զ����������� Person��Ҫ���������<<
        cout << this->addr[i] << " ";
    }
    cout << endl;
}
