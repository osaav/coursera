#include <iostream>
#include <string>
#include <vector>

#define MON_CNT 12;
#define MAX_MON 31

using namespace std;

void add(vector<vector<string>>& diary, const int date, const string& work) {
	diary[date].push_back(work);
}

void next(vector<vector<string>>& diary, const int prev_size, const int cur_size) {
	if (cur_size > prev_size) {
		return;
	}
	for (int i = cur_size + 1; i <= prev_size; ++i) {
		for (auto elem : diary[i]) {
			add(diary, cur_size, elem);
		}
		diary[i].clear();
	}
}

void dump(const vector<vector<string>>& diary, const int date) {
	cout << diary[date].size();
	for (auto elem : diary[date]) {
		 cout << " " << elem;
	}
	cout << endl;
}

int main() {
	vector<int> mon = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int cur_mon = 0;
	vector<vector<string>> diary(MAX_MON + 1);

	int cmd_nbr;
	cin >> cmd_nbr;
	for (int i = 0; i < cmd_nbr; ++i) {
		string op_name;
		cin >> op_name;
		if (op_name == "NEXT") {
			int prev_mon = cur_mon;
			++cur_mon %= MON_CNT;
			next(diary, mon[prev_mon], mon[cur_mon]);
		}
		else {
			int date;
			cin >> date;
			if (op_name == "DUMP") {
				dump(diary, date);
			}
			if (op_name == "ADD") {
				string work;
				cin >> work;
				add(diary, date, work);
			}
		}

	}
	cin >> cmd_nbr;

	return 0;
}