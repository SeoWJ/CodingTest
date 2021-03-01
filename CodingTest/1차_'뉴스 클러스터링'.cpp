#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

#define isAlphabet(a) (('a' <= a && a <= 'z') || ('A' <= a && a <= 'Z'))
#define isCapital(a) ('A' <= a && a <= 'Z')
#define TO_CAPITAL 'A' - 'a'

using namespace std;

int solution(string str1, string str2) {
	int answer = 0;

	unordered_map<string, int> A;
	unordered_map<string, int> B;
	vector<string> A_index;
	vector<string> B_index;

	for (unsigned int i = 0; i < str1.size() - 1; i++) {
		if (isAlphabet(str1[i]) && isAlphabet(str1[i + 1])) {
			string temp = "";
			
			if (isCapital(str1[i])) temp += str1[i];
			else temp += (str1[i] + TO_CAPITAL);
			if (isCapital(str1[i + 1])) temp += str1[i + 1];
			else temp += (str1[i + 1] + TO_CAPITAL);

			A[temp]++;
			A_index.push_back(temp);
		}
	}
	for (unsigned int i = 0; i < str2.size() - 1; i++) {
		if (isAlphabet(str2[i]) && isAlphabet(str2[i + 1])) {
			string temp = "";

			if (isCapital(str2[i])) temp += str2[i];
			else temp += (str2[i] + TO_CAPITAL);
			if (isCapital(str2[i + 1])) temp += str2[i + 1];
			else temp += (str2[i + 1] + TO_CAPITAL);

			B[temp]++;
			B_index.push_back(temp);
		}
	}

	if (A.size() == 0 && B.size() == 0) return 1 * 65536;

	vector<string> AUB;
	vector<string> ANB;

	for (unsigned int i = 0; i < A_index.size(); i++) {
		if (A[A_index[i]] > 0 && B[A_index[i]] > 0) {
			A[A_index[i]]--;
			B[A_index[i]]--;
			ANB.push_back(A_index[i]);
		}
	}
	AUB = ANB;
	for (unsigned int i = 0; i < A_index.size(); i++) {
		if (A[A_index[i]] > 0) {
			A[A_index[i]]--;
			AUB.push_back(A_index[i]);
		}
	}
	for (unsigned int i = 0; i < B_index.size(); i++) {
		if (B[B_index[i]] > 0) {
			B[B_index[i]]--;
			AUB.push_back(B_index[i]);
		}
	}

	double AUB_size = (double)AUB.size();
	double ANB_size = (double)ANB.size();

	double jacad = (ANB_size / AUB_size) * 65536;

	answer = (int)jacad;

	return answer;
}