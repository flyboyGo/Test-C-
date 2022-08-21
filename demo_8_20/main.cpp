#include <iostream>

using namespace std;

///////////C++中的引用详解

/* 变量的引用
 * 1、&和别名 结合 表示引用
 * 2、给某个变量取别名 就定义某个变量
 * 3、从上往下替代
 * 注意: 引用变量必须初始化,引用一旦初始化 就不能再次修改别名
 */

void test01()
{
    int num = 10;
    int &a = num; // 此处 &不是取地址 而是表明 a是引用变量 (a 是 num的别名)
    cout << "num = " << num << endl; // 10
    cout << "&a = " << a << endl; // 10

    a = 15; //对引用变量a赋值,等价于对num赋值
    cout << "num = " << num << endl; // 15

    //a是num的别名 所以num和a具有相同的地址空间
    cout << "a的地址:" << &a << endl;
    cout << "num的地址:" << &num << endl;


    int data = 20;
    a = data; // 不是data的别名为a  而是将data的赋值给a(num)
    cout << "num = " << num << endl; // 20
    cout << "&a = " << a << endl; //20
}

/*
 *数组的引用
 * 1、直接给数组取别名,别名为数组的引用
 * 2、(配合typedef使用)typedef先给数组类型取别名,再给数组取别名,别名为数组的引用
 */
void test02()
{
    int arr[5] = {1,2,3,4,5};
    //需求: 给arr起个别名
    int (&myArr)[5] = arr;// my_arr就是数组arr的别名

    int i = 0;
    for(i = 0; i < 5; i++)
    {
        cout << myArr[i] << " ";
    }
    cout << endl;
}

void test03()
{
    int arr[5] = {1,2,3,4,5};
    //1、用typedef给 数组类型 取别名
    //TYPE_ARR是一个数组类型(有五个元素 每个元素为int)
    typedef int TYPE_ARR [5]; //给数据类型起别名

    TYPE_ARR &myArr = arr; //myArr就是数组arr的别名

    int i = 0;
    for(i = 0; i < 5; i++)
    {
        cout << myArr[i] << " ";
    }
    cout << endl;
}

/*
 *引用在函数中的使用
 */
void mySwap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void mySwapPlus(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void test04()
{
    int data1 = 10, data2 = 20;
    cout << "data1 = " << data1 << " data2 = " << data2 << endl;

    mySwap(&data1, &data2);
    cout << "data1 = " << data1 << " data2 = " << data2 << endl;

//    int &a = data1, &b = data2;
//    mySwapPlus(a, b);
    mySwapPlus(data1, data2);//(推荐)
    cout << "data1 = " << data1 << " data2 = " << data2 << endl;
}

//引用作为函数的返回值()
int &myData(void)
{
    //函数的返回值是引用时 不要返回局部变量
    int num = 320;
    return num; //函数返回什么变量 引用就是该变量的别名
}

int &myDataStatic(void)
{
    //函数的返回值是引用时 不要返回局部变量
    static int num = 370;
    return num; //函数返回什么变量 引用就是该变量的别名
}

void test05()
{
    //ret是返回值的别名
    int &ret = myData();
    //cout << "ret = " << ret << endl; //非法访问内存

    int &ret2 = myDataStatic();
    cout << "ret = " << ret2 << endl; // 370
}


//当函数返回值作为 "左值" 时 那么函数的返回值类型必须是引用
int& myData2(void)
{
    static int num = 10;
    cout << "num = " << num <<endl; // 10

    return num;
}
void test06()
{
    //函数的返回值 作为左值
    myData2() = 2000;
    myData2(); // 2000
}

//int main(int argc, char *argv[])
//{
//    /*
//     * 加了另外一种给函数传递地址的途径，这就是按引用传递(pass-by-reference)，它
//       也存在于其他一些编程语言中，并不是 c++的发明。
//       变量名实质上是一段连续内存空间的别名，是一个标号(门牌号) 程序中通过变量
//       来申请并命名内存空间 通过变量的名字可以使用存储空间
//       对一段连续的内存空间只能取一个别名吗？ c++中新增了引用的概念，引用可以作
//       为一个已定义变量的别名。 基本语法: Type& ref = val; 注意事项： &在此不是求
//       地址运算，而是起标识作用。 类型标识符是指目标变量的类型 必须在声明引用变
//       量时进行初始化。 引用初始化之后不能改变。 不能有 NULL 引用。必须确保引用
//       是和一块合法的存储单元关联。 可以建立对数组的引用
//     */
//    test01();

//    //数组的引用
//    test02();
//    test03();

//    /*
//     * 最常见看见引用的地方是在函数参数和返回值中。当引用被用作函数参数的时，在
//       函数内对任何引用的修改，将对还函数外的参数产生改变。当然，可以通过传递一
//       个指针来做相同的事情，但引用具有更清晰的语法。 如果从函数中返回一个引
//       用，必须像从函数中返回一个指针一样对待。当函数返回值时，引用关联的内存一
//       定要存在。
//     */

//    /*
//     * 调用时传递的实参不必加“&”符 2) 在被调函数中不必在参数前加“*”符 引用作为
//       其它变量的别名而存在，因此在一些场合可以代替指针。C++主张用引用传递取代
//       地址传递的方式，因为引用语法容易且不易出错。
//     */
//    //引用作为函数的参数
//    test04();

//    //引用作为函数的返回值
//    test05();
//    test06();

//    return 0;
//}
