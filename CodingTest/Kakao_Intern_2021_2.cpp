#include <string>
#include <vector>

#define PERSON 'P'
#define TABLE 'O'
#define PARTITION 'X'

using namespace std;

bool check(vector<vector<string>>& places, int roomNumber, int x, int y) {
	if (places[roomNumber][y][x] != PERSON)
		return true;

	if (places[roomNumber][y][x - 2] == PERSON && places[roomNumber][y][x - 1] != PARTITION)
		return false;
	if (places[roomNumber][y][x + 2] == PERSON && places[roomNumber][y][x + 1] != PARTITION)
		return false;
	if (places[roomNumber][y - 2][x] == PERSON && places[roomNumber][y - 1][x] != PARTITION)
		return false;
	if (places[roomNumber][y + 2][x] == PERSON && places[roomNumber][y + 1][x] != PARTITION)
		return false;

	if (places[roomNumber][y][x - 1] == PERSON)
		return false;
	if (places[roomNumber][y][x + 1] == PERSON)
		return false;
	if (places[roomNumber][y - 1][x] == PERSON)
		return false;
	if (places[roomNumber][y + 1][x] == PERSON)
		return false;

	if (places[roomNumber][y - 1][x - 1] == PERSON && (places[roomNumber][y - 1][x] != PARTITION || places[roomNumber][y][x - 1] != PARTITION))
		return false;
	if (places[roomNumber][y - 1][x + 1] == PERSON && (places[roomNumber][y - 1][x] != PARTITION || places[roomNumber][y][x + 1] != PARTITION))
		return false;
	if (places[roomNumber][y + 1][x - 1] == PERSON && (places[roomNumber][y + 1][x] != PARTITION || places[roomNumber][y][x - 1] != PARTITION))
		return false;
	if (places[roomNumber][y + 1][x + 1] == PERSON && (places[roomNumber][y + 1][x] != PARTITION || places[roomNumber][y][x + 1] != PARTITION))
		return false;

	return true;
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;
	vector<vector<string>> placesErrorPrevent;
	
	string barrier = "XXXXXXXXX";
	vector<string> room(9, barrier);
	placesErrorPrevent.assign(5, room);

	for (unsigned int i = 0; i < places.size(); i++) {
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				placesErrorPrevent[i][y + 2][x + 2] = places[i][y][x];
			}
		}
	}

	for (unsigned int room = 0; room < places.size(); room++) {
		bool enoughSpace = true;

		for (int y = 2; y < 7; y++) {
			for (int x = 0; x < 7; x++) {
				enoughSpace = check(placesErrorPrevent, room, x, y);

				if (!enoughSpace)
					break;
			}

			if (!enoughSpace)
				break;
		}

		int result = enoughSpace ? 1 : 0;
		answer.push_back(result);
	}

	return answer;
}

int main() {
	solution({ {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} });
}