int generateRandomNumber(int min, int max) {//獲得隨機亂數
	return min + rand() % (max - min + 1);
}