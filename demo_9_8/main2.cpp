#include <iostream>
#include <string.h>

using namespace std;

void myTest(int a, int b)
{
    cout << "��ͨ����" << endl;
}

template<typename T>
void myTest(T a, T b)
{

   cout << "����ģ��" << endl;
}

//3������ģ��ĵ���ʱ��
void test04()
{
    int a = 10;
    char b = 'a';
    //Ĭ������ѡ�� ��ͨ����
    myTest(a,a);

    //ѡ����ģ��
    myTest<>(a,a);

    //����ģ��Ĭ�ϵĲ��� ���� �Զ�����ת��(�����û��ֶ�ָ��)
    //��ͨ����Ĭ�ϵĲ��� ���� �Զ�����ת��
    myTest(a,b); //ѡ����ͨ����

    //�û����� ��ʽָ�� ����ģ�� T�Ĳ�������
    //myTest<>(a,b); // error a,b�����Ͳ�һ��
    myTest<int>(a,b);

}


//ʹ��ģ�庯��ʵ�ֶ�int��char���͵���������
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
