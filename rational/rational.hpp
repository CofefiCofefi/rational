#pragma once
class Rational {
public:

	Rational();
	Rational(int num, int den);

	int _num, _den;

	Rational Simplify(int num, int den);

private:



};