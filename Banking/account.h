
#pragma once
#include <string>
#include <iostream>
#include <fstream>

enum type { current = 50, saving = 80 };

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
			interestRate = current / 10000;
		else if (type == "saving")
			interestRate = saving / 10000;
	}

	Account(std::string userName, std::string accType) : name(userName), balance(0), type(accType)
	{
		int lastID;
		std::ifstream myReadFile;
		myReadFile.open("settings.txt");
		std::string output;
		if (myReadFile.is_open()) {
			while (!myReadFile.eof()) {
				myReadFile >> output;
			}
			lastID = atoi(output.c_str());
			lastID = lastID + 1;
			id = lastID;

			std::ofstream myfile("settings.txt");
			myfile << lastID;
			myfile.close();
		}
		else
		{
			id = 0;
			std::ofstream myfile("settings.txt");
			myfile << 0;
			myfile.close();
		}
		myReadFile.close();

		if(accType == "current")
			interestRate = current / 10000;
		else if(accType == "saving")
			interestRate = saving / 10000;
	}
	~Account();

	double GetBalance();
	std::string GetName();
	std::string GetType();
	int GetID();
	void Deposit(unsigned long long amount);
	void Withdraw(unsigned long long amount);
	void UpdateFile();
};

