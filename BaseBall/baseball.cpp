#include <stdexcept>

using namespace std;


struct GuessResult
{
	bool solved;
	int strikes;
	int balls;
};
class Baseball
{

private:
	string question;
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
	int getStrikeNum(string guessNumber)
	{
		int StrikeNum = 0;
		for (int i = 0; i < 3; i++)
		{
			if (guessNumber[i] == question[i])
				StrikeNum++;
		}
		return StrikeNum;
	}
	int getBallNum(string guessNumber)
	{
		int ballNum = 0;
		for (char guess_ch : guessNumber){
			for(char ques_ch : question){
				if (guess_ch == ques_ch)
					ballNum++;
			}
		}
		ballNum -= getStrikeNum(guessNumber);
		return ballNum;
	}
	bool isSolved(GuessResult result)
	{
		if (result.strikes == 3)
			return true;
		return false;
	}

public:
	explicit Baseball(const string& question): question(question){
		
	}
	
	GuessResult guess(const string& guessNumber)
	{
		assertArgment(guessNumber);

		GuessResult result = { false,0,0 };
		result.strikes = getStrikeNum(guessNumber);
		result.balls = getBallNum(guessNumber);
		result.solved = isSolved(result);

		return result;
	}
};

