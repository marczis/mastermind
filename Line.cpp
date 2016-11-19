#include "Line.h"

#include <sstream>

Line::Line(const std::string &line)
 :items(Config::get_number_of_cols())
{
	std::stringstream l(line);

	for( auto &x: items ) {
		int i = 0;
		l >> i;
		if (l.fail()) throw WrongInput();
		x = Colors(i);
	}
}

Line::Colors Line::getItem(int i) const {
	return items.at(i);
}