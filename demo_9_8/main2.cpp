#include <iostream>
#include <string.h>

using namespace std;

void myTest(int a, int b)
{
    cout << "普通函数" << endl;
}

template<typename T>
void myTest(T a, T b)
{

   cout << "函数模板" << endl;
}

//3、函数模板的调用时机
void test04()
{
    int a = 10;
    char b = 'a';
    //默认优先选择 普通函数
    myTest(a,a);

    //选择函数模板
    myTest<>(a,a);

    //函数模板默认的参数 不能 自动类型转换(可以用户手动指定)
    //普通函数默认的参数 可以 自动类型转换
    myTest(a,b); //选择普通函数

    //用户可以 显式指定 函数模板 T的参数类型
    //myTest<>(a,b); // error a,b的类型不一致
    myTest<int>(a,b);

}


//使用模板函数实现对int、char类型的数组排序
template<typename T> void PrintfArray(T *arr, int len)
{
    for(int i = 0; i < len; i ++)
    {
        cout << arr[i];
    }
    cout << endl;
}

template<typename T> void SortArray(T *arr, int len)
{
    bool flag = false;
    for(int i = 0; i < len; i ++)
    {
        for(int j = 0; j < len - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                T tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
                flag = true;
            }
        }
        if(flag == true)
        {
            flag = false;
            continue;
        }
        else
        {
            break;
        }
    }
}

void test05()
{
    char arr[] = "hello world";
    SortArray(arr,strlen(arr));
    PrintfArray(arr,strlen(arr));

    int arr2[] = {2,4,6,1,3,5};
    SortArray(arr2,sizeof(arr2)/sizeof(int));
    PrintfArray(arr2,sizeof(arr2)/sizeof(int));
}


//int main(int argc, char *argv[])
//{
//    //test04();

//    test05();

//    return 0;
//}
