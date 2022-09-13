#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//��������������������

void myPrintInt(int val);

void test02()
{
    //���˶�̬����vector ����(��ģ��)
    vector<int> v;//v ��һ������vector����
    //push_back β�����
    v.push_back(100);
    v.push_back(200);
    v.push_back(300);
    v.push_back(400);
    v.push_back(500);


    //��������

    //��ʽһ
    //����һ�������� v����ʼ������ ָ���0��Ԫ�ص�λ��
    vector<int>::iterator beginIt = v.begin();
    //����һ�������� v�Ľ��������� ָ��βԪ�ص���һ��Ԫ�صĵ�ַ
    vector<int>::iterator endIt = v.end();
    //forѭ������ ��ʽһ
    for (; beginIt != endIt; beginIt++)
    {
        //�Ե�����ȡ* ������� ������Ԫ��
        //*beginIt �ȼ��� ����vector�е�int
        cout << *beginIt << " ";
    }
    cout << endl;

    //��ʽ��
    //forѭ������ ��ʽ��(�Ƽ�)
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    //STL�ṩ���㷨����������(�����㷨��ͷ�ļ� algorithm)
    //for_each ����������ʼ-->���� ���Ԫ��ȡ��
    //myPrintInt �������ݵĴ�ӡ��ʽ
    for_each(v.begin(), v.end(), myPrintInt);
    cout << endl;

}

void myPrintInt(int val)
{
    cout << val << " ";
}

//int main(int argc, char* argv[])
//{
//    test02();
//
//    return 0;
//}
