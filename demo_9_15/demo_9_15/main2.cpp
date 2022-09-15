#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

//案例：5个员工 分到3个部门
class Person
{
private:
	string name;
	int age;
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string getName(void) const
	{
		return this->name;
	}
	int getAge(void) const
	{
		return this->age;
	}
};

void createVectorPerson(vector<Person> &v)
{
	v.push_back(Person("jack",23));
	v.push_back(Person("tim", 37));
	v.push_back(Person("rose", 25));
	v.push_back(Person("nancy", 18));
	v.push_back(Person("flyboy", 25));
}

void PersonByGroup(vector<Person> &v, multimap<int, Person> &m)
{
	//逐个将员工分派到 各个部门内
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//*it == Person
		cout << "请输入员工：" << (*it).getName() << " 将要加入的部门：1、2、3" << endl;
		int num = 0; //部门号
		cin >> num;
		if (num >= 1 && num <= 3)
		{
			m.insert(make_pair(num, *it));
		}
	}
}

void showPersonList(multimap<int, Person> &m, int num)
{
	switch (num)
	{
	case 1:
		cout << "研发部：" << endl;
		break;
	case 2:
		cout << "测试部：" << endl;
		break;
	case 3:
		cout << "人事部：" << endl;
		break;
	}

	//注意：m中存放的数据(部门号、员工信息)
	//统计部门号的元素个数
	int n = m.count(num);
	cout << "部门的人数个数 ：" << n << endl;
	//由于 multimap将key自动排序 重复 相同的key值一定挨在一起
	multimap<int, Person>::const_iterator ret;
	ret = m.find(num);
	if (ret != m.end()) //寻找到key值
	{
		for (int i = 0; i < n; i++,ret++)
		{
			cout << "部门号：" << (*ret).first << ", 员工信息" << ((*ret).second).getName() << " " << ((*ret).second).getAge() << endl;
		}
	}

}
void test04()
{
	//vector容器将5名员工信息存储起来
	vector<Person> v;

	//创建5名员工
	createVectorPerson(v);

	//将员工分配到不同的部门(员工<部门号、员工信息>)
	multimap<int, Person> m; //存放员工<部门号、员工信息>
	PersonByGroup(v,m);

	//按部门查看员工信息
	showPersonList(m, 1);
	showPersonList(m, 2);
	showPersonList(m, 3);
}

//int main(int argc, char* argv[])
//{
//	test04();
//
//	return 0;
//}