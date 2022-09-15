#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

//set�����ĸ���
/*
* set�����е����������Ԫ�ص� "��ֵ" �Զ�������
* Set ��Ԫ�ز��� map ��������ͬʱӵ��ʵֵ�ͼ�ֵ��set ��Ԫ�ؼ��Ǽ�ֵ����ʵֵ��
* Set ����������Ԫ������ͬ�ļ�ֵ��
* set�����ṩ����"ֻ��������"(�������û��޸�Ԫ�ص�����)
*/

/*
* 3.7.2.1 set ���캯��
set<T> st;//set Ĭ�Ϲ��캯����
mulitset<T> mst; //multiset Ĭ�Ϲ��캯�� :
set(const set &st);// �������캯��

3.7.2.2 set ��ֵ����
set& operator=(const set &st);// ���صȺŲ�����
swap(st);// ����������������

3.7.2.3 set ��С����
size();// ����������Ԫ�ص���Ŀ
empty();// �ж������Ƿ�Ϊ��

*/
void test01()
{
	set<int> s = set<int>(); //set�������ݼ�ֵ�Զ�����
	s.insert(30);
	s.insert(10);
	s.insert(50);
	s.insert(20);
	s.insert(40);

	for_each(s.begin(), s.end(), [](int val) {
		cout << val << " ";
	}); // 10 20 30 40 50
	cout << endl;

	//set�����ṩ����ֻ��������const_iterator
	//�û��������޸�set������Ԫ��
	set<int>::iterator it = s.begin();
	//(*it) = 100; // error

	cout << "size = " << s.size() << endl;
}

/*
3.7.2.4 set �����ɾ������
insert(elem);// �������в���Ԫ�ء�
clear();// �������Ԫ��
erase(pos);// ɾ�� pos ��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
erase(beg, end);// ɾ������ [beg,end) ������Ԫ�� ��������һ��Ԫ�صĵ�������
erase(elem);// ɾ��������ֵΪ elem ��Ԫ�ء�
*/

void test02()
{
	set<int> s = set<int>(); //set�������ݼ�ֵ�Զ�����
	s.insert(30);
	s.insert(10);
	s.insert(50);
	s.insert(20);
	s.insert(40);

	//����Ԫ�ص�λ��ֱ��ɾ��
	s.erase(s.begin());

	for_each(s.begin(), s.end(), [](int val) {
		cout << val << " ";
		});
	cout << endl;

	//����Ԫ��ֱ��ɾ��
	s.erase(30);

	for_each(s.begin(), s.end(), [](int val) {
		cout << val << " ";
		});
	cout << endl;
}

/*
* 3.7.2.5 set ���Ҳ���
find(key);// ���Ҽ� key �Ƿ����,������,���ظü���Ԫ�ص�"������";��������,���� set.end();
count(key);// ���Ҽ� key ��Ԫ�ظ���
*/

void test03()
{
	set<int> s = set<int>(); //set�������ݼ�ֵ�Զ�����
	s.insert(30);
	s.insert(10);
	s.insert(50);
	s.insert(20);
	s.insert(40);

	//find(key);
	//���Ҽ� key �Ƿ����,������,���ظü���Ԫ�ص�"������";��������,���� set.end();
	set<int>::const_iterator ret = s.find(20); //����Ԫ�صĵ�����
	if (ret == s.end())
	{
		cout << "û�ҵ�" << endl;
	}
	else
	{
		cout << "Ԫ��Ϊ��" << *ret << endl;
	}

	//count(key);// ���Ҽ� key ��Ԫ�ظ��� ����ֵֻ��Ϊ 1 �� 0
	//set�����ļ�ֵ �ǲ��ظ���
	cout << s.count(10) << endl; //1
	cout << s.count(60) << endl; //0
}

/*
* 3.7.2.5.2 set ���Ҳ���
lower_bound(keyElem);// ���ص�һ�� key>=keyElem Ԫ�ص� "������"(����)��
upper_bound(keyElem);// ���ص�һ�� key>keyElem Ԫ�ص� "������"(����)
equal_range(keyElem);// ���������� key �� keyElem ��ȵ������޵� "����������"��
*/

void test04()
{
	set<int> s = set<int>(); //set�������ݼ�ֵ�Զ�����
	s.insert(30);
	s.insert(10);
	s.insert(50);
	s.insert(20);
	s.insert(40);

	for_each(s.begin(), s.end(), [](int val) {
		cout << val << " ";
		});
	cout << endl;
	
	//lower_bound(keyElem);// ���ص�һ�� key>=keyElem Ԫ�ص� "������"(����)��
	set<int>::const_iterator lower_ret = s.lower_bound(30);
	if (lower_ret == s.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "����Ϊ��" << *lower_ret << endl;
	}

	//upper_bound(keyElem);// ���ص�һ�� key>keyElem Ԫ�ص� "������"(����)
	set<int>::const_iterator upper_ret = s.upper_bound(30);
	if (upper_ret == s.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "����Ϊ��" << *upper_ret << endl;
	}

	//equal_range(keyElem);// ���������� key �� keyElem ��ȵ������޵� "����������"
	//equal_range ���ص��Ƕ���
	//first �����еĵ�һ��ֵ  second �����еĵڶ���ֵ 
	pair<set<int>::const_iterator, set<int>::const_iterator> pair_ret;
	pair_ret = s.equal_range(30);
	//����lower_bound
	if (pair_ret.first == s.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "����Ϊ��" << *pair_ret.first << endl;
	}
	//����upper_bound
	if (pair_ret.second == s.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "����Ϊ��" << *pair_ret.second << endl;
	}
}

//int main(int argc, char* argv[])
//{
//
//	//test01();
//
//	//test02();
//
//	//test03();
//
//	test04();
//
//	return 0;
//}