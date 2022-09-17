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
		//存放选手编号
		v.push_back(100+i);

		//存放<编号、选手>
		//string name = (string)"选手" + tmp[i];
		string name = "选手";
		name += tmp[i];
		m.insert(make_pair(100 + i, Speaker(name)));
	}
}

void speech_contest(int n, vector<int>& v, map<int, Speaker>& m, vector<int>& v1)
{
	//计数器
	int count = 0;
	//设计一个<分数、编号>的容器scoreMap 存放每一组<分数、编号>
	multimap<int, int,greater<int>> scoreMap;

	//选手逐一登台比赛
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		count++;

		//*it 表示一名选手编号
		//10个评委开始打分
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}

		//对d容器排序
		sort(d.begin(),d.end());

		//去掉最低分、去掉最低分
		d.pop_back();
		d.pop_front();

		//求总分数
		int sum = accumulate(d.begin(),d.end(),0);

		//求平均分 并赋值给选手的score[n-1]
		//map<int,Speaker>
		int avg = sum / d.size();
		m[*it].setScore(n - 1, avg);

		//保存选手的成绩
		scoreMap.insert(make_pair(avg, *it));

		//刚好已有6人 把上面6人的成绩取前三名
		if (count % 6 == 0)
		{
			int i = 0;
			//遍历scoreMap容器 取出前三名 编号
			for (multimap<int, int, greater<int>>::iterator mit = scoreMap.begin();
				 mit != scoreMap.end() && i < 3; mit++,i++)
			{
				//将晋级的编号 放入晋级的容器v1中
				v1.push_back((*mit).second);
			}

			//将上一组的scoreMap清空
			scoreMap.clear();
		}
			
	}
}

void printfSpeechResult(int n, vector<int>& v, map<int, Speaker>& m, vector<int>& v1)
{
	cout << "第" << n << "轮比赛成绩如下" << endl;
	//计数器
	int count = 0;
	//小组号
	int time = 0;
	//晋级名单容器的迭代器
	vector<int>::iterator it3 = v1.begin();
	
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		if (count % 6 == 0)
		{
			time = count / 6 + 1;
			cout << "第" << time  << "组的成绩如下：" << endl;
		}
		count++;

		//小组名单
		cout << "姓名：" << m[*it].getName() << ", 得分" << m[*it].getScore(n - 1) << endl;

		//小组晋级名单
		if (count % 6 == 0)
		{
			cout << "第" << time << "组的晋级名单如下：" << endl;
			for (int i = 0; i < 3; i++, it3++)
			{
				cout << "姓名：" << m[*it3].getName() << "、";
			}
			cout << endl;
		}

	}
}

#include <time.h>
int main(int argc, char* argv[])
{

	//创建24名选手,将选手<编号、选手> 放入容器map中,选手编号单独放入vector容器中 晋级选手编号放入v1容器
	vector<int> v;
	map<int, Speaker> m;
	vector<int> v1;

	//创建选手24名
	createSpeaker(v,m);

	//设置种子
	srand(time(NULL));

	//第一轮：参加的选手抽签
	random_shuffle(v.begin(),v.end());

	//进行第一轮比赛
	//1表示当前轮数、v选手编号、m选手信息、v1晋级容器
	speech_contest(1,v,m,v1);

	//打印第一轮比赛结果：所有参与比赛人员的成绩、晋级的名单
	printfSpeechResult(1,v,m,v1);

	//第二轮：参加的选手抽签
	swap(v, v1);
	v1.clear();
	random_shuffle(v.begin(), v.end());
	speech_contest(2, v, m, v1);
	printfSpeechResult(2, v, m, v1);

	//第三轮：参加的选手抽签
	swap(v, v1);
	v1.clear();
	random_shuffle(v.begin(), v.end());
	speech_contest(3, v, m, v1);
	printfSpeechResult(3, v, m, v1);

	return 0;
}