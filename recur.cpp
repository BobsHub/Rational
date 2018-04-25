#include "fraction.h"
#include "recur.h"

std::deque<int> RecurringFractions::ToList(const Fraction& f2)
{
	long rm, n = f2.num, d = f2.den;
	std::deque<int> recur;
	while(d != 0) {
		rm = n % d;
		recur.push_back((n - rm) / d);
		n = d; d = rm;
	}
	return recur;
}


Fraction RecurringFractions::ToFraction(std::deque<int>& recur)
{
	Fraction a, b;

	std::deque<int>::const_reverse_iterator rit = recur.crbegin();
	while(rit != recur.crend()) {
		a.Assign(*rit++, 1);
		a = a + b;
		b.Assign(1);
		b = b / a;
	}
	a.Assign(1);
	a = a / b;

	return a;
}

