#include "Polynomial.h"
#include <iostream>

using namespace std;
//adds a term to the polynomial
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

	void Polynomial::operator +(Polynomial rhs) {
		if (rhs.polyList.size() < 1) {
			//cout << "there are no items in the second polynomial" << endl;
		}
		else {
			list<Term>::iterator iter = rhs.polyList.begin();
			for (iter; iter != rhs.polyList.end(); iter++) {
				addTerm(*iter);
			}
			simplify();
		}
		
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

		return cout;
	}



		//add zero exception?
		//GET SIGN FOR EXPONENTS
		if (curTermCoe != 0)
			cout << sign << curTermCoe;
		if (theLetter != ' ')
			cout << theLetter;
		if (curTermExp != 1)
			cout << "^(" << curTermExp << ")";

		//cout << theList.front().getCoefficient() << theList.front().getLetter() << "^(" << theList.front().getExponent() << ")" << endl;