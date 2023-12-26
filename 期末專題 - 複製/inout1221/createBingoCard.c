struct BingoCard {
	int numbers[25];
};
struct BingoCard createBingoCard() {//將獲得的隨機亂數放進5*5的陣列中，自動創建Bingo卡
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