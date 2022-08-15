#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//int main()
//{
//	/*
//	  程序流程结构
//	  三种基本结构: 顺序结构、选择结构、循环结构
//
//	  1、选择结构:
//	     if语句的三种形式
//		  单行格式if语句
//		  多行格式if语句
//		  多条件的if语句
//		  嵌套if语句
//	*/
//
//	//案例,有三只小猪ABC,请分别输入三只小猪的体重，并且判断那只小猪最终
//	int A = 0, B = 0, C = 0;
//
//	cout << "请输入小猪A的体重: " << endl;
//	cin >> A;
//
//	cout << "请输入小猪B的体重: " << endl;
//	cin >> B;
//
//	cout << "请输入小猪C的体重: " << endl;
//	cin >> C;
//	
//	if (A >= B && A >= C)
//	{
//		cout << "小猪A最重,体重为: " << A << endl;
//	}
//
//	if (C >= B &&C >= A)
//	{
//		cout << "小猪C最重,体重为: " << C << endl;
//	}
//
//	if (B >= C && B >= A)
//	{
//		cout << "小猪B最重,体重为: " << B << endl;
//	}
//
//	/*
//	* switch/case语句
//	* 作用：执行多条件分支语句
//	*     1、switch语句中表达式类型只能是整型或者字符型或者枚举
//    *     2、case里如果没有break，那么程序会一直向下执行
//	*     总结：与if语句比，对于多条件判断时，switch的结构清晰，执行效率高，缺点是switch不可以判断区间
//	*/
//
//	system("pause");
//
//	return 0;
//}
