#define _CRT_SECURE_NO_WARNINGS
#define USER_MAX 20
#include <stdio.h>
#include <string.h>
typedef struct
{
	char name[20];
	char password[20];
}
User;//定義一個存放使用者的結構體

User list[USER_MAX];//定義一個全域性陣列(登入註冊系統)
int login_menu()
{
	int choice;

	printf(" ＿＿＿＿＿＿\n");
	printf("| 登入、註冊 |\n");
	printf(" ￣￣￣￣￣￣\n");
	printf("1.登入\n");
	printf("2.註冊\n");
	printf("!.離開\n");
	printf("輸入你的選擇:");
	scanf("%d", &choice);
	return choice;
}