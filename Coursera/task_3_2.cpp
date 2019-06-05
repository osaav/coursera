#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> v(n);
	for (string& s : v) {
		cin >> s;
	}
	sort(v.begin(), v.end(), [](string a, string b) {
		transform(a.begin(), a.end(), a.begin(), ::tolower);
		transform(b.begin(), b.end(), b.begin(), ::tolower);
		return (a < b);
	});
	for (string& s : v) {
		cout << s << ' ';
	}
	cout << endl;
	cin >> n;
}