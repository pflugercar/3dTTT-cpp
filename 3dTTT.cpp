#include <iostream>
#include <string>
#include <array>

int getPlayers(const unsigned int &smallest, const unsigned int &largest);

void printBoard(const char *board);

int main() {

	const int minPlayers = 2;
	const int maxPlayers = 4; 

	int playerCount;
	std::string playerNames[maxPlayers];
	playerCount = getPlayers(minPlayers, maxPlayers);

	// Initializing player names based on the max number of players possible
	for(int i = 0; i < playerCount; i++)
		playerNames[i] = "Player " + std::to_string(i + 1);

	char pieces[4] = {'X','O','Y','Z'};

	char board[28];
	for (unsigned int element = 0; element < 27; element++)
		board[element] = ' ';

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

void printBoard(const char *board) {
	std::cout << "Printing the board.\n\n";

	for(int z = 0; z < 3; z++) {
		for(int y = 0; y < 3; y++) {
			if(y != 0)
				std::cout << "---+---+---\n";
			for(int x = 0; x < 3; x++) {
				if(x != 0)
					std::cout << " |";
				std::cout << " " << board[x+y*3+z*9];
			}
			std::cout << "\n";
		}
		std::cout << "\n\n";
	}
}