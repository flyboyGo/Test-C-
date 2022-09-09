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
    //注意：
    //对于自定义数据类型 new Person[3]  数组中的每个元素 都会默认调用无参构造函数
    this->addr = new T [capacity];
    this->capacity = capacity;
    this->size = 0;
    cout << "构造函数" << endl;
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
    cout << "拷贝构造函数" << endl;
}

template<class T>
MyArray<T>::~MyArray()
{
    if(this->addr != NULL)
    {
        delete [] this->addr;
        this->addr = NULL;
    }
    cout << "析构函数" << endl;
}

template<class T>
void MyArray<T>::PushBack(const T &val)
{
    if(this->capacity == this->size)
    {
        this->addr = (T *)realloc(this->addr,sizeof(T)*(this->capacity * 2));
        this->capacity = this->capacity * 2;
        cout << "容量已满,扩容成功" << endl;
    }

    this->addr[this->size] = val;
    this->size++;
}

template<class T>
void MyArray<T>::PrintArray()
{
    for(int i = 0; i < this->size; i++)
    {
        //如果输出自定义数据类型 Person需要重载运算符<<
        cout << this->addr[i] << " ";
    }
    cout << endl;
}
