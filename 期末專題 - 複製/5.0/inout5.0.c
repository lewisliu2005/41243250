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
User;//定義一個存放使用者的結構體

User list[USER_MAX];//定義一個全域性陣列(登入註冊系統)

User login()//登入函式
{
	char name[20];
	char password[20];
	User lg;
	printf(" ------\n");
	printf("| 登入 |\n");
	printf(" ------\n");
	printf("輸入使用者名稱:");
	scanf("%s", name);
	strcpy(lg.name, name);
	printf("輸入使用者密碼:");
	scanf("%s", password);
	strcpy(lg.password, password);
	return lg;
}

void writeToFile(User u)//寫入txt檔案，每一行存在一個使用者
{
	FILE* fw = fopen("user.txt", "a+");
	fprintf(fw, u.name);
	fprintf(fw, "\t");
	fprintf(fw, u.password);
	fprintf(fw, "\n");
	fclose(fw);
}

int exist(User u)//判斷是否存在該使用者(密碼是否正確)
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

void registerUser()//註冊使用者
{
	char name[20];
	char password[20];
	User user;
	int i;

	printf(" ------\n");
	printf("| 註冊 |\n");
	printf(" ------\n");
	printf("輸入使用者名稱:");
	scanf("%s", name);
	strcpy(user.name, name);//複製字串

	for (i = 0; i < USER_MAX; i++)//判斷註冊的使用者是否已存在
	{
		if (0 == strcmp(list[i].name, name))
		{
			printf("使用者名稱已經存在\n");
			return;
		}
	}

	printf("輸入使用者密碼:");
	scanf("%s", password);
	strcpy(user.password, password);
	writeToFile(user);
	printf("註冊成功\n");
}

int login_menu()
{
	int choice;

	printf("--------------\n");
	printf("| 登入、註冊 |\n");
	printf("--------------\n");
	printf("1.登入\n");
	printf("2.註冊\n");
	printf("!.離開\n");
	printf("輸入你的選擇:");
	scanf("%d", &choice);
	return choice;
}
int main()
{
	/////////////////////////////////////////////////////////////////////////////////登入登出系統主程式
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
				printf("登入成功");
				Sleep(1000);
				system("cls");//clear
				break;
			}
			else
			{
				printf("錯誤的使用者或密碼\n");
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