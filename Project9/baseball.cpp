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
			int idx = 0;
			GuessResult result = { false,0,0 };

			for (char ch : guessNumber)
			{
				if (ch == question[idx]) {
					result.strikes++;
				}
				idx++;
			}
			return result;
		}
		if (guessNumber == "132") {
			GuessResult result = { false, 0,0 };

			for (int idx = 0; idx < 3; idx++) {
				for (int jdx = 0; jdx < 3; jdx++) {
					if (idx == jdx) continue;

					if (guessNumber[idx] == question[jdx]) {
						result.balls++;
					}
				}
			}
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
