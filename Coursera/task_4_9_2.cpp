#include <iostream>

using namespace std;

// ����� ���������� ����� �������� (greatest common divisor)
int GetGCD(int a, int b) {
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
		// ���� ���� �� ����� ��������� ����� ����, ������, �� ��������� ��������
		// ������� ����� ����������� �� �������
	}
	return a + b;
}

class Rational {
public:
	Rational() {}

	Rational(int a, int b) {
		if (a == 0) {
			numerator = 0;
			denominator = 1;
			return;
		}
		if (b < 0) {
			numerator = a * (-1);
			denominator = b * (-1);
		}
		int gdc = GetGCD(a, b);
		numerator = a / gdc;
		denominator = b / gdc;
	}

	int Numerator() const {
		return numerator;
	}

	int Denominator() const {
		return denominator;
	}

private:
	int numerator = 0;
	int denominator = 1;
};

int main() {
	{
		Rational r1(4, 6);
		Rational r2(2, 3);
		bool equal = r1 == r2;
		if (!equal) {
			cout << "4/6 != 2/3" << endl;
			return 1;
		}
	}

	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a + b;
		bool equal = c == Rational(2, 1);
		if (!equal) {
			cout << "2/3 + 4/3 != 2" << endl;
			return 2;
		}
	}

	{
		Rational a(5, 7);
		Rational b(2, 9);
		Rational c = a - b;
		bool equal = c == Rational(31, 63);
		if (!equal) {
			cout << "5/7 - 2/9 != 31/63" << endl;
			return 3;
		}
	}

	cout << "OK" << endl;
	int n;
	cin >> n;
	return 0;
}