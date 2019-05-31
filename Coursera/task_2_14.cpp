#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
	map<vector<string>, int> route;
	int n;
	cin >> n;
	int bus = 1;
	for (int i = 0; i < n; ++i) {
		int cnt;
		cin >> cnt;
		vector<string> stops(cnt);
		for (string& stop : stops) {
			cin >> stop;
		}
		if (route.count(stops) != 0) {
			cout << "Already exists for " << route[stops] << endl;
		}
		else {
			int bus = route.size() + 1;
			route[stops] = bus;
			cout << "New bus " << route[stops] << endl;
		}
	}
	cin >> n;
	return 0;
}