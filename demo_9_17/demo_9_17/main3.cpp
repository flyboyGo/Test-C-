#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <functional>
#include <numeric>

using namespace std;

class Speaker
{
private:
	string name;
	int score[3];
public:
	Speaker()
	{

	}
	Speaker(string name)
	{
		this->name = name;
		memset(this->score,0,sizeof(this->score));
	}
	string getName(void)const
	{
		return this->name;
	}
	int getScore(int n)const
	{
		return this->score[n];
	}
	void setScore(int n,int score)
	{
		this->score[n] = score;
	}
};

void createSpeaker(vector<int> &v, map<int, Speaker> &m)
{
	char tmp[25] = "ABCDEFGHIJKLMNOPQRSTUVWX";
	for (int i = 0; i < 24; i++)
	{
		//���ѡ�ֱ��
		v.push_back(100+i);

		//���<��š�ѡ��>
		//string name = (string)"ѡ��" + tmp[i];
		string name = "ѡ��";
		name += tmp[i];
		m.insert(make_pair(100 + i, Speaker(name)));
	}
}

void speech_contest(int n, vector<int>& v, map<int, Speaker>& m, vector<int>& v1)
{
	//������
	int count = 0;
	//���һ��<���������>������scoreMap ���ÿһ��<���������>
	multimap<int, int,greater<int>> scoreMap;

	//ѡ����һ��̨����
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		count++;

		//*it ��ʾһ��ѡ�ֱ��
		//10����ί��ʼ���
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}

		//��d��������
		sort(d.begin(),d.end());

		//ȥ����ͷ֡�ȥ����ͷ�
		d.pop_back();
		d.pop_front();

		//���ܷ���
		int sum = accumulate(d.begin(),d.end(),0);

		//��ƽ���� ����ֵ��ѡ�ֵ�score[n-1]
		//map<int,Speaker>
		int avg = sum / d.size();
		m[*it].setScore(n - 1, avg);

		//����ѡ�ֵĳɼ�
		scoreMap.insert(make_pair(avg, *it));

		//�պ�����6�� ������6�˵ĳɼ�ȡǰ����
		if (count % 6 == 0)
		{
			int i = 0;
			//����scoreMap���� ȡ��ǰ���� ���
			for (multimap<int, int, greater<int>>::iterator mit = scoreMap.begin();
				 mit != scoreMap.end() && i < 3; mit++,i++)
			{
				//�������ı�� �������������v1��
				v1.push_back((*mit).second);
			}

			//����һ���scoreMap���
			scoreMap.clear();
		}
			
	}
}

void printfSpeechResult(int n, vector<int>& v, map<int, Speaker>& m, vector<int>& v1)
{
	cout << "��" << n << "�ֱ����ɼ�����" << endl;
	//������
	int count = 0;
	//С���
	int time = 0;
	//�������������ĵ�����
	vector<int>::iterator it3 = v1.begin();
	
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		if (count % 6 == 0)
		{
			time = count / 6 + 1;
			cout << "��" << time  << "��ĳɼ����£�" << endl;
		}
		count++;

		//С������
		cout << "������" << m[*it].getName() << ", �÷�" << m[*it].getScore(n - 1) << endl;

		//С���������
		if (count % 6 == 0)
		{
			cout << "��" << time << "��Ľ����������£�" << endl;
			for (int i = 0; i < 3; i++, it3++)
			{
				cout << "������" << m[*it3].getName() << "��";
			}
			cout << endl;
		}

	}
}

#include <time.h>
int main(int argc, char* argv[])
{

	//����24��ѡ��,��ѡ��<��š�ѡ��> ��������map��,ѡ�ֱ�ŵ�������vector������ ����ѡ�ֱ�ŷ���v1����
	vector<int> v;
	map<int, Speaker> m;
	vector<int> v1;

	//����ѡ��24��
	createSpeaker(v,m);

	//��������
	srand(time(NULL));

	//��һ�֣��μӵ�ѡ�ֳ�ǩ
	random_shuffle(v.begin(),v.end());

	//���е�һ�ֱ���
	//1��ʾ��ǰ������vѡ�ֱ�š�mѡ����Ϣ��v1��������
	speech_contest(1,v,m,v1);

	//��ӡ��һ�ֱ�����������в��������Ա�ĳɼ�������������
	printfSpeechResult(1,v,m,v1);

	//�ڶ��֣��μӵ�ѡ�ֳ�ǩ
	swap(v, v1);
	v1.clear();
	random_shuffle(v.begin(), v.end());
	speech_contest(2, v, m, v1);
	printfSpeechResult(2, v, m, v1);

	//�����֣��μӵ�ѡ�ֳ�ǩ
	swap(v, v1);
	v1.clear();
	random_shuffle(v.begin(), v.end());
	speech_contest(3, v, m, v1);
	printfSpeechResult(3, v, m, v1);

	return 0;
}