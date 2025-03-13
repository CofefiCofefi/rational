//Instructions at https://cs.harding.edu/gfoust/classes/comp3450/projects/rational
#include "rational.hpp"
#include <stdexcept>
#include <algorithm>

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
}

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
	return Rational();
};

Rational operator-(Rational const& a) {
	return Rational();
};