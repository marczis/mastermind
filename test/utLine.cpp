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
	CPPUNIT_TEST ( test1Good );
	CPPUNIT_TEST ( test1Has );
	CPPUNIT_TEST_SUITE_END();

	void testCreate();
	void testNotEnoughNumbers();
	void testCompEq();
	void testAllBad();
	void test1Good();
	void test1Has();

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
	//You may think that it would be better to have a real
	//class for CmpRes, and have == operator, BUT, in the real
	//game logic I don't need that, and I'm keen not to introduce
	//extra code for unit testing. Alto I could extend that class,
	//but than I don't test the original code again... taff decision.
	//Wondering if we agree about these things.
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

void utLine::test1Good()
{
	Line::CmpRes x = Line("1 2 3 4").compare(Line("5 2 7 8"));
	Line::CmpRes y = {
					  Line::CmpResItem::Bad //This is intentional
					 ,Line::CmpResItem::Bad  //we don't want to tell
					 ,Line::CmpResItem::Bad  //at which position we have
					 ,Line::CmpResItem::Good //the good. So result has to be sorted
					 };
	CPPUNIT_ASSERT( x == y );
}

void utLine::test1Has()
{
	Line::CmpRes x = Line("1 2 1 1").compare(Line("0 1 0 0"));
	Line::CmpRes y = {
					  Line::CmpResItem::Bad
					 ,Line::CmpResItem::Bad
					 ,Line::CmpResItem::Bad
					 ,Line::CmpResItem::Has
					 };
	CPPUNIT_ASSERT( x == y );
}
CPPUNIT_TEST_SUITE_REGISTRATION( utLine );