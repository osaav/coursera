#include <iostream>
#include <map>
#include <set>
#include <vector>

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
// ����� ���������� ����� ������� (least common multiple)
int GetLCM(int a, int b) {
	return a * b / GetGCD(a, b);
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

bool operator ==(const Rational& lhs, const Rational& rhs) {
	if (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator()) {
		return true;
	}
	else {
		return false;
	}
}
/*
// ����� �������� lhs � rhs, ������� �� �������� � ����, ��� ����������� ��������� � ���� ���������
bool operator < (const Rational& lhs, const Rational& rhs) {
	return (lhs - rhs).Numerator() < 0;
}
*/
bool operator <(const Rational& lhs, const Rational& rhs) {
	if (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() > rhs.Denominator()) {
		return true;
	}
	else if (lhs.Denominator() == rhs.Denominator() && lhs.Numerator() < rhs.Numerator()) {
		return true;
	}
	else {
		int new_lhs_numerator = lhs.Numerator() * rhs.Denominator();
		int new_rhs_numerator = rhs.Numerator() * lhs.Denominator();
		if (new_lhs_numerator < new_rhs_numerator) {
			return true;
		}
		else {
			return false;
		}
	}
}

int main() {
	{
		const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
		if (rs.size() != 3) {
			cout << "Wrong amount of items in the set" << endl;
			return 1;
		}

		vector<Rational> v;
		for (auto x : rs) {
			v.push_back(x);
		}
		if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
			cout << "Rationals comparison works incorrectly" << endl;
			return 2;
		}
	}

	{
		map<Rational, int> count;
		++count[{1, 2}];
		++count[{1, 2}];

		++count[{2, 3}];

		if (count.size() != 2) {
			cout << "Wrong amount of items in the map" << endl;
			return 3;
		}
	}

	cout << "OK" << endl;
	int n;
	cin >> n;
	return 0;
}