#pragma once

#ifndef __Common__
#define __Common__

#include <vector>

using namespace std;

vector<int> answers;
int len = 0, h = 0, final_length = 0, index;
int f[4] = { -1, -1, -1, -1 }, indices[4] = { -1, -1, -1, -1 };

//turns are to switch turns between player and the computer since it's a turn based game
enum turns
{
	PLAYER,
	PC,
	WIN
};

//approach is the method that the computer is gonna select to guess the user's number
enum approach
{
	bull,
	cow,
	none
};

#endif