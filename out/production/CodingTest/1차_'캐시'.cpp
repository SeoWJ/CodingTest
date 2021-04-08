#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define CACHEHIT 1
#define CACHEMISS 5

using namespace std;

string toCapitial(string city) {
	for (unsigned int i = 0; i < city.size(); i++) {
		if ('a' <= city[i] && city[i] <= 'z') {
			city[i] += 'A' - 'a';
		}
	}

	return city;
}

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;

	deque<string> cache;

	if (cacheSize == 0)
		return 5 * cities.size();

	for (unsigned int i = 0; i < cities.size(); i++) {
		string city = toCapitial(cities[i]);

		deque<string>::iterator iter = cache.begin();
		for (; iter != cache.end(); iter++) {
			if (city == *iter)
				break;
		}

		if (iter == cache.end()) {
			answer += CACHEMISS;
			
			if (cache.size() == cacheSize)
				cache.pop_front();

			cache.push_back(city);
		}
		else {
			answer += CACHEHIT;
			cache.erase(iter);
			cache.push_back(city);
		}
	}

	return answer;
}
