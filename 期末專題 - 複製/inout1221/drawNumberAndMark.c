struct BingoCard {
	int numbers[25];
};
void drawNumberAndMark(struct BingoCard* card, int number) {//�N��ܪ��Ʀr��*���N�A��ܤw��L���Ʀr
	for (int i = 0; i < 25; ++i) {
		if (card->numbers[i] == number) {
			card->numbers[i] = 0;
		}
	}
}