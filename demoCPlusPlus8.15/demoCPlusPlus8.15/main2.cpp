#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
	/*循环语句
	* 
	* while循环语句
	* while(循环条件){循环语句}
	* 解释:只要循环条件的结构为真,就执行循环语句
	* 注意：在执行循环语句时候，程序必须提供跳出循环的出口，否则出现死循环
	*/

	//猜数字游戏
	/*
	* 因为rand 函数产生的随机数是伪随机数，是根据一个数按照某个公式推算出来的，这个数我们称之为“种子”，
	* 但是这个种子在系统启动之后就是一个定值。要想每次产生的随机数不一样，那么，我们就要用到 srand 函数。
	* 
	* rand() 产生随机数时，如果用srand(seed) 播下种子之后，一旦种子相同，产生的随机数将是相同的。
	* 当然很多时候刻意让rand() 产生的随机数随机化，用时间作种子 srand(time(NULL)) ，
	* 这样每次运行程序的时间肯定是不相同的，产生的随机数肯定就不一样了。
	*/

	srand((unsigned)time(NULL));
	int randNum = rand() % 10 + 1;
	int guessNum = 0;
	while (1)
	{
		cout << "请输入你猜测的数字(数字的范围1~10): " << endl;
		cin >> guessNum;
		if (guessNum > randNum)
		{
			cout << "你猜测的数字过大: " << endl;
		}
		else if (guessNum > randNum)
		{
			cout << "你猜测的数字过小: " << endl;
		}
		else
		{
			cout << "恭喜你猜对了!: " << endl;
			break;
		}
	}

	/*
	* do...while循环语句
	* 作用： 满足循环条件，执行循环语句
    * 语法：  do{ 循环语句 } while(循环条件);
    * 注意：与while的区别在于do...while会先执行一次循环语句，再判断循环条件
	*/

	//求水仙花数
	int sum = 0, num = 100;
	do 
	{
		int tmp = num;
		while (tmp)
		{
			sum = sum + pow(tmp % 10, 3);
			tmp = tmp / 10;
		}
		if (sum == num)
		{
			cout << num << endl;
		}
		sum = 0;
		num++;
	} while (num < 999);

	/*
	* for循环语句
	* 作用： 满足循环条件，执行循环语句
    * 语法： for(起始表达式;条件表达式;末尾循环体) { 循环语句; }
	* 
	* 注意：for循环中的表达式，要用分号进行分隔
    * 总结：while , do...while, for都是开发中常用的循环语句，for循环结构比较清晰，比较常用
	*/

	//敲桌子游戏,个位为7或十位为7或7的倍数

	for (int i = 1; i <= 100; i++)
	{
		int tmp = i;
		if (tmp % 10 == 7 || tmp / 10  == 7 || tmp % 7 == 0)
		{
			cout << "敲桌子" << endl;
		}
		else
		{
			cout << i << endl;
		}
	}

	/*
	* 嵌套循环
	* 外层执行一次,内存执行一周
	*/

	//乘法口诀表
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << i << "*" << j << "=" << i * j << "\t"; //打印换行
		}
		cout << endl; //换行  endl ==> end line
	}

	/*
	*  跳转语句 break
	*    作用: 用于跳出选择结构或者循环结构
    *    break使用的时机：
    *    出现在switch条件语句中，作用是终止case并跳出switch
    *    出现在循环语句中，作用是跳出当前的循环语句
    *    出现在嵌套循环中，跳出最近的内层循环语句
	*/

	/*
	* continue语句
	*    作用：在循环语句中，跳过本次循环中余下尚未执行的语句，继续执行下一次循环
	*    注意：continue并没有使整个循环终止，而break会跳出循环
	*/

	/* goto语句
	*     作用：可以无条件跳转语句
    *     语法：  goto 标记;  
    *     解释：如果标记的名称存在，执行到goto语句时，会跳转到标记的位置
	*     注意：在程序中不建议使用goto语句，以免造成程序流程混乱
	*/

	goto FLAG;
	cout << "go" << endl;
FLAG:
	cout << "goto";

	return 0;
}