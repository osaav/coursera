#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v) {
	vector<int> res = v;
	vector<int>::iterator first = res.begin(), last = res.end();
	while ((first != last) && (first != --last)) {
		swap(*first++, *last);
	}
	return res;
}

int main() {
	vector<int> a {1, 2, 3, 4, 5};
	for (auto elem : Reversed(a)) {
		cout << elem << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}