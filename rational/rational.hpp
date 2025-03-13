#pragma once

class Rational {
public:
	Rational();
	Rational(int num, int den);
	int num() const;
	int den() const;
	void num(int num);
	void den(int den);

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
