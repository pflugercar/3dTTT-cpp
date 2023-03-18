#include <iostream>
#include <string>
#include <array>

int getPlayers(const unsigned int &least, const unsigned int &most) {
	std::string input;
	unsigned int result;

	while(true) {
		std::cout << "How many playerNames will be playing? [2-4] ";
		std::cin >> input;
		
		result = stoi(input);

		if (result >= least && result <= most)
			break;

		std::cout << "Integer result is: " << result << std::endl;
	}

	return result;
}


int main() {

	const int minPlayers = 2;
	const int maxPlayers = 4; 
	int playerCount;
	playerCount = getPlayers(minPlayers, maxPlayers);
	
	std::string playerNames[maxPlayers];
	for(int i = 0; i < playerCount; i++)
		playerNames[i] = "Player " + std::to_string(i + 1);

	for(int i = 0; i < playerCount; i++)
		std::cout << playerNames[i] << std::endl;

	return 0;
}
