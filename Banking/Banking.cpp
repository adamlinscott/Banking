// Banking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int RunHelp() {
	cout << "usage: Banking <command>[<args>]";
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
		cout << command;
		if (command == "help") {
			return RunHelp();
		}
		else if (command == "new") {

		}

		return 0;
	}
}