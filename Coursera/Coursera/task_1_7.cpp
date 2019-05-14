#include <iostream>
#include <string>

using namespace std;

int main()
{
/*
	string str;
	char c = 'f';
	int res = -2;

	getline(cin, str);
	size_t found = str.find(c);
	if (found != string::npos)
		res = -1;
	found = str.find(c, found + 1);
	if (found != string::npos)
		res = found;
	cout << res << endl;
	return 0;
*/
	string str;
	cin >> str;

	int res = -2;
	for (int i = 0; i < str.size(); ++i) {
		cout << i;
		if (str[i] == 'f') {
			if (res == -2) {
				res = -1;
			}
			else if (res == -1) {
				res = i;
				break;
			}
		}
	}
	cout << res;
	cin >> res;
	return 0;
}