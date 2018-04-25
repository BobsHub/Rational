#include "fraction.h"

Fraction::Fraction(const long n, const long d) 
{
	long a = n, b = d, r;
	if(a == 0 || b == 0) {
		this-> num = a;
		this-> den = b;
		return;
	}

	if(a > b) {
		r = a;
		a = b;
		b = r;
	}

	while(true) {
		r = b % a;
		if(r == 0)
			break;
		b = a;
		a = r;
	}
	
	this->num = n / a;
	this->den = d / a;	
}

std::string Fraction::ToStr()
{
	if(den == 1)
		return std::to_string(num);
	else
		return std::to_string(num) + "/" + std::to_string(den);
}

Fraction Fraction::operator+(const Fraction& f2) const
{
	return Fraction(this->num * f2.den + this->den * f2.num,
				this->den * f2.den);	
}

Fraction Fraction::operator+(const long& n) const
{
	return Fraction(this->num + this->den * n, this->den);
}

Fraction operator+(const long& n, const Fraction& f2)
{
	return Fraction(f2.num + n * f2.den, f2.den);
}

Fraction Fraction::operator-(const Fraction& f2) const
{
	return Fraction(this->num * f2.den - this->den * f2.num,
				this->den * f2.den);	
}

Fraction Fraction::operator-(const long& n) const
{
	return Fraction(this->num - this->den * n, this->den);
}

Fraction operator-(const long& n, const Fraction& f2)
{
	return Fraction(n * f2.den - f2.num, f2.den);
}

Fraction Fraction::operator*(const Fraction& f2) const
{
	return Fraction(this->num * f2.num,	this->den * f2.den);	
}

Fraction Fraction::operator*(const long& n) const
{
	return Fraction(this->num * n, this->den);
}

Fraction operator*(const long& n, const Fraction& f2)
{
	return Fraction(f2.num * n, f2.den);
}

Fraction Fraction::operator/(const Fraction& f2) const
{
	return Fraction(this->num * f2.den,	this->den * f2.num);	
}

Fraction Fraction::operator/(const long& n) const
{
	return Fraction(this->num, this->den * n);
}

Fraction operator/(const long& n, const Fraction& f2)
{
	return Fraction(n * f2.den, f2.num);
}





