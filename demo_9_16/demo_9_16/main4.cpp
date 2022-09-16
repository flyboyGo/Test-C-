#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

class Person
{
private:
	string name;
	int age;
public:
	Person()
	{

	}
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	int getAge(void)
	{
		return this->age;
	}
	string getName(void)
	{
		return this->name;
	}

	void showPerson(void)
	{
		cout << "name = " << this->name << " , age = " << this->age << endl;
	}
};

void MyPrintfPerson(Person &ob)
{
	cout << "name = " << ob.getName() << " , age = " << ob.getAge() << endl;
}

//��Ա����������
void test08()
{
	vector<Person> v;
	v.push_back(Person("jack",23));
	v.push_back(Person("tim", 38));
	v.push_back(Person("nancy", 18));
	v.push_back(Person("helle", 25));

	//lambda���ʽ
	for_each(v.begin(), v.end(), [](Person &ob) {
		cout << "name = " << ob.getName() << " , age = " << ob.getAge() << endl;
	});

	//��ͨ����
	for_each(v.begin(), v.end(), MyPrintfPerson);

	//��Ա���� 
	// ���� mem_fun_ref �� Person �ڲ���Ա��������
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
}


//����ָ��������
void MyPrintInt(int val,int tmp)
{
	cout << val + tmp << " ";
}
void test09()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(5);

	//��ͨ������Ҫʹ��ptr_fun ת���ɺ���ָ��
	for_each(v.begin(),v.end(), bind2nd(ptr_fun(MyPrintInt),1000));
	cout << endl;
}

int main(int argc, char* argv[])
{
	//test08();

	test09();

	return 0;
}