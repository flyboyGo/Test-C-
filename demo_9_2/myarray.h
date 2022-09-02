#ifndef MYARRAY_H
#define MYARRAY_H

#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class MyArray
{
private:
    int capacity; //数组的容量
    int size; //数组实际存放的元素的个数
    int *address; //数组首元素地址
public:
    MyArray();
    MyArray(int capacity);
    ~MyArray();

    //尾插法
    void pushBack(int data);

    //获得指定位置的数据
    int getDataByPos(int pos);

    //修改指定位置的数据
    void updateDataByPos(int pos, int data);

    //获取数组的容量
    int getCapacity(void);

    //获取数组实际的大小
    int getSize(void);

    //遍历数组中的元素
    void printfArray(void);
};

#endif // MYARRAY_H
