#include "UserInterface.h"



Polynomial getPoly()
{
	Polynomial input;
	cin >> input;
	return input;
}

void UserInterface::displayMenu()
{
	char input;
	//while the user did not enter 3 (to exit the program) get the user's input
	do
	{
		cout << "Please select one of three options:" << endl;
		cout << "To enter a polynomial and have it displayed on the console, press 1" << endl;
		cout << "To enter add two polynomials together and display the result, press 2" << endl;
		cout << "To end the program, press 3" << endl;
		cin >> input;
		//if the user inputs 1, then they will be asked to enter the polynomial and it will be displayed back to them
		if (input == '1')
		{
			Polynomial polyInput;
			cout << "Please enter the polynomial" << endl;
			cin >> polyInput;
			cout << polyInput;
		}
		//if the user enters 2, then they will be asked for two polynomials. Then the polynomials will be added together and will be displayed
		if (input == '2')
		{
			cout << "Please enter the first polynomial" << endl;
			Polynomial poly1 = getPoly();
			cout << "Now enter the second polynomial" << endl;
			Polynomial poly2 = getPoly();
			Polynomial finalPoly;
			finalPoly = poly1 + poly2;
			cout << finalPoly << endl;
		}
	} while (input != '3');
}

