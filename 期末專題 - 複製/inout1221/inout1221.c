#include "bingogame.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>


////////////////////////////////////////////////////////賓果系統

//struct BingoCard {
//	int numbers[25];
//};

//int generateRandomNumber(int min, int max) {//獲得隨機亂數
//	return min + rand() % (max - min + 1);
//}

//struct BingoCard createBingoCard() {//將獲得的隨機亂數放進5*5的陣列中，自動創建Bingo卡
//	struct BingoCard card;
//	int possibleNumbers[25];
//	for (int i = 0; i < 25; ++i) {
//		possibleNumbers[i] = i + 1;
//	}
//	for (int i = 0; i < 25; ++i) {
//		int j = generateRandomNumber(i, 24);
//		int temp = possibleNumbers[i];
//		possibleNumbers[i] = possibleNumbers[j];
//		possibleNumbers[j] = temp;
//	}
//	for (int i = 0; i < 25; ++i) {
//		card.numbers[i] = possibleNumbers[i];
//	}
//	return card;
//}

//void drawNumberAndMark(struct BingoCard* card, int number) {//將選擇的數字用*替代，表示已選過的數字
//	for (int i = 0; i < 25; ++i) {
//		if (card->numbers[i] == number) {
//			card->numbers[i] = 0;
//		}
//	}
//}

//int hasBingo(struct BingoCard card) {//判斷是否Bingo
//	for (int i = 0; i < 5; ++i) {
//		//橫排判斷
//		if (card.numbers[i * 5] == 0
//			&& card.numbers[i * 5 + 1] == 0
//			&& card.numbers[i * 5 + 2] == 0
//			&& card.numbers[i * 5 + 3] == 0
//			&& card.numbers[i * 5 + 4] == 0) {
//			return 1;
//		}
//		//直排判斷
//		if (card.numbers[i] == 0 && card.numbers[i + 5] == 0
//			&& card.numbers[i + 10] == 0
//			&& card.numbers[i + 15] == 0
//			&& card.numbers[i + 20] == 0) {
//			return 1;
//		}
//	}
//	//對角線判斷
//	if ((card.numbers[0] == 0 && card.numbers[6] == 0
//		&& card.numbers[12] == 0 && card.numbers[18] == 0
//		&& card.numbers[24] == 0)
//		|| (card.numbers[4] == 0 && card.numbers[8] == 0
//			&& card.numbers[12] == 0
//			&& card.numbers[16] == 0
//			&& card.numbers[20] == 0)) {
//		return 1;
//	}
//	return 0;
//}

//void displayCardForPlayer(struct BingoCard card, int playerNumber) {//顯示玩家目前Bingo卡的樣子
//	printf("玩家 %d 的卡:\n", playerNumber);
//	for (int i = 0; i < 25; ++i) {
//		if (card.numbers[i] != 0) {
//			printf("%d\t", card.numbers[i]);
//		}
//		else {
//			printf("X\t");
//		}
//		if ((i + 1) % 5 == 0) {
//			printf("\n");
//		}
//	}
//	printf("\n");
//}

////////////////////////////////////////////////////////////////////////////登入登出系統

//typedef struct
//{
//	char name[20];
//	char password[20];
//}
//User;//定義一個存放使用者的結構體
//
//User list[USER_MAX];//定義一個全域性陣列(登入註冊系統)

//User login()//登入函式
//{
//	char name[20];
//	char password[20];
//	User lg;
//	printf(" ＿＿＿\n");
//	printf("| 登入 |\n");
//	printf(" ￣￣￣\n");
//	printf("輸入使用者名稱:");
//	scanf("%s", name);
//	strcpy(lg.name, name);
//	printf("輸入使用者密碼:");
//	scanf("%s", password);
//	strcpy(lg.password, password);
//	return lg;
//}

//void writeToFile(User u)//寫入txt檔案，每一行存在一個使用者
//{
//	FILE * fw = fopen("user.txt", "a+");
//	fprintf(fw, u.name);
//	fprintf(fw, "\t");
//	fprintf(fw, u.password);
//	fprintf(fw, "\n");
//	fclose(fw);
//}

//int exist(User u)//判斷是否存在該使用者(密碼是否正確)
//{
//	int i;
//	for (i = 0; i < USER_MAX; i++)
//	{
//		if (0 == strcmp(list[i].name, u.name) && 0 == strcmp(list[i].password, u.password))
//		{
//			return 1;
//		}
//	}
//	return -1;
//}

//void registerUser()//註冊使用者
//{
//	char name[20];
//	char password[20];
//	User user;
//	int i;
//
//	printf(" ＿＿＿\n");
//	printf("| 註冊 |\n");
//	printf(" ￣￣￣\n");
//	printf("輸入使用者名稱:");
//	scanf("%s", name);
//	strcpy(user.name, name);//複製字串
//
//	for (i = 0; i < USER_MAX; i++)//判斷註冊的使用者是否已存在
//	{
//		if (0 == strcmp(list[i].name, name))
//		{
//			printf("使用者名稱已經存在\n");
//			return;
//		}
//	}
//
//	printf("輸入使用者密碼:");
//	scanf("%s", password);
//	strcpy(user.password, password);
//	writeToFile(user);
//	printf("註冊成功\n");
//}
//
//int login_menu()
//{
//	int choice;
//
//	printf(" ＿＿＿＿＿＿\n");
//	printf("| 登入、註冊 |\n");
//	printf(" ￣￣￣￣￣￣\n");
//	printf("1.登入\n");
//	printf("2.註冊\n");
//	printf("!.離開\n");
//	printf("輸入你的選擇:");
//	scanf("%d", &choice);
//	return choice;
//}

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
	////////////////////////////////////////////////////////////////////////////////////////////////////////賓果遊戲主程式
	srand((unsigned int)time(NULL));

	printf("歡迎來到賓果遊戲！\n");
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

		printf("\n玩家 %d - 輸入您選擇的號碼 (1-25): ", currentPlayer);
		int chosenNumber;
		if (scanf("%d", &chosenNumber) != 1) {
			printf("輸入錯誤。請輸入一個介於1和25之間的數字。\n");
			rewind(stdin); // 清空緩衝區
			continue;
		}

		// 驗證使用者輸入
		if (chosenNumber < 1 || chosenNumber > 25) {
			printf("無效輸入。請輸入介於1和25之間的數字。\n");
			continue;
		}

		drawNumberAndMark(&player1Card, chosenNumber);
		drawNumberAndMark(&player2Card, chosenNumber);

		if (hasBingo(player1Card)) {
			printf("\n玩家 1 已達成賓果！恭喜！\n");
			break;
		}

		if (hasBingo(player2Card)) {
			printf("\n玩家 2 已達成賓果！恭喜！\n");
			break;
		}

		printf("\n玩家 %d - 抽出的號碼: %d\n", currentPlayer, chosenNumber);

		if (currentPlayer == 1) {
			displayCardForPlayer(player1Card, 1);
			printf("--------------------------\n");
		}
		else {
			printf("玩家 1 的卡: 隱藏\n");
			printf("--------------------------\n");
		}

		if (currentPlayer == 2) {
			displayCardForPlayer(player2Card, 2);
			printf("--------------------------\n");
		}
		else {
			printf("玩家 2 的卡: 隱藏\n");
			printf("--------------------------\n");
		}

		// Wait for user input before proceeding to the next turn
		printf("按Enter鍵繼續...");
		getchar();
		getchar(); // Consume the newline character

		currentPlayer = (currentPlayer == 1) ? 2 : 1;
	}


	system("pause"); return 0;

}
