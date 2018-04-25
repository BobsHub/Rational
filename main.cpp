#include <iostream>
#include <sstream>
#include <string>
#include <deque>
#include "fraction.h"
#include "recur.h"

int main() {

	std::cout.precision(9);
	std::cout << "Enter a Fraction as 2 integers (a b) : ";
	long a, b;
	std::cin >> a >> b;
	std::cin.ignore(256, '\n');

	Fraction f1(a, b);
	std::deque<int> rec = RecurringFractions::ToList(f1);
	
	std::cout << "For Fraction " << f1.ToStr() << " or "
		<< f1.ToFlt() << "\nRecurring Fractional Notation:\n";

	for(auto x: rec)
		std::cout << x << " ";
	std::cout << "\n";

	std::cout << "Re-enter a Fractional Notation to create an Approximated Fraction:\n";
	std::string argstr;
	std::deque<int> rec2;
	getline(std::cin, argstr, '\n'); 

	std::istringstream sin(argstr);
	while(getline(sin, argstr, ' ')) {
		rec2.push_back(stoi(argstr));		
	}
	
	Fraction f2 = RecurringFractions::ToFraction(rec2);
	std::cout << "New fraction is : " << f2.ToStr() << " or ";		
	std::cout << f2.ToFlt() << "\n";

	return 0;
}

