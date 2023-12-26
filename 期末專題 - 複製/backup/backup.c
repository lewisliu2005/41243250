//#include "bingogame.h"
#define _CRT_SECURE_NO_WARNINGS
#define USER_MAX 20
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>


////////////////////////////////////////////////////////���G�t��

struct BingoCard {
	int numbers[25];
};

int generateRandomNumber(int min, int max) {//��o�H���ü�
	return min + rand() % (max - min + 1);
}

struct BingoCard createBingoCard() {//�N��o���H���üƩ�i5*5���}�C���A�۰ʳЫ�Bingo�d
	struct BingoCard card;
	int possibleNumbers[25];
	for (int i = 0; i < 25; ++i) {
		possibleNumbers[i] = i + 1;
	}
	for (int i = 0; i < 25; ++i) {
		int j = generateRandomNumber(i, 24);
		int temp = possibleNumbers[i];
		possibleNumbers[i] = possibleNumbers[j];
		possibleNumbers[j] = temp;
	}
	for (int i = 0; i < 25; ++i) {
		card.numbers[i] = possibleNumbers[i];
	}
	return card;
}

void drawNumberAndMark(struct BingoCard* card, int number) {//�N��ܪ��Ʀr��*���N�A��ܤw��L���Ʀr
	for (int i = 0; i < 25; ++i) {
		if (card->numbers[i] == number) {
			card->numbers[i] = 0;
		}
	}
}

int hasBingo(struct BingoCard card) {//�P�_�O�_Bingo
	for (int i = 0; i < 5; ++i) {
		//��ƧP�_
		if (card.numbers[i * 5] == 0
			&& card.numbers[i * 5 + 1] == 0
			&& card.numbers[i * 5 + 2] == 0
			&& card.numbers[i * 5 + 3] == 0
			&& card.numbers[i * 5 + 4] == 0) {
			return 1;
		}
		//���ƧP�_
		if (card.numbers[i] == 0 && card.numbers[i + 5] == 0
			&& card.numbers[i + 10] == 0
			&& card.numbers[i + 15] == 0
			&& card.numbers[i + 20] == 0) {
			return 1;
		}
	}
	//�﨤�u�P�_
	if ((card.numbers[0] == 0 && card.numbers[6] == 0
		&& card.numbers[12] == 0 && card.numbers[18] == 0
		&& card.numbers[24] == 0)
		|| (card.numbers[4] == 0 && card.numbers[8] == 0
			&& card.numbers[12] == 0
			&& card.numbers[16] == 0
			&& card.numbers[20] == 0)) {
		return 1;
	}
	return 0;
}

void displayCardForPlayer(struct BingoCard card, int playerNumber) {//��ܪ��a�ثeBingo�d���ˤl
	printf("���a %d ���d:\n", playerNumber);
	for (int i = 0; i < 25; ++i) {
		if (card.numbers[i] != 0) {
			printf("%d\t", card.numbers[i]);
		}
		else {
			printf("X\t");
		}
		if ((i + 1) % 5 == 0) {
			printf("\n");
		}
	}
	printf("\n");
}

//////////////////////////////////////////////////////////////////////////�n�J�n�X�t��

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
	printf(" ------\n");
	printf("| �n�J |\n");
	printf(" ------\n");
	printf("��J�ϥΪ̦W��:");
	scanf("%s", name);
	strcpy(lg.name, name);
	printf("��J�ϥΪ̱K�X:");
	scanf("%s", password);
	strcpy(lg.password, password);
	return lg;
}

void writeToFile(User u)//�g�Jtxt�ɮסA�C�@��s�b�@�ӨϥΪ�
{
	FILE * fw = fopen("user.txt", "a+");
	fprintf(fw, u.name);
	fprintf(fw, "\t");
	fprintf(fw, u.password);
	fprintf(fw, "\n");
	fclose(fw);
}

int exist(User u)//�P�_�O�_�s�b�ӨϥΪ�(�K�X�O�_���T)
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

void registerUser()//���U�ϥΪ�
{
	char name[20];
	char password[20];
	User user;
	int i;

	printf(" ------\n");
	printf("| ���U |\n");
	printf(" ------\n");
	printf("��J�ϥΪ̦W��:");
	scanf("%s", name);
	strcpy(user.name, name);//�ƻs�r��

	for (i = 0; i < USER_MAX; i++)//�P�_���U���ϥΪ̬O�_�w�s�b
	{
		if (0 == strcmp(list[i].name, name))
		{
			printf("�ϥΪ̦W�٤w�g�s�b\n");
			return;
		}
	}

	printf("��J�ϥΪ̱K�X:");
	scanf("%s", password);
	strcpy(user.password, password);
	writeToFile(user);
	printf("���U���\\n");
}

int login_menu()
{
	int choice;

	printf("--------------\n");
	printf("| �n�J�B���U |\n");
	printf("--------------\n");
	printf("1.�n�J\n");
	printf("2.���U\n");
	printf("!.���}\n");
	printf("��J�A�����:");
	scanf("%d", &choice);
	return choice;
}

int main()
{
	/////////////////////////////////////////////////////////////////////////////////�n�J�n�X�t�ΥD�{��
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
				printf("�n�J���\");
				Sleep(1000);
				system("cls");//clear
				break;
			}
			else
			{
				printf("���~���ϥΪ̩αK�X\n");
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
	////////////////////////////////////////////////////////////////////////////////////////////////////////���G�C���D�{��
	srand((unsigned int)time(NULL));

	printf("�w��Ө컫�G�C���I\n");
	Sleep(3000);
	struct BingoCard player1Card = createBingoCard();
	struct BingoCard player2Card = createBingoCard();

	int currentPlayer = 1;

	while (1) {
		// Clear the screen
//#ifdef _WIN32
		system("cls");
		//#else
		//		system("clear");
		//#endif

		struct BingoCard currentCard = (currentPlayer == 1) ? player1Card : player2Card;

		printf("\n���a %d - ��J�z��ܪ����X (1-25): ", currentPlayer);
		int chosenNumber;
		if (scanf("%d", &chosenNumber) != 1) {
			printf("��J���~�C�п�J�@�Ӥ���1�M25�������Ʀr�C\n");
			rewind(stdin); // �M�Žw�İ�
			continue;
		}

		// ���ҨϥΪ̿�J
		if (chosenNumber < 1 || chosenNumber > 25) {
			printf("�L�Ŀ�J�C�п�J����1�M25�������Ʀr�C\n");
			continue;
		}

		drawNumberAndMark(&player1Card, chosenNumber);
		drawNumberAndMark(&player2Card, chosenNumber);

		if (hasBingo(player1Card)) {
			printf("\n���a 1 �w�F�����G�I���ߡI\n");
			break;
		}

		if (hasBingo(player2Card)) {
			printf("\n���a 2 �w�F�����G�I���ߡI\n");
			break;
		}

		printf("\n���a %d - ��X�����X: %d\n", currentPlayer, chosenNumber);

		if (currentPlayer == 1) {
			displayCardForPlayer(player1Card, 1);
			printf("--------------------------\n");
		}
		else {
			printf("���a 1 ���d: ����\n");
			printf("--------------------------\n");
		}

		if (currentPlayer == 2) {
			displayCardForPlayer(player2Card, 2);
			printf("--------------------------\n");
		}
		else {
			printf("���a 2 ���d: ����\n");
			printf("--------------------------\n");
		}

		// Wait for user input before proceeding to the next turn
		printf("��Enter���~��...");
		getchar();
		getchar(); // Consume the newline character

		currentPlayer = (currentPlayer == 1) ? 2 : 1;
	}


	system("pause"); return 0;

}
