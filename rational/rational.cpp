#include "rational.hpp"
//Instructions at https://cs.harding.edu/gfoust/classes/comp3450/projects/rational
include "rational.hpp"

Rational::Rational() {
	_num = 0;
	_den = 1
};

Rational::Rational(int num, int den) {
	if (den != 0) {
		_num = num;
		_den = den
	}
	else {
		throw std::domain_error("Denominator cannot be 0");
	}
};

void Rational::simplify(int& num, int& den) {
	int GCF = findGCF(num, den);
	num = num / GCF;
	den = den / GCF;
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
