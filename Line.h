#ifndef __LINE_H__
#define __LINE_H__

#include <string>
#include <vector>
#include <exception>
#include <random>
#include "config.h"

class Line
{
public:
	enum class Colors { Black = 0, Yellow, Green, Red, Purple, Blue, Pink, Cyan, Count };
	//using LineItems = std::vector<Colors>;
	typedef std::vector<Colors> LineItems;
	enum class CmpResItem { Good = 0, Has = 1, Bad = 2}; //NOTE: Order does matter !
	typedef std::vector<CmpResItem> CmpRes;

	class WrongInput : public std::exception {};
	

private:
	LineItems items;
	std::random_device rd;
	std::mt19937 random;

public:
	Line();
	Line(const std::string &line);
	Line(const Line&& other);

	void setup(const std::string &line);
	void setup_random();

	Colors getItem(int i) const;

	CmpRes compare(const Line& other) const;
};

std::ostream& operator<<(std::ostream &os, const Line::CmpRes &res);

#endif