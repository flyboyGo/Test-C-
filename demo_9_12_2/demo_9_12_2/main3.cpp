#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <deque>
#include <algorithm>
#include <time.h>

using namespace std;

//srand()、rand() 产生随机数

int main(int argc, char* argv[])
{
	//设置随机数种子 默认种子为 1
	//系统的时间作为种子
	srand(time(NULL)); 

	for (int i = 0; i < 10; i++)
	{
		//rand()函数的返回值就是随机数 伪随机 默认基准值是 1
		int num = rand() % 10 + 1; //产生 1 ~ 10 的随机数
		cout << num << endl;
	}

	return 0;
}