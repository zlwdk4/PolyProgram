#include "Polynomial.h"
#include <sstream>


using namespace std;
//adds a term to the polynomial

struct VALUES {


	string curNums = "0";
	string curExp = "1";
	char theLetter = ' ';
	bool letterMade = false;
	char ch = ' ';
	bool completedCoe = false;
	bool completedExp = false;
	bool startExp = false;
	bool isNegative = false;
	bool inParenth = false;
	bool expNeg = false;
	bool inExp = false;


};

void resetVals(VALUES &vals) {
	vals.curNums = "0";
	vals.curExp = "1";
	vals.theLetter = ' ';
	vals.letterMade = false;
	vals.ch = ' ';
	vals.completedCoe = false;
	vals.completedExp = false;
	vals.startExp = false;
	vals.isNegative = false;
	vals.inParenth = false;
	vals.expNeg = false;
	vals.inExp = false;
}


void Polynomial::addTerm(Term termToAdd)
{
	polyList.push_back(termToAdd);

}

//Go through the array and check for terms with the same exponent.
//If two exponenents are the same, delete one term and update the other
void Polynomial::simplify()
{
	//if the list has zero or 1 items, there is no need to simplify
	if (polyList.size() == 0 || polyList.size() == 1)
		return;


	//iterator through all of the terms
	for (list<Term>::iterator iter = polyList.begin(); iter != polyList.end(); ++iter)
	{
		/* I don't want the second iterator to compare itself to the same term as the first
		 * so I have to make the second iterator(jter) point to the term after the term the first(iter) is pointing to.
		 * However, since there is no operator for iterator + integer (otherwise I would have just done jter = iter + 1),
		 * I had to increment iter and assign that value to jter and then decrement iter;
		 */
		list<Term>::iterator jter = (++iter);
		--iter;

		//loops through all terms after iter
		while(jter != polyList.end())
		{
			//checks if the exponents of each term are the same
			if (iter->getExponent() == jter->getExponent())
			{
				//If they are the same, set iter's coeficient to iter's plus jter's
				iter->setCoefficient((iter->getCoefficient() + jter->getCoefficient()));

				/*Since the two coefficients are the same, I want to remove the one that jter is pointing to.
				 *If I am at the last term, then I want to go ahead and break out of the loop after removing the term.
				*/
				if ((++jter) == (polyList.end()))
				{
					--jter;
					polyList.remove(*jter);
					break;
				}
				//If I am not at the end of the loop, I want to save the term that I am currently pointing at,
				//delete it, and point to the next one
				list<Term>::iterator temp = jter;
				--jter;
				polyList.remove(*jter);
				jter = temp;
				jter--;
			}
			jter++;
		}
	}

}

//make const???????
Polynomial Polynomial::operator +(Polynomial rhs) {
	Polynomial finalPoly;
	finalPoly.polyList = polyList;
		if (rhs.polyList.size() < 1) {
			cout << "there are no items in the second polynomial" << endl;
		}
		else {
			list<Term>::iterator iter = rhs.polyList.begin();
			for (iter; iter != rhs.polyList.end(); iter++) {
				finalPoly.addTerm(*iter);
			}
	//		finalPoly.simplify();
		}
		
		return finalPoly;
}





	//const issue passing P
ostream& operator <<(ostream& cout,  Polynomial& P){
		if (P.polyList.size() < 1) {
			cout << "No terms in given polynomial." << endl;
			return cout; 
		}
		list<Term>::iterator iter = P.polyList.begin();
	
		bool firstEntry = true;
		string sign = "";
		
		if (iter->getCoefficient() < 0)
			string sign = "-";

		for (iter; iter != P.polyList.end(); iter++) {
			Term cur = *iter;
			int curCoe = cur.getCoefficient();
			int curExp = cur.getExponent();
			char curLetter = cur.getLetter();

			if (curCoe >= 0 && firstEntry == false)
				sign = "+";

			else if (curCoe < 0 && firstEntry == false)
				sign = "";

			firstEntry = false;

			if (curCoe != 0)
				cout << sign << curCoe;
			if (curLetter != ' ') 
				cout << curLetter;
			if (curExp != 1)
				cout << "^(" << curExp << ")";
			
		}

		cout << endl;
		return cout;
	}




void storeCur(string curNums, string curExp, char theLetter, bool isNegative, bool expNeg, Polynomial &P) {
	//can make letter optional
	int  storeNum;
	istringstream(curNums) >> storeNum;
	if (isNegative) {
		storeNum *= -1;
	}

	int storeExp;
	istringstream(curExp) >> storeExp;
	if (expNeg) {
		storeExp *= -1;
	}

	Term storeTerm(storeNum, storeExp, theLetter);
	P.addTerm(storeTerm);
	return;

}









//syntax example
//2x+3^4-(-4)x^(-20)

istream& operator >>(istream &cin, Polynomial& P) {
		string thePoly;
		cin >> thePoly;
		thePoly += "+";

		VALUES vals;

		for (int i = 0; i < thePoly.size(); i++) {

			vals.ch = thePoly[i];


			//for non exponent parenthesis (negative vals)
			//////////////////////////
			if (vals.ch == '(' && !vals.inExp) {
				vals.inParenth = true;
				vals.curNums = "";
				if (thePoly[i + 1] == '-') {
					vals.isNegative = true;
					i++;
				}

				continue;
			}

			if (isdigit(vals.ch) && vals.inParenth) {
				vals.curNums += vals.ch;
				continue;
			}

			if (vals.ch == ')') {
				vals.inParenth = false;
				if (vals.inExp) {
					storeCur(vals.curNums, vals.curExp, vals.theLetter, vals.isNegative, vals.expNeg, P);
					resetVals(vals);
					if (thePoly[i + 1] = '-') {
						vals.isNegative = true;
					}
					i++;
					continue;

				}

			}

			/////HERE JARREN
			///SYNTAX FOR INPUT   2x^(-5)
			if (isdigit(vals.ch) && !vals.startExp) {
				vals.curNums += vals.ch;
			}





			/// encountering a  + or -
			if (vals.ch == '+' || vals.ch == '-' && !vals.inParenth && !vals.startExp) {
				if ((i < thePoly.size() && isalnum(thePoly[i + 1]) ||
					(i < thePoly.size() && thePoly[i + 1] == '(') &&
					(i > 0 && thePoly[i - 1] != '(') ||
					(i > 0 && isalnum(thePoly[i - 1])))) {


					storeCur(vals.curNums, vals.curExp, vals.theLetter, vals.isNegative, vals.expNeg, P);
					//reset all vals
					resetVals(vals);
					if (thePoly[i] == '-') {
						vals.isNegative = true;
					}
					continue;
				}

				//throw incorrect format exception
			}

			if (vals.ch == '-' && !vals.inParenth && !vals.inExp) {
				storeCur(vals.curNums, vals.curExp, vals.theLetter, vals.isNegative, vals.expNeg, P);
				//reset all vals
				resetVals(vals);
				vals.isNegative = true;
				continue;
			}


			//// encountering a letter
			if (isalpha(vals.ch)) {
				if (vals.ch != vals.theLetter && vals.letterMade) {
					//throw too many variables error
					//!!!!!!!!!!!!!!!!!!!!!!!
				}
				vals.theLetter = vals.ch;
				vals.letterMade = true;

				if ((i < thePoly.size()) && (thePoly[i + 1] == '+' || thePoly[i + 1] == '-' || thePoly[i + 1] == '^')) {
					continue;
				}

				else {
					//throw incorrect format exception
				}

			}




			///// encountering a '^'

			//////////HERE JARREN!!!!
			if (vals.ch == '^') {
				vals.inExp = true;
				vals.curExp = "0";
				if (!isalpha(thePoly[i - 1])) {
					//throw incorrect format exception
				}
				//assumes no variables in the exponent
				if (thePoly[i + 1] == '(' && thePoly[i + 2] == '-'  && isdigit(thePoly[i + 3])) {
					vals.startExp = true;
					
					vals.expNeg = true;
					continue;
				}
				vals.startExp = true;

				if ((i < thePoly.size()) && (isdigit(thePoly[i + 1]))) {
					continue;
				}
				else {
					//throw inccorect format exception
				}
			}


			if (isdigit(vals.ch) && vals.startExp) {
				vals.curExp += vals.ch;
				continue;
			}








		}
		P.simplify();
		P.polyList.sort();
		P.polyList.reverse();
		return cin;
	}


