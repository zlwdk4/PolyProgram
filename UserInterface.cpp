#include "UserInterface.h"

void UserInterface::displayMenu()
{
	char input;
	do
	{
		cout << "Please select one of three options:" << endl;
		cout << "To enter a polynomial and have it displayed on the console, press 1" << endl;
		cout << "To enter add two polynomials together and display the result, press 2" << endl;
		cout << "To end the program, press 3" << endl;
		cin >> input;
		if (input == '1')
		{
			Polynomial polyInput;
			cout << "Please enter the polynomial" << endl;
			//cin >> polyInput;
			//cout << polyInput;
		}

		if (input == '2')
		{
			cout << "Please enter the first polynomial" << endl;
			//Polynomial poly1 = getPoly();
			cout << "Now enter the second polynomial" << endl;
			//Polynomial poly2 = getPoly();
			//cout << (poly1 + poly2) << endl;
		}
	} while (input != '3');
}


//Polynomial getPoly()
//{
//	Polynomial input;
//	cin >> input;
//}