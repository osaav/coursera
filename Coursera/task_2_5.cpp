#include <iostream>
#include <vector>
#include <string>

using namespace std;

void MoveStrings(vector<string>& first, vector<string>& second) {
	for (auto elem : first) {
		second.push_back(elem);
	}
	first.clear();
}

int main() {
	vector<string> first{ "abc", "def", "ghi" }, second{"xyz"};
	MoveStrings(first, second);
	for (auto elem : first) {
		cout << elem << " ";
	}
	cout << endl;
	for (auto elem : second) {
		cout << elem << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}