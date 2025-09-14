/*
Abdulrahman Al-Nachar
3/23/2-23
Chada Clock
*/

// I need these two libraries the second one is used for setw and setfill for the display
#include <iostream>
#include <iomanip>

using namespace std;

// this function does two things converts the input hours into 12 & 24 hour format and displays the two clocks
void displayTime(int hours, int minutes, int seconds, string answer) 
{
	// this variable is used to determine the time for the 24 hour clock
	int twentyFourHours;
	// this is to set the 12 hour format ex:(PM to P M) just like how the example results showed
	string time;

	/* 
	two if statements to convert the time for the 24 hour format and set the string for the time variable.
	* the PM for that 24 hour format for ex if the input is 3 PM it will be 15 pm unless the input is 12 then 12 PM doesnt change.
	*/ 
	if (answer == "pm" || answer == "PM") {
		time = "P M";
		if (hours != 12) {
			twentyFourHours = hours + 12;
		}
		else {
			twentyFourHours = hours;
			}
	}

	// this one is for the AM so if its 12 am for the 24 hours format it turns into 0 anything else stays the same
	else if (answer == "AM" || answer == "am") {
		time = "A M";
		if (hours == 12) {
			twentyFourHours = 0;
		} else {
			twentyFourHours = hours;
			}
	}


	// 8 space 26 stars 4 space 26 stars 8 space
	cout << "        *************************    **************************        " << endl;
	cout << "        *     12-Hour Clock     *    *      24-Hour Clock     *        " << endl;
	cout << "        * " << "    " << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << ":"
		<< setw(2) << setfill('0') << seconds << " " << time << "      *    *        " << setw(2) << setfill('0') << twentyFourHours << ":" << setw(2) << setfill('0') << minutes << ":"
		<< setw(2) << setfill('0') << seconds << "        *        " << endl;
	cout << "        *************************    **************************        " << endl;

}

// this function is to add the hour and if after the adding of one it becomes 13 it fixes it and changes it to one
int addHour(int hour) 
{
	int tempHour = hour + 1;
	if (tempHour == 13) {
		tempHour = 1;
	}
	hour = tempHour;
	return hour;
}

// this function checks if the hour after addHour function becomes 12 it chenges the am to pm and vice versa
string didItChange(int hour, string answer)
{
	if (hour == 12 && (answer == "pm" || answer == "PM")) {
		answer = "am";
	}
	else if (hour == 12 && (answer == "am" || answer == "AM")) {
		answer = "pm";
	}

	return answer;
}

// this function checks if the hour is 13 so it resets it to one it is only used case 3 in the switch statement
int checkHours(int hour)
{
	if (hour == 13) {
		hour = 1;
	}
	return hour;
}

// this function add a minute to minutes
int addMins(int minutes)
{
	return minutes + 1;
}

// this function checks if minutes reached 60 it will add 1 hour to hours
int minsToHours(int minutes, int hour) 
{

	if (minutes == 60) {
		hour += 1;
	}

	return hour;
}

// this function checks if minutes reached 60 so it resets it to 0
int minsToMins(int minutes) 
{
	int temp;
	if (minutes == 60) {
		temp = 0;
		minutes = temp;
	}
	return minutes;
}

// this function adds one to seconds and if its 60 it will set it to 0
int addSecs(int seconds)
{
	int tempSecs = seconds + 1; 
	if (tempSecs == 60) {
		tempSecs = 0;
	}
	seconds = tempSecs;
	return seconds;
}

// this function will add a minute to minutes if seconds got to 60 in the last function
int secsToMins(int seconds, int minutes)
{

	if (seconds == 0 ) {
		minutes += 1;
	}

	return minutes;
}


int main() 
{
	// these variables is for the input hours , minutes , seconds and AM or PM which is answer
	int hoursInput;
	int minsInput;
	int secsInput;
	string answer;

	cout << "This is the time converter program." << endl;

	// this do while statement makes sure the hours is between (1-12)
	do {
		cout << "Please enter the time in hours (1-12): ";
		cin >> hoursInput;
	} while (hoursInput < 1 || hoursInput > 12);

	// this do while statement makes sure the minutes is between (0-59)
	do {
		cout << "Please enter the time in minutes (0-59): ";
		cin >> minsInput;
	} while (minsInput < 0 || minsInput > 59);

	// this do while statement makes sure the seconds is between (0-59)
	do {
		cout << "Please enter the time in seconds (0-59): ";
		cin >> secsInput;
	} while (secsInput < 0 || secsInput > 59);

	// this do while statement makes sure its either am or pm
	do {
		cout << "Is it AM or PM: ";
		cin >> answer;
	} while (answer != "AM" && answer != "PM" && answer != "am" && answer != "pm");

	// this will be used in a switch statement later after getting its input
	char choice;
	// this is a while do statement that will end the program once the user wants out
	do {
		// Display the current time
		displayTime(hoursInput, minsInput, secsInput, answer);

		// Displays the menu like how the guidline doc had it
		cout << endl;
		cout << "                       *************************                     " << endl;
		cout << "                       * 1 - Add One Hour      *                     " << endl;
		cout << "                       * 2 - Add One Minute    *                     " << endl;
		cout << "                       * 3 - Add One Second    *                     " << endl;
		cout << "                       * 4 - Exit Program      *                     " << endl;
		cout << "                       *************************                     " << endl;

		cin >> choice;
		// this is the switch statment 
		switch (choice) {

		case '1':
			//this adds an hour and checks if its time to switch am to pm and vice versa
			hoursInput = addHour(hoursInput);
			answer = didItChange(hoursInput, answer);
			break;
		case '2':
			/* this adds a minute and checks if it completed a hour
			*/ 
			minsInput = addMins(minsInput);
			hoursInput = minsToHours(minsInput, hoursInput);
			minsInput = minsToMins(minsInput);
			break;
		case '3':
			/* this adds a second and it then starts the domino effect of checking if it completed a minute
			* and if it did then check if it completed a hour and then check if the hour reached 13 so it can be 
			* reset to 1 and check if its time to change from am to pm and vice versa like a real clock.
			*/
			secsInput = addSecs(secsInput);
			minsInput = secsToMins(secsInput, minsInput);
			hoursInput = minsToHours(minsInput, hoursInput);
			minsInput = minsToMins(minsInput);
			hoursInput = checkHours(hoursInput);
			/* I added this if statement because if it was 11:59:59 and the user adds a second it becomes 12:00:00 and changes 
			* from pm to am or vice versa but then if u add a second after that it keeps changing the am/pm because it kept 
			* activating this function didItChange() over and over.
			*/
			if (secsInput == 0) {
				answer = didItChange(hoursInput, answer);
			}
			break;
		case '4':
			// this exits the program
			break;
		default:
			// this if the input is not between 1-4
			cout << "Invalid, Choose between 1-4" << endl;
		}
	} while (choice != '4');

	return 0;
}
