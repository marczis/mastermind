#ifndef __USER_INPUT_H__
#define __USER_INPUT_H__

#include <iostream>

class UserInput
{
	std::istream &inp;

public:
	UserInput(std::istream &inp);

};

#endif
