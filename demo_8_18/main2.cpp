#include <iostream>

using namespace std;

/////C++�Խṹ�����ǿ��bool���͵����ӡ���Ŀ���������ǿ

struct stu
{
    int age;
    char name[32];

    //��Ա����
    void walk(void)
    {
        cout << name << " ɢ��" << endl;
    }
};

void test02()
{
    //C++�п��Բ�ʹ�ùؼ���struct
    struct stu li = {100, "������"};
    stu jack = {100, "������"};
    cout << "����: " << li.name << " ����: " << li.age << endl;
}

void test03()
{
    struct stu fly = {23,"flyboy"};
    fly.walk();
}

void test04()
{
     bool mybool;
     cout << "sizeof(bool)" << sizeof(mybool) << endl;
     mybool = true;
     cout << "mybool = " << mybool << endl; // 1

     mybool = false;
     cout << "mybool = " << mybool << endl; // 0

     mybool = -10;
     cout << "mybool = " << mybool << endl; // 1
}

void test05()
{
    int a = 10;
    int b = 20;
    cout << "c++��:%d = " << (a > b ? a : b) << endl;

    //a > b ? a : b�������Ǳ������� ��ֵ (���Ա���ֵ)

    a > b ? a : b = 100; // b = 100;
}

//int main(int argc, char *argv[])
//{
//    //1��C�ж���ṹ����Ҫʹ��struct�ؼ���,C++�в���Ҫʹ��
//    test02();

//    //2��C++�нṹ���п��Զ����Ա����,C��ֻ�ܶ����Ա����
//    //C++���ó�Ա����
//    test03();

//    //3��bool��������
//        //��׼c++�� bool_�����������ڽ��ĳ���true(ת��Ϊ����1)�� false(ת��Ϊ����0)��ʾ״̬��
//        //���������ֶ��ǹؼ��֡�bool_����ֻ������ֵ��true(1 ֵ)��false(Oֵ)
//        //bool_����ռ1���ֽڴ�С��bool_���͸�ֵʱ���ǧ�ֵ���Զ�ת��Ϊtrue(1),0ֵ���Զ�ת��false(0)

//        //C������C99��׼֮ǰ��û��bool�ؼ��ֵ�,C99֮������<stdbool.h>����ʹ�ú�C++һ����bool����
//    test04();

//    //4����Ŀ��������ܸ���ǿ
//        //C��������Ŀ������ʽ����ֵΪ����������ֵ,����ֵ,ҲΪ��ֵ,���ܱ���ֵ
//        //C++��������Ŀ������ʽ����ֵΪ��������(����),Ϊ��ֵ,���Ա���ֵ
//    test05();
//    /*
//     *[��ֵ����ֵ����]��c++�п��Է��ڸ�ֵ��������ߵ�����ֵ�����Էŵ���ֵ���������������ֵ��
//     * ��Щ���������Ե���ֵ��Ҳ���Ե���ֵ��
//     * ��ֵΪLvalue��L���� Location����ʾ�ڴ����Ѱַ�����Ը�ֵ��
//     * ��ֵΪRvalue��R���� Read,���ǿ���֪������ֵ������:int temp = 10;
//     * temp���ڴ����е�ַ��10û�У����ǿ�Read������ֵ
//     */

//    return 0;
//}
