#define _CRT_SECURE_NO_WARNINGS
#define USER_MAX 20
#include <stdio.h>
typedef struct
{
	char name[20];
	char password[20];
}
User;//定義一個存放使用者的結構體

User list[USER_MAX];//定義一個全域性陣列(登入註冊系統)
void writeToFile(User u)//寫入txt檔案，每一行存在一個使用者
{
	FILE* fw = fopen("user.txt", "a+");
	fprintf(fw, u.name);
	fprintf(fw, "\t");
	fprintf(fw, u.password);
	fprintf(fw, "\n");
	fclose(fw);
}