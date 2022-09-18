#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
* �ļ�������
* 1���ı��ļ����ļ����ı���ASCLL�����ʽ�洢�ڼ������
* 2���������ļ����ļ����ı��Ķ�������ʽ�洢�ڼ������,�û�һ�㲻��ֱ�Ӷ�������
* 
* �����ļ���������
* 1��ofstream��д����
* 2��ifstream��������
* 3��fstream����д����
*/

//�ı��ļ�  д�ļ�
void test01()
{
	//1������ͷ�ļ� fstream

	//2������������
	ofstream ofs;

	//3��ָ���ļ��Ĵ򿪷�ʽ
	ofs.open("test.txt",ios::out);

	//4��д�ļ�
	ofs << "������������  ���䣺25" << endl;
	ofs << "�Ա���  ���᣺�����γ�" << endl;

	//5���ر��ļ�
	ofs.close();
}

//�ı��ļ� ���ļ�
void test02()
{
	//1������ͷ�ļ� fstream

	//2������������
	ifstream ifs;

	//3��ָ���ļ��Ĵ򿪷�ʽ���ж��Ƿ�ɹ�
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��!" << endl;
		return;
	}

	//4�����ļ�
	//��һ�ַ�ʽ
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}

	//�ڶ��ַ�ʽ
	//char buf[100] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf <<endl;
	//}

	//�����ַ�ʽ
	string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;;
	}

	//�����ַ�ʽ
	//char c;
	//while ((c = ifs.get()) != EOF) // EOF end of file
	//{
	//	cout << c;
	//}

	//5���ر��ļ�
	ifs.close();
}

//int main(int argc, char* argv[])
//{
//    //test01();
//
//	test02();
//
//	return 0;
//}