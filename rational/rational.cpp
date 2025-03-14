//Instructions at https://cs.harding.edu/gfoust/classes/comp3450/projects/rational
#include "rational.hpp"

int Rational::doubleBase = 1000000;

Rational::Rational() {
	_num = 0;
	_den = 1;
};

Rational::Rational(int num, int den) {
	if (den == 0) {
		throw std::domain_error("Denominator cannot be 0");
	}

	if (num == 0) {
		_num = 0;
		_den = 1;
	}
	else {
		simplify(num, den);

		if (den < 0) {
			_num = -num;
			_den = -den;
		}
		else {
			_num = num;
			_den = den;
		}
	}
};

Rational::Rational(int other) {
	_num = other;
	_den = 1;

	simplify(_num, _den);
};

Rational::Rational(double other) {
	_num = other * doubleBase;
	_den = doubleBase;
	simplify(_num, _den);
};

Rational::operator int() const {
	return _num / _den;
};

Rational::operator double() const {
	return static_cast<double>(_num) / _den;
};

int Rational::num() const {
	return _num;
};

int Rational::den() const {
	return _den;
};

void Rational::num(int num) {
	if (num == 0) {
		_num = 0;
		_den = 1;
	}
	else {
		int den = _den;
		simplify(num, den);

		if (den < 0) {
			num = -num;
			den = -den;
		};

		_num = num;
		_den = den;
	};
};

void Rational::den(int den) {
	if (den == 0) {
		throw std::domain_error("Denominator cannot be 0");
	}
	else {
		int num = _num;
		simplify(num, den);

		if (den < 0) {
			num = -num;
			den = -den;
		};

		_num = num;
		_den = den;
	};
};

std::istream& operator>>(std::istream& in, Rational& rat) {
	int num, den;
	char slash;

	if (!(in >> num)) {
		in.setstate(ios::failbit);
		return in;
	}

	if (!(in >> slash) || slash != '/') {
		in.setstate(ios::failbit);
		return in;
	}

	if (!(in >> den)) {
		in.setstate(ios::failbit);
		return in;
	}

	if (den == 0) {
		in.setstate(ios::failbit);
		return in;
	}

	rat = Rational(num, den);

	return in;
};

std::ostream& operator<<(std::ostream& out, Rational const& rat) {
	out << rat.num() << '/' << rat.den();
	return out;
};

void Rational::simplify(int& num, int& den) {
	int GCF = findGCF(num, den);
	num = num / GCF;
	den = den / GCF;
};

int findGCF(int num, int den){
	if (num % den == 0) {
		return den;
	}
	else {
		return findGCF(den, num % den);
	}
};

int findLCM(int den1, int den2){
	return (den1 / findGCF(den1, den2)) * den2;
};

int findGCD(int den1, int den2){
	while (den2 != 0) {
		int temp = den2;
		den2 = den1 % den2;
		den1 = temp;
	}
	return den1;
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
	int lcm = findLCM(lhs.den(), rhs.den());

	int newNum = (lhs.num() * (lcm / lhs.den()))+(rhs.num() * (lcm / rhs.den()));
	int newDen = lcm;

	return Rational(newNum, newDen);
};

Rational operator-(Rational const& lhs, Rational const& rhs) {
	int lcm = findLCM(lhs.den(), rhs.den());

	int newNum = (lhs.num() * (lcm / lhs.den()))-(rhs.num() * (lcm / rhs.den()));
	int newDen = lcm;

	return Rational(newNum, newDen);
};

Rational operator*(Rational const& lhs, Rational const& rhs) {
	Rational sum;
	sum.num(lhs.num() * rhs.num());
	sum.den(lhs.den() * rhs.den());
	return sum;
};

Rational operator/(Rational const& lhs, Rational const& rhs) {
	if (rhs.num() != 0) {
		Rational sum;
		sum.num(lhs.num() * rhs.den());
		sum.den(lhs.den() * rhs.num());
		return sum;
	}
	else {
		throw std::domain_error("Operation would result in dividing by 0 which is not allowed");
	}
};

Rational operator-(Rational const& a) {
	return Rational(-a.num(), a.den());
};

Rational& operator+=(Rational& dst, Rational const& src) {
	dst = dst + src;
	return dst;
};

Rational& operator-=(Rational& dst, Rational const& src) {
	dst = dst - src;
	return dst;
};

Rational& operator*=(Rational& dst, Rational const& src) {
	dst = dst * src;
	return dst;
};

Rational& operator/=(Rational& dst, Rational const& src) {
	dst = dst / src;
	return dst;
};

Rational& operator++(Rational& dst) {		//Prefix
	dst.num(dst.num() + dst.den());
	return dst;
};

Rational& operator--(Rational& dst) {		//Prefix
	dst.num(dst.num() - dst.den());
	return dst;
};

Rational operator++(Rational& dst, int) {	//Postfix
	Rational temp(dst.num(), dst.den());

	dst.num(dst.num() + dst.den());

	return temp;
}

Rational operator--(Rational& dst, int) {	//Postfix
	Rational temp(dst.num(), dst.den());

	dst.num(dst.num() - dst.den());

	return temp;
};

bool operator==(Rational const& lhs, Rational const& rhs) {
	if (lhs.num() == rhs.num() && lhs.den() == rhs.den()) {
		return true;
	}
	return false;
};

bool operator!=(Rational const& lhs, Rational const& rhs) {
	if (lhs.num() != rhs.num() || lhs.den() != rhs.den()) {
		return true;
	}
	return false;
};

bool operator<(Rational const& lhs, Rational const& rhs) {
	int lcm = findLCM(lhs.den(), rhs.den());

	if ((lhs.num() * (lcm / lhs.den())) < (rhs.num() * (lcm / rhs.den()))) {
		return true;
	}
	return false;
};

bool operator>=(Rational const& lhs, Rational const& rhs) {
	int lcm = findLCM(lhs.den(), rhs.den());

	if ((lhs.num() * (lcm / lhs.den())) >= (rhs.num() * (lcm / rhs.den()))) {
		return true;
	}
	return false;
};

bool operator>(Rational const& lhs, Rational const& rhs) {
	int lcm = findLCM(lhs.den(), rhs.den());

	if ((lhs.num() * (lcm / lhs.den())) > (rhs.num() * (lcm / rhs.den()))) {
		return true;
	}
	return false;
};

bool operator<=(Rational const& lhs, Rational const& rhs) {
	int lcm = findLCM(lhs.den(), rhs.den());

	if ((lhs.num() * (lcm / lhs.den())) <= (rhs.num() * (lcm / rhs.den()))) {
		return true;
	}
	return false;
};
