#include <iostream>

using namespace std;

class Data
{
friend ostream& operator<<(ostream &out, Data &data);
friend Data& operator--(Data &data);
friend Data operator--(Data &data, int);

private:
    int a;
    int b;
public:
    Data()
    {
        a = 0;
        b = 0;
        cout << "�޲ι���" << endl;
    }
    Data(int a, int b):a(a),b(b) //��ʼ���б�
    {
//        this->a = a;
//        this->b = b;
        cout << "�вι���" << endl;
    }
    void showData(void)
    {
        cout << "a = " << a << " b = " << b << endl;
    }

    ~Data()
    {
        cout << "��������" << endl;
    }

    //��Ա���� ���� ǰ��++����� ++ob1
    //������  Ĭ��ʶ�� operator++(a) ����a������this���� �Ӷ��� operator++()
    Data& operator++()
    {
       //�ȼӼ�
       this->a++;
       this->b++;

       //��ʹ��
       return *this;
    }

    //��Ա���� ���� ����++����� ob1++
    //������  Ĭ��ʶ�� operator++(a,int) ����a������this���� �Ӷ��� operator++(int)
    Data operator++(int)
    {
        //��ʹ��(���ݼ�֮ǰ��ֵ)
        Data old = *this;

        //��Ӽ�
        this->a++;
        this->b++;

        //ע�⣺��Ҫ���ؾֲ����������� �ֲ���������ǰ�ͷ�
        return old;
    }

};

//��ͨȫ�ֺ��� ��Ϊ�����Ԫ "����" << �����
ostream& operator<<(ostream &out, Data &data)
{
    out << "a = " << data.a << " b = " << data.b;
    return out;
}

void test01()
{
    Data d1 = Data(10,20);
    Data d2 = Data(30,40);
    d1.showData();

    //���������<< ����Զ���������Ϣ
    operator<<(cout,d1);
    cout << d1 << d2 << endl;
}

/*
 * ���統����������++a(ǰ��++)�����͵��� operator++(a),
 * ������������ a++������++�������ͻ�ȥ���� operator++(a,int)
 */


//��Ա������ɶ�++������
void test02()
{
    Data d1 = Data(10,20);
    //++d1
    cout << ++d1 << endl; // �ȼ���  d1.operator++();
    cout << d1.operator ++() << endl;

    Data d2 = Data(100,200);
    //d2++
    cout << d2 << endl;

    Data tmp = d2++; //�ȼ���Data tmp = d2.operator ++(0);
    cout << tmp << endl;
    cout << d2 << endl;
}

//��ͨ��ȫ�ֺ�����ɶ�--������
//ǰ��--
Data& operator--(Data &data)
{
    data.a--;
    data.b--;

    return data;
}

//����--
Data operator--(Data &data, int)
{
    //���Խ�tmp����Ϊstatic �����Ϳ��Է��ر���������
    //��Ϊ��������static���ͱ������ڵĿռ䲻�ᱻ��ǰ�ͷ�
    Data tmp = data;

    data.a--;
    data.b--;

    return tmp;
}

void test03()
{
    //ǰ��
    Data d1 = Data(10,20);
    cout << operator--(d1) << endl;
    cout << --d1 << endl;

    //����
    Data d2 = Data(100,200);
    //�������ؾֲ����� ����������ʱ������������ ���߾ֲ����������ͷſռ�
    Data tmp = d2--;//�ȼ��� Data tmp = operator--(d2,0);
    cout << tmp << endl;
    cout << d2 << endl;

}

//ע�⣺����Ա���� ����ͨȫ�ֺ���������ʵ�����������ʱ ����ѡ���Ա����!!!!!!

//int main(int argc, char *argv[])
//{
//    test01();

//    test02();

//    test03();

//    return 0;
//}
