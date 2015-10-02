#pragma once
#include <list>
#include "Term.h"

using namespace std;

class Polynomial
{

public:
	//operator +
	void simplify();
	//operator <<
	//opeartor >>
private:
	list<Term> polyList;
};
