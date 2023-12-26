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
void registerUser()//註冊使用者
{
	char name[20];
	char password[20];
	User user;
	int i;

	printf(" ＿＿＿\n");
	printf("| 註冊 |\n");
	printf(" ￣￣￣\n");
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