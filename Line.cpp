#include "Line.h"

#include <sstream>
#include <algorithm>

Line::Line()
 :items(Config::get_number_of_cols()),random(rd())
{ 
}

Line::Line(const std::string &line)
 :Line()
{
	setup(line);
}

Line::Line(const Line&& other)
 :items(std::move(other.items)), random(std::move(other.random))
{
}

void Line::setup(const std::string &line)
{
	std::stringstream l(line);

	for( auto &x: items ) {
		int i = 0;
		l >> i;
		if (l.fail()) throw WrongInput();
		//If I would have more time, I would make a better error handling.
		//So I can tell to the user what's wrong with the input.
		x = Colors(i);
	}
}

void Line::setup_random()
{
	for( auto &x: items ) {
		x = Colors(random() % int(Colors::Count));
	}
}

Line::Colors Line::getItem(int i) const 
{
	return items.at(i);
}

Line::CmpRes Line::compare(const Line& other) const
//Required: Valid Line objects, with same amount of "cols"
{
	CmpRes res(Config::get_number_of_cols());

	for(int i = 0; i < Config::get_number_of_cols() ; ++i) {
		res[i] = CmpResItem::Bad;
		if (getItem(i) == other.getItem(i)) {
			res[i] = CmpResItem::Good;
			continue;
		}
	}

	for(int o = 0; o < Config::get_number_of_cols(); ++o) {
		if (res[o] == CmpResItem::Good) continue;
		for( int t = 0; t < Config::get_number_of_cols(); ++t ) {
			if ( (res[t] == CmpResItem::Good) ||
			     (res[t] == CmpResItem::Has) ) continue;
			if (other.getItem(o) == getItem(t)) {
				res[t] = CmpResItem::Has;
				break;
			}
		}
	}

	std::sort(res.begin(), res.end(), std::greater<CmpResItem>());
	return res;
}

std::ostream& operator<<(std::ostream &os, const Line::CmpRes &res)
{
	for (auto x: res) {
		switch(x) {
			case Line::CmpResItem::Bad:
				os << "x ";
				break;
			case Line::CmpResItem::Has:
				os << "O ";
				break;
			case Line::CmpResItem::Good:
				os << "# ";
				break;
		}
	}
	return os;
}