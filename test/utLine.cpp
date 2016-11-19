#include <cppunit/extensions/HelperMacros.h>
#include <iostream>

#include "../Line.h"

class utLine : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE( utLine );
	CPPUNIT_TEST ( testCreate );
	CPPUNIT_TEST ( testNotEnoughNumbers );
	CPPUNIT_TEST ( testCompEq );
	CPPUNIT_TEST ( testAllBad );
	CPPUNIT_TEST_SUITE_END();

	void testCreate();
	void testNotEnoughNumbers();
	void testCompEq();
	void testAllBad();

public:
	void setUp() {}
	void tearDown() {}

};

void utLine::testCreate() 
{
	Line g("1 2 3 4");
	CPPUNIT_ASSERT( g.getItem(0) == Line::Colors(1) );
	CPPUNIT_ASSERT( g.getItem(1) == Line::Colors(2) );
	CPPUNIT_ASSERT( g.getItem(2) == Line::Colors(3) );
	CPPUNIT_ASSERT( g.getItem(3) == Line::Colors(4) );
}

void utLine::testNotEnoughNumbers()
{
	CPPUNIT_ASSERT_THROW(Line g("1 2 3"), Line::WrongInput);
}

void utLine::testCompEq()
{
	Line::CmpRes x = Line("1 2 3 4").compare(Line("1 2 3 4"));
	Line::CmpRes y = {
					  Line::CmpResItem::Good
					 ,Line::CmpResItem::Good
					 ,Line::CmpResItem::Good
					 ,Line::CmpResItem::Good
					 };
	CPPUNIT_ASSERT( x == y );
}

void utLine::testAllBad()
{
	Line::CmpRes x = Line("1 2 3 4").compare(Line("5 6 7 8"));
	Line::CmpRes y = {
					  Line::CmpResItem::Bad
					 ,Line::CmpResItem::Bad
					 ,Line::CmpResItem::Bad
					 ,Line::CmpResItem::Bad
					 };
	CPPUNIT_ASSERT( x == y );
}


CPPUNIT_TEST_SUITE_REGISTRATION( utLine );