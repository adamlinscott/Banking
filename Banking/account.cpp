#include "stdafx.h"
#include "Account.h"
#include <string>
#include <iostream>
#include <fstream>


Account::~Account()
{
}



double Account::GetBalance()
{
	return (double)balance/100;
}



std::string Account::GetName()
{
	return name;
}



std::string Account::GetType()
{
	return type;
}



int Account::GetID()
{
	return id;
}



void Account::Deposit(unsigned long long amount)
{
	balance += amount;
}



void Account::Withdraw(unsigned long long amount)
{
	if (amount <= balance)
		balance -= amount;
}