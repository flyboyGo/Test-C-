#ifndef MAIN_H
#define MAIN_H

/*
 * 如果C++环境下调用了这部分C语言的代码,防止链接错误
 * 加上 extern "C"后，这部分代码编译器按 c 语言的方式进行编译和链接，而不是按 c++的方式。
 */
//判断以下编译环境
#if __cplusplus
extern "C"
{
#endif

    extern int my_add(int x, int y);

    extern int my_sub(int x, int y);

#if __cplusplus
}
#endif
#endif
