#include <string>
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
}