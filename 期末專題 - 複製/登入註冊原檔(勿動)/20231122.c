#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 宣告指向檔案的結構指標/////
FILE* pfile, * pfin, * pfout;

// 宣告變數/////
char ch = '0';
char cAcc[20] = { '0' };  // 存放寫出的字元(account)帳號
char cPswd[20] = { '0' };// 存放寫出的字元(password)密碼
int i = 0, len = 0, j = 0;




// 宣告開啟檔案的副程式函式/////
void openoutfile();
void openaccfile();
void openpswdfile();



// // 輸入帳號密碼副程式函式/////
void finAcc();
void finPswd();




// // 輸入帳號密碼副程式函式/////
void finAcc()
{
	printf("請輸入帳號名稱:");
	do
	{
		scanf("%s", cAcc);
	} while ((getchar(ch) != '\n'));
	fputs(cAcc, pfile);  // 寫出字串 cStr 的內容
	fputc('\n', pfile);  // 寫入換行字元, 使用 putc 亦可
	fputs(cAcc, pfin);  // 寫出字串 cStr 的內容
	fputc('\n', pfin);  // 寫入換行字元, 使用 putc 亦可
	rewind(stdin);
}
void finPswd()
{
	printf("請輸入密碼:");
	do
	{
		scanf("%s", cPswd);
	} while ((getchar(ch) != '\n'));
	fputs(cPswd, pfile);  // 寫出字串 cStr 的內容
	fputc('\n', pfile);  // 寫入換行字元, 使用 putc 亦可
	fputs(cPswd, pfout);  // 寫出字串 cStr 的內容
	fputc('\n', pfout);  // 寫入換行字元, 使用 putc 亦可
	rewind(stdin);
}



// 宣告開啟檔案的副程式函式//////////////////////////////
void openoutfile()
{
	if ((pfile = fopen("out.txt", "a+")) == NULL) {
		printf("out.txt 檔案無法開啟");
		system("pause"); return(0);
	}
}
void openaccfile()
{
	if ((pfin = fopen("account.txt", "a+")) == NULL) {
		printf("account.txt 檔案無法開啟");
		system("pause"); return(0);
	} // 開啟讀入的檔案
}
void openpswdfile()
{
	if ((pfout = fopen("password.txt", "a+")) == NULL) {
		printf("password.txt 檔案無法開啟");
		system("pause"); return(0);
	}
}

int main(void)
{


	openoutfile();
	openaccfile();
	openpswdfile();

	finAcc();
	finPswd();

	

	fclose(pfile); // 關閉檔案
	system("pause"); return(0);
}
//printf("請輸入帳號名稱:");
	//do
	//{
	//	scanf("%s", cAcc);
	//}while ((getchar(ch) != '\n'));
	//fputs(cAcc, pfile);  // 寫出字串 cStr 的內容
	//fputc('\n', pfile);  // 寫入換行字元, 使用 putc 亦可
	//fputs(cAcc, pfin);  // 寫出字串 cStr 的內容
	//fputc('\n', pfin);  // 寫入換行字元, 使用 putc 亦可
	//rewind(stdin);
	//printf("請輸入密碼:");
	//do
	//{
	//	scanf("%s", cPswd);
	//} while ((getchar(ch) != '\n'));
	//fputs(cPswd, pfile);  // 寫出字串 cStr 的內容
	//fputc('\n', pfile);  // 寫入換行字元, 使用 putc 亦可
	//fputs(cPswd, pfout);  // 寫出字串 cStr 的內容
	//fputc('\n', pfout);  // 寫入換行字元, 使用 putc 亦可
	//rewind(stdin);
	//len = strlen(cStr); // 計算字串的長度
	//for (i = 0; i < len; i++) {
	//	fputc(cStr[i], pfile);
	//	fputc('\n', pfile); // 寫一個字元換一行
	//}


	//char ch = '0';
	//char cAcc[20] = {'0'};  // 存放寫出的字元(account)帳號
	//char cPswd[20] = { '0' };// 存放寫出的字元(password)密碼
	//int i = 0, len = 0, j = 0;