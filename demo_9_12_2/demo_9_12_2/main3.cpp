#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <deque>
#include <algorithm>
#include <time.h>

using namespace std;

//srand()��rand() ���������

int main(int argc, char* argv[])
{
	//������������� Ĭ������Ϊ 1
	//ϵͳ��ʱ����Ϊ����
	srand(time(NULL)); 

	for (int i = 0; i < 10; i++)
	{
		//rand()�����ķ���ֵ��������� α��� Ĭ�ϻ�׼ֵ�� 1
		int num = rand() % 10 + 1; //���� 1 ~ 10 �������
		cout << num << endl;
	}

	return 0;
}