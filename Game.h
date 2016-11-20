#ifndef __GAME_H__
#define __GAME_H__

#include "Line.h"

class Game
{
private:
	Line code;
	
	Line get_guess();

public:
	Game();
	void play();
};

#endif