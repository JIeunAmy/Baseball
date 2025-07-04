#include "gmock/gmock.h"
#include <vector>
#include <string>
#include "baseball.cpp"

using namespace testing;
using std::string;

class BaseballFixture : public Test
{
public:
	Baseball game{"123"};

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

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
	
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, ReturnTwoStrikesZeroBall) {
	
	GuessResult result = game.guess("124");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, ReturnOneStrikesTwoBall) {
	
	GuessResult result = game.guess("132");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(1, result.strikes);
	EXPECT_EQ(2, result.balls);
}

TEST_F(BaseballFixture, ReturnZeroStrikeOneBall) {
	
	GuessResult result = game.guess("819");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(0, result.strikes);
	EXPECT_EQ(1, result.balls);
}
