#pragma once

class Term
{
public:
	Term(int coe = 1, int exp = 0);
	Term(int coe = 1, int exp = 0, char = ' ');
	bool operator < (Term rhs);
	bool operator > (Term rhs);
	bool operator == (Term rhs);
	void setExponent(const int exp);
	void setCoefficient(const int coe);
	const int getExponent();
	const int getCoefficient();
	const char getLetter();
private:
	int exponent;
	int coefficient;
	char letter = ' ';

};