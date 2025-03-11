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

	Simplify(_num, _den);

};

Rational::Rational Simplify(int num, int den) {

};
