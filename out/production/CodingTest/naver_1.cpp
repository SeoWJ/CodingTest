#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class player {
public:
	char name;
	int count = 0;

	player() {};

	player(char _name) {
		name = _name;
	}
};

void solution(int numOfAllPlayers, int numOfQuickPlayers, char* namesOfQuickPlayers, int numOfGames, int* numOfMovesPerGame) {
	// TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.

	vector<player> game;
	player soolrae('A');
	soolrae.count++;
	for (int i = 1; i < numOfAllPlayers; i++)
		game.push_back(player('A' + i));

	int soolrae_position = 0;
	
	for (int round = 0; round < numOfGames; round++) {
		soolrae_position += numOfMovesPerGame[round];
		soolrae_position %= game.size();
		
		bool can_catch = false;
		for (int i = 0; i < numOfQuickPlayers; i++) {
			if (namesOfQuickPlayers[i] == game[soolrae_position].name)
				can_catch = true;
		}

		if (can_catch == true) {
			soolrae.count++;
		}
		else {		// false
			game[soolrae_position].count++;
			
			player temp;
			temp.name = game[soolrae_position].name;
			temp.count = game[soolrae_position].count;
			game[soolrae_position].name = soolrae.name;
			game[soolrae_position].count = soolrae.count;
			soolrae.name = temp.name;
			soolrae.count = temp.count;
		}
	}

	for (int i = 0; i < game.size(); i++) {
		cout << game[i].name << " " << game[i].count << endl;
	}
	cout << soolrae.name << " " << soolrae.count << endl;
}

struct input_data {
	int numOfAllPlayers;
	int numOfQuickPlayers;
	char* namesOfQuickPlayers;
	int numOfGames;
	int* numOfMovesPerGame;
};

void process_stdin(struct input_data& inputData) {
	string line;
	istringstream iss;

	getline(cin, line);
	iss.str(line);
	iss >> inputData.numOfAllPlayers;

	getline(cin, line);
	iss.clear();
	iss.str(line);
	iss >> inputData.numOfQuickPlayers;

	getline(cin, line);
	iss.clear();
	iss.str(line);
	inputData.namesOfQuickPlayers = new char[inputData.numOfQuickPlayers];
	for (int i = 0; i < inputData.numOfQuickPlayers; i++) {
		iss >> inputData.namesOfQuickPlayers[i];
	}

	getline(cin, line);
	iss.clear();
	iss.str(line);
	iss >> inputData.numOfGames;

	getline(cin, line);
	iss.clear();
	iss.str(line);
	inputData.numOfMovesPerGame = new int[inputData.numOfGames];
	for (int i = 0; i < inputData.numOfGames; i++) {
		iss >> inputData.numOfMovesPerGame[i];
	}
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.numOfAllPlayers, inputData.numOfQuickPlayers, inputData.namesOfQuickPlayers, inputData.numOfGames, inputData.numOfMovesPerGame);
	return 0;
}