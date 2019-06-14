#include <iostream>

using namespace std;

// Ќайти наибольший общий делитель (greatest common divisor)
int GetGCD(int a, int b) {
	a = abs(a);
	b = abs(b);
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

Rational operator *(const Rational& lhs, const Rational& rhs) {
	return {
		lhs.Numerator() * rhs.Numerator(),
		lhs.Denominator() * rhs.Denominator()
	};
}

Rational operator /(const Rational& lhs, const Rational& rhs) {
	return lhs * Rational(rhs.Denominator, rhs.Numerator);
}

int main() {
	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a * b;
		bool equal = c == Rational(8, 9);
		if (!equal) {
			cout << "2/3 * 4/3 != 8/9" << endl;
			return 1;
		}
	}

	{
		Rational a(5, 4);
		Rational b(15, 8);
		Rational c = a / b;
		bool equal = c == Rational(2, 3);
		if (!equal) {
			cout << "5/4 / 15/8 != 2/3" << endl;
			return 2;
		}
	}

	cout << "OK" << endl;
	int n;
	cin >> n;
	return 0;
}