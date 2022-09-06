#include <iostream>

using namespace std;

//1����̬�ĸ���
/*
 * ��̬��C++��������̵�����֮һ
 * ��̬�ķ��ࣺ��̬��̬(��̬����)����̬��̬(��̬����)
 * ��̬��̬(��̬����)����������ڵ�ַ ���� ����׶� ȷ�� (��������ء���������) ���
 * ��̬��̬(��̬����)����������ڵ�ַ ���� ���н׶� ȷ�� (�麯��) ���
 */

//2������

class Animal
{
public:
    //�麯�� ֻҪ�漰���̳� ������ͬ���������� �麯��
    //�麯�� ���� ��һ������ָ�����
    virtual void sleep(void)
    {
        cout << "Animal ����˯��" << endl;
    }
};

class Cat:public Animal
{
public:

    virtual void sleep(void)
    {
        cout << "Cat è˯��" << endl;
    }
};

void test01()
{
//    Cat cat = Cat();
//    cat.sleep();
//    cat.Animal::sleep();

    //�û���(ָ�������) ���� ������� (����ת��)
    Animal *animal = new Cat;
    animal->sleep(); //���õ��ǻ����sleep

    Cat cat;
    Animal &animal2 = cat;
    animal->sleep(); //���õ��ǻ����sleep

    //������(ָ�������) ���� ������� (����ת��) (����ȫ)
    //Cat *cat = new Animal; //error
    //cat->sleep();

    //�ܽ�:�û���ָ�롢���� ֻ�ܷ��� ��������� ���ಿ�� ����
}


void test02()
{
    //����ʹ�û���ָ�롢���� ���� ������� ���ҿ��Է��ʡ����������Ա����(�麯��)
    /*
     * �麯�� ʹ��virtual���γ�Ա���� �ó�Ա���������麯����
     * ��ʱ�������ɣ�vfptr��vftable
     * vfptr�麯��ָ�� ָ������麯����(vftable)
     * vftable���ŵ��� �麯��������ĺ�����ڵ�ַ
     */
    Animal *animal = new Cat;
    animal->sleep();
}

void test03()
{
    //�麯�� ���� ��һ������ָ�����
    //1����� ӵ���麯���� Animalû���漰�����̳� ����ָ����� ��ָ�������sleep()
    Animal ob;
    ob.sleep();
}

void test04()
{
    //2����� ӵ���麯���� Animal�漰�����̳� ����ָ����� ��ָ��������ͬ����sleep()
    Animal ob;
    ob.sleep();

    /*
     * �ܽ�:
     * ���麯���漰���̳е�ʱ�� ����� �̳� ����� (�麯��ָ��vfptr �麯����vftable).
     * �������Ὣ�麯����ڵ�ַ ���³����� ͬ��(����ֵ����������ͬ) �ĺ�����ַ
     * �������ָ�롢���� �����麯����ʱ�� �ͻ� ��ӵĵ��� ������麯��
     */
}


//int main(int argc, char *argv[])
//{

//    //test01();

//    //test02();

//    //test03();

//    test04();

//    return 0;
//}
