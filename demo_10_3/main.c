#include <stdio.h>

/*C/C++���ļ��Ĵ������
 *
 * hello.c ����ÿһ�� c ��䶼����ת��Ϊ�ͼ��Ļ���ָ�Ȼ����Щ����ָ��
 * ����ɿ�ִ��Ŀ���ļ���ʽ�����Զ�������ʽ�洢�ڴ����С�
 *
 * Ԥ����(Pre-processing) -> ����(Compiling) ->���(Assembling) -> ����(Linking)
 *
 * hello.c����Ԥ������ ,����չ�������ɵ��ļ�Ϊhello.i
 * hello.i���������������ļ�����ɻ�����ԣ������ļ�Ϊhello.s
 * hello.s��������������ļ������Ŀ���ļ�hello.o(win��Ϊhello.obj)
 * hekllo.o���������������ļ�����ɿ�ִ���ļ�
 */

int main(int argc, char *argv[])
{
    printf("Hello World!\n");
    return 0;
}
