// Banking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(int argc, char* argv[])
{
	string command;
	
	if (argc < 2)
	{
		cout << "Please give a command\n";
		return 1;
	}
	else
	{
		command = argv[1];
		cout << command;
		if (command == "help") {

		}
		else if (command == "new") {

		}

		return 0;
	}
}