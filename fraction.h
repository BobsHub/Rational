#ifndef FRACTION_H
#define FRACTION_H

#include <string>

class RecurringFractions;

class Fraction {

public:
	Fraction(const long n = 0, const long d = 1);

	void Assign(long n = 0, long d = 1) 
		{ num = n; den = d; };
	double ToFlt()
		{ return num / (double) den; };
	std::string ToStr();

	Fraction operator+(const Fraction& f2) const;
	Fraction operator+(const long& n) const;
	Fraction operator-(const Fraction& f2) const;
	Fraction operator-(const long& n) const;
	Fraction operator*(const Fraction& f2) const;
	Fraction operator*(const long& n) const;
	Fraction operator/(const Fraction& f2) const;
	Fraction operator/(const long& n) const;

private:
	friend Fraction operator+(const long& n, const Fraction& f2);
	friend Fraction operator-(const long& n, const Fraction& f2);
	friend Fraction operator*(const long& n, const Fraction& f2);
	friend Fraction operator/(const long& n, const Fraction& f2);

	friend RecurringFractions;

	long num;
	long den;

};



#endif
