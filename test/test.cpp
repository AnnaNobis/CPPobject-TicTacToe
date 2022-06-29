// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Fraction {
	int numerator, denominator;
	Fraction() {}
public:
	Fraction(int _numerator, int _denominator) : numerator(_numerator), denominator(_denominator) {}
	Fraction operator * (const Fraction& another) {
		Fraction result;
		result.numerator = this->numerator * another.numerator;
		result.denominator = this->denominator * another.denominator;
		return result;
	}
};


std::ostream& operator<<(std::ostream& s, const Fraction& v)
{
	//std::count zaminiamy na s
	if (cs == CheckerState::empty)
		s << "-";
	else if (cs == CheckerState::X)
		s << "X";
	else if (cs == CheckerState::O)
		s << "O";
	return s;
}
int main() {
	Fraction a(1, 2);
	std::cout << a;
}
