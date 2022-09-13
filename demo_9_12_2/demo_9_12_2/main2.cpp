#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <time.h>

using namespace std;

/*
* 3.3.3.8 ��������ҵ��
�� 5 ��ѡ�֣�ѡ�� ABCDE��10 ����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ��
��ί����ͷ֣�ȡƽ���֡�
1. ��������ѡ�֣��ŵ� vector ��
2. ���� vector ������ȡ����ÿһ��ѡ�֣�ִ�� for ѭ�������԰� 10 �����ִ�
�ִ浽 deque ������
3. sort �㷨�� deque �����з�������pop_back pop_front ȥ����ߺ����
��
4. deque ��������һ�飬�ۼӷ������ۼӷ���/d.size()
5. person.score = ƽ����
*/

class Person
{
private:
	string name;
	int score;
public:
	Person(string name, int score)
	{
		this->name = name;
		this->score = score;
	}
	string getName(void)
	{
		return this->name;
	}
	void setScore(int score)
	{
		this->score = score;
	}
	int getScore(void)
	{
		return this->score;
	}
};

void createPerson(vector<Person>& v)
{
	//5��ѡ����ABCDE;
	string nameTmp = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "ѡ��";
		name += nameTmp[i];
		
		//��ѡ�ֵ�����������0 ����vector������
		v.push_back(Person(name,0));
	}
}

void printfVectorPerson(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it).getName() << ", " << (*it).getScore() << endl;
	}
}

void playGame(vector<Person>& v)
{
	//�����������
	srand(time(NULL));

	//�����е�ÿ����
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//ÿ��ѡ�� ��Ҫ��10����ί��� ��ַ��� deque������
		deque<int> d = deque<int>();
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60; // 60 ~ 100
			d.push_back(score);
		}

		//��deque����(��ί��10������) ����
		sort(d.begin(),d.end());

		//ȥ����ߡ���ͷ�
		d.pop_front(); d.pop_back();

		//�õ�ÿ��ѡ�ֵ��ܷ�
		int sum = 0;
		for (deque<int>::iterator mit = d.begin(); mit != d.end(); mit++)
		{
			sum += (*mit);
		}

		//��ȡƽ���� ��ֵ�� ѡ�ֵ�score
		(*it).setScore((sum / d.size()));
	}
}

//int main(int argc, char* argv[])
//{
//	//1������һ��vector�������Person
//	vector<Person> v = vector<Person>();
//	createPerson(v);
//
//	//2��5��ѡ����һ����
//	playGame(v);
//
//	//3����5��ѡ�ֵĳɼ���ӡ����
//    printfVectorPerson(v);
//
//	return 0;
//}