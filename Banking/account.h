
#pragma once

enum type { current = 50, saving = 80 };
static int lastID = 0;

class account
{
private:
	long long balance;
	char* name;
	int id;
	double interestRate;
public:
	account(int accountID) : id(accountID) 
	{
		//build from save file
	}

	account(char* userName, char* accType) : name(userName), balance(0), id(lastID + 1)
	{
		if(accType == "current")
			interestRate = current / 10000;
		else if(accType == "saving")
			interestRate = saving / 10000;

		//get last used id and assign id + 1
		lastID = lastID + 1;
	}
	~account();

	long long GetBalance();
	void Deposit(unsigned long long amount);
	void Withdraw(unsigned long long amount);
};

