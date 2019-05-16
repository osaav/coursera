#include <iostream>
#include <string>
#include <vector>

#define MON_CNT 12;

using namespace std;

void add(vector<vector<string>>& diary, int date, string work) {
	diary[date].push_back(work);
}

void next(vector<vector<string>>& diary, int next_size) {

}

void dump(const vector<vector<string>>& diary, int date) {
	cout << date;
	for (auto elem : diary[date]) {
		 cout << " " << elem;
	}
	cout << endl;
}

int main() {
	vector<int> mon = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int cur_mon = 0;
	vector<vector<string>> diary;

	int cmd_nbr;
	cin >> cmd_nbr;
	for (int i = 0; i < cmd_nbr; ++i) {
		string op_name;
		cin >> op_name;
		if (op_name == "NEXT") {
			++cur_mon %= MON_CNT;
			next(diary, mon[cur_mon]);
		}
		else {
			int date;
			cin >> date;
			if (op_name == "DUMP") {
				dump(diary, date);
			}
			if (op_name == "ADD") {
				string work;
				add(diary, date, work);
			}
		}

	}

	return 0;
}