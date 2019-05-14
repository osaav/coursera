#include <iostream>
#include <vector>

using namespace std;

int average(const int n, const vector<int>& days) {
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += days[i];
	}
	double res = sum / n;
	return res;
}

vector<int> find_days(const int aver, const vector<int>& days) {
	vector<int> res;
	for (int i = 0; i < days.size(); ++i) {
		if (days[i] > aver) {
			res.push_back(i);
		}
	}
	return res;
}

int main() {
	int n;
	vector<int> v;
	cin >> n;
	int tmp;
	std::string word;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		v.push_back(tmp);
	}
	int aver = average(n, v);
	vector<int> res = find_days(aver, v);
	cout << res.size() << endl;
	for (auto elem : res) {
		cout << elem << " ";
	}
	cin >> n;
	return 0;
}