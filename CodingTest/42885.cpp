#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	int idx_front = 0, idx_back = people.size() - 1;
	vector<pair<int, bool>> _people;

	sort(people.begin(), people.end());

	for (int i = 0; i < people.size(); i++)
		_people.push_back(make_pair(people[i], false));

	while (idx_front != people.size()) {
		if (idx_front < idx_back) {
			if (_people[idx_front].second == false) {
				while (1) {
					if (idx_front >= idx_back) {
						answer++;
						_people[idx_front].second = true;
						break;
					}
					if (_people[idx_front].first + _people[idx_back].first <= limit) {
						_people[idx_front].second = true;
						_people[idx_back].second = true;
						idx_back--;
						answer++;
						break;
					}
					else {
						idx_back--;
					}
				}
				idx_front++;
			}
		}
		else {
			if (_people[idx_front].second == false) {
				_people[idx_front].second = true;
				answer++;
			}
			idx_front++;
		}
	}
	
	return answer;
}

int main() {
	solution({ 70,50,80,50 }, 100);
}