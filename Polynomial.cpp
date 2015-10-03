#include "Polynomial.h"
#include <map>

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
