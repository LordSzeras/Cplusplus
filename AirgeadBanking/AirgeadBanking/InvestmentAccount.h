#ifndef INVESTMENTACCOUNT_H
#define INVESTMENTACCOUNT_H


using namespace std;

class InvestmentAccount {
	public:
		InvestmentAccount();
		void SetInitialInvestment(double t_initialInvestment);
		double GetInitialInvestment();
		void SetMonthlyDeposit(double t_monthlyDeposit);
		double GetMonthlyDeposit();
		void SetInterestPercent(double t_interestPercent);
		double GetInterestPercent();
		void SetYearsToInvest(int t_yearsToInvest);
		int GetYearsToInvest();
		void SetOpeningAmount(double t_openingAmount);
		double GetOpeningAmount();
		void SetAccountTotal(double t_accountTotal);
		double GetAccountTotal();
		void CalcMonthlyInterestEarned();
		double GetMonthlyInterestEarned();
		void SetClosingBalance(double t_closingBalance);
		double GetClosingBalance();
		double GetYearEndBalance();
		void CalcYearlyInterestEarned();
		double GetYearlyInterestEarned();

	private:
		double m_initialInvestment;
		double m_monthlyDeposit;
		double m_interestPercent;
		int m_yearsToInvest;
		double m_openingAmount;
		double m_accountTotal;
		double m_monthlyInterestEarned;
		double m_closingBalance;
		double m_yearEndBalance;
		double m_yearlyInterestEarned;
};
#endif
