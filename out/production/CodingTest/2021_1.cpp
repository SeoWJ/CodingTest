#include <iostream>
#include <string>
#include <vector>

using namespace std;

string step1(string new_id);
string step2(string new_id);
string step3(string id);
string step4(string id);
string step5(string id);
string step6(string id);
string step7(string id);

string solution(string new_id) {
	string answer = "";
	string recommand_id;
	
	recommand_id = step1(new_id);
	recommand_id = step2(recommand_id);
	recommand_id = step3(recommand_id);
	recommand_id = step4(recommand_id);
	recommand_id = step5(recommand_id);
	recommand_id = step6(recommand_id);
	recommand_id = step7(recommand_id);

	answer = recommand_id;

	return answer;
}

string step1(string id) {
	for (unsigned int x = 0; x < id.size(); x++) {
		if ('A' <= id[x] && id[x] <= 'Z')
			id[x] += 32;
	}

	return id;
}

string step2(string id) {
	string::iterator iter = id.begin();
	
	for (; iter != id.end(); iter++) {
		if ('a' <= *iter && *iter <= 'z') continue;
		else if ('0' <= *iter && *iter <= '9') continue;
		else if (*iter == '-' || *iter == '_' || *iter == '.') continue;
		else {
			id.erase(iter);
			iter--;
		}
	}

	return id;
}

string step3(string id) {
	if (id == "") return id;

	string n_id = "";
	n_id += id[0];

	for (int x = 1; x < id.size(); x++) {
		if (n_id[n_id.size() - 1] == '.' && id[x] == '.') continue;
		else n_id += id[x];
	}

	return n_id;
}

string step4(string id) {
	if (id == "") return id;

	string::iterator iter = id.begin();

	if (*iter == '.')
		id.erase(iter);

	iter = id.end();
	iter--;

	if (*iter == '.')
		id.erase(iter);

	return id;
}

string step5(string id) {
	if (id == "")
		id += "a";

	return id;
}

string step6(string id) {
	if (id.size() >= 16) {
		string n_id = "";
		for (int x = 0; x < 15; x++) {
			if (x == 14 && id[x] == '.')
				break;
			n_id += id[x];
		}

		return n_id;
	}

	return id;
}

string step7(string id) {
	if (id.size() <= 2) {
		while (1) {
			id += id[id.size() - 1];

			if (id.size() == 3)
				break;
		}
	}

	return id;
}

int main() {
	string new_id;
	cin >> new_id;
	cout << solution(new_id) << endl;
}