//#include "bingogame.h"
#define _CRT_SECURE_NO_WARNINGS
#define USER_MAX 20
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>

typedef struct
{
	char name[20];
	char password[20];
}
User;//�w�q�@�Ӧs��ϥΪ̪����c��

User list[USER_MAX];//�w�q�@�ӥ���ʰ}�C(�n�J���U�t��)

User login()//�n�J�禡
{
	char name[20];
	char password[20];
	User lg;
	printf(" ------\n");
	printf("| �n�J |\n");
	printf(" ------\n");
	printf("��J�ϥΪ̦W��:");
	scanf("%s", name);
	strcpy(lg.name, name);
	printf("��J�ϥΪ̱K�X:");
	scanf("%s", password);
	strcpy(lg.password, password);
	return lg;
}

void writeToFile(User u)//�g�Jtxt�ɮסA�C�@��s�b�@�ӨϥΪ�
{
	FILE* fw = fopen("user.txt", "a+");
	fprintf(fw, u.name);
	fprintf(fw, "\t");
	fprintf(fw, u.password);
	fprintf(fw, "\n");
	fclose(fw);
}

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

void registerUser()//���U�ϥΪ�
{
	char name[20];
	char password[20];
	User user;
	int i;

	printf(" ------\n");
	printf("| ���U |\n");
	printf(" ------\n");
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

int login_menu()
{
	int choice;

	printf("--------------\n");
	printf("| �n�J�B���U |\n");
	printf("--------------\n");
	printf("1.�n�J\n");
	printf("2.���U\n");
	printf("!.���}\n");
	printf("��J�A�����:");
	scanf("%d", &choice);
	return choice;
}
int main()
{
	/////////////////////////////////////////////////////////////////////////////////�n�J�n�X�t�ΥD�{��
	FILE* fu = fopen("user.txt", "r");
	int i = 0;
	User u;
	if (NULL == fu)
	{
		printf("FILE NOT FOUND(u)");
		return -1;
	}

	while (1)
	{
		for (i = 0; i < USER_MAX; i++)
		{
			char uname[20];
			char upassword[20];
			fscanf(fu, "%s%s", uname, upassword);

			strcpy(list[i].name, uname);
			strcpy(list[i].password, upassword);
		}

		int choice = login_menu();

		if (1 == choice)
		{
			system("cls");
			u = login();
			if (1 == exist(u))
			{
				printf("�n�J���\");
				Sleep(1000);
				system("cls");//clear
				break;
			}
			else
			{
				printf("���~���ϥΪ̩αK�X\n");
				Sleep(1000);
				system("cls");//clear
			}
		}
		else if (2 == choice)
		{
			system("cls");//clear
			registerUser();
		}
		else
		{
			system("pause");
			return 0;
		}
	}
}