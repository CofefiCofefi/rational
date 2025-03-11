#pragma once
class Rational {
public:

	Rational();
	Rational(int num, int den);

	int _num, _den;

private:
	void simplify(int& num, int& den);
	const int findGCF(int num, int den);

};