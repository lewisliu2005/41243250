#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// �ŧi���V�ɮת����c����/////
FILE* pfile, * pfin, * pfout;

// �ŧi�ܼ�/////
char ch = '0';
char cAcc[20] = { '0' };  // �s��g�X���r��(account)�b��
char cPswd[20] = { '0' };// �s��g�X���r��(password)�K�X
int i = 0, len = 0, j = 0;




// �ŧi�}���ɮת��Ƶ{���禡/////
void openoutfile();
void openaccfile();
void openpswdfile();



// // ��J�b���K�X�Ƶ{���禡/////
void finAcc();
void finPswd();




// // ��J�b���K�X�Ƶ{���禡/////
void finAcc()
{
	printf("�п�J�b���W��:");
	do
	{
		scanf("%s", cAcc);
	} while ((getchar(ch) != '\n'));
	fputs(cAcc, pfile);  // �g�X�r�� cStr �����e
	fputc('\n', pfile);  // �g�J����r��, �ϥ� putc ��i
	fputs(cAcc, pfin);  // �g�X�r�� cStr �����e
	fputc('\n', pfin);  // �g�J����r��, �ϥ� putc ��i
	rewind(stdin);
}
void finPswd()
{
	printf("�п�J�K�X:");
	do
	{
		scanf("%s", cPswd);
	} while ((getchar(ch) != '\n'));
	fputs(cPswd, pfile);  // �g�X�r�� cStr �����e
	fputc('\n', pfile);  // �g�J����r��, �ϥ� putc ��i
	fputs(cPswd, pfout);  // �g�X�r�� cStr �����e
	fputc('\n', pfout);  // �g�J����r��, �ϥ� putc ��i
	rewind(stdin);
}



// �ŧi�}���ɮת��Ƶ{���禡//////////////////////////////
void openoutfile()
{
	if ((pfile = fopen("out.txt", "a+")) == NULL) {
		printf("out.txt �ɮ׵L�k�}��");
		system("pause"); return(0);
	}
}
void openaccfile()
{
	if ((pfin = fopen("account.txt", "a+")) == NULL) {
		printf("account.txt �ɮ׵L�k�}��");
		system("pause"); return(0);
	} // �}��Ū�J���ɮ�
}
void openpswdfile()
{
	if ((pfout = fopen("password.txt", "a+")) == NULL) {
		printf("password.txt �ɮ׵L�k�}��");
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

	

	fclose(pfile); // �����ɮ�
	system("pause"); return(0);
}
//printf("�п�J�b���W��:");
	//do
	//{
	//	scanf("%s", cAcc);
	//}while ((getchar(ch) != '\n'));
	//fputs(cAcc, pfile);  // �g�X�r�� cStr �����e
	//fputc('\n', pfile);  // �g�J����r��, �ϥ� putc ��i
	//fputs(cAcc, pfin);  // �g�X�r�� cStr �����e
	//fputc('\n', pfin);  // �g�J����r��, �ϥ� putc ��i
	//rewind(stdin);
	//printf("�п�J�K�X:");
	//do
	//{
	//	scanf("%s", cPswd);
	//} while ((getchar(ch) != '\n'));
	//fputs(cPswd, pfile);  // �g�X�r�� cStr �����e
	//fputc('\n', pfile);  // �g�J����r��, �ϥ� putc ��i
	//fputs(cPswd, pfout);  // �g�X�r�� cStr �����e
	//fputc('\n', pfout);  // �g�J����r��, �ϥ� putc ��i
	//rewind(stdin);
	//len = strlen(cStr); // �p��r�ꪺ����
	//for (i = 0; i < len; i++) {
	//	fputc(cStr[i], pfile);
	//	fputc('\n', pfile); // �g�@�Ӧr�����@��
	//}


	//char ch = '0';
	//char cAcc[20] = {'0'};  // �s��g�X���r��(account)�b��
	//char cPswd[20] = { '0' };// �s��g�X���r��(password)�K�X
	//int i = 0, len = 0, j = 0;