#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

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

istream& operator >>(istream& in, Rational& obj) {
	int n, d;
	char c;
	in >> n >> c >> d;
	if (in && c == '/') {
		obj = Rational(n, d);
	}
	return in;
}

ostream& operator <<(ostream& out, const Rational& obj) {
	return out << obj.Numerator() << "/" << obj.Denominator();
}

int main() {
	{
		ostringstream output;
		output << Rational(-6, 8);
		if (output.str() != "-3/4") {
			cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
			return 1;
		}
	}

	{
		istringstream input("5/7");
		Rational r;
		input >> r;
		bool equal = r == Rational(5, 7);
		if (!equal) {
			cout << "5/7 is incorrectly read as " << r << endl;
			return 2;
		}
	}

	{
		istringstream input("5/7 10/8");
		Rational r1, r2;
		input >> r1 >> r2;
		bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
			return 3;
		}

		input >> r1;
		input >> r2;
		correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
			return 4;
		}
	}

	cout << "OK" << endl;
	int n;
	cin >> n;
	return 0;
}