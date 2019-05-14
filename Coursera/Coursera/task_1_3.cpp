#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double a, b, c;
	cin >> a >> b >> c;

	if (a == 0)
	{
		if (b != 0)
		{
			cout << (c * (-1)) / b;
			return 0;
		}
		else
			return 0;
	}
	double D = b * b - 4 * a * c;
	if (D < 0)
	{
		return 0;
	}
	else if (D == 0)
	{
		cout << (b * (-1)) / (2 * a);
	}
	else
	{
		cout << (b * (-1) + sqrt(D)) / (2 * a) << " ";
		cout << (b * (-1) - sqrt(D)) / (2 * a);
	}
	cin >> a;
	return 0;
}