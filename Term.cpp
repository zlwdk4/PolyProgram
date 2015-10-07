#include "Term.h"
#include <string>
#include <iostream>
#include <sstream>
#include <list>



Term::Term(int coe, int exp)
{
	coefficient = coe;
	exponent = exp;
}

Term::Term(int coe, int exp, char theLetter) {
	coefficient = coe;
	exponent = exp;
	letter = theLetter;

}

//
//Term::Term(int coe, int exp, char theLetter) {
//	coefficient = coe;
//	exponent = exp;
//	letter = theLetter;
//
//}


bool Term::operator < (Term rhs)
{
	if (exponent < rhs.exponent)
		return true;
	if (exponent == rhs.exponent && coefficient < rhs.coefficient)
		return true;

	return false;

}

bool Term::operator > (Term rhs)
{
	if (exponent > rhs.exponent)
		return true;
	if (exponent == rhs.exponent && coefficient > rhs.coefficient)
		return true;

	return false;

}

bool Term::operator == (Term rhs)
{

	if (!(*this < rhs) && !(*this > rhs))
		return true;
	else return false;
}

void Term::setExponent(const int exp)
{
	exponent = exp;
}
void Term::setCoefficient(const int coe)
{
	if (coe == 0)
		return;
	else coefficient = coe;

}
const int Term::getExponent()
{
	return exponent;
}
const int Term::getCoefficient()
{

	return coefficient;
}
const char Term::getLetter() {
	return letter;
}



