struct BingoCard {
	int numbers[25];
};
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