#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <time.h>

using namespace std;

/*
* 3.3.3.8 案例（作业）
有 5 名选手：选手 ABCDE，10 个评委分别对每一名选手打分，去除最高分，去除
评委中最低分，取平均分。
1. 创建五名选手，放到 vector 中
2. 遍历 vector 容器，取出来每一个选手，执行 for 循环，可以把 10 个评分打
分存到 deque 容器中
3. sort 算法对 deque 容器中分数排序，pop_back pop_front 去除最高和最低
分
4. deque 容器遍历一遍，累加分数，累加分数/d.size()
5. person.score = 平均分
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
	//5名选手是ABCDE;
	string nameTmp = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameTmp[i];
		
		//将选手的姓名、分数0 放入vector容器中
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
	//设置随机种子
	srand(time(NULL));

	//容器中的每个人
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//每个选手 需要被10个评委打分 打分放入 deque容器中
		deque<int> d = deque<int>();
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60; // 60 ~ 100
			d.push_back(score);
		}

		//对deque容器(评委的10个分数) 排序
		sort(d.begin(),d.end());

		//去掉最高、最低分
		d.pop_front(); d.pop_back();

		//得到每个选手的总分
		int sum = 0;
		for (deque<int>::iterator mit = d.begin(); mit != d.end(); mit++)
		{
			sum += (*mit);
		}

		//获取平均分 赋值给 选手的score
		(*it).setScore((sum / d.size()));
	}
}

//int main(int argc, char* argv[])
//{
//	//1、定义一个vector容器存放Person
//	vector<Person> v = vector<Person>();
//	createPerson(v);
//
//	//2、5名选手逐一比赛
//	playGame(v);
//
//	//3、将5名选手的成绩打印出来
//    printfVectorPerson(v);
//
//	return 0;
//}