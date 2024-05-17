#include "pch.h"
#include "../BaseBall/baseball.cpp"
TEST(BaseballGame, ThrowExceptionWhenInputlength_error) {
	Baseball game;
	EXPECT_THROW(game.guess("123"), length_error);

}