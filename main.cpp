#include <iostream>
#include <List>
#include "Term.h"
#include "UserInterface.h"
#include <sstream>

using namespace std;

//void storeCur(string curNums, string curExp, char theLetter, bool isNegative, bool expNeg, list<Term> &theList) {
//	//can make letter optional
//	int  storeNum;
//	istringstream(curNums) >> storeNum;
//	if (isNegative) {
//		storeNum *= -1;
//	}
//
//	int storeExp;
//	istringstream(curExp) >> storeExp;
//	if (expNeg) {
//		storeExp *= -1;
//	}
//
//	Term storeTerm(storeNum, storeExp, theLetter);
//	theList.push_back(storeTerm);
//	return;
//
//}
//
//
//
//struct VALUES {
//
//
//	string curNums = "0";
//	string curExp = "1";
//	char theLetter = ' ';
//	bool letterMade = false;
//	char ch = ' ';
//	bool completedCoe = false;
//	bool completedExp = false;
//	bool startExp = false;
//	bool isNegative = false;
//	bool inParenth = false;
//	bool expNeg = false;
//
//
//};
//
//void resetVals(VALUES &vals) {
//	vals.curNums = "0";
//	vals.curExp = "1";
//	vals.theLetter = ' ';
//	vals.letterMade = false;
//	vals.ch = ' ';
//	vals.completedCoe = false;
//	vals.completedExp = false;
//	vals.startExp = false;
//	vals.isNegative = false;
//	vals.inParenth = false;
//	vals.expNeg = false;
//}
//
//
//
//
//
/////make this return a list?
//Term readInPoly(std::string theString, std::list<Term> &theList) {
//	
//	theString += "+";
//
//	
//
//	VALUES vals;
//
//
//	
//
//
//	
//	for (int i = 0; i < theString.size(); i++) {
//		
//
//
//		
//		vals.ch = theString[i];
//		//for non exponent parenthesis (negative vals)
//		//////////////////////////
//		if (vals.ch == '(') {
//			vals.inParenth = true;
//			vals.curNums = "";
//			if (theString[i + 1] == '-') {
//				vals.isNegative = true;
//				i++;
//			}
//
//			continue;
//		}
//
//		if (isdigit(vals.ch) && vals.inParenth) {
//			vals.curNums += vals.ch;
//			continue;
//		}
//
//		if (vals.ch == ')') {
//			vals.inParenth = false;
//			
//		}
//		
//		if (isdigit(vals.ch) && !vals.startExp) {
//			vals.curNums += vals.ch;
//		}
//
//
//
//
//
//		/// encountering a  + or -
//		if (vals.ch == '+' || vals.ch == '-' && !vals.inParenth) {
//			if((i < theString.size() && isalnum(theString[i+1]) ||
//				(i < theString.size() && theString[i+1] == '(') &&
//				(i > 0 && theString[i - 1] != '(') ||
//				(i > 0 && isalnum(theString[i - 1])))) {
//
//
//				storeCur(vals.curNums, vals.curExp, vals.theLetter, vals.isNegative, vals.expNeg, theList);
//				//reset all vals
//				resetVals(vals);
//				if (theString[i] == '-') {
//					vals.isNegative = true;
//				}
//				continue;
//			}
//
//			//throw incorrect format exception
//		}
//
//		if (vals.ch == '-' && !vals.inParenth) {
//			storeCur(vals.curNums, vals.curExp, vals.theLetter, vals.isNegative, vals.expNeg, theList);
//			//reset all vals
//			resetVals(vals);
//			vals.isNegative = true;
//			continue;
//		}
//		
//
//		//// encountering a letter
//		if (isalpha(vals.ch)) {
//			if (vals.ch != vals.theLetter && vals.letterMade) {
//				//throw too many variables error
//				//!!!!!!!!!!!!!!!!!!!!!!!
//			}
//			vals.theLetter = vals.ch;
//			vals.letterMade = true;
//
//			if ((i < theString.size()) && (theString[i + 1] == '+' || theString[i + 1] == '-' || theString[i + 1] == '^')) {
//				continue;
//			}
//
//			else {
//				//throw incorrect format exception
//			}
//		
//		}
//
//
//
//
//		///// encountering a '^'
//
//		if (vals.ch == '^') {
//			vals.curExp = "0";
//			if (!isalpha(theString[i - 1])) {
//				//throw incorrect format exception
//			}
//			//assumes no variables in the exponent
//			if (theString[i + 1] == '(' && theString[i+2] == '-'  && isdigit(theString[i + 3])) {
//				vals.expNeg = true;
//				continue;
//			}
//			vals.startExp = true;
//			
//			if ((i < theString.size()) && (isdigit(theString[i + 1]))) {
//				continue;
//			}
//			else {
//				//throw inccorect format exception
//			}
//		}
//
//
//		if (isdigit(vals.ch) && vals.startExp) {
//			vals.curExp += vals.ch;
//			continue;
//		}
//
//
//
//
//
//
//
//
//	}

	
	//cout << cur;
//	Term A(1,1, ' ');
//	return A;
//
//
//}





int main()
{
	UserInterface ui;
	ui.displayMenu();

	system("pause");

	return 0;

}