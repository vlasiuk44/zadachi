#include "Rational.h"
#include <math.h>
#include <iostream>

using namespace std;

Rational::Rational()
{
	this->numer = 0;
	this->denom = 1;
}

Rational::Rational(int numer)
{
	this->numer = numer;
	this->denom = 1;
}

Rational::Rational(int numer, int denom)
{
	this->numer = numer;
	this->denom = denom;
	this->simplify();
}


Rational Rational::operator -() const
{
	Rational temp(-this->numer, this->denom);
	return temp;
}

Rational& Rational::operator +=(const Rational& other) {
	this->numer = this->numer * other.denom + this->denom * other.numer;
	this->denom *= other.denom;
	this->simplify();

	return *this;
}

Rational Rational::operator +(const Rational& other) const
{
	Rational temp(*this);

	return temp += other;
}

Rational& Rational::operator -=(const Rational& other)
{
	this->numer = this->numer * other.denom - this->denom * other.numer;
	this->denom *= other.denom;
	this->simplify();

	return *this;
}

Rational Rational::operator -(const Rational& other) const
{
	Rational temp(*this);

	return temp -= other;
}

Rational& Rational::operator *=(const Rational& other)
{
	this->numer *= other.numer;
	this->denom *= other.denom;
	this->simplify();

	return *this;
}

Rational Rational::operator *(const Rational& other) const
{
	Rational temp(*this);

	return temp *= other;
}

Rational Rational::operator *(const int number) const
{
	Rational temp(*this);
	temp.numer *= number;

	return temp;
}

Rational& Rational::operator /=(const Rational& other)
{
	this->numer *= other.denom;
	this->denom *= other.numer;
	this->simplify();

	return *this;
}

Rational Rational::operator /(const Rational& other) const
{
	Rational temp(*this);

	return temp /= other;
}

Rational Rational::operator++(int)
{
	Rational temp(*this);

	this->numer += this->denom;
	this->simplify();

	return temp;
}

Rational& Rational::operator ++()
{
	this->numer += this->denom;
	this->simplify();

	return *this;
}

bool Rational::operator ==(const Rational& other) const
{
	return this->numer == other.numer && this->denom == other.denom;
}

bool Rational::operator !=(const Rational& other) const
{
	return !(*this == other);
}

bool Rational::operator <(int number) const
{
	return (double)*this < (double)number;
}

Rational::operator int() const
{
	return this->numer / this->denom;
}

Rational::operator double() const
{
	return ((double)this->numer) / this->denom;
}

istream& operator >>(istream& in, Rational& r)
{
	in >> r.numer >> r.denom;
	return in;
}

ostream& operator << (ostream& on, const Rational& r)
{
	if (r.denom == 1)
		on << r.numer;
	else if (r.numer == 0)
		on << 0;
	else
		on << r.numer << "/" << r.denom;

	return on;
}

void Rational::simplify()
{
	if (this->denom < 0)
	{
		this->numer = -this->numer;
		this->denom = -this->denom;
	}
	for (int i = 2; i <= abs(this->denom) && i <= abs(this->numer); i++)
	{
		if (this->numer % i == 0 && this->denom % i == 0)
		{
			this->numer /= i;
			this->denom /= i;
			i--;
		}
	}
}

int nod(int a, int b)
{
	if (b == 0)
		return a;
	else if (a == 0)
		return b;

	if (a > b)
		return nod(b, a % b);
	else
		return nod(a, b % a);
}

Rational Rational::Sqrt_rational()
{
	double value = sqrt((double)*this);
	double integral = floor(value);
	double frac = value - integral;

	int val = nod(round(frac * 1000000), 1000000);

	int denom = 1000000 / val;
	int numer = round(frac * 1000000) / val + integral * denom;

	Rational temp(numer, denom);

	return temp;
}

void Rational::solution(const Rational& a, const Rational& b, const Rational& c)
{
	Rational D = b * b - a * c * 4;

	if (D < 0)
		cout << "D < 0" << endl;
	else {
		Rational x1 = (-b - D.Sqrt_rational()) / (a * 2);
		Rational x2 = (-b + D.Sqrt_rational()) / (a * 2);

		cout << "x1 = " << x1 << "\nx2 = " << x2 << endl;
	}
}