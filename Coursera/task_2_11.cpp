#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> GetWordMap(const string& word) {
	map<char, int> counters;
	for (char c : word) {
		++counters[c];
	}
	return counters;
}

int main() {
	int pairs_num;
	cin >> pairs_num;
	for (int i = 0; i < pairs_num; ++i) {
		string one, two;
		map <char, int> m_one, m_two;
		cin >> one >> two;
		if (GetWordMap(one) == GetWordMap(two)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	cin >> pairs_num;
	return 0;
}