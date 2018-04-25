#ifndef RECUR_H
#define RECUR_H

#include <deque>

class RecurringFractions {

public:
	static std::deque<int> ToList(const Fraction& f2);
	static Fraction ToFraction(std::deque<int>& recur);
};

#endif
