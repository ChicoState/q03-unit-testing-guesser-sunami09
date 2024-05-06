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
	ASSERT_TRUE(myguess.match("acDfgR"));
}
TEST(GuesserTest, perfect_mixed_character_match){
	Guesser myguess = Guesser("ac#$%@#dfgr");
	ASSERT_TRUE(myguess.match("ac#$%@#dfgr"));
}
TEST(GuesserTest, perfect_alphabet_lowercase_character_not_match){
	Guesser myguess = Guesser("afgr456f");
	ASSERT_FALSE(myguess.match("acdfgr"));
}
TEST(GuesserTest, perfect_alphabet_mixedcase_character_not_match){
	Guesser myguess = Guesser("acDfgR");
	ASSERT_FALSE(myguess.match("acdfgR2323d"));
}
TEST(GuesserTest, perfect_mixed_character_not_match){
	Guesser myguess = Guesser("ac#$%@#dfgr");
	ASSERT_FALSE(myguess.match("ac#$%@#dfgR"));
}
TEST(GuesserTest, char_32_not_match){
	Guesser myguess = Guesser("ac#$%@#dfgrsdfghjhgfdsdfghgfdsderftgbvcxsdfgbvcxsdfgbvcxdcfvgb");
	ASSERT_FALSE(myguess.match("ac#$%@#dfgRsdcfvcxcvbvcscvbvcxz"));
}
TEST(GuesserTest, char_32_match){
	Guesser myguess = Guesser("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	ASSERT_TRUE(myguess.match("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
}


TEST(GuesserTest, initial_guess_remaining){
	Guesser myguess = Guesser("ac#$%@#dfgr");
	ASSERT_EQ(3, myguess.remaining());
}

TEST(GuesserTest, guessed_once_remaining){
	Guesser myguess = Guesser("ac#$%@#dfgr");
	myguess.match("ac#$%@#df");
	ASSERT_EQ(2, myguess.remaining());
}
TEST(GuesserTest, guessed_twice_remaining){
	Guesser myguess = Guesser("ac#$%@#dfgr");
	myguess.match("ac#$%@#df");
	myguess.match("ac#$%@#dfg");
	ASSERT_EQ(1, myguess.remaining());
}
TEST(GuesserTest, guessed_thrice_remaining){
	Guesser myguess = Guesser("ac#$%@#dfgr");
	myguess.match("ac#$%@#df");
	myguess.match("ac#$%@#dfg");
	myguess.match("ac#$%@#dfgrf");
	ASSERT_EQ(0, myguess.remaining());
}
TEST(GuesserTest, guessed_once_locked_remaining){
	Guesser myguess = Guesser("ac#$%@#dfgr");
	myguess.match("ac#$f");
	ASSERT_EQ(0, myguess.remaining());
}
TEST(GuesserTest, guessed_twice_locked_remaining){
	Guesser myguess = Guesser("ac#$%@#dfgr");
	myguess.match("ac#$%@#df");
	myguess.match("ac#$f");
	ASSERT_EQ(0, myguess.remaining());
}
TEST(GuesserTest, guessed_thrice_locked_remaining){
	Guesser myguess = Guesser("ac#$%@#dfgr");
	myguess.match("ac#$%@#df");
	myguess.match("ac#$%@#dfg");
	myguess.match("ac#$f");
	ASSERT_EQ(0, myguess.remaining());
}

TEST(GuesserTest, guessed_once_set_remaining_to_initial){
	Guesser myguess = Guesser("ac#$%@#dfgr");
	myguess.match("ac#$%@#dfgr");
	
	ASSERT_EQ(3, myguess.remaining());
}
TEST(GuesserTest, guessed_twice_set_remaining_to_initial){
	Guesser myguess = Guesser("ac#$%@#dfgr");
	myguess.match("ac#$%@#df");
	myguess.match("ac#$%@#dfgr");
	ASSERT_EQ(3, myguess.remaining());
}
TEST(GuesserTest, guessed_thrice_set_remaining_to_initial){
	Guesser myguess = Guesser("ac#$%@#dfgr");
	myguess.match("ac#$%@#df");
	myguess.match("ac#$%@#dfg");
	myguess.match("ac#$%@#dfgr");
	ASSERT_EQ(3, myguess.remaining());
}


TEST(GuesserTest, distance_zero){
	Guesser myguess = Guesser("guess");
	myguess.match("guess");
	ASSERT_EQ(0, myguess.get_distance());
}

TEST(GuesserTest, distance_one_space){
	Guesser myguess = Guesser("guess");
	myguess.match("guess ");
	ASSERT_EQ(1, myguess.get_distance());
}

TEST(GuesserTest, distance_two_uppercase_space){
	Guesser myguess = Guesser("guess");
	myguess.match("guesS ");
	ASSERT_EQ(2, myguess.get_distance());
}

TEST(GuesserTest, distance_secret_size_maximum){
	Guesser myguess = Guesser("guess");
	myguess.match("guessguessguessguessguess");
	ASSERT_EQ(5, myguess.get_distance());
}

TEST(GuesserTest, distance_secret_size_maximum_reverse){
	Guesser myguess = Guesser("guessguessguessguessguess");
	myguess.match("guess");
	ASSERT_EQ(20, myguess.get_distance());
}
TEST(GuesserTest, Distance_EqualLength) {
    Guesser guesser("password");
    guesser.match("passw0rd");
    ASSERT_EQ(1, guesser.get_distance());  // 'o' and '0' are different.
}
TEST(GuesserTest, Distance_ShorterGuess) {
    Guesser guesser("password123");
    guesser.match("password");
    ASSERT_EQ(3, guesser.get_distance());  // Missing "123"
}

TEST(GuesserTest, distance_locked){
	Guesser myguess = Guesser("guess");
	myguess.match("guessguessguessguessguess");
	ASSERT_FALSE(myguess.match("guess"));
}

TEST(GuesserTest, distance_locked_zero){
	Guesser myguess = Guesser("guess");
	myguess.match("guessguessguessguessguess");
	ASSERT_EQ(0, myguess.remaining());
}