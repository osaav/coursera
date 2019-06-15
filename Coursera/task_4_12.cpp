#include <exception>
#include <iostream>
#include <string>

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
		if (b == 0) {
			throw std::invalid_argument("Invalid argument");
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

Rational operator *(const Rational& lhs, const Rational& rhs) {
	return {
		lhs.Numerator() * rhs.Numerator(),
		lhs.Denominator() * rhs.Denominator()
	};
}

Rational operator /(const Rational& lhs, const Rational& rhs) {
	if (rhs.Numerator() == 0) {
		throw domain_error("Division by zero");
	}
	return lhs * Rational(rhs.Denominator(), rhs.Numerator());
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
	try {
		Rational a, b;
		std::cin >> a;
		cin.ignore(1);
		string cmd;
		std::cin >> cmd;
		cin.ignore(1);
		std::cin >> b;

		if (cmd == "+") {
			cout << a + b;
		}
		else if (cmd == "-") {
			cout << a - b;
		}
		else if (cmd == "*") {
			cout << a * b;
		}
		else if (cmd == "/") {
			cout << a / b;
		}
	}
	catch (logic_error& ex) {
		cout << ex.what();
	}

	int n;
	cin >> n;
	return 0;
}