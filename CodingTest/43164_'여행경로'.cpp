// Sol 1.

/*#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

struct Airport {
	string name = "";
	vector<pair<string, bool>> destination;
};

vector<string> answer;

void DFS(vector<Airport> airport, vector<string> _answer);

vector<string> solution(vector<vector<string>> tickets) {
	vector<Airport> airport;

	for (unsigned int x = 0; x < tickets.size(); x++) {
		bool inserted = false;

		for (unsigned int y = 0; y < airport.size(); y++) {
			if (airport[y].name == tickets[x][0]) {
				airport[y].destination.push_back(make_pair(tickets[x][1], false));
				inserted = true;
				break;
			}
		}
		if (inserted == false) {
			Airport a;
			a.name = tickets[x][0];
			a.destination.push_back(make_pair(tickets[x][1], false));
			airport.push_back(a);
		}
	}

	vector<string> empty_answer;
	empty_answer.push_back("ICN");
	
	DFS(airport, empty_answer);

	return answer;
}

void DFS(vector<Airport> airport, vector<string> _answer) {
	bool finished = true;
	for (unsigned int y = 0; y < airport.size(); y++) {
		for (unsigned int x = 0; x < airport[y].destination.size(); x++) {
			if (airport[y].destination[x].second == false) {
				finished = false;
				break;
			}
		}
		if (finished == false) break;
	}

	if (finished == true) {
		if (answer.size() == 0) {
			answer = _answer;
			return;
		}
		else {
			for (unsigned int x = 0; x < answer.size(); x++) {
				if (answer[x] == _answer[x])
					continue;
				else {
					answer = answer[x] < _answer[x] ? answer : _answer;
					return;
				}
			}
			return;
		}
	}

	unsigned int position = -1;
	for (unsigned int x = 0; x < airport.size(); x++) {
		if (airport[x].name == _answer.back()) {
			position = x;
			break;
		}
	}
	if (position == -1) return;

	for (unsigned int x = 0; x < airport[position].destination.size(); x++) {
		if (airport[position].destination[x].second == false) {
			_answer.push_back(airport[position].destination[x].first);
			airport[position].destination[x].second = true;
			DFS(airport, _answer);
			_answer.pop_back();
			airport[position].destination[x].second = false;
		}
	}
}

int main() {
	vector<vector<string>> tickets;
	vector<string> ticket;
	
	ticket.push_back("ICN");
	ticket.push_back("SFO");
	tickets.push_back(ticket);

	ticket[0] = "ICN";
	ticket[1] = "ATL";
	tickets.push_back(ticket);

	ticket[0] = "SFO";
	ticket[1] = "ATL";
	tickets.push_back(ticket);

	ticket[0] = "ATL";
	ticket[1] = "ICN";
	tickets.push_back(ticket);

	ticket[0] = "ATL";
	ticket[1] = "ZZZ";
	tickets.push_back(ticket);

	solution(tickets);

	for (unsigned int x = 0; x < answer.size(); x++)
		cout << answer[x] << " ";
	cout << endl;

	return 0;
}*/

// Sol 2.

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int ROUTEMAX;
vector<string> answer;

void DFS(string currentAirport, unordered_map<string, vector<pair<string, bool>>> unorderedMap, vector<string> route);

vector<string> solution(vector<vector<string>> tickets) {
	ROUTEMAX = tickets.size() + 1;

	unordered_map<string, vector<pair<string, bool>>> unorderedMap;

	for (unsigned int i = 0; i < tickets.size(); i++)
		unorderedMap[tickets[i][0]].push_back({ tickets[i][1], false });

	DFS("ICN", unorderedMap, { "ICN" });

	return answer;
}

void DFS(string currentAirport, unordered_map<string, vector<pair<string, bool>>> unorderedMap, vector<string> route) {
	if (route.size() == ROUTEMAX) {
		if (answer == route) return;
		
		if (answer.empty()) {
			answer = route;
			return;
		}
		else {
			for (unsigned int i = 0; i < answer.size(); i++) {
				if (answer[i] == route[i]) continue;
				else if (answer[i] < route[i]) return;
				else answer = route;
			}
		}
	}

	for (unsigned int i = 0; i < unorderedMap[currentAirport].size(); i++) {
		if (unorderedMap[currentAirport][i].second == false) {
			unorderedMap[currentAirport][i].second = true;
			route.push_back(unorderedMap[currentAirport][i].first);
			
			DFS(unorderedMap[currentAirport][i].first, unorderedMap, route);

			route.pop_back();
			unorderedMap[currentAirport][i].second = false;
		}
	}
}

int main() {
	solution({ {"ICN","HND"}, {"HND", "ICN"}, {"ICN", "HND"}, {"HND", "ICN"} });
}