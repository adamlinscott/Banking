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
	UpdateFile();
}



int Account::Withdraw(unsigned long long amount)
{
	if (amount <= balance)
	{
		balance -= amount;
		UpdateFile();
		return 0;
	}
	else
	{
		return 1;
	}
}



void Account::UpdateFile()
{
	std::string fileName = std::to_string(GetID()) + ".txt";
	std::ofstream myfile(fileName);
	myfile << GetID() << std::endl;
	myfile << GetName() << std::endl;
	myfile << balance << std::endl;
	myfile << GetType();
	myfile.close();
}