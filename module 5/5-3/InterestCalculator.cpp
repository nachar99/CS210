//Abdulrahman Al-Nachar
#include <iostream>
#include <iomanip>

using namespace std;

// this is for the first display which basically shows an empty account
void FirstDisplay(double investment = 0, double deposit = 0, double interest = 0, int years = 0) {
    cout << endl;
    cout << "**********************************" << endl;
    cout << "********** " << "Data Input" << " **********" << endl;
    cout << "Initial Investment Amount: " << investment << endl;
    cout << "Monthly Deposit: " << deposit << endl;
    cout << "Annual Interest: " << interest << endl;
    cout << "Number of Years: " << years << endl;
    cout << "Press any key to continue " << endl;

} 

// this shows whatever the user input and at the same time calculates balance and interest without adding monthly deposits
void SecondDisplay(double balance = 0, double interest = 0, int years = 0) {
    int i;
    double interestGained = balance * (interest / 100);
    cout << endl;
    cout << "  Balance and Interest Without Additional Monthly Deposits  " << endl;
    cout << "============================================================" << endl;
    cout << "  Year           Year End Balance         Year End Interest " << endl;
    cout << "------------------------------------------------------------" << endl;
    for (i = 1; i <= years; ++i) {
        cout << "    " << i << "                 " << "$" << balance + (interestGained * i) << "                     " << "$" << balance * (interest / 100) << " " << endl;
    }
    cout << endl;
}

// this is like the last one but shows the effects of adding monthly deposits
void ThirdDisplay(double investment = 0, double deposit = 0, double interest = 0, int years = 0) {
    int i;
    double balance = investment + deposit;
    double interestGained = balance * (interest / 100);
    cout << endl;
    cout << "    Balance and Interest With Additional Monthly Deposits   " << endl;
    cout << "============================================================" << endl;
    cout << "  Year           Year End Balance         Year End Interest " << endl;
    cout << "------------------------------------------------------------" << endl;
    for (i = 1; i <= years; ++i) {
        if (i > 1) {
            cout << "    " << i << "                 " << "$" << balance + (interestGained * i) + deposit << "                     " << "$" << (deposit + balance) * (interest / 100) << " " << endl;
        } 
        else {
            cout << "    " << i << "                 " << "$" << balance + (interestGained * i) << "                     " << "$" << interestGained << " " << endl;
        }
    }
    cout << endl;
}


// this display is the table that is required at the end that shows the effects month to month
void fourthDisplay(double initialInvestment, double monthlyDeposit, double annualInterest, int numberOfYears) {
    int totalMonths = numberOfYears * 12;
    // This is for the table's header
    cout << left << setw(6) << "Month" << setw(16) << "Opening Amount" << setw(16) << "Deposited Amount" << setw(16) << "Interest" << setw(16) << "Closing Balance" << endl;
    cout << setfill('-') << setw(70) << "-" << setfill(' ') << endl;

    double openingAmount = initialInvestment;
    double closingBalance = initialInvestment;

    for (int month = 1; month <= totalMonths; month++) {
        // this is for the monthly interest
        double monthlyInterestRate = (annualInterest / 100.0) / 12;
        double interest = (openingAmount + monthlyDeposit) * monthlyInterestRate;

        // This is for the closing balance
        closingBalance = openingAmount + monthlyDeposit + interest;

        // This to print the data for each month
        cout << left << setw(6) << month << fixed << setprecision(2) << setw(16) << openingAmount << setw(16) << monthlyDeposit << setw(16) << interest << setw(16) << closingBalance << endl;

        // this to update the opening balance
        openingAmount = closingBalance;
    }
}

int main() {

    char answer;
    // I am using a do while statement so that the user can use the system more than once if they want

    do {
        // these are the basic variables needed to run the program and call the diferrent functions
        double initialInvestment;
        double monthlyDeposit;
        double annualInterest;
        int numberOfYears;
    
        // this to call the first display without any parameters
        FirstDisplay();

    
        // this to get the input from the user 
        cout << endl;
        cout << "What's your initial investment? " << endl;
        cin >> initialInvestment;
        cout << "How much do you want to deposit each month? " << endl;
        cin >> monthlyDeposit;
        cout << "What is the interest rate? " << endl;
        cin >> annualInterest;
        cout << "How long you wanna calculate for in terms of years? " << endl;
        cin >> numberOfYears;

        // this total balance is only used in the 2nd function since there no monthly deposits 
        double totalBalance = initialInvestment + monthlyDeposit;

        // here I am calling the functions one after the other based on the inputs recieved from the user
        FirstDisplay(initialInvestment, monthlyDeposit, annualInterest, numberOfYears);

        SecondDisplay(totalBalance, annualInterest, numberOfYears);

        ThirdDisplay(initialInvestment, monthlyDeposit, annualInterest, numberOfYears);

        fourthDisplay(initialInvestment, monthlyDeposit, annualInterest, numberOfYears);

        // this asks them if they wanna use the system again 
        cout << "Do you want to use this again (Y/N)? ";
        cin >> answer;

    } while (answer == 'Y' || answer == 'y');

	return 0;
}