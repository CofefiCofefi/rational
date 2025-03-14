#pragma once
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <sstream>
#include <string>
using std::istringstream;
using std::string;
using std::cout;
using std::ios;

class Rational {
public:
	Rational();
	Rational(int num, int den);

	Rational(int other);
	Rational(double other);
	explicit operator int() const;
	explicit operator double() const;

	int num() const;
	int den() const;
	void num(int num);
	void den(int den);
	static int doubleBase;

private:
	int _num, _den;
	void simplify(int& num, int& den);
};

int findGCF(int num, int den);
int findLCM(int den1, int den2);
int findGCD(int den1, int den2);
Rational operator +(Rational const& lhs, Rational const& rhs);
Rational operator -(Rational const& lhs, Rational const& rhs);
Rational operator *(Rational const& lhs, Rational const& rhs);
Rational operator /(Rational const& lhs, Rational const& rhs);
Rational operator -(Rational const& a);
Rational& operator +=(Rational& dst, Rational const& src);
Rational& operator -=(Rational& dst, Rational const& src);
Rational& operator *=(Rational& dst, Rational const& src);
Rational& operator /=(Rational& dst, Rational const& src);
Rational& operator ++(Rational& dst);		// prefix
Rational& operator --(Rational& dst);		// prefix
Rational operator ++(Rational& dst, int);	// postfix
Rational operator --(Rational& dst, int);	// postfix
bool operator ==(Rational const& lhs, Rational const& rhs);
bool operator !=(Rational const& lhs, Rational const& rhs);
bool operator < (Rational const& lhs, Rational const& rhs);
bool operator >=(Rational const& lhs, Rational const& rhs);
bool operator > (Rational const& lhs, Rational const& rhs);
bool operator <=(Rational const& lhs, Rational const& rhs);
std::istream& operator >>(std::istream& in, Rational& rat);
std::ostream& operator <<(std::ostream& out, Rational const& rat);
