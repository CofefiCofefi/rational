#include "gtest/gtest.h"
#include "rational.hpp"

TEST(ValueCtor, CorrectlySimplifies) {
	Rational test(4, 8);
	EXPECT_EQ(test.den(), 2);
	EXPECT_EQ(test.num(), 1);
	Rational test2(65, 75);
	EXPECT_EQ(test2.den(), 15);
	EXPECT_EQ(test2.num(), 13);
}