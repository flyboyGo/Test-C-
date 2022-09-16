#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//�����㷨

/*
* for_each(iterator beg, iterator end, _callback);  �����㷨 ��������Ԫ��
@param beg ��ʼ������   @param end ����������
@param _callback �����ص����ߺ�������  @return ��������
*/
void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	for_each(v.begin(), v.end(), [](int val) {
		cout << val << " ";
	});
	cout << endl;
}

/*
transform(iterator beg1, iterator end1, iterator beg2, _callbakc);
transform �㷨 ��ָ����������Ԫ�ذ��˵���һ������
ע�� : transform �����Ŀ�����������ڴ棬������Ҫ���� "��ǰ������ڴ�"
@param beg1 Դ������ʼ������    @param end1 Դ��������������
@param beg2 Ŀ��������ʼ������  @param _cakkback �ص��������ߺ�������(����������ֵ ���ݸ�Ŀ������)
@return ����Ŀ������������
*/

int myTransInt(int val)
{
	return val;
}

class MyTransInt
{
public:
	int operator()(int val)
	{
		return val;
	}
};

void test02()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);

	vector<int> v2;
	//Ԥ�ȣ�����v2�Ĵ�С
	//v2.reserve(v1.size()); //error ֻ��Ԥ�����㹻�Ŀռ� �ռ仹�����롢��ʼ��,�޷�ֱ��ʹ��
	v2.resize(v1.size());
	cout << "size = " << v2.size() << endl; // 0
	cout << "capacity = " << v2.capacity() << endl; // 4
	

	//��v1�е�Ԫ�ذ��˵�v2��
	//���˵Ĺ��� ������������ռ� ֻ�ǵ����������ķ���ֵ ��ֵ�� Ŀ������
	//��ͨ����
	//transform(v1.begin(), v1.end() - 1, v2.begin(), myTransInt);
	//�º���
	transform(v1.begin(), v1.end(), v2.begin(), MyTransInt());

	for_each(v2.begin(), v2.end(), [](int val) {
		cout << val << " ";
	});
	cout << endl;
}


//int main(int argc, char* argv[])
//{
//	test01();
//
//	test02();
//
//	return 0;
//}