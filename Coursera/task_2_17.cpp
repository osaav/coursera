#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

void add(map<string, set<string>>& dict, const string& word1, const string& word2) {
	dict[word1].insert(word2);
	dict[word2].insert(word1);
}

int count(map<string, set<string>>& dict, const string& word) {
	return dict[word].size();
}

bool check(map<string, set<string>>& dict, const string& word1, const string& word2) {
	return (dict[word1].count(word2) != 0);
}

int main() {
	map<string, set<string>> dict;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string cmd;
		cin >> cmd;
		if (cmd == "ADD") {
			string word1, word2;
			cin >> word1 >> word2;
			add(dict, word1, word2);
		}
		else if (cmd == "COUNT") {
			string word;
			cin >> word;
			cout << count(dict, word) << endl;
		}
		else if (cmd == "CHECK") {
			string word1, word2;
			cin >> word1 >> word2;
			bool syn = check(dict, word1, word2);
			cout << (syn ? "YES" : "NO") << endl;
		}
	}
	cin >> n;
	return 0;
}