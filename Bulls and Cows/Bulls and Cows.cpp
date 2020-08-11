//Bulls and Cows

#include "pch.h"
#include "User_Exception.h"
#include "Menu.h"
#include "Number.h"

using namespace std;

 int main()
 {
	 int temp, choice;
	 choice = menu();
	 a:
	 number *player = new number();
	 number *PC = new number();
	 current_turn = turns::PLAYER;
	 PC->random();
	 int *num = new int[4];
	 
	 //State Machine
	 try
	 {
		 while (current_turn != turns::WIN && choice == 1)
		 {
			 switch (current_turn)
			 {
			 case turns::PC:
			 {
				 current_turn = turns::PLAYER;
				 switch (a)
				 {
				 case approach::none:
				 {
					 player->answer_guessing();
					 break;
				 }
				 case approach::bull:
				 {
					 player->b();
					 break;
				 }
				 case approach::cow:
				 {
					 player->c();
					 break;
				 }
				 }
				 if (player->bulls + player->cows > 4)
					 throw BAD_INPUT_BC();
				 break;
			 }
			 case turns::PLAYER:
			 {
				 current_turn = turns::PC;
				 cout << "Enter your guess - ";
				 cin >> temp;
				 if (!digits_check(temp))
					 throw BAD_INPUT_DIGITS_COUNT();
				 if (!external_check(temp))
					 throw BAD_INPUT_GUESS();
				 num = external_converter(temp);
				 PC->ai_secret_check(num);
				 cout << "Bulls - " << PC->p.first << endl;
				 cout << "Cows - " << PC->p.second << endl;
				 break;
			 }
			 }
		 }
	 }
	 catch (BAD_INPUT_BC temp_BIB)
	 {
		cout << temp_BIB.what() << endl;
		choice = end_menu();
	 }
	 catch (BAD_INPUT_GUESS temp_BIG)
	 {
		cout << temp_BIG.what() << endl;
		choice = end_menu();
	 }
	 catch (BAD_INPUT_DIGITS_COUNT temp_BIDC)
	 {
		 cout << temp_BIDC.what() << endl;
		 choice = end_menu();
	 }
	 if (choice == 1)
		 goto a;
	 if (player->bulls == 4)
		 cout << "PC wins!";
	 else if(PC->bulls == 4)
		 cout << "Player wins!";
	 delete player;
	 delete PC;
	 return 0;
 }

