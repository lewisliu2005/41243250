#define _CRT_SECURE_NO_WARNINGS
#define USER_MAX 20
#include <stdio.h>
typedef struct
{
	char name[20];
	char password[20];
}
User;//�w�q�@�Ӧs��ϥΪ̪����c��

User list[USER_MAX];//�w�q�@�ӥ���ʰ}�C(�n�J���U�t��)
void writeToFile(User u)//�g�Jtxt�ɮסA�C�@��s�b�@�ӨϥΪ�
{
	FILE* fw = fopen("user.txt", "a+");
	fprintf(fw, u.name);
	fprintf(fw, "\t");
	fprintf(fw, u.password);
	fprintf(fw, "\n");
	fclose(fw);
}