#define _CRT_SECURE_NO_WARNINGS
#define USER_MAX 20
#include <stdio.h>
#include <string.h>
typedef struct
{
	char name[20];
	char password[20];
}
User;//�w�q�@�Ӧs��ϥΪ̪����c��

User list[USER_MAX];//�w�q�@�ӥ���ʰ}�C(�n�J���U�t��)
int exist(User u)//�P�_�O�_�s�b�ӨϥΪ�(�K�X�O�_���T)
{
	int i;
	for (i = 0; i < USER_MAX; i++)
	{
		if (0 == strcmp(list[i].name, u.name) && 0 == strcmp(list[i].password, u.password))
		{
			return 1;
		}
	}
	return -1;
}