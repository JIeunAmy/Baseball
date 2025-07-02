#include "gmock/gmock.h"
#include <vector>
#include <string>
#include "baseball.cpp"

using namespace testing;
using std::string;

class BaseballFixture : public Test
{
public:
	Baseball game;

	void assertIllegalArgument(string guessNumber) {

		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e) {
			// PASS
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument("12");	
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}
