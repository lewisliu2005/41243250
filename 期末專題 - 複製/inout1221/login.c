#define _CRT_SECURE_NO_WARNINGS
#define USER_MAX 20
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
	printf(" �ġġ�\n");
	printf("| �n�J |\n");
	printf(" �áá�\n");
	printf("��J�ϥΪ̦W��:");
	scanf("%s", name);
	strcpy(lg.name, name);
	printf("��J�ϥΪ̱K�X:");
	scanf("%s", password);
	strcpy(lg.password, password);
	return lg;
}