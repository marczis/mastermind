#ifndef __GUESS_H__
#define __GUESS_H__

#include <string>
#include <vector>

#include "config.h"

class Guess 
{
	std::vector<int> guess;
public:
	Guess(std::string &line);
};

#endif