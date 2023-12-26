#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define USER_MAX 20

struct BingoCard {
	int numbers[25];
};

int generateRandomNumber(int , int );
struct BingoCard createBingoCard();
void drawNumberAndMark(struct BingoCard* , int );
int hasBingo(struct BingoCard );
void displayCardForPlayer(struct BingoCard , int );

typedef struct
{
	char name[20];
	char password[20];
}
User;//�w�q�@�Ӧs��ϥΪ̪����c��

User list[USER_MAX];//�w�q�@�ӥ���ʰ}�C(�n�J���U�t��)

User login(void);
void writeToFile(User );
int exist(User );
void registerUser(void);
int login_menu(void);