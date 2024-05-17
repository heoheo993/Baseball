#include <stdexcept>

using namespace std;
void assertArgment(const std::string& guessNumber);
class Baseball
{
private:
	bool isDuplicatedChar(const string guessNumber)
	{
		if (guessNumber[0] == guessNumber[1] ||
			guessNumber[1] == guessNumber[2] ||
			guessNumber[2] == guessNumber[0])
			return true;
		return false;
	}

	void assertArgment(const std::string guessNumber)
	{
		if (guessNumber.length() != 3)
		{
			throw length_error("Must be three letters.");
		}
		for (char ch : guessNumber)
		{
			if (ch >= '0' && ch <= '9')
				continue;

			throw invalid_argument("Must be number");
		}
		if (isDuplicatedChar(guessNumber)) {
			throw invalid_argument("Duplicated number");
		}
	}

public:
	void guess(const string& guessNumber)
	{
		assertArgment(guessNumber);
	}
};

