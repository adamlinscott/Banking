#include "stdafx.h"
#include "account.h"
#include <string>


account::~account()
{
}



long long account::GetBalance()
{
	return balance;
}


void account::Deposit(unsigned long long amount)
{
	balance += amount;
}



void account::Withdraw(unsigned long long amount)
{
	if (amount <= balance)
		balance -= amount;
}