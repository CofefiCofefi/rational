#pragma once
class Rational {
public:

	Rational();
	Rational(int num, int den);
	int num();
	int den();

private:
	int _num, _den;
	void simplify(int& num, int& den);
	const int findGCF(int num, int den);
};