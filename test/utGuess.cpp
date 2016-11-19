#include <cppunit/extensions/HelperMacros.h>
#include <iostream>

#include "../Guess.h"

class utGuess : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE( utGuess );
	CPPUNIT_TEST ( testValidInput );
	CPPUNIT_TEST_SUITE_END();

	void testValidInput();

public:
	void setUp() {}
	void tearDown() {}

};

void utGuess::testValidInput() 
{
		Guess g("1 2 3 4");
		CPPUNIT_ASSERT( true == false );
}

CPPUNIT_TEST_SUITE_REGISTRATION( utUserInput );