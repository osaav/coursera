#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <int> res;
	int n;
	cin >> n;
	while (n > 0) {
		res.push_back(n % 2);
		n /= 2;
	}
	for (int i = res.size() - 1; i >= 0; --i) {
		cout << res[i];
	}
	cin >> n;
	return 0;
}