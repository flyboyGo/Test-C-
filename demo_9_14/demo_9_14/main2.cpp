#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

/*
* 3.7.3  ����(pair)
����(pair)��һ��ֵ��ϳ�һ��ֵ����һ��ֵ���Ծ��в�ͬ���������ͣ�
����ֵ���Էֱ��� pair �������������� first �� second ���ʡ� 
��ģ�壺template <class T1,class T2> struct pair. ��δ�������?
*/

void test05()
{
	//�������ķ�ʽһ
	//pair<int, string> pair(9527, "��ү");
	//cout << "��ţ�" << pair.first << ", ���" << pair.second << endl;

	//�������ķ�ʽ��
	pair<int, string> pair2 = make_pair(10086,"�ƶ�");
	cout << "��ţ�" << pair2.first << ", ���" << pair2.second << endl;
}

//int main(int argc, char* argv[])
//{
//	test05();
//
//	return 0;
//}