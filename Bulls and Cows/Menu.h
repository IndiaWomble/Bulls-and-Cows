#pragma once

#ifndef __Menu__
#define __Menu__

//This is the main menu
int menu()
{
	cout << "1. Play" << endl;
	cout << "2. Exit" << endl;
	cout << "Enter your choice - ";
	int choice;
	cin >> choice;
	if (choice == 1 || choice == 2)
		return choice;
	else return 0;
}

//this is the menu that will appear once the game is over or if any exception is thrown
int end_menu()
{
	cout << "1. Retry" << endl;
	cout << "2. Exit" << endl;
	cout << "Enter your choice - ";
	int choice;
	cin >> choice;
	if (choice == 1 || choice == 2)
		return choice;
	else return 0;
}

#endif