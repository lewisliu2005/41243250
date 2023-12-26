struct BingoCard {
	int numbers[25];
};
void drawNumberAndMark(struct BingoCard* card, int number) {//將選擇的數字用*替代，表示已選過的數字
	for (int i = 0; i < 25; ++i) {
		if (card->numbers[i] == number) {
			card->numbers[i] = 0;
		}
	}
}