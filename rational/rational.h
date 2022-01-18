#include <istream>
#ifndef  RATIONAL_H
#define RATIONAL_H

using namespace std;

class Rational
{
private:
	int numer, denom;

	void simplify();



public:
	Rational();
	Rational(int numer);
	Rational(int numer, int denom);

	Rational operator -() const;

	Rational operator +(const Rational& other) const;
	Rational& operator +=(const Rational& other);

	Rational operator -(const Rational& other) const;
	Rational& operator -=(const Rational& other);

	Rational operator *(const Rational& other)const;
	Rational operator *(const int number)const;
	Rational& operator *=(const Rational& other);

	Rational operator /(const Rational& other) const;
	Rational& operator /=(const Rational& other);

	Rational operator ++(int);
	Rational& operator ++();

	bool operator ==(const Rational& other) const;
	bool operator !=(const Rational& other) const;
	bool operator <(const int number) const;

	operator int() const;
	operator double() const;

	friend istream& operator >>(istream& in, Rational& r);
	friend ostream& operator <<(ostream& out, const Rational& r);

	static void solution(const Rational& a, const Rational& b, const Rational& c);

	Rational Sqrt_rational();
};

#endif // ! RATIONAL_H