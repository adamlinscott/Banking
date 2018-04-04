
#pragma once
#include <string>
#include <iostream>
#include <fstream>

enum type { cInterest = 50, sInterest = 80, cLimit = 200, sLimit = 1000 };

class Account
{
private:
	long long balance;
	long long interestLimit;
	std::string name;
	std::string type;
	int id;
	double interestRate;
public:
	Account(int accountID) : id(accountID) 
	{
		std::ifstream myReadFile;
		myReadFile.open(std::to_string(accountID) + ".txt");
		std::string output;
		if (myReadFile.is_open()) {
			if(!myReadFile.eof())
				myReadFile >> output;

			if (!myReadFile.eof())
				myReadFile >> output;
			name = output;

			if (!myReadFile.eof())
				myReadFile >> output;
			balance = std::stoll(output);

			if (!myReadFile.eof())
				myReadFile >> output;
			type = output;
		}
		else
		{
			std::cout << "fatal: Account" << accountID << "does not exist";
		}
		myReadFile.close();

		if (type == "current")
		{
			interestRate = (double)cInterest / 10000;
			interestLimit = cLimit;
		}
		else if (type == "saving")
		{
			interestRate = (double)sInterest / 10000;
			interestLimit = sLimit;
		}
	}

	Account(std::string userName, std::string accType) : name(userName), balance(0), type(accType)
	{
		int lastID;
		std::ifstream myReadFile;
		myReadFile.open("settings.txt");
		std::string output;
		if (myReadFile.is_open()) {
			myReadFile >> output;
			lastID = atoi(output.c_str());
			lastID = lastID + 1;
			id = lastID;

			std::ofstream myfile("settings.txt");
			myfile << lastID;
			myfile.close();
		}
		else
		{
			id = 1;
			std::ofstream myfile("settings.txt");
			myfile << 1;
			myfile.close();
		}
		myReadFile.close();

		if (accType == "current")
		{
			interestRate = (double)cInterest / 10000;
			interestLimit = cLimit;
		}
		else if (accType == "saving")
		{
			interestRate = (double)sInterest / 10000;
			interestLimit = sLimit;
		}
	}
	~Account();

	double GetBalance();
	double GetInterest();
	long long GetMinimumBalance();
	std::string GetName();
	std::string GetType();
	int GetID();
	void Deposit(unsigned long long amount);
	int Withdraw(unsigned long long amount);
	void UpdateFile();
	void ApplyInterest();
};

