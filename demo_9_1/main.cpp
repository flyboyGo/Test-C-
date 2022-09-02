#include <iostream>

using namespace std;

//const���γ�Ա����
/*
 * �� const ���εĳ�Ա����ʱ, const ���� this ָ��ָ����ڴ����򣬳�Ա������
   �ڲ������޸ı����е��κ���ͨ��Ա����,����Ա�������ͷ�ǰ��  mutable����ʱ ����
 */

class Data
{
private:
    int num;
    mutable int data;

public:
    Data()
    {
        cout << "�޲ι���" << endl;
    }
    Data(int num, int data)
    {
        this->num = num;
        this->data = data;
         cout << "�вι���" << endl;
    }
    Data(const Data &data)
    {
       this->num = data.num;
        this->data = data.data;
         cout << "��������" << endl;
    }
    ~Data()
    {
         cout << "��������" << endl;
    }

    //��������Ϊ ��ͨ��Ա���� �����޸ĳ�Ա������ ������
    //������ ֻ�ܵ�������const���ε� ������
    void setNum(int num) const
    {
        // error �������в����޸ĳ�Ա���� ���ǳ�Ա�� mutable ���Σ���������ֻ�ܵ��ó���������ӵĵ����������Ľ��
        // this->num = num;
    }
    // ���ǳ�Ա�� mutable ����
    void setData(int data) const
    {
        this->data = data;
    }


    //const ���εĳ�Ա����ʱ const ���� this ָ��ָ����ڴ�����
    //��Ա�������ڲ������޸ı����е��κ���ͨ��Ա����
    int printNum(void) const
    {

        //this->num = 1000; // error num read-only

        return this->num;
    }
    //����Ա�������ͷ�ǰ��  mutable����ʱ ����
    int printData(void) const
    {

        this->data = 2000;
        return this->data;
    }

};

void test01()
{
    Data d1 = Data(100,200);
    cout << "Data��num : " << d1.printNum() << endl;
    cout << "Data��Data : " << d1.printData() << endl;
}

/*
 * const ���ζ���(������) ������ֻ�ܵ��� const �ĳ�Ա����
 * ������ɷ��� const ��� const ���ݳ�Ա�������޸ģ����ǳ�Ա�� mutable ����
 */

void test02()
{
    Data d1 = Data (10,20);
    d1.setData(2000);
    d1.setNum(3000);
    cout << "data : " << d1.printData() << endl;
    cout << "num : " << d1.printNum() << endl;
}


//int main(int argc, char *argv[])
//{
//    //const���γ�Ա����
//    test01();

//    //const���ζ���,������ ֻ�ܵ��ó��������� ��Ա����
//    test02();

//    return 0;
//}
