#include <iostream>

using namespace std;

int main()
{
/*
	int a, b;
	int max, min;
	int res = 0;
	cin >> a >> b;
	if (a >= b) {
		max = a;
		min = b;
	}
	else {
		max = b;
		min = a;
	}
	while (res == 0) {
		int remain = max % min;
		if (remain == 0) {
			res = min;
			break;
		}
		else {
			max = min;
			min = remain;
		}
	}
	cout << res;
	return 0;
*/
	int a, b;
	cin >> a >> b;
	// ���� ��� ����� ������������, ����� �� ���������, �� ����� �� ���
	while (a > 0 && b > 0) {
		// ������ ������� �� ����� � ������� ��� �������� �� ������� �� ������
		// �������������, ���� a � b ������� �� x, �� a - b � b ������� �� x
		// ����� � a % b � b ������� �� x, ��� ��� ����� a �������� �� a % b
		if (a > b) {
			a %= b;
		}
		else {
			b %= a;
		}
	}
	// ���� ���� �� ����� ��������� ����� ����, ������, �� ��������� ��������
	// ������� ����� ����������� �� �������
	cout << a + b;
	return 0;
}