#pragma once
class Rational {
public:

	Rational();
	Rational(int num, int den);
	const int num();
	const int den();
	void num(int num);
	void den(int den);

private:
	int _num, _den;
	void simplify(int& num, int& den);
	void makeOnlyNumNegative(int& num, int& den);
	const int findGCF(int num, int den);
};