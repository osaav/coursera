#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SortedStrings {
public:
	void AddString(const string& s) {
		sorted.push_back(s);
	}
	vector<string> GetSortedStrings() {
		sort(begin(sorted), end(sorted));
		return sorted;
	}
private:
	vector<string> sorted;
};

void PrintSortedStrings(SortedStrings& strings) {
	for (const string& s : strings.GetSortedStrings()) {
		cout << s << ' ';
	}
	cout << endl;
}

int main() {
	SortedStrings strings;

	strings.AddString("first");
	strings.AddString("third");
	strings.AddString("second");
	PrintSortedStrings(strings);

	strings.AddString("second");
	PrintSortedStrings(strings);

	int n;
	cin >> n;
	return 0;
}