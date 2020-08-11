#pragma once

#ifndef __User_Exception__
#define __User_Exception__

#include <exception>

using namespace std;

//user made exceptions to deal with bad input
class BAD_INPUT_GUESS : public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Bad Input! The number should be of 4 digits and each digit of the number should be different";
	}
};

class BAD_INPUT_BC : public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Bad Input! The sum of bulls and cows cannot be greater than 4";
	}
};

class BAD_INPUT_DIGITS_COUNT : public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Bad Input! Number of digits allowed are 4. Not less than that or more than that";
	}
};

#endif
