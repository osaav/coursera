#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
	set<string> res_set;
	for (const auto& item : m) {
		res_set.insert(item.second);
	}
	return res_set;
}

int main() {
	set<string> res_set = BuildMapValuesSet({ {1, "odd"}, {2 ,"even"}, {3, "odd"}, {4, "even"}, {5, "odd"} });
	for (const string& item : res_set) {
		cout << item << endl;
	}
	int a;
	cin >> a;
	return 0;
}