#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
	map<set<string>, int> route;
	int n;
	cin >> n;
	int bus = 1;
	for (int i = 0; i < n; ++i) {
		int cnt;
		cin >> cnt;
		set<string> stops;
		for (int j = 0; j < cnt; j++) {
			string stop;
			cin >> stop;
			stops.insert(stop);
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