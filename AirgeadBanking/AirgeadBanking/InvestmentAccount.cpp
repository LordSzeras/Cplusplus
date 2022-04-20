#include <iostream>
#include "InvestmentAccount.h"


using namespace std;

InvestmentAccount::InvestmentAccount() {
	m_initialInvestment = 0;
	m_monthlyDeposit = 0;
	m_interestPercent = 0;
	m_yearsToInvest = 0;
	m_openingAmount = 0;
	m_accountTotal = 0;
	m_monthlyInterestEarned = 0;
	m_closingBalance = 0;
	m_yearEndBalance = 0;
	m_yearlyInterestEarned = 0;
}

void InvestmentAccount::SetInitialInvestment(double t_initialInvestment) {
	m_initialInvestment = t_initialInvestment;
}

double InvestmentAccount::GetInitialInvestment() {
	return m_initialInvestment;
}

void InvestmentAccount::SetMonthlyDeposit(double t_monthlyDeposit) {
	m_monthlyDeposit = t_monthlyDeposit;
}

double InvestmentAccount::GetMonthlyDeposit() {
	return m_monthlyDeposit;
}
void InvestmentAccount::SetInterestPercent(double t_interestPercent) {
	m_interestPercent = t_interestPercent;
}

double InvestmentAccount::GetInterestPercent() {
	return m_interestPercent;
}

void InvestmentAccount::SetYearsToInvest(int t_yearsToInvest) {
	m_yearsToInvest = t_yearsToInvest;
}

int InvestmentAccount::GetYearsToInvest() {
	return m_yearsToInvest;
}

void InvestmentAccount::SetOpeningAmount(double t_openingAmount) {
	m_openingAmount = t_openingAmount;
}

double InvestmentAccount::GetOpeningAmount() {
	return m_openingAmount;
}

void InvestmentAccount::SetAccountTotal(double t_accountTotal) {
	m_accountTotal = t_accountTotal;
}

double InvestmentAccount::GetAccountTotal() {
	return m_accountTotal;
}

void InvestmentAccount::CalcMonthlyInterestEarned() {
	m_monthlyInterestEarned = (m_openingAmount + m_monthlyDeposit) * ((m_interestPercent / 100.0) / 12.0); //calcs monthly interest
	m_accountTotal = m_openingAmount + m_monthlyDeposit;                                                   //adds deposit to opening and sets to total
	m_closingBalance = m_accountTotal + m_monthlyInterestEarned;                                           //adds interest to total and sets to closing
	m_openingAmount = m_closingBalance;                                                                    //set opening to closing for next month
	m_yearEndBalance = m_closingBalance;
	m_yearlyInterestEarned = m_yearlyInterestEarned + m_monthlyInterestEarned;
}

double InvestmentAccount::GetMonthlyInterestEarned() {
	return m_monthlyInterestEarned;
}

void InvestmentAccount::SetClosingBalance(double t_closingBalance) {
	m_closingBalance = t_closingBalance;
}

double InvestmentAccount::GetClosingBalance() {
	return m_closingBalance;
}

double InvestmentAccount::GetYearEndBalance() {
	return m_yearEndBalance;
}

void InvestmentAccount::CalcYearlyInterestEarned() {
	m_yearlyInterestEarned = 0;                                                                                //resets yearly interest
	for (int i = 0; i < 12; i++) {
		m_monthlyInterestEarned = (m_openingAmount + m_monthlyDeposit) * ((m_interestPercent / 100.0) / 12.0); //calcs monthly interest
		m_accountTotal = m_openingAmount + m_monthlyDeposit;                                                   //adds deposit to opening and sets to total
		m_closingBalance = m_accountTotal + m_monthlyInterestEarned;                                           //adds interest to total and sets to closing
		m_openingAmount = m_closingBalance;                                                                    //set opening to closing for next month
		m_yearEndBalance = m_closingBalance;                                                                   //sets year end balance
		m_yearlyInterestEarned = m_yearlyInterestEarned + m_monthlyInterestEarned;                             //adds months interest to year interest
	}
}

double InvestmentAccount::GetYearlyInterestEarned() {
	return m_yearlyInterestEarned;
}
