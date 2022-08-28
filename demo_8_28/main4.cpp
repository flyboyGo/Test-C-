#include <iostream>

using namespace std;

class MyPlus
{
private :
    int num; //��ͨ��Ա����
public :
    const static int data; //��̬��Ա����(�������������ⶨ��,��̬��Ա�Ĵ�С����������Ĵ�С��)

    //��ͨ��Ա���� ���� ������ ����
    int getData(void)
    {
        return data;
    }

    //��̬��Ա����  ������ �������ڶ���
    static int getStaticData(void)
    {
        //num = 200; //��̬��Ա�������ܷ��ʷǾ�̬��Ա����
        return data;
    }
};

//����ʱ����Ҫ�ټ�static
//��̬������ʹ����������Ϊ˽�б���,����Ȼ��Ҫ�����ⱻ���塢��ʼ��
const int MyPlus::data = 250; //���ⶨ��+��ʼ��

void test11()
{
    /*
     * ���һ����ĳ�Ա����Ҫʵ�ֹ�����Ҫʵ�ֲ��ɸı䣬�Ǿ��� static const ���Ρ�
     * ���徲̬ const ���ݳ�Աʱ����������ڲ���ʼ��
     */
    cout << "��̬��Ա���� : " << MyPlus::getStaticData() << endl;

    //���¸�ֵ
    //MyPlus::data = 120; //error const����data, data��ֻ����

}

int main(int argc, char * argv[])
{
    test11();
    return 0;
}
