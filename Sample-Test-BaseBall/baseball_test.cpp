#include "pch.h"
#include "../BaseBall/baseball.cpp"
class BaseballFixture : public testing::Test
{
public:
	Baseball game{ "123" };
	void assertillegalArgument(string guessNumber)
	{
		try
		{
			GuessResult result = game.guess(guessNumber);
		}
		catch (exception e)
		{
			FAIL();
		}
	}
};

TEST_F(BaseballFixture, test1)
{
	GuessResult result = game.guess("123");
	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, DISABLED_ThrowExceptionWhenInputlength_error)
{
	assertillegalArgument(string("1244"));
}
TEST_F(BaseballFixture, DISABLED_ThrowExceptionWhenInvalicChar)
{
	assertillegalArgument(string("1s3"));
}

TEST_F(BaseballFixture, DISABLED_ThrowExceptionWhenDuplicatedChar)
{
	assertillegalArgument(string("141"));
}