#include <iostream>

using namespace std;

///////////�����ռ����

namespace veryLongName
{
     int b = 100;
     void func()
     {
         cout << "hello namespace" << endl;
     }
}

void test07()
{
    int b = 200; //�ֲ�����a
    //cout << "b = " << veryLongNmae::b << endl;
    //veryLongNmae::func();

    //ʹ��veryLongName�����ռ䣬��λ�����µı���������,���ȵ������ռ���Ѱ��
    using namespace veryLongName;

    //���ֵı���,�ȴ�veryLongName�����ռ���Ѱ��,�Ҳ���,�������ط�Ѱ��(�ֲ�������ȫ�ֱ�����std��׼�����ռ�)
    //���´�����ܳ��ֱ��������ĳ�ͻ
    cout << "b = " << b << endl; //���ʵ��Ǿֲ������е�b(�ֲ����������ȼ����������ռ��ֵı���(�����ռ�����ȫ��))
    cout << "b = " << veryLongName::b << endl; //���ʵ��������ռ��е�b
    func();
}


int b = 450; //ȫ�ֱ���
void test08()
{
    //int b = 450; //error
    //ָ��  ʹ�������ռ�ľ����Ա,���׺�����������ͻ(ͬ���ľֲ�����)
    //ֱ��ʹ�������ռ��еĳ�Ա��;ֲ�������ͻ(����ȫ�ֱ�����ͻ)
    using veryLongName :: b;
    cout << "�����ռ��е�b = " << b << endl;//����ѡ�������ռ��еĳ�Ա
    cout << "ȫ�ֱ���b = " << ::b << endl;

    //���ǵ��������ռ��������Ա,��Ȼ��Ҫָ�������ռ�
    veryLongName::func();
}

namespace I
{
   //��������
   void func(){cout << "�޲ε�func" << endl;}
   //func_void
   void func(int a){cout << "int��func" << endl;}
   //func_int
   void func(int a,int b){cout << "int int��func" << endl;}
   //func_int_int

   //C���Բ�֧�ֺ�������,��ΪC�����к�����������Ǻ�����ڵ�ַ
   //C++�� ������ + ���� ��ϴ�����Ǻ�������ڵ�ַ

   int d = 490;
}
void test09()
{
    //usingָ�� ʹ��I�е�func��� "���е�func" ������
    using I::func;

    func();
    func(1);
    func(1,2);
}



namespace J
{
   int d = 370;
}
void test10()
{
    using namespace I;
    using namespace J;

    //��ͬ�������ռ京��ͬ���ĳ�Ա����,ʹ��ʱע�����������
    //cout << "d = " << d << endl;//'d' is ambiguous

    //�������
    cout << "I�е�d = " << J::d << endl;
    cout << "J�е�d = " << I::d << endl;
}

//int main(int argc, char *argv[])
//{
//    //usingָ�� ʹ��ĳ�������ռ�
//    test07();

//    //usingָ�� ʹ��ĳ�������ռ��ĳ�������Ա
//    test08();

//    //usingָ�����غ���
//    test09();

//    //��ͬ�����ռ��е� ͬ����Ա ʹ�õ�ʱ��ע�������
//    test10();

//    /*�ܽ�
//     * 1�������ռ�Ķ���(������ ������ ���������ռ�)
//     * 2��ʹ�������ռ��еĳ�Ա �ȫ�ķ�ʽ �����ռ���::��Ա��
//     * 3��using namespace �����ռ���; ʹ�����������ռ�
//     * 4������ ʹ�������ռ��еľ����Ա: using �����ռ���::��Ա��
//     */

//    return 0;
//}
