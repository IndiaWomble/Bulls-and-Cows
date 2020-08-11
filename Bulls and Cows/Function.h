#pragma once

#ifndef __Function__
#define __Function__

#include "Common.h"

//This function checks if the number entered by the user has 4 digits or not
bool digits_check(int num)
{
	int n = num, i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	if (i < 4 || i > 4)
		return false;
	return true;
}

//This function makes a number stored in the array form into int
int* external_converter(int num)
{
	static int temp[4];
	int n = num, i = 3;
	while (n > 0)
	{
		temp[i] = n % 10;
		n = n / 10;
		i--;
	}
	return temp;
}

//This function checks if any digit in the is repeated
bool external_check(int temp)
{
	int *t = external_converter(temp);
	for (int i = 0; i <= 3; i++)
	{
		for (int j = i + 1; j <= 3; j++)
		{
			if (t[i] == t[j])
			{
				return false;
			}
		}
	}
	return true;
}

//This function checks if the new guess of the computer has already guessed by it earlier or not
bool check_answers(int num)
{
	for (int i = 0; i < len; i++)
	{
		if (answers[i] == num)
			return false;
	}
	return true;
}

//This function checks if the index we are working on has been solved or not
bool check_index(int n)
{
	for (int i = 0; i < h; i++)
	{
		if (n == indices[i])
			return false;
	}
	return true;
}

#endif // !__Function__

