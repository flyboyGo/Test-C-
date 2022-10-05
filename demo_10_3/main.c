#include <stdio.h>

/*C/C++中文件的处理过程
 *
 * hello.c 程序，每一条 c 语句都必须转化为低级的机器指令。然后将这些机器指令
 * 打包成可执行目标文件格式，并以二进制形式存储于磁盘中。
 *
 * 预处理(Pre-processing) -> 编译(Compiling) ->汇编(Assembling) -> 链接(Linking)
 *
 * hello.c经过预处理器 ,将宏展开，生成的文件为hello.i
 * hello.i经过编译器，将文件编译成汇编语言，生成文件为hello.s
 * hello.s经过汇编器，将文件编译成目标文件hello.o(win下为hello.obj)
 * hekllo.o经过链接器，将文件编译成可执行文件
 */

int main(int argc, char *argv[])
{
    printf("Hello World!\n");
    return 0;
}
