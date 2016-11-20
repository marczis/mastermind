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
	CPPUNIT_TEST ( testRest );
	CPPUNIT_TEST_SUITE_END();

	void testCreate();
	void testNotEnoughNumbers();

	//Little helper to make next ones easier
	void test(const std::string &a, const std::string &b, Line::CmpRes res);
	//And this one, because I'm more than lazy.
	typedef Line::CmpResItem X;

	void testCompEq();
	void testAllBad();
	void test1Good();
	void test1Has();
	void testRest();

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

void utLine::test(const std::string &a, const std::string &b, Line::CmpRes res)
{
	Line::CmpRes x = Line(a).compare(Line(b));
	//You may think that it would be better to have a real
	//class for CmpRes, and have == operator, BUT, in the real
	//game logic I don't need that, and I'm keen not to introduce
	//extra code for unit testing. Alto I could extend that class,
	//but than I don't test the original code again... taff decision.
	//Wondering if we agree about these things.
	CPPUNIT_ASSERT( x == res );
}

void utLine::testCompEq()
{
	test("1 2 3 4", "1 2 3 4", {X::Good, X::Good, X::Good, X::Good});
}

void utLine::testAllBad()
{
	test("1 2 3 4", "5 6 7 8", {X::Bad, X::Bad, X::Bad, X::Bad});
}

void utLine::test1Good()
{
	test("1 2 3 4", "5 2 7 8", {X::Good, X::Bad, X::Bad, X::Bad});
}

void utLine::test1Has()
{
	test("1 2 1 1", "0 1 0 0", {X::Has, X::Bad, X::Bad, X::Bad});
}

void utLine::testRest()
{
	test("0 0 0 4", "1 2 3 0", {X::Has, X::Bad, X::Bad, X::Bad});
	test("0 0 4 4", "1 2 0 0", {X::Has, X::Has, X::Bad, X::Bad});
	test("0 4 4 4", "1 0 0 0", {X::Has, X::Bad, X::Bad, X::Bad});
}

CPPUNIT_TEST_SUITE_REGISTRATION( utLine );