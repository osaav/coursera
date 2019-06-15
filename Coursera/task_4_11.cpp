#include <iostream>
#include <exception>

using namespace std;

// ����� ���������� ����� �������� (greatest common divisor)
int GetGCD(int a, int b) {
	a = abs(a);
	b = abs(b);
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

// ������� ������, ���� �� ����, � ���������
void FixSign(int& a, int& b) {
	if (b < 0) {
		a *= -1;
		b *= -1;
	}
}

// ���������� ��������� � ����������� �� ���
void ReduceFraction(int& a, int& b) {
	int gdc = GetGCD(a, b);
	a /= gdc;
	b /= gdc;
}

class Rational {
public:
	Rational() {}

	Rational(int a, int b) {
		if (b == 0) {
			throw std::invalid_argument("");
		}
		if (a == 0) {
			numerator = 0;
			denominator = 1;
			return;
		}
		FixSign(a, b);
		ReduceFraction(a, b);
		numerator = a;
		denominator = b;
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

Rational operator *(const Rational& lhs, const Rational& rhs) {
	return {
		lhs.Numerator() * rhs.Numerator(),
		lhs.Denominator() * rhs.Denominator()
	};
}

Rational operator /(const Rational& lhs, const Rational& rhs) {
	if (rhs.Numerator() == 0) {
		throw domain_error("");
	}
	return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

int main() {
	try {
		Rational r(1, 0);
		cout << "Doesn't throw in case of zero denominator" << endl;
		return 1;
	} 
	catch (invalid_argument&) {
	}

	try {
		auto x = Rational(1, 2) / Rational(0, 1);
		cout << "Doesn't throw in case of division by zero" << endl;
		return 2;
	}
	catch (domain_error&) {
	}

	cout << "OK" << endl;
	int n;
	cin >> n;
	return 0;
}