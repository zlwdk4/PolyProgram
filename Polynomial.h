#pragma once
#include <list>
#include <iostream>
#include <string>
#include "Term.h"

using namespace std;

class Polynomial
{

public:
	//operator +

	Polynomial  operator +(Polynomial rhs);
	//operator =
	void simplify();
	void addTerm(Term termToAdd);
	//operator <<
	friend ostream& operator <<(ostream &cout,  Polynomial& P);
	//opeartor >>
	friend istream& operator >>(istream &cin, Polynomial& P);
private:
	list<Term> polyList;
};
