#include <stdio.h>

int a = 10; //已赋值 定义
int a;      //同名 且未赋值 声明

void func(int i)
{
    printf("i = %d\n", i);
}

//函数参数没有声明类型
//C语言中函数没有参数可以声明为void
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


//C语言中使用枚举模拟实现布尔值
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

//声明其他源文件中的变量
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

    //C语言中使用枚举模拟实现布尔值
    printf("bool = %d\n",makeBool(2,1));

    //读取其他源文件中的变量
    printf("data = %d\n", data);

    //C语言中const的使用
    test01();

    return 0;
}

