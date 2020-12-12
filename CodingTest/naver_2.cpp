#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> building;
int cement = 0;

void goLeft(int max_idx);
void goRight(int max_idx);

void solution(int day, int width, int** blocks) {
	// TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.
	for (int i = 0; i < width; i++) {
		building.push_back(blocks[0][i]);
	}

	for (int count = 0; count < day; count++) {
		if (count == 0);
		else {
			for (int i = 0; i < width; i++) {
				building[i] += blocks[count][i];
			}
		}

		int max_height = building[0];
		int max_idx = 0;

		for (int i = 0; i < width; i++) {
			max_height = max_height > building[i] ? max_height : building[i];
			max_idx = max_height > building[i] ? max_idx : i;
		}

		goLeft(max_idx);
		goRight(max_idx);

		for (int i = 0; i < building.size(); i++) {
			cout << building[i] << " ";
		}
		cout << endl << cement << endl;
	}
	
}

void goLeft(int max_idx) {
	int sub_max = 0;
	int sub_max_idx = max_idx + 1;

	for (int i = max_idx - 1; i >= 0; i--) {
		sub_max = sub_max > building[i] ? sub_max : building[i];
		sub_max_idx = sub_max > building[i] ? sub_max_idx : i;
	}

	for (int i = sub_max_idx; i < max_idx; i++) {
		cement += (sub_max - building[i]);
		building[i] += (sub_max - building[i]);		
	}

	if (sub_max_idx == 0)
		return;
	else
		goLeft(sub_max_idx);
}

void goRight(int max_idx) {
	int sub_max = 0;
	int sub_max_idx = max_idx - 1;

	for (int i = max_idx + 1; i < building.size(); i++) {
		sub_max = sub_max > building[i] ? sub_max : building[i];
		sub_max_idx = sub_max > building[i] ? sub_max_idx : i;
	}

	for (int i = sub_max_idx; i > max_idx; i--) {
		cement += (sub_max - building[i]);
		building[i] += (sub_max - building[i]);
	}

	if (sub_max_idx == building.size() - 1)
		return;
	else
		goRight(sub_max_idx);
}

struct input_data {
	int day;
	int width;
	int** blocks;
};

void process_stdin(struct input_data& inputData) {
	string line;
	istringstream iss;

	getline(cin, line);
	iss.str(line);
	iss >> inputData.day;

	getline(cin, line);
	iss.clear();
	iss.str(line);
	iss >> inputData.width;

	inputData.blocks = new int* [inputData.day];
	for (int i = 0; i < inputData.day; i++) {
		getline(cin, line);
		iss.clear();
		iss.str(line);
		inputData.blocks[i] = new int[inputData.width];
		for (int j = 0; j < inputData.width; j++) {
			iss >> inputData.blocks[i][j];
		}
	}
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.day, inputData.width, inputData.blocks);
	return 0;
}