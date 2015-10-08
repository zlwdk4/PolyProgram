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
	//if the lhs exponent is less than the rhs, then we know the lhs term is less than the rhs term
	if (exponent < rhs.exponent)
		return true;
	//if the lhs exponent is equal to the exponent of the rhs and the coefficient of the lhs is less than the coefficient
	//of the rhs, then we know that the lhs term is smaller.
	if (exponent == rhs.exponent && coefficient < rhs.coefficient)
		return true;
	//other wise the rhs side is smaller
	return false;

}
//same logic as the < operator
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
	//if the lhs is not less than the rhs and the rhs is not less than the lhs, then we know they they are equal
	if (!(*this < rhs) && !(*this > rhs))
		return true;
	//otherwise they are not equal
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



