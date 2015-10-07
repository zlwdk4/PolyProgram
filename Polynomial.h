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
	//const?

	void  operator +(Polynomial rhs);
	//operator =
	void simplify();
	void addTerm(Term termToAdd);
	//operator <<
	friend ostream& operator <<(ostream &cout,  Polynomial& P);
	//opeartor >>
	//void operator >>(string theString);
private:
	list<Term> polyList;
};
