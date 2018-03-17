// Banking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "account.h"

using namespace std;

int RunHelp() {
	cout << "usage: Banking <command>[<args>]";
	return 0;
}

int RunNew(string accType, string accName) {
	if (accType == "")
		accType = "current";
	if (accName == "")
	{
		cout << "fatal: Account name not specified";
		return 0;
	}
	cout << "account created";
	return 0;
}


int main(int argc, char* argv[])
{
	string command;
	
	if (argc < 2)
	{
		return RunHelp();
	}
	else
	{
		command = argv[1];
		if (command == "help") {
			return RunHelp();
		}
		else if (command == "new") {
			string AccName = "";
			string AccType = "";

			for (int i = 2; i < argc; i++) {
				string param = argv[i];
				if (param == "-h" or param == "--help")
				{
					cout << "usage: Banking new [<options>] \n\n\t-n, --name\t\tName of Account \n\t-t, --type\t\tType of Account \n" << endl;
					return 0;
				}
				else if (param == "-n" or param == "--name")
				{
					if (i < argc - 1)
						if (argv[i + 1][0] != '-')
							AccName = argv[i + 1];
				}
				else if (param == "-t" or param == "--type")
				{
					if (i < argc - 1)
						AccType = argv[i + 1];
				}
			}

			RunNew(AccType, AccName);
		}

		return 0;
	}
}