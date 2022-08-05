#include <iostream>

const int NUMBER_OF_SPACES = 9;		
const char CROSS = 'X';
const char NOUGHT = 'O';
const char EMPTY = ' ';

// a function that writes out the opening ASCII image
void writeOutOpeningImage() {
	std::cout << "%%          %% |               |              " << std::endl;
	std::cout << "  %%      %%   |               |              " << std::endl;
	std::cout << "    %%  %%     |               |              " << std::endl;
	std::cout << "      %%       |               |              " << std::endl;
	std::cout << "    %%  %%     |               |              " << std::endl;
	std::cout << "  %%      %%   |               |              " << std::endl;
	std::cout << "%%          %% |               |              " << std::endl;
	std::cout << "---------------+---------------+--------------" << std::endl;
	std::cout << "               |     %%%%      |              " << std::endl;
	std::cout << "               |  %%      %%   |              " << std::endl;
	std::cout << "               | %%        %%  |              " << std::endl;
	std::cout << "               |%%          %% |              " << std::endl;
	std::cout << "               |%%          %% |              " << std::endl;
	std::cout << "               | %%        %%  |              " << std::endl;
	std::cout << "               |  %%      %%   |              " << std::endl;
	std::cout << "               |     %%%%      |              " << std::endl;
	std::cout << "---------------+---------------+--------------" << std::endl;
	std::cout << "               |               |              " << std::endl;
	std::cout << "               |               |           TIC" << std::endl;
	std::cout << "               |               |           TAC" << std::endl;
	std::cout << "               |               |           TOE" << std::endl;
	std::cout << "               |               |              " << std::endl;
	std::cout << "               |               |    Sebastijan" << std::endl;
	std::cout << "               |               |       Cerovec" << std::endl;
}

// a function that writes out the grid
void writeOutGrid(char spaces[NUMBER_OF_SPACES]) {

	std::cout << std::endl;
	for (int i = 0; i < NUMBER_OF_SPACES; i++) {

		if (i == 0 || i == 3 || i == 6)
			std::cout << "   " << (char)186 << "   " << (char)186 << "   " << std::endl;

		std::cout << " " << spaces[i] << " ";

		if (i == 2 || i == 5 || i == 8)
		{
			std::cout << std::endl;
			if (i == 2)
			{
				std::cout << "  1" << (char)186 << "  2" << (char)186 << "  3" << std::endl;
				std::cout << (char)205 << (char)205 << (char)205 << (char)206;
				std::cout << (char)205 << (char)205 << (char)205 << (char)206;
				std::cout << (char)205 << (char)205 << (char)205 << std::endl;
			}

			else if (i == 5)
			{
				std::cout << "  4" << (char)186 << "  5" << (char)186 << "  6" << std::endl;
				std::cout << (char)205 << (char)205 << (char)205 << (char)206;
				std::cout << (char)205 << (char)205 << (char)205 << (char)206;
				std::cout << (char)205 << (char)205 << (char)205 << std::endl;
			}
			else if (i == 8)
				std::cout << "  7" << (char)186 << "  8" << (char)186 << "  9" << std::endl;
		}
		else
			std::cout << (char)186;

	}
	std::cout << std::endl;
}

// a function that checks if a player has succeeded in placing three marks in a single row
bool checkRow(char spaces[NUMBER_OF_SPACES], int firstSpace, int secondSpace, int thirdSpace) {
	if (spaces[firstSpace] == spaces[secondSpace] && spaces[firstSpace] == spaces[thirdSpace] && (spaces[firstSpace] == CROSS || spaces[firstSpace] == NOUGHT))
		return true;
	else
		return false;
}

// a function that checks the grid if a player has succeeded in placing three marks in a horizontal, vertical, or diagonal row 
bool checkGrid(char spaces[NUMBER_OF_SPACES]) {
	if (checkRow(spaces, 0, 1, 2)
		||
		checkRow(spaces, 3, 4, 5)
		||
		checkRow(spaces, 6, 7, 8)
		||
		checkRow(spaces, 0, 3, 6)
		||
		checkRow(spaces, 1, 4, 7)
		||
		checkRow(spaces, 2, 5, 8)
		||
		checkRow(spaces, 0, 4, 8)
		||
		checkRow(spaces, 2, 4, 6))
		return true;
	else
		return false;
}

// a function that checks if any player won
bool checkIfAnyPlayerWon(char spaces[NUMBER_OF_SPACES], char mark) {
	if (checkGrid(spaces))
	{
		std::cout << "Victory! ";

		if (mark == CROSS) {
			std::cout << "Player (" << CROSS << ") won! Crosses won!" << std::endl << std::endl;
			std::cout << "%%          %%" << std::endl;
			std::cout << "  %%      %%  " << std::endl;
			std::cout << "    %%  %%    " << std::endl;
			std::cout << "      %%      " << std::endl;
			std::cout << "    %%  %%    " << std::endl;
			std::cout << "  %%      %%  " << std::endl;
			std::cout << "%%          %%" << std::endl << std::endl;
		}
		else if (mark == NOUGHT) {
			std::cout << "Player (" << NOUGHT << ") won! Noughts won!" << std::endl << std::endl;
			std::cout << "     %%%%      " << std::endl;
			std::cout << "  %%      %%   " << std::endl;
			std::cout << " %%        %%  " << std::endl;
			std::cout << "%%          %% " << std::endl;
			std::cout << "%%          %% " << std::endl;
			std::cout << " %%        %%  " << std::endl;
			std::cout << "  %%      %%   " << std::endl;
			std::cout << "     %%%%      " << std::endl << std::endl;
		}

		if (mark == CROSS || mark == NOUGHT)
			return true;
		else
			return false;
	}
}

// a function that asks if the players want another game
bool askPlayersForAnotherGame() {
	char choice;
	do {
		std::cout << "Want to play again? (y/n): " << std::endl;

		std::cin >> choice;

		switch (choice) {
		case 'N':
		case 'n':
			std::cout << std::endl << "Thank you for playing!" << std::endl;
			return false;
		case 'Y':
		case 'y':
			std::cout << std::endl << "Here we go!" << std::endl << std::endl;
			return true;
		default:
			std::cout << "Wrong answer." << std::endl << std::endl;
			break;
		}
	} while (!(choice == 'N' || choice == 'n' || choice == 'y' || choice == 'Y'));
}

int main() {

	bool wantToPlay = true;

	do {

		const bool playerXsTurn = 0; // player (X) always starts first

		bool victory = false;

		char spaces[NUMBER_OF_SPACES];
		bool markedSpaces[NUMBER_OF_SPACES] = { 0 };

		memset(spaces, EMPTY, sizeof(spaces));

		bool nextInLine = playerXsTurn;

		writeOutOpeningImage();

		writeOutGrid(spaces);

		for (int i = 0; i < NUMBER_OF_SPACES; i++)
		{

			int position;
			int index;
			int currentMark;

			do {
				if (nextInLine == playerXsTurn)
					std::cout << "Player (" << CROSS << "), place your mark!" << std::endl;
				else
					std::cout << "Player (" << NOUGHT << "), place your mark!" << std::endl;
				std::cout << "Mark space: (1-" << NUMBER_OF_SPACES << ") " << std::endl;
				std::cin >> position;
				if (std::cin.fail()) {
					std::cout << "Wrong entry!" << std::endl;
					std::cin.clear();
					std::cin.ignore(10, '\n');
					continue;
				}

				index = position - 1;

				if (position < 1 || position > NUMBER_OF_SPACES)
					std::cout << "There is no space " << position << "!" << std::endl << std::endl;
				else if (markedSpaces[index])
					std::cout << "This space is already marked!" << std::endl << std::endl;

			} while (!(position >= 1 && position <= NUMBER_OF_SPACES) || markedSpaces[index]);


			// select mark
			if (nextInLine == playerXsTurn)
				currentMark = CROSS;
			else
				currentMark = NOUGHT;

			// mark space and save information that marked space is taken
			spaces[index] = currentMark;
			markedSpaces[index] = true;

			// switch to the next player in line
			nextInLine = !nextInLine;

			writeOutGrid(spaces);

			victory = checkIfAnyPlayerWon(spaces, currentMark);

			if (victory)
				break;
		}

		if (!victory)
			std::cout << "Draw. Cat's game!" << std::endl;

		wantToPlay = askPlayersForAnotherGame();

	} while (wantToPlay);

}