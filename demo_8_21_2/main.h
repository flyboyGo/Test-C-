#ifndef MAIN_H
#define MAIN_H

/*
 * ���C++�����µ������ⲿ��C���ԵĴ���,��ֹ���Ӵ���
 * ���� extern "C"���ⲿ�ִ���������� c ���Եķ�ʽ���б�������ӣ������ǰ� c++�ķ�ʽ��
 */
//�ж����±��뻷��
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
