#include <iostream>

using namespace std;

class MyData
{
private :
    int num;
public :
    MyData()
    {
        cout << "�޲ι��캯��" << endl;
    }

    //���вι��캯�� ��������ʽת��
    explicit MyData(int data)
    {
        this->num = data;
        cout << "�вι��캯��" << endl;
    }
    ~MyData()
    {
        cout << "��������" << endl;
    }
    void showNum(void)
    {
        cout << " num = " << num << endl;
    }
};

//int main(int argc, char *argv[])
//{
//    //C++�ṩ�˹ؼ��� explicit����ֹͨ�����캯�����е���ʽת����
//    // explicit �������ι��캯��,��ֹ��ʽת���� ����Ե������Ĺ��캯��(���߳��˵�һ�������������������Ĭ��ֵ�Ķ�ι���)����
//    //����Ϊ explicit �Ĺ��캯����������ʽת����ʹ��
//    //MyData md = 10; //MyData md(10) == > MyData md = MyData(10)

//    MyData md2 = MyData(10);
//    md2.showNum();

//    return 0;
//}
