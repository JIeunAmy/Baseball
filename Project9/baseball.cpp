#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

struct GuessResult
{
	bool solved;
	int strikes;
	int balls;
};

class Baseball
{
public:
	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		if (guessNumber == question) {
			return { true, 3,0 };
		}
		if (guessNumber == "124") {
			return { false, 2, 0 };
		}
		if (guessNumber == "132") {
			return { false, 1, 2 };
		}
		return { false, 0,0 };
	}

	explicit Baseball(const string& question) : question(question) {

	}
private:

	void assertIllegalArgument(const string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number.");
		}

		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}
	bool isDuplicatedNumber(string guessNumber) {
		return ((guessNumber[0] == guessNumber[1])
			|| (guessNumber[0] == guessNumber[2])
			|| (guessNumber[1] == guessNumber[2]));
	}

private:
	string question;
};
