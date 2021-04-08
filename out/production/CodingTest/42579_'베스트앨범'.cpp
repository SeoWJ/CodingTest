// Sol. 1

/*#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct song {
	string genre;
	int plays;
	int id;
};

struct total {
	string genre;
	int plays = 0;
	vector<int> id;
};

bool compare(song s1, song s2);
bool compare2(total t1, total t2);

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	vector<song> songs;

	for (unsigned int x = 0; x < genres.size(); x++) {
		song s;
		s.genre = genres[x];
		s.plays = plays[x];
		s.id = x;

		songs.push_back(s);
	}

	sort(songs.begin(), songs.end(), compare);

	vector<total> t;
	int t_index = 0;

	total temp;
	temp.genre = songs[0].genre;
	temp.plays += songs[0].plays;
	temp.id.push_back(songs[0].id);
	t.push_back(temp);

	
	for (unsigned int x = 1; x < songs.size(); x++) {
		if (songs[x - 1].genre == songs[x].genre) {
			t[t_index].plays += songs[x].plays;
			t[t_index].id.push_back(songs[x].id);
		}
		else {
			total temp;
			temp.genre = songs[x].genre;
			temp.plays += songs[x].plays;
			temp.id.push_back(songs[x].id);
			t.push_back(temp);
			t_index++;
		}
	}

	sort(t.begin(), t.end(), compare2);
	
	for (unsigned int x = 0; x < t.size(); x++) {
		if (t[x].id.size() < 2)
			answer.push_back(t[x].id[0]);
		else {
			answer.push_back(t[x].id[0]);
			answer.push_back(t[x].id[1]);
		}
	}

	return answer;
}

bool compare(song s1, song s2){
	if (s1.genre == s2.genre) {
		if (s1.plays == s2.plays) {
			return s1.id < s2.id;
		}
		return s1.plays > s2.plays;
	}
	return s1.genre < s2.genre;
}

bool compare2(total t1, total t2) {
	return t1.plays > t2.plays;
}*/

// Sol 2.

#include <string>
#include <vector>
#include <algorithm>

#define HASH_MAX 9713547

using namespace std;

struct Genre {
	int totalPlayed = 0;
	vector<pair<int, int>> songs;
};

Genre* genreList[HASH_MAX] = { NULL };

int hashFunction(string genre);
bool genreListSort(Genre* g1, Genre* g2);
bool songSort(pair<int, int> s1, pair<int, int> s2);

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	for (unsigned int i = 0; i < genres.size(); i++) {
		int idx = hashFunction(genres[i]);

		if (genreList[idx] == NULL)
			genreList[idx] = new Genre;

		genreList[idx]->totalPlayed += plays[i];
		genreList[idx]->songs.push_back({ plays[i], i });
	}

	sort(genreList, genreList + HASH_MAX, genreListSort);

	for (int i = 0; genreList[i] != NULL; i++) {
		sort(genreList[i]->songs.begin(), genreList[i]->songs.end(), songSort);

		if (genreList[i]->songs.size() < 2)
			answer.push_back(genreList[i]->songs[0].second);
		else {
			answer.push_back(genreList[i]->songs[0].second);
			answer.push_back(genreList[i]->songs[1].second);
		}
	}

	return answer;
}

bool genreListSort(Genre* g1, Genre* g2) {
	if (g1 == NULL && g2 == NULL) return false;
	else if (g1 == NULL && g2 != NULL) return false;
	else if (g1 != NULL && g2 == NULL) return true;
	else {
		return g1->totalPlayed > g2->totalPlayed;
	}
}
bool songSort(pair<int, int> s1, pair<int, int> s2) {
	if (s1.first == s2.first) return s1.second < s2.second;
	else return s1.first > s2.first;
}

int hashFunction(string genre) {
	int result = 1;

	for (unsigned int i = 0; i < genre.size(); i++)
		result = ((result * genre[i]) + 157) % HASH_MAX;

	return result;
}

int main() {
	solution({ "classic", "pop", "classic", "classic", "pop" }, { 500, 600, 150, 800, 2500 });
}