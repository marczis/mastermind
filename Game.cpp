#include "Game.h"

#include <iostream>

#include "config.h"

Game::Game()
{
	code.setup_random();
}

Line Game::get_guess()
{
	std::string x;
	while ( 1 ) {
		std::getline(std::cin,x);
		try {
			Line l(x);
			return l;
		} catch (Line::WrongInput &e) {
			//std::cout << std::endl << "Sorry can't understand that, try again." << std::endl;
		}
	}
}

void Game::play()
{
	std::cout << "Hello, I made a code, it's " 
	<< Config::get_number_of_cols()
	<< " long and you can use: "
	<< int(Line::Colors::Count)
	<< " \"colors\""
	<< std::endl;

	bool end = false;
	int rounds = 1;
	//Note: I did not limited the game to x turns. 
	//Could be added here easily.
	while ( !end ) {
		std::cout << "[" << rounds++ << "]:";
		Line guess = get_guess();
		Line::CmpRes res = guess.compare(code);
		std::cout << res << std::endl;

		//Refact: CmpRes could be a real class, with a flag for equal lines
		end = true;
		for ( auto &x: res ) {
			if ( x != Line::CmpResItem::Good ) {
				end = false;
				break;
			}
		}
		
		if (end) {
			std::cout << "Grats ! You figured out in: " << rounds << " steps." << std::endl;
		}
	}
}