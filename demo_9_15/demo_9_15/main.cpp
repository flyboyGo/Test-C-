#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

//map��������
/*
* 
1��Map �������ǣ�����Ԫ�ض������Ԫ�صļ�ֵ�Զ�����
2��Map ���е�Ԫ�ض���pair,ͬʱӵ��ʵֵ�ͼ�ֵ,pair �ĵ�һԪ�ر���Ϊ��ֵ,�ڶ�Ԫ�ر���Ϊʵֵ
   map ����������Ԫ������ͬ�ļ�ֵ
3�����ǿ���ͨ�� map �ĵ������ı� map �ļ�ֵ�𣿴��ǲ���,��Ϊ map �ļ�ֵ��ϵ�� map Ԫ�ص����й���
   ����ı� map��ֵ���������ƻ� map ��֯�������Ҫ�޸�Ԫ�ص�ʵֵ����ô�ǿ��Եġ�
   Map�����ļ�ֵ���ɱ�,ʵֵ���ɱ�
4��Multimap �� map �Ĳ������ƣ�Ψһ���� multimap ��ֵ���ظ���Map �� multimap �����Ժ����Ϊ�ײ�ʵ�ֻ���
*/

/*
* 3.8.2 map/multimap  ���� API

3.8.2.1 map ���캯��
map<T1, T2> mapTT;//map Ĭ�Ϲ��캯�� :
map(const map &mp);// �������캯��

3.8.2.2 map ��ֵ����
map& operator=(const map &mp);// ���صȺŲ�����
swap(mp);// ����������������

3.8.2.3 map ��С����
size();// ����������Ԫ�ص���Ŀ
empty();// �ж������Ƿ�Ϊ��

3.8.2.4 map ��������Ԫ�ز���
map.insert(...); // ����������Ԫ�أ����� pair<iterator,bool>
map<int, string> mapStu;
// ��һ�� ͨ�� pair �ķ�ʽ�������
mapStu.insert(pair<int, string>(3, "С��"));
// �ڶ��� ͨ�� pair �ķ�ʽ�������
mapStu.inset(make_pair(-1, "У��"));
// ������ ͨ�� value_type �ķ�ʽ�������
mapStu.insert(map<int, string>::value_type(1, "С��"));
// ������ ͨ������ķ�ʽ����ֵ
mapStu[3] = "С��";
mapStu[5] = "С��";
*/

void myPrintfMap(map<int, string> &map)
{
	for (auto it = map.begin(); it != map.end(); it++)
	{
		cout << (*it).first << " = " << (*it).second << endl;
	}
}

void test01()
{
	
	//int Ϊ��ֵ������ string��Ϊʵֵ������
	map<int, string> map;

	//����ĵ�һ�ַ�ʽ
	map.insert(pair<int,string>(9527,"��ү"));

	//����ĵڶ��ַ�ʽ
	map.insert(make_pair(10086,"�ƶ�"));

	//����ĵ����ַ�ʽ
	//map.insert(map<int, string>::value_type(10010, "��ͨ"));

	//����ĵ����ַ�ʽ ��ȡmap����ʱ �Ƽ�
	map[10010] = "����"; //�ȼ���map.insert(pair<int,string>(10010,"����"));
	
	//map[10] Ѱ��keyΪ10��ʵֵ
	//cout << map[10] << endl;(������ʽ�ķ��� 10����Ǵ��ڵ�)
	//������� ������û�� keyΪ10  �ᴴ��һ�� keyΪ10 ʵֵΪ��ֵ �Ķ���
	//�����������keyΪ10 ��ômap[10]����key = 10��ʵֵ

	//ֻ��鿴key == 9527�� ʵֵ(ʵֵȷʵ����)
	cout << map[9527] << endl;

	//(ʵֵ��һ������)
	auto ret = map.find(10086);
	if (ret == map.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		//ret�������keyΪ10085�Ķ���ĵ�����
		cout << "�ҵ���ؽڵ㣺" << "key = "<< (*ret).first << "��value = " << (*ret).second << endl;
	}
	

	//����map���� ��һ�ַ�ʽ
	for_each(map.begin(), map.end(), [](pair<int,string> val) {
		cout << val.first << " = " << val.second << endl;
	});

	//����map���� �ڶ��ַ�ʽ
	myPrintfMap(map);
}

/*
* 3.8.2.5 map ɾ������
clear();// ɾ������Ԫ��
erase(pos);// ɾ�� pos ��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
erase(beg,end);// ɾ������ [beg,end) ������Ԫ�� ��������һ��Ԫ�صĵ�������
erase(keyElem);// ɾ�������� key Ϊ keyElem �Ķ��顣

3.8.2.6 map ���Ҳ���
find(key);// ���Ҽ� key �Ƿ���� , �����ڣ����ظü���Ԫ�صĵ��������������ڣ����� map.end();
count(keyElem);// ���������� key Ϊ keyElem �Ķ��������
               �� map ��˵��Ҫô�� 0 ��Ҫô�� 1 ���� multimap ��˵��ֵ���ܴ��� 1 ��

lower_bound(keyElem);// ���ص�һ�� key>=keyElem Ԫ�صĵ�������
upper_bound(keyElem);// ���ص�һ�� key>keyElem Ԫ�صĵ�������
equal_range(keyElem);// ���������� key �� keyElem ��ȵ������޵�������������
*/

//map������vector�������ʹ��
//������4��ս�� �����ǩ���� ���ӡ����˳��
#include<numeric> //���ٵ��㷨
void test02()
{
	//ս������(ս�ӱ�š�ս������)
	map<int, string> map;
	map.insert(make_pair(1, "RNG"));
	map.insert(make_pair(2, "IG"));
	map.insert(make_pair(3, "EDG"));
	map.insert(make_pair(4, "WE"));

	//ʹ��vector�������վ�ӱ��
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	//�����ǩ(ϴ��) ���������е�Ԫ��˳��
	//�����������
	srand(time(NULL));
	random_shuffle(v.begin(),v.end());

	//�������
	//= �Ƕ����� �ⲿ���� &�Ǵ����ⲿ���ݵ����� ���Զ�д����
	for_each(v.begin(), v.end(), [&](int key) {
		//val ����map�����е�keyֵ
		cout << map[key] << endl;
	});
}


//multimap��������key��ͬ��map������key��ͬ
void test03()
{

	//ս������(ս�ӱ�š�ս������)
	map<int, string> map;
	map.insert(make_pair(1, "RNG"));
	map.insert(make_pair(1, "IG"));

	cout << map[1] << endl;
	cout << map.count(1) << endl; //1

	multimap<int, string> m1;
	m1.insert(make_pair(1,"RNG"));
	m1.insert(make_pair(1, "IG"));
	cout << m1.count(1) << endl; //2
}

//int main(int argc, char* argv[])
//{
//	//test01();
//
//	//test02();
//
//	test03();
//
//	return 0;
//}