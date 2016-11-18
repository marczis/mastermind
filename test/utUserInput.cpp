#include <cppunit/extensions/HelperMacros.h>

class utUserInput : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE( utUserInput );
	CPPUNIT_TEST ( firsttest );
	CPPUNIT_TEST_SUITE_END();

	void firsttest();

public:
	void setUp() {}
	void tearDown() {}

};

void utUserInput::firsttest() {
		CPPUNIT_ASSERT( true == false );
}

CPPUNIT_TEST_SUITE_REGISTRATION( utUserInput );