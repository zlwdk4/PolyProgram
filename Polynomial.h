#pragma once
#include <list>
#include "Term.h"

using namespace std;

class Polynomial
{

public:
	//operator +
	void simplify();
	void addTerm(Term termToAdd);
	//operator <<
	//opeartor >>
private:
	list<Term> polyList;
};
