#include <iostream>

using namespace std;

int main()
{
	double n, a, b, x, y;
	cin >> n >> a >> b >> x >> y;
	if (a >= b) {
		return 0;
	}
	if (n > a) {
		if (n > b) {
			cout << n - n * (y / 100) << endl;
		}
		else
			cout << n - n * (x / 100) << endl;
	}
	else
		cout << n << endl;
	return 0;
}