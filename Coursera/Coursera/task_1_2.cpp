#include <iostream>
#include <string>
using namespace std;

int main()
{
	string w1, w2, w3;
	cin >> w1 >> w2 >> w3;
	if (w1 <= w2 && w1 <= w3)
	{
		cout << w1;
	}
	else if (w2 <= w1 && w2 <= w3)
	{
		cout << w2;
	}
	else
		cout << w3;
	cin >> w1;
	return 0;
}