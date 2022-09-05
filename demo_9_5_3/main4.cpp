#include <iostream>

using namespace std;

//�̳еĶ���  ��̳�
//���� �������
/* �﷨��ʽ
 *  class ���� : virtual public ����
 *  {
 *      ......
 *  }
 */

class animal
{
public:
    int data;
};
//sheep��̳�animal ����animal�������
class sheep : virtual public animal
{
public:

};
//camel��̳�animal ����animal�������
class camel : virtual public animal
{
public:

};

class alpaca :  public sheep, public camel
{
public:

};

/* vbptr(�����ָ�� vbptrָ��������) ����v��virtual���� b��base���� ptrָ��
 * vbtable(������ ������������ �Ĳ��� dataƫ����)
 * �ܽ�: ֮���Բ���vbptr��vbtable Ŀ�� ��֤���ܶ��ٸ��̳� ����������ֻ��һ��
 */

void test04()
{
    alpaca a = alpaca();
    a.data = 100;
    cout << a.data << endl;

    cout << sizeof(animal) << endl; //4
    cout << sizeof(sheep) << endl; // 8
    cout << sizeof(camel) << endl; // 8
    cout << sizeof(alpaca) << endl; // 12
}

int main(int argc, char *argv[])
{
    test04();

    return 0;
}
