#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom(string s)
{
	int len = s.length();
	for (int i = 0; i < len/2; ++i) {
		if (s[i] != s[len - 1 - i]) {
			return false;
		}
	}
	return true;
}

int main()
{
	string s;
	cin >> s;
	cout << std::boolalpha;
	cout << IsPalindrom(s) << endl;
	system("pause");
	return 0;
}