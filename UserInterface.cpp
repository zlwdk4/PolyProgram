#include "UserInterface.h"

void UserInterface::displayMenu()
{
	cout << "Please select one of three options:" << endl;
	cout << "To enter a polynomial and have it displayed on the console, press 1" << endl;
	cout << "To enter add two polynomials together and display the result, press 2" << endl;
	cout << "To end the program, press 3" << endl;

}

bool UserInterface::respondToUserInput(char input)
{
	if (input == '1') 
	{
		//cout << getPoly() << endl;
		return true;
	}
		
	if (input == '2')
	{
		cout << "Please enter the first polynomial" << endl;
		//Polynomial poly1 = getPoly();
		cout << "Now enter the second polynomial" << endl;
		//Polynomial poly2 = getPoly();
		//cout << (poly1 + poly2) << endl;
		return true;
	}

	if (input == '3')
		return false;


}

char UserInterface::getUserInput()
{
	char input;
	cin >> input;
	if (input != 1 || input != 2 || input != 3)
		displayMenu();
	return input;
}

//Polynomial getPoly()
//{
//	Polynomial input;
//	cin >> input;
//}