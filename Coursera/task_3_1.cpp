#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int& i : v) {
		cin >> i;
	}
	sort(begin(v), end(v), [](const int& a, const int& b) {	return (abs(a) < abs(b)); });
	for (int& i : v) {
		cout << i << ' ';
	}
	cout << endl;
	cin >> n;
	return 0;
}