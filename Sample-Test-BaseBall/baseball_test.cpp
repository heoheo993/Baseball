#include "pch.h"
#include "../BaseBall/baseball.cpp"
class BaseballFixture : public testing::Test
{
public:
	Baseball game;
	void assertillegalArgument(string guessNumber)
	{
		try
		{
			game.guess(guessNumber);
			
			
		}
		catch (exception e)
		{
			FAIL();
		}
	}
};
TEST_F(BaseballFixture, ThrowExceptionWhenInputlength_error)
{
	assertillegalArgument(string("1244"));
}
TEST_F(BaseballFixture, ThrowExceptionWhenInvalicChar)
{
	assertillegalArgument(string("1s3"));
}

TEST_F(BaseballFixture, ThrowExceptionWhenDuplicatedChar)
{
	assertillegalArgument(string("141"));
}