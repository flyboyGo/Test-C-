#include <iostream>

using namespace std;

///////////C++���﷨����ǿ

//�ظ�����(C++�б���ʧ��,C�п��Ա���ɹ�)
//int a = 10; //�Ѹ�ֵ ����
//int a;      //ͬ�� ��δ��ֵ ����


//��������û����������(C++�б���ʧ��,C�п��Ա���ɹ�)
//void func2(i)
//{
//    printf("i = %s\n", i);
//}


//C++�ϸ������ת��
enum COLOR
{
    green,
    red,
    yello
};

void test01()
{
    enum COLOR mycolor = green;
    printf("mycolor = %d\n", mycolor);// 0

    //mycolor = 10; //����,�Ƿ�����
    printf("mycolor = %d\n", mycolor); // 0

    enum COLOR mycolor2 = red;
    printf("mycolor = %d\n", mycolor2); //  1

}

//int main(int argc, char *argv[])
//{
//    //1��C++�﷨�����ǿ
//    //�ظ�����
//    //int a = 10; //�Ѹ�ֵ ����
//    //int a;      //ͬ�� ��δ��ֵ ����

//    //2��C++�����еı����ͺ�������������������
//    //func2("hello");

//    //3�����ϸ������ת��
//    test01();

//    return 0;
//}
