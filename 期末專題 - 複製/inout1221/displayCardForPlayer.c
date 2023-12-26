struct BingoCard {
	int numbers[25];
};
void displayCardForPlayer(struct BingoCard card, int playerNumber) {//顯示玩家目前Bingo卡的樣子
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