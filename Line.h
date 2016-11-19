#ifndef __LINE_H__
#define __LINE_H__

#include <string>
#include <vector>
#include <exception>

#include "config.h"

class Line
{
public:
	enum class Colors { Black = 0, Yellow, Green, Red };
	//using LineItems = std::vector<Colors>;
	typedef std::vector<Colors> LineItems;
	enum class CmpResItem { Bad = 0, Has = 1, Good = 2}; //NOTE: Order does matter !
	typedef std::vector<CmpResItem> CmpRes;

	class WrongInput : public std::exception {};
	

private:
	LineItems items;

public:
	Line(const std::string &line);

	Colors getItem(int i) const;

	CmpRes compare(const Line& other) const;
};

#endif