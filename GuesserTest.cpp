/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

/* Example test
TEST(GuesserTest, smoke_test)
{
    ASSERT_EQ( 1+1, 2 );
}
*/

TEST(GuesserTest, empty_string_match){
	Guesser myguess = Guesser("");
	ASSERT_TRUE(myguess.match(""));
}
TEST(GuesserTest, single_space_string_not_match){
	Guesser myguess = Guesser("");
	ASSERT_FALSE(myguess.match(" "));
}

TEST(GuesserTest, perfect_alphabet_lowercase_character_match){
	Guesser myguess = Guesser("acdfgr");
	ASSERT_TRUE(myguess.match("acdfgr"));
}
TEST(GuesserTest, perfect_alphabet_mixedcase_character_match){
	Guesser myguess = Guesser("acDfgR");
	ASSERT_TRUE(myguess.match("acdfgR"));
}
TEST(GuesserTest, perfect_mixed_character_match){
	Guesser myguess = Guesser("ac#$%@#dfgr");
	ASSERT_TRUE(myguess.match("ac#$%@#dfgr"));
}
TEST(GuesserTest, perfect_alphabet_lowercase_character_not_match){
	Guesser myguess = Guesser("afgr456f");
	ASSERT_TRUE(myguess.match("acdfgr"));
}
TEST(GuesserTest, perfect_alphabet_mixedcase_character_not_match){
	Guesser myguess = Guesser("acDfgR");
	ASSERT_TRUE(myguess.match("acdfgR2323d"));
}
TEST(GuesserTest, perfect_mixed_character_not_match){
	Guesser myguess = Guesser("ac#$%@#dfgr");
	ASSERT_TRUE(myguess.match("ac#$%@#dfgR"));
}