#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//容器操作基本数据类型

void myPrintInt(int val);

void test02()
{
    //单端动态数组vector 容器(类模板)
    vector<int> v;//v 是一个具体vector容器
    //push_back 尾插插入
    v.push_back(100);
    v.push_back(200);
    v.push_back(300);
    v.push_back(400);
    v.push_back(500);


    //访问数据

    //方式一
    //定义一个迭代器 v的起始迭代器 指向第0个元素的位置
    vector<int>::iterator beginIt = v.begin();
    //定义一个迭代器 v的结束迭代器 指向尾元素的下一个元素的地址
    vector<int>::iterator endIt = v.end();
    //for循环遍历 方式一
    for (; beginIt != endIt; beginIt++)
    {
        //对迭代器取* 代表的是 容器的元素
        //*beginIt 等价于 容器vector中的int
        cout << *beginIt << " ";
    }
    cout << endl;

    //方式二
    //for循环遍历 方式二(推荐)
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    //STL提供的算法来遍历容器(包含算法的头文件 algorithm)
    //for_each 从容器的起始-->结束 逐个元素取出
    //myPrintInt 容器数据的打印方式
    for_each(v.begin(), v.end(), myPrintInt);
    cout << endl;

}

void myPrintInt(int val)
{
    cout << val << " ";
}

//int main(int argc, char* argv[])
//{
//    test02();
//
//    return 0;
//}
