#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Reverse(vector<int>& v) {

	vector<int>::iterator first = v.begin(), last = v.end();
	while ((first != last) && (first != --last)) {
		swap(*first++, *last);
	}
/*
	int n = v.size();
	for (int i = 0; i < n / 2; ++i) {
		int tmp = v[i];
		v[i] = v[n - 1 - i];
		v[n - 1 - i] = tmp;
	}
*/
}

int main() {
	vector<int> a{1, 2, 3, 4, 5};
	Reverse(a);
	for (auto elem : a) {
		cout << elem << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}