struct BingoCard {
	int numbers[25];
};
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