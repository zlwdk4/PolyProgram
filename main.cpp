#include <iostream>
#include <List>
#include "Term.h"
#include <sstream>
//DID IT WORK??????????!!!!!!!!!
using namespace std;

void storeCur(string curNums, string curExp, char theLetter, bool isNegative, bool expNeg, list<Term> &theList) {
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
	theList.push_back(storeTerm);
	return;

}



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
}





///make this return a list?
Term readInPoly(std::string theString, std::list<Term> &theList) {
	//std::stringstream ss;
	//ss << theString;
	//

	//std::string::iterator iter = theString.begin();
	//while (iter != theString.end()) {

	//}
	theString += "+";

	

	VALUES vals;


	


	
	for (int i = 0; i < theString.size(); i++) {
		


		
		vals.ch = theString[i];
		//for non exponent parenthesis (negative vals)
		//////////////////////////
		if (vals.ch == '(') {
			vals.inParenth = true;
			vals.curNums = "";
			if (theString[i + 1] == '-') {
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
			//storeCur(curNums, curExp, theLetter, isNegative, theList);
		}
		//////////////////////


		//// collecting non exponent nums

		if (isdigit(vals.ch) && !vals.startExp) {
			vals.curNums += vals.ch;
		}





		/// encountering a  + or -
		if (vals.ch == '+' || vals.ch == '-' && !vals.inParenth) {
			if((i < theString.size() && isalnum(theString[i+1]) ||
				(i < theString.size() && theString[i+1] == '(') &&
				(i > 0 && theString[i - 1] != '(') ||
				(i > 0 && isalnum(theString[i - 1])))) {


				storeCur(vals.curNums, vals.curExp, vals.theLetter, vals.isNegative, vals.expNeg, theList);
				//reset all vals
				resetVals(vals);
				if (theString[i] == '-') {
					vals.isNegative = true;
				}
				continue;
			}

			//throw incorrect format exception
		}

		if (vals.ch == '-' && !vals.inParenth) {
			storeCur(vals.curNums, vals.curExp, vals.theLetter, vals.isNegative, vals.expNeg, theList);
			//reset all vals
			resetVals(vals);
			vals.isNegative = true;
			continue;
		}

		/*if (ch == '+' && startExp && !inParenth) {
			storeCur(curNums, curExp, theLetter, isNegative, theList);
			continue;
		}

		if (ch == '-' && startExp && !inParenth) {
			storeCur(curNums, curExp, theLetter, isNegative, theList);
			isNegative = true;
			continue;
		}*/



		//// encountering a letter
		if (isalpha(vals.ch)) {
			if (vals.ch != vals.theLetter && vals.letterMade) {
				//throw too many variables error
				//!!!!!!!!!!!!!!!!!!!!!!!
			}
			vals.theLetter = vals.ch;
			vals.letterMade = true;

			if ((i < theString.size()) && (theString[i + 1] == '+' || theString[i + 1] == '-' || theString[i + 1] == '^')) {
				continue;
			}

			else {
				//throw incorrect format exception
			}
		
		}




		///// encountering a '^'

		if (vals.ch == '^') {
			vals.curExp = "0";
			if (!isalpha(theString[i - 1])) {
				//throw incorrect format exception
			}
			//assumes no variables in the exponent
			if (theString[i + 1] == '(' && theString[i+2] == '-'  && isdigit(theString[i + 3])) {
				vals.expNeg = true;
				continue;
			}
			vals.startExp = true;
			
			if ((i < theString.size()) && (isdigit(theString[i + 1]))) {
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

	
	//cout << cur;
	Term A(1,1, ' ');
	return A;


}





int main()
{
	/*list<Term> testList;

	Term term1(4, 2);
	Term term2(3,9);
	Term term3(5, 1);
	Term term4(5, 7);

	testList.push_back(term1);
	testList.push_back(term2);
	testList.push_back(term3);
	testList.push_back(term4);
	
	testList.sort();*/

//	cout << (term3 > term4) << endl;
//	cout << (term3 == term4) << endl;
//	cout << (term3 < term4) << endl;
//*/

	
	//	cout << ch == str[i] << endl;
	std::string str = "1+2x-3x^2";

	list<Term> theList;
	readInPoly(str, theList);

	//std::list<Term>::iterator iter;
	//for (iter = theList.begin(); iter != theList.end(); ++iter) {
	//	//cout << *iter.getCoefficient() << endl;
	//	//*iter;
	//}
	bool firstEntry = true;
	string sign = "";
	if (theList.front().getCoefficient() < 0)
		string sign = "-";

	while (!theList.empty()) {
		int curTermCoe = theList.front().getCoefficient();
		int curTermExp = theList.front().getExponent();
		char theLetter = theList.front().getLetter();
		if (curTermCoe >= 0 && firstEntry == false) {
			sign = "+";
		}
		else if (curTermCoe < 0 && firstEntry == false) {
			sign = "";

		}
		firstEntry = false;

		//bool hasCoe = true;
		//bool hasExp = true;
		//bool hasLetter = true;

		//add zero exception?
		//GET SIGN FOR EXPONENTS
		if (curTermCoe != 0)
			cout << sign << curTermCoe;
		if (theLetter != ' ')
			cout << theLetter;
		if (curTermExp != 1)
			cout << "^(" << curTermExp << ")";

	//cout << theList.front().getCoefficient() << theList.front().getLetter() << "^(" << theList.front().getExponent() << ")" << endl;
		
	theList.pop_front();

	}
	system("pause");

	return 0;

}