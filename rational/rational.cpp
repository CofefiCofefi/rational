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
		_num = num;
		_den = 1;
	}
	else if (den > 0) {
		simplify(num, den);
		_num = num;
		_den = den;
	}
	else {
		simplify(num, den);
		makeOnlyNumNegative(num, den);

		_num = num;
		_den = den;
	}
}

const int Rational::num() {
	return _num;
};

const int Rational::den() {
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
			makeOnlyNumNegative(num, den);
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
			makeOnlyNumNegative(num, den);
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

void Rational::makeOnlyNumNegative(int& num, int& den) {
		num = (abs(num) * -1);
		den = abs(den);
};

const int Rational::findGCF(int num, int den)
{
	if (num % den == 0) {
		return den;
	}
	else {
		return findGCF(den, num % den);
	}
};
