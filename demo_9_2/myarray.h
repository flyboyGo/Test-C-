#ifndef MYARRAY_H
#define MYARRAY_H

#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class MyArray
{
private:
    int capacity; //���������
    int size; //����ʵ�ʴ�ŵ�Ԫ�صĸ���
    int *address; //������Ԫ�ص�ַ
public:
    MyArray();
    MyArray(int capacity);
    ~MyArray();

    //β�巨
    void pushBack(int data);

    //���ָ��λ�õ�����
    int getDataByPos(int pos);

    //�޸�ָ��λ�õ�����
    void updateDataByPos(int pos, int data);

    //��ȡ���������
    int getCapacity(void);

    //��ȡ����ʵ�ʵĴ�С
    int getSize(void);

    //���������е�Ԫ��
    void printfArray(void);
};

#endif // MYARRAY_H
