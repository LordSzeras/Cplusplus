#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#include "InvestmentAccount.h"

using namespace std;

void DisplayMenu() {
	cout << "******************************" << endl;
	cout << "********* Data Input *********" << endl;
	cout << "Initial Investment Amount:    " << endl;
	cout << "Monthly Deposit Amount:       " << endl;
	cout << "Annual Interest Percent:      " << endl;
	cout << "Number of years to invest:    " << endl;
	cout << "******************************" << endl;
	cout << endl << endl;
}


int main() {
	InvestmentAccount withDeposits;
	InvestmentAccount withoutDeposits;
	vector<double> yearEndBalanceWithout;
	vector<double> yearEndInterestWithout;
	vector<double> yearEndBalanceWith;
	vector<double> yearEndInterestWith;
	double userInitialInvestment;
	double userMonthlyDeposit;
	double userInterestPercent;
	int userYearsToInvest;
	char userInput = 'y';
	unsigned int i;

	//Loop so user can try new numbers
	while (userInput == 'y') {
		DisplayMenu();

		//Gets initial investment amount and sets for both accounts
		cout << "Please enter your inital Investment amount." << endl;
		cin >> userInitialInvestment;
		withDeposits.SetInitialInvestment(userInitialInvestment);
		withoutDeposits.SetInitialInvestment(userInitialInvestment);
		withDeposits.SetOpeningAmount(userInitialInvestment);
		withoutDeposits.SetOpeningAmount(userInitialInvestment);

		//Gets monthly deposit amounts and sets 1 with value and other with '0'
		cout << "Please enter your monthly deposit amount." << endl;
		cin >> userMonthlyDeposit;
		withDeposits.SetMonthlyDeposit(userMonthlyDeposit);
		withoutDeposits.SetMonthlyDeposit(0);

		//Gets annual interest percent and sets for both accounts
		cout << "Please enter your Annual Interest Percent." << endl;
		cin >> userInterestPercent;
		withDeposits.SetInterestPercent(userInterestPercent);
		withoutDeposits.SetInterestPercent(userInterestPercent);

		//Gets number of years to calculate for investing and sets for both accounts
		cout << "Please enter how many years you plan to invest." << endl;
		cin >> userYearsToInvest;
		withDeposits.SetYearsToInvest(userYearsToInvest);
		withoutDeposits.SetYearsToInvest(userYearsToInvest);
		yearEndBalanceWith.resize(userYearsToInvest);
		yearEndInterestWith.resize(userYearsToInvest);
		yearEndBalanceWithout.resize(userYearsToInvest);
		yearEndInterestWithout.resize(userYearsToInvest);

		//Calculates Yearly Balance and Interest for accounts and stores in vectors
		for (int i = 0; i < userYearsToInvest; i++) {
			withDeposits.CalcYearlyInterestEarned();
			withoutDeposits.CalcYearlyInterestEarned();
			yearEndBalanceWith.at(i) = withDeposits.GetYearEndBalance();
			yearEndInterestWith.at(i) = withDeposits.GetYearlyInterestEarned();
			yearEndBalanceWithout.at(i) = withoutDeposits.GetYearEndBalance();
			yearEndInterestWithout.at(i) = withoutDeposits.GetYearlyInterestEarned();
		}

		//Prints out Year, Year End Balance, and Yearly Interest for withoutDeposit account
		cout << "=====================================================" << endl;
		cout << "    Balance and Interest without Monthly Deposits    " << endl;
		cout << "=====================================================" << endl;
		cout << " Year    Year End Balance    Year End Interest Earned" << endl;
		cout << "-----------------------------------------------------" << endl;
		for (int i = 1; i <= userYearsToInvest; i++) {
			cout << setfill(' ') << setw(4) << i;
			cout << setfill(' ') << setw(21) << fixed << setprecision(2) << yearEndBalanceWithout.at(i - 1);
			cout << setfill(' ') << setw(28) << fixed << setprecision(2) << yearEndInterestWithout.at(i - 1) << endl;
		}
		cout << "=====================================================" << endl;
		cout << endl;

		//Prints out Year, Year End Balance, and Yearly Interest for withDeposit account
		cout << "=====================================================" << endl;
		cout << "      Balance and Interest with Monthly Deposits     " << endl;
		cout << "=====================================================" << endl;
		cout << " Year    Year End Balance    Year End Interest Earned" << endl;
		cout << "-----------------------------------------------------" << endl;
		for (int i = 1; i <= userYearsToInvest; i++) {
			cout << setfill(' ') << setw(4) << i;
			cout << setfill(' ') << setw(21) << fixed << setprecision(2) << yearEndBalanceWith.at(i - 1);
			cout << setfill(' ') << setw(28) << fixed << setprecision(2) << yearEndInterestWith.at(i - 1) << endl;
		}
		cout << "=====================================================" << endl;
		cout << endl << endl;

		//Asks if user would like to test different amounts
		cout << "Would you like to use new numbers? (y/n)" << endl;
		cin >> userInput;
	}


	return 0;
}