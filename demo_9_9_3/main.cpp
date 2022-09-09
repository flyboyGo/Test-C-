#include <iostream>

using namespace std;

//C++������ת��

//��̬ת�� static_cast
/*
 * �������νṹ�л��ࣨ���ࣩ�������ࣨ���ࣩ֮��ָ������õ�ת����
 * ��������ת�������������ָ�������ת���ɻ����ʾ���ǰ�ȫ�ģ�
 * ��������ת�����ѻ���ָ�������ת�����������ʾ��ʱ������û�ж�̬���ͼ�飬�����ǲ���ȫ�ġ�
 * ���ڻ�����������֮���ת������� int ת���� char���� char ת����int������ת���İ�ȫ��ҲҪ������Ա����֤
 */

class Animal{};
class Dog:public Animal{};
class Other{};

void test01()
{
    //static_cast ������ ��������
    char ch = 'a';
    double d = static_cast<double>(ch);
    cout << d << endl;

    //static_cast ������ �Զ�������(�ṹ�� ��)
    //��ϵ����֮��(��������)
    //����ת�� ��ȫ
    Animal* ob =static_cast<Animal *> (new Dog);
    //����ת�� ����ȫ
    Dog* ob2 = static_cast<Dog *>(new Animal);

    //static_cast ���������� ����ص���֮��ת��
    //Animal * ob3 = static_cast<Animal *>(new Other); // error
    //Animal * ob3 = (Animal *)(new Other); //������ ���ǳ�ΣΣ��
}


//��̬ת�� dynamic_cast
/*
 * dynamiccast ��Ҫ�������μ������ת��������ת����
 * �����μ��������ת��ʱ,dynamiccast �� staticcast ��Ч����һ���ģ�
   �ڽ�������ת��ʱ��dynamiccast �������ͼ��Ĺ��ܣ��� static_cast ����ȫ��
 */
void test02()
{
    //1��dynamic_cast��֧�ֻ�����������
    //char ch = 'a';
    //double d = dynamic_cast<double>(ch); //error

    //2��dynamic_cast ����ת�� (����ָ�� ָ�� ����ռ� ��ȫ)
    Animal * p1 = dynamic_cast<Animal *>(new Dog);

    //3��dynamic_cast ����ת�� (����ָ�� ָ�� ����ռ� ����ȫ)
    //Dog * p2 = dynamic_cast<Dog *>(new Animal); //��֧�� ����ȫ��ת��

    //4��dynamic_cast ��֧�� û�й�ϵ�� ����ת��

}

//����ת�� const_cast
/*
 *  ������������޸����͵� const ���ԡ�
 *  ����ָ�뱻ת���ɷǳ���ָ�룬������Ȼָ��ԭ���Ķ���
    �������ñ�ת���ɷǳ������ã�������Ȼָ��ԭ���Ķ���

    ע��:����ֱ�ӶԷ�ָ��ͷ����õı���ʹ�� const_cast ������ȥֱ���Ƴ�����const
 */

void test03()
{

    const int *p = NULL;
    int *p1 = const_cast<int *> (p);

    int *p2 = NULL;
    const int * p3 = const_cast<const int *>(p2);

    //const_cast ��֧�� ��ָ�롢�����õ�ת��
    const int a = 100;
    //int b = const_cast<int>(a); //error

    int data = 100;
    //������ ת���� ��ͨ����
    const int &ob = data;
    int &ob2 = const_cast<int &> (ob);
}


//���½���ת��(reinterpret_cast) ������ ǿ������ת��
/*
 * �������ȫ��һ��ת�����ƣ����п��ܳ����⡣
 * ��Ҫ���ڽ�һ���������ʹ�һ������ת��Ϊ��һ�����͡�
 * �����Խ�һ��ָ��ת����һ��������Ҳ���Խ�һ������ת����һ��ָ��.
 */

void test04()
{
    //��֧�� ������������
    float ch = 3.14f;
    //double d = reinterpret_cast<double>(ch); //error

    //û�й�ϵ����֮��Ĳ��� �������
    Animal *p1 = reinterpret_cast<Animal *>(new Other); //�ǳ�Σ�յĲ���
}

int main(int argc, char *argv[])
{
    //test01();

    //test02();

    //test03();

    test04();

    return 0;
}
