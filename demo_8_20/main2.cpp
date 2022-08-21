#include <iostream>

using namespace std;

void test07()
{
    int data = 10;
    int &a = data; //a����data�ı���
    //�������ڴ�ת��: int * const a = &data;

    a = 100; // �ȼ��� data = 100
    //*a = 100; //*a == data
}

#include <stdlib.h>
#include <string.h>
//C���Է�ʽ
void myStr(char** pStr) //pStr = &str
{
    *pStr = (char*)malloc(sizeof(char)*20);
    strcpy(*pStr,"hello world");
    return;
}
//C++��ʽ
void myStr2(char* &my_str) // char* &my_str = str; my_str�ȼ���str
{
    my_str = (char*)malloc(sizeof(char)*20);
    strcpy(my_str,"hello world");
    return;
}

void test08()
{
    char *str = NULL;
    //����,��װһ������ �Ӷ��� ��str����һ���ռ� ����ֵΪ "hello wolrd"
    //myStr(&str);
    myStr2(str);
    cout << "str = " << str << endl;
    free(str);
    str = NULL;
}


typedef struct
{
    int age;
    char name[32];
}STU;

void myPrintStu(STU tmp) //��ͨ�ṹ�������Ϊ�β� ����̫��
{
    cout << "����: " << tmp.name << " ����: " << tmp.age << endl;
}
//������,�޷���������ָ������ݣ���֤����ȫ
void myPrintStuPlus(const STU &tmp) //STU &tmp = stu; tmp��stu�ı��� tmpû�п��ٶ����ռ�
{
    //tmp.age = 100; // read-only
    cout << "����: " << tmp.name << " ����: " << tmp.age << endl;
}

void test09()
{
    STU stu = {23, "lucy"};

    //������һ������ ����stu
    //myPrintStu(stu);
    myPrintStuPlus(stu);

}

void test10()
{
    //������10ȡ���� Ϊnum
    //int & ��Ե���int, 10��const int����
    //int &num = 10;
    //const int & ��Ե���const int, 10��const int����
    const int &num = 10;

    cout << "num = " << num << endl;
}

int main(int argc, char *argv[])
{
    /* ���õı���
     * ���õı�����c++�ڲ�ʵ����һ������ָ��. Type& ref = val; // Type* const ref = &val
     * c++�������ڱ��������ʹ�ó���ָ����Ϊ���õ��ڲ�ʵ�֣�
     * ���������ռ�õĿռ��С��ָ����ͬ��ֻ����������Ǳ������ڲ�ʵ�֣����û����ɼ�
     */
    test07();

    //ָ�������
    test08();


    //������(��������)
    /*
     * [const ����ʹ�ó���] ����������Ҫ���ں������βΣ���������Ŀ���/���ƹ���
       ������ ���������βζ���Ϊ�������õĺô�: ���ò������µı����������β���ʵ
       �δ���ʱ�Ŀ����� �������ÿ��ܵ���ʵ�����βθı���ı䣬���䶨��Ϊ������
       �ÿ����������ָ����á� ���ϣ��ʵ�������βεĸı���ı䣬��ôʹ��һ���
       ���ã������ϣ��ʵ�������βθı䣬��ôʹ�ó����á�
     */
    test09();

    //����������
    test10();

    return 0;
}
