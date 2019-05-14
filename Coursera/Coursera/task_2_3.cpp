#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(string s)
{
	int len = s.length();
	for (int i = 0; i < len / 2; ++i) {
		if (s[i] != s[len-1-i]) {
			return false;
		}
	}
	return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength)
{
	vector<string> res;
	for (auto s : words) {
		if (s.size() >= minLength && IsPalindrom(s)) {
				res.push_back(s);
		}
	}
	return res;
}

int main()
{
	vector<string> words1 {"abacaba", "aba"};
	vector<string> words2 { "weew", "bro", "code" };
	int minLength = 3;
	vector<string> res = PalindromFilter(words2, minLength);
	for (auto elem : res) {
		cout << elem << ' ';
	}
	cout << endl;
	
	system("pause");
	return 0;
}