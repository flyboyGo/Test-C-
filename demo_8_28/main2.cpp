#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

//��̬��Ա  static���εĳ�Ա ��̬����  ��̬����
/*
 * ���ඨ���У����ĳ�Ա(������Ա�����ͳ�Ա����),��Щ��Ա�����ùؼ���static ����Ϊ��̬��,��Ϊ��̬��Ա��
   ��������ഴ���˶��ٸ�����,��̬��Աֻ��һ������,����������������������Ķ�����
   ��̬��Ա ������ �����Ƕ���
 */

/*
 * ��̬����������"����׶�"�ͷ���ռ䣬����û�д���ʱ�����Ѿ�����ռ䡣
   ��̬��Ա���������� ���������������ⶨ�塣
   ��̬���ݳ�Ա������ĳ��������Ϊ�������ռ��� "������" ��̬��Ա��ռ�ռ䡣
   ��̬���ݳ�Ա����ͨ���������߶����������á�
 */

class MyData
{
private :
    int num; //��ͨ��Ա����
public :
    static int data; //��̬��Ա����(�������������ⶨ��,��̬��Ա�Ĵ�С����������Ĵ�С��)
    MyData()
    {
    }

    MyData(int a, int b)
    {
    }

    MyData(const MyData &md)
    {
    }

    ~MyData()
    {
    }
};

//����ʱ����Ҫ�ټ�static
int  MyData::data = 100; //���ⶨ��+��ʼ��

void test09()
{
    //data�Ǿ�̬��Ա���� �������� ����ͨ��������ֱ�ӷ���
     cout << MyData::data<< endl; // 100

    //��ֵ
     MyData::data = 200;
     cout << MyData::data<< endl; // 200

     cout << sizeof(MyData) << endl; //4 ��Ĵ�С

     //data��̬���� �����ж��� ����� ����ͨ������������
     MyData md;
     cout << md.data << endl; // 200
     md.data = 300;
     cout << md.data << endl; // 300
     cout << MyData::data<< endl; // 300

     //��ͨ�����Ա���� ���ڶ���� ֻ��ͨ������������
}



//int main(int argc, char * argv[])
//{
//    //��̬��Ա�������
//    test09();

//    return 0;
//}
