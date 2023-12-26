#define _CRT_SECURE_NO_WARNINGS
#define USER_MAX 20
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
	printf(" ＿＿＿\n");
	printf("| 登入 |\n");
	printf(" ￣￣￣\n");
	printf("輸入使用者名稱:");
	scanf("%s", name);
	strcpy(lg.name, name);
	printf("輸入使用者密碼:");
	scanf("%s", password);
	strcpy(lg.password, password);
	return lg;
}