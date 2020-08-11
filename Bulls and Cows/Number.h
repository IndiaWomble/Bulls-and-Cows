#pragma once

#ifndef __Number__
#define __Number__

#include <iostream>
#include <ctime>
#include "Function.h"

using namespace std;

turns current_turn;
approach a = approach::none;

//this is the main class
class number
{

	//t is the previos bull and s is the previous cow
	//temp stores the number in integer form whereas actual stores it in array form
	//k and v are 2 integers which are used later in order to maintian the continuity of the code when the turns are reversed
	//same for t2
	int temp, length, t, s, pool, i, j, k, v, t2;
public:
	int actual[4], bulls, cows;
	pair<int, int> p;
	number()
	{
		length = 3;
		p.first = 0;
		p.second = 0;
		bulls = cows = t = s = pool = i = j = k = 0;
		v = -1;
	}

	//converts integer to array
	void converter();

	//converts array to integer
	void reverse_converter();

	//returns integer number
	int get_temp();
	
	//changes the number
	void set_temp(int);
	
	//changes the array
	void set_actual(int, int);
	
	//creates a random number which has four digits and makes sure that those digits are unique
	void random();
	
	//checks if the digits in the number are unique or not
	bool check(int);
	
	//main function to let player determine the coputer's number
	void ai_secret_check(int*);
	
	//copies the identifies digits to the current number at their respective places
	void copy();
	
	//main function for computer to guess player's number
	void answer_guessing();
	
	//AI using bulls first approach
	void b();
	
	//AI using cows first approach
	void c();
	
	//Continuity function for bulls approach
	void for_j_9();
	
	//First continuity function for cows approach
	int cow_g_s();
	
	//Second continuity function for cows approach
	void c_g_b(int);
};

void number::copy()
{
	for (int i = 0; i < h; i++)
		actual[indices[i]] = f[indices[i]];
}

void number::converter()
{
	int rem, n, i = 3;
	n = temp;
	while (n > 0)
	{
		rem = n % 10;
		set_actual(rem, i);
		n = n / 10;
		i--;
	}
}

void number::reverse_converter()
{
	int num = 0;
	for (int i = 0; i < 4; i++)
	{
		num = (num * 10) + actual[i];
	}
	set_temp(num);
}

int number::get_temp()
{
	return temp;
}

void number::set_temp(int n)
{
	temp = n;
}

void number::set_actual(int n, int l)
{
	actual[l] = n;
}

void number::random()
{
	srand(time(0));
	bool flag = false;
	actual[0] = (rand() % 9) + 1;
	for (int i = 1; i < 4; i++)
	{
		while (flag == false)
		{
			actual[i] = rand() % 9;
			flag = check(i);
		}
		flag = false;
	}
}

bool number::check(int l)
{
	int temp[4];
	for (int i = 0; i <= l; i++)
		temp[i] = actual[i];
	for (int i = 0; i <= l; i++)
	{
		for (int j = i + 1; j <= l; j++)
		{
			if (temp[i] == temp[j])
			{
				return false;
			}
		}
	}
	return true;
}

void number::ai_secret_check(int *l)
{
	int bulls = 0, cows = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (l[i] == actual[j])
			{
				cows++;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (l[i] == actual[i])
		{
			bulls++;
			if (cows > 0)
				cows--;
		}
	}
	p.first = bulls;
	p.second = cows;
	if (bulls == 4)
		current_turn = turns::WIN;
}

void number::answer_guessing()
{
	if (bulls == 0 && cows == 0)
	{
		random();
		reverse_converter();
		answers[0] = get_temp();
		cout << "Enter bulls and cows - " << get_temp() << endl << "Bulls - ";
		cin >> bulls;
		cout << "Cows - ";
		cin >> cows;
	}
	else if (bulls > 0)
	{
		a = approach::bull;
		t = bulls;
		b();
	}
	else if (cows > 0)
	{
		a = approach::cow;
		c();
	}
	else if (bulls == 4)
		current_turn = turns::WIN;
}

void number::b()
{
	if (i < 4)
	{
		if (!check_index(i))
		{
			i++;
			b();
			return;
		}
		if (j < 10)
		{
			if (i == 0 && j == 0)
			{
				j++;
				b();
				return;
			}
			else if (j == 9)
			{
				//fuction
				index = i;
				pool = actual[i];
				k = i;
				for_j_9();
			}
			else if (actual[i] != j && bulls != 4)
			{
				actual[i] = j;
				copy();
				reverse_converter();
				if (!check(3) || !check_answers(get_temp()))
				{
					j++;
					b();
					return;
				}
				answers[++len] = get_temp();
				cout << "Enter bulls and cows - " << get_temp() << endl << "Bulls - ";
				cin >> bulls;
				cout << "Cows - ";
				cin >> cows;
				if (bulls < t && bulls != 4)
				{
					int *ptr = external_converter(answers[len - 1]);
					f[i] = ptr[i];
					final_length++;
					len--;
					cout << "Answer - " << f[i] << endl;
					actual[i] = f[i];
					indices[h++] = i;
					j = 0;
					i++;
				}
				else if (bulls > t && bulls != 4)
				{
					f[i] = j;
					final_length++;
					cout << "Answer - " << f[i] << endl;
					actual[i] = j;
					indices[h++] = i;
					t = bulls;
					j = -1;
					i++;
				}
			}
			else
			{
				j++;
				b();
				return;
			}
			j++;
		}
	}
	if (bulls == 4)
	{
		cout << "Your number is - " << get_temp() << endl;
		current_turn = turns::WIN;
		return;
	}
}

void number::c()
{
	if (i < 4)
	{
		if (!check_index(i))
		{
			i++;
			c();
			return;
		}
		if (j < 10)
		{
			if (i == 0 && j == 0)
			{
				j++;
				c();
				return;
			}
			else if (v == 1)
				c_g_b(t2);
			else if (bulls == 4)
			{
				cout << "Your Number is - " << get_temp() << endl;
				current_turn = turns::WIN;
				return;
			}
			else if (actual[i] != j && bulls != 4)
			{
				actual[i] = j;
				copy();
				reverse_converter();
				answers[++len] = get_temp();
				if (!check(3) || !check_answers(get_temp()))
				{
					j++;
					c();
					return;
				}
				cout << "Enter bulls and cows - " << get_temp() << endl << "Bulls - ";
				cin >> bulls;
				cout << "Cows - ";
				cin >> cows;
				if (bulls > t && bulls != 4)
				{
					f[i] = j;
					final_length++;
					cout << "Answer - " << f[i] << endl;
					actual[i] = j;
					reverse_converter();
					t = bulls;
					indices[h++] = i;
					i++;
				}
				else if (cows > s)
				{
					int *ptr = external_converter(answers[len]);
					pool = ptr[i];
					index = i;
					k = i + 1;
					t = bulls;
					s = cows;
					v = cow_g_s();
					i++;
					return;
				}
				else if (cows < s)
				{
					int *ptr = external_converter(answers[len - 1]);
					len--;
					pool = ptr[i];
					int index = i;
					k = i + 1;
					t = bulls;
					s = cows;
					v = cow_g_s();
					i++;
					return;
				}
				s = cows;
				t = bulls;
			}
			else
			{
				j++;
				c();
				return;
			}
		}
		i = 0;
		if (bulls == 4)
		{
			cout << "Your Number is - " << get_temp() << endl;
			current_turn = turns::WIN;
			return;
		}
	}
}

void number::for_j_9()
{
	if (k < 4)
	{
		if (k != i && check_index(k) && actual[k] != 0)
		{
			t2 = actual[k];
			actual[k] = pool;
			actual[index++] = t2;
			copy();
			reverse_converter();
			if (!check_answers(get_temp()) && !check(3))
			{
				k++;
				for_j_9();
				return;
			}
			answers[++len] = get_temp();
			cout << "Enter bulls and cows - " << get_temp() << endl << "Bulls - ";
			cin >> bulls;
			cout << "Cows - ";
			cin >> cows;
			if (bulls > t)
			{
				f[i] = actual[i];
				final_length++;
				indices[h++] = i;
				cout << "Answer - " << f[i] << endl;
				return;
			}
			else if (bulls < t)
			{
				int *ptr = external_converter(answers[len - 1]);
				f[k] = ptr[k];
				final_length++;
				len--;
				cout << "Answer - " << f[k] << endl;
				actual[k] = f[k];
				indices[h++] = k;
				return;
			}
		}
		k++;
	}
}

int number::cow_g_s()
{
	if (k < 4)
	{
		if (k != i && check_index(k) && actual[k] != 0)
		{
			t2 = actual[k];
			actual[k] = pool;
			actual[index++] = t2;
			copy();
			reverse_converter();
			if (!check_answers(get_temp()) && !check(3))
			{
				k++;
				cow_g_s();
				return -1;
			}
			answers[++len] = get_temp();
			cout << "Enter bulls and cows - " << get_temp() << endl << "Bulls - ";
			cin >> bulls;
			cout << "Cows - ";
			cin >> cows;
			if (bulls > t && bulls != 4)
				return 1;
			else
				return 0;
		}
	}
}

void number::c_g_b(int t2)
{
	actual[k] = ++pool;
	reverse_converter();
	while (!check_answers(get_temp()) || !check(3))
		actual[k] = ++pool;
	copy();
	reverse_converter();
	answers[++len] = get_temp();
	t = bulls;
	s = cows;
	cout << "Enter bulls and cows - " << get_temp() << endl << "Bulls - ";
	cin >> bulls;
	cout << "Cows - ";
	cin >> cows;
	if (bulls < t && bulls != 4)
	{
		int *ptr1 = external_converter(answers[--len]);
		f[k] = ptr1[k];
		final_length++;
		actual[k] = ptr1[k];
		reverse_converter();
		cout << "Answer - " << f[k] << endl;
		indices[h++] = k;
		s = cows;
		return;
	}
	else
	{
		int *ptr1 = external_converter(answers[len]);
		f[index - 1] = t2;
		final_length++;
		actual[index - 1] = t2;
		reverse_converter();
		cout << "Answer - " << t2 << endl;
		t = bulls;
		s = cows;
		indices[h++] = index - 1;
		return;
	}
	v = 0;
}

#endif