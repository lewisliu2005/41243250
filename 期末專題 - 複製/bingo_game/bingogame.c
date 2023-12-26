#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct BingoCard {
    int numbers[25];
};

int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

struct BingoCard createBingoCard() {
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

void drawNumberAndMark(struct BingoCard* card, int number) {
    for (int i = 0; i < 25; ++i) {
        if (card->numbers[i] == number) {
            card->numbers[i] = 0;
        }
    }
}

int hasBingo(struct BingoCard card) {
    for (int i = 0; i < 5; ++i) {
        if (card.numbers[i * 5] == 0
            && card.numbers[i * 5 + 1] == 0
            && card.numbers[i * 5 + 2] == 0
            && card.numbers[i * 5 + 3] == 0
            && card.numbers[i * 5 + 4] == 0) {
            return 1;
        }
        if (card.numbers[i] == 0 && card.numbers[i + 5] == 0
            && card.numbers[i + 10] == 0
            && card.numbers[i + 15] == 0
            && card.numbers[i + 20] == 0) {
            return 1;
        }
    }
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

void displayCardForPlayer(struct BingoCard card, int playerNumber) {
    printf("玩家 %d 的卡:\n", playerNumber);
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

int main() {
    srand((unsigned int)time(NULL));

    printf("歡迎來到賓果遊戲！\n");

    struct BingoCard player1Card = createBingoCard();
    struct BingoCard player2Card = createBingoCard();

    int currentPlayer = 1;

    while (1) {
        // Clear the screen
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

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

    return 0;
}
