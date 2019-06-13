#include <iostream>

using namespace std;

// Ќайти наибольший общий делитель (greatest common divisor)
int GetGCD(int a, int b) {
	// пока оба числа положительны, будем их уменьшать, не мен€€ их Ќќƒ
	while (a > 0 && b > 0) {
		// возьмЄм большее из чисел и заменим его остатком от делени€ на второе
		// действительно, если a и b дел€тс€ на x, то a - b и b дел€тс€ на x
		// тогда и a % b и b дел€тс€ на x, так что можно a заменить на a % b
		if (a > b) {
			a %= b;
		}
		else {
			b %= a;
		}
		// если одно из чисел оказалось равно нулю, значит, на последней итерации
		// большее число разделилось на меньшее
	}
	return a + b;
}
// Ќайти наименьшее общее кратное (least common multiple)
int GetLCM(int a, int b) {
	return a * b / GetGCD(a, b);
}

// ѕеренос минуса, если он есть, в числитель
void FixSign(int& a, int& b) {
	if (b < 0) {
		a *= -1;
		b *= -1;
	}
}

// —окражение числител€ и знаменател€ на Ќќƒ
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

Rational operator +(const Rational& lhs, const Rational& rhs) {
	int lcm = GetLCM(lhs.Denominator(), rhs.Denominator());
	int mul_lhs = lcm / lhs.Denominator();
	int mul_rhs = lcm / rhs.Denominator();
	int Numerators_sum = lhs.Numerator() * mul_lhs + rhs.Numerator() * mul_rhs;
	int Denominator_sum = lcm;
	ReduceFraction(Numerators_sum, Denominator_sum);
	Rational res(Numerators_sum, Denominator_sum);
	return res;
}

Rational operator -(const Rational& lhs, const Rational& rhs) {
	int lcm = GetLCM(lhs.Denominator(), rhs.Denominator());
	int mul_lhs = lcm / lhs.Denominator();
	int mul_rhs = lcm / rhs.Denominator();
	int Numerators_sum = lhs.Numerator() * mul_lhs - rhs.Numerator() * mul_rhs;
	int Denominator_sum = lcm;
	ReduceFraction(Numerators_sum, Denominator_sum);
	Rational res(Numerators_sum, Denominator_sum);
	return res;
}

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