struct BingoCard {
	int numbers[25];
};
int hasBingo(struct BingoCard card) {//§PÂ_¬O§_Bingo
	for (int i = 0; i < 5; ++i) {
		//¾î±Æ§PÂ_
		if (card.numbers[i * 5] == 0
			&& card.numbers[i * 5 + 1] == 0
			&& card.numbers[i * 5 + 2] == 0
			&& card.numbers[i * 5 + 3] == 0
			&& card.numbers[i * 5 + 4] == 0) {
			return 1;
		}
		//ª½±Æ§PÂ_
		if (card.numbers[i] == 0 && card.numbers[i + 5] == 0
			&& card.numbers[i + 10] == 0
			&& card.numbers[i + 15] == 0
			&& card.numbers[i + 20] == 0) {
			return 1;
		}
	}
	//¹ï¨¤½u§PÂ_
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