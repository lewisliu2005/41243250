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
int login_menu()
{
	int choice;

	printf(" �ġġġġġ�\n");
	printf("| �n�J�B���U |\n");
	printf(" �ááááá�\n");
	printf("1.�n�J\n");
	printf("2.���U\n");
	printf("!.���}\n");
	printf("��J�A�����:");
	scanf("%d", &choice);
	return choice;
}