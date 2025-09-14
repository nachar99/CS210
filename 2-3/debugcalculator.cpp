/*
 * Calculator.cpp
 *
 *  Date: 9/23/2023
 *  Author: Abdulrahman Al-Nachar
 */

#include <iostream>

using namespace std;
// here I changed the main from void to int so I can add the return 0; statement at the end.
int main()
{
	// this char is never used so I commented it out  char statement[100];
	int op1, op2;
	char operation;
	// char answer was missing a semi colon ";" at the end & it was double colon so I changed it to single colons.
	char answer = 'Y';
	// the while loop's condition I added tolower(answer) so that if someone inputs 'Y' the loop will still run.
		while (tolower(answer) == 'y')
		{
			cout << "Enter expression" << endl;
			// op2 and op1 are switched so I changed it so it reads op1 and then op2, its better for divisions. 
			cin >> op1 >> operation >> op2;
			// in this if statement it was == "+" so I changed it to == '+' from double colons to single colons.
			if (operation == '+') {
				// after op2 it was >> instead of << , so I fixed that.
				cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;
				}
			else if (operation == '-') {
				// same problem here but it was after the cout so the first << was >>.
				cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;
				}
			else if (operation == '*') {
				// here the * sign inside the cout statement was / so I fixed that.
				cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;
				}
			else if (operation == '/') {
				// here the / sign inside the cout statement was * , so I fixed that
				cout << op1 << " / " << op2 << " = " << op1 / op2 << endl;
				}

			cout << "Do you wish to evaluate another expression? " << endl;
			cin >> answer;
		}
		// now this is a while statement so if the user answere anything other than y or Y the system will quit an output this statement.
		cout << "Program Finished." << endl;
		// I added this return statement since its a good practice to have one of those.
		return 0;

}