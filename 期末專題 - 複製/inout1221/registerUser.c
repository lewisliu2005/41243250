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
void registerUser()//���U�ϥΪ�
{
	char name[20];
	char password[20];
	User user;
	int i;

	printf(" �ġġ�\n");
	printf("| ���U |\n");
	printf(" �áá�\n");
	printf("��J�ϥΪ̦W��:");
	scanf("%s", name);
	strcpy(user.name, name);//�ƻs�r��

	for (i = 0; i < USER_MAX; i++)//�P�_���U���ϥΪ̬O�_�w�s�b
	{
		if (0 == strcmp(list[i].name, name))
		{
			printf("�ϥΪ̦W�٤w�g�s�b\n");
			return;
		}
	}

	printf("��J�ϥΪ̱K�X:");
	scanf("%s", password);
	strcpy(user.password, password);
	writeToFile(user);
	printf("���U���\\n");
}