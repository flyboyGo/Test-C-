#include <iostream>

using namespace std;

/*
 * c++����Ҫ�������Ǵ������ã�ͨ���̳л��ƿ����������е����������������µ�
   �������ͣ��µ��಻��ӵ�о���ĳ�Ա����ӵ���¶���ĳ�Ա�� һ�� B ��̳���
   A �࣬��ƴ��� A ������ B�������Ļ����� A ��Ϊ���ࣨ���ࣩ�� �� B ��Ϊ����
   �ࣨ���ࣩ�� �������еĳ�Ա���������󲿷֣� һ���Ǵӻ���̳й����ģ�һ��
   ���Լ����ӵĳ�Ա�� �ӻ���̳й������ı����乲�ԣ��������ĳ�Ա����������ԡ�
 */

//�̳л������ĸ�ʽ
/*
 * �����ඨ���ʽ��
     Class �������� : �̳з�ʽ ������{
        ���������������ݳ�Ա�ͳ�Ա����
     }

    ���ּ̳з�ʽ�� public �� ���м̳� private �� ˽�м̳� protected �� �����̳�

    �Ӽ̳�Դ�Ϸ֣�
    ���̳У�ָÿ��������ֱֻ�Ӽ̳���һ�����������
    ��̳У�ָ�������������һ��������ļ̳й�ϵ,��̳е�������ֱ�Ӽ̳��˲�ֹһ�����������
 */

/*ע���:
 * ������̳л��࣬������ӵ�л�����ȫ����Ա�����ͳ�Ա���������˹��������֮��ĳ�Ա��������
 * �������������У��̳еĳ�Ա����һ����ֱ�ӷ��ʣ���ͬ�ļ̳з�ʽ�ᵼ�²�ͬ�ķ���Ȩ��
 */

//����һ������
class Base
{
public:
    int a;
private:
    int b;
protected:
    int c;
};

//����һ������(�����̳�)
class Son:public Base
{
public:
    //�����е�public ������������ Ҳ��public
    //�����е�private ������������ �ǲ��ɼ���
    //�����е�protected ������������ ��protected

    //������ڲ�
    void setData(void)
    {
        this->a = 100; //���ⲿ���Է���
        //this->b = 200; //error ���ɼ� �����ⲿ�޷�����
        this->c = 300; //���ⲿҲ�޷�����
    }

};

void test01()
{
    //������ⲿ
    Son son = Son();
    son.setData();

    cout << "a = " << son.a << endl;
    //cout << "b = " << son.b << endl;
    //cout << "c = " << son.c << endl;

}

/*
 * �ܽ᣺ public�̳�
     �����е�public����  �������� Ҳ��public
     �����е�private���� �������� �ǲ��ɼ���
     �����е�protected���� �������� ��protected��
    ��public �̳�  �����е�˽������ ������ ���ɼ� ��������ԭ����
 */


//����һ������(�����̳�)
class Son2:protected Base
{
    //�����е�public ������������ Ҳ��protected
    //�����е�private ������������ �ǲ��ɼ���
    //�����е�protected ������������ ��protected
public:
    void setData(void)
    {
        this->a = 100; //���ⲿ�����Է���
        //this->b = 200;//error ���ɼ� �����ⲿ�޷�����
        this->c = 300;//���ⲿ�����Է���
    }
};

void test02(void)
{
    Son2 son = Son2();
    son.setData();

    //cout << "a = " << son.a << endl;
    //cout << "b = " << son.b << endl;
    //cout << "c = " << son.c << endl;
}

/*�ܽ᣺  protected�̳�
    �����е�public����  �������� Ҳ��protected
    �����е�private���� �������� �ǲ��ɼ���
    �����е�protected���� �������� ��protected��
   �������̳�  �����˽������ �������� ���ɼ�  �������� ���䱣����
 */


//����һ������(˽�м̳�)
class Son3:private Base
{
    //�����е�public ������������ Ҳ��private
    //�����е�private ������������ �ǲ��ɼ���
    //�����е�protected ������������ ��private
public:
    void setData(void)
    {
        this->a = 100; //���ⲿ�����Է���
        //this->b = 200;//error ���ɼ� ���ⲿ�޷�����
        this->c = 300;//���ⲿ�����Է���
    }
};

void test03(void)
{
    Son3 son = Son3();
    son.setData();

    //cout << "a = " << son.a << endl;
    //cout << "b = " << son.b << endl;
    //cout << "c = " << son.c << endl;
}

/*
 * �ܽ᣺ private˽�м̳�
   �����е�public����  �������� Ҳ��private
   �����е�private���� �������� �ǲ��ɼ���
   �����е�protected���� �������� ��private��
  ��˽�м̳�  �����е�˽�������������� ���ɼ�  �������˽�У�
 */

//int main(int argc, char *argv[])
//{
//    test01();

//    test02();

//    test03();

//    return 0;
//}
