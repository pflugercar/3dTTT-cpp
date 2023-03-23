#include <iostream>
#include <string>

int getPlayers(const unsigned int &smallest, const unsigned int &largest);

void printBoard(const std::string board);

int main() {

	const int minPlayers = 2;
	const int maxPlayers = 4; 

	int playerCount;
	playerCount = getPlayers(minPlayers, maxPlayers);
	std::string playerNames[playerCount];

	// Initializing player names based on the max number of players possible
	for(int i = 0; i < playerCount; i++)
		playerNames[i] = "Player " + std::to_string(i + 1);

	char pieces[4] = {'X','O','Y','Z'};

	//  back layers      123      012      901
	//  middle layers       456      345      234
	//  front layers           789      678      567
	std::string board = "                           ";

	printBoard(board);

	return 0;
}

int getPlayers(const unsigned int &smallest, const unsigned int &largest) {
	std::string input;
	unsigned int result;

	while(true) {
		std::cout << "How many playerNames will be playing? [2-4] ";
		std::cin >> input;
		result = int(input[0]) - int('0');

		if (result >= smallest && result <= largest)
			break;

		std::cout << "Try again.\n" << std::endl;
	}

	return result;
}

void printBoard(const std::string b) {
	std::cout << "Printing the board.\n\n";

	printf(" %c | %c | %c\n",			b[0],b[1],b[2]);
	printf("---+---+---\n");
	printf(" %c | %c | %c    Top\n",	b[3],b[4],b[5]);
	printf("---+---+---\n");
	printf(" %c | %c | %c\n",			b[6],b[7],b[8]);
	printf("\n");
	printf(" %c | %c | %c\n",			b[9],b[10],b[11]);
	printf("---+---+---\n");
	printf(" %c | %c | %c    Middle\n",	b[12],b[13],b[14]);
	printf("---+---+---\n");
	printf(" %c | %c | %c\n",			b[15],b[16],b[17]);
	printf("\n");
	printf(" %c | %c | %c\n",			b[18],b[19],b[20]);
	printf("---+---+---\n");
	printf(" %c | %c | %c    Bottom\n",	b[21],b[22],b[23]);
	printf("---+---+---\n");
	printf(" %c | %c | %c\n",			b[24],b[25],b[26]);
}