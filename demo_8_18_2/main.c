#include <stdio.h>

int a = 10; //�Ѹ�ֵ ����
int a;      //ͬ�� ��δ��ֵ ����

void func(int i)
{
    printf("i = %d\n", i);
}

//��������û����������
//C�����к���û�в�����������Ϊvoid
void func2(i)
{
    printf("i = %s\n", i);
}

void func3(void)
{
}

enum COLOR
{
    green,
    red,
    yello
};


//C������ʹ��ö��ģ��ʵ�ֲ���ֵ
typedef enum bool
{
    false, // 0
    true   // 1
}bool;

bool makeBool(int a, int b)
{
    bool ret;
    if(a > b)
    {
        ret = true;
        return ret;
    }
    else
    {
        ret = false;
        return ret;
    }
}

//��������Դ�ļ��еı���
extern int data;

void test01()
{
    const int num = 10;
    printf("num = %d\n", num);
    //num = 20; // error read-only
    //printf("num = %d\n", num);
    int * p = (int *)&num;
    *p = 30;
    printf("num = %d\n", num); // 30
}

int main(int argc, char *argv[])
{
    printf("a = %d\n", a);

    func(10);
    func2("hello");
    func3();

    enum COLOR mycolor = green;
    printf("mycolor = %d\n", mycolor);// 0

    mycolor = 10;
    printf("mycolor = %d\n", mycolor); // 10

    enum COLOR mycolor2 = red;
    printf("mycolor = %d\n", mycolor2); //  1

    //C������ʹ��ö��ģ��ʵ�ֲ���ֵ
    printf("bool = %d\n",makeBool(2,1));

    //��ȡ����Դ�ļ��еı���
    printf("data = %d\n", data);

    //C������const��ʹ��
    test01();

    return 0;
}

