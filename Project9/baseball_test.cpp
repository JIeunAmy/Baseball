#include "gmock/gmock.h"
#include <vector>
#include <string>
#include "baseball.cpp"

using namespace testing;
using std::string;

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmatched) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}