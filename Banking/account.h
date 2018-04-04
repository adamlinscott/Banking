
#pragma once
#include <string>

enum type { current = 50, saving = 80 };
static int lastID = -1;

class Account
{
private:
	long long balance;
	std::string name;
	std::string type;
	int id;
	double interestRate;
public:
	Account(int accountID) : id(accountID) 
	{
		//build from save file
	}

	Account(std::string userName, std::string accType) : name(userName), balance(0), id(lastID + 1), type(accType)
	{
		if(accType == "current")
			interestRate = current / 10000;
		else if(accType == "saving")
			interestRate = saving / 10000;

		lastID = lastID + 1;
	}
	~Account();

	double GetBalance();
	std::string GetName();
	std::string GetType();
	int GetID();
	void Deposit(unsigned long long amount);
	void Withdraw(unsigned long long amount);
};

