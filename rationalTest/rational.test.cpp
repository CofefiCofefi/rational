#include "gtest/gtest.h"
#include "rational.hpp"

TEST(ValueCtor, CorrectlySimplifies) {
	Rational test(4, 8);
	EXPECT_EQ(test.num(), 1);
	EXPECT_EQ(test.den(), 2);

	Rational test2(65, 75);
	EXPECT_EQ(test2.num(), 13);
	EXPECT_EQ(test2.den(), 15);

	Rational test3(2, 8);
	EXPECT_EQ(test3.num(), 1);
	EXPECT_EQ(test3.den(), 4);
}

TEST(ValueCtor, CorrectlyHandelsNegatives) {
	Rational test(-4, -8);
	EXPECT_EQ(test.num(), -1);
	EXPECT_EQ(test.den(), 2);

	Rational test2(65, -75);
	EXPECT_EQ(test2.num(), -13);
	EXPECT_EQ(test2.den(), 15);

	Rational test3(92, -66);
	EXPECT_EQ(test3.num(), -46);
	EXPECT_EQ(test3.den(), 33);

	Rational test4(1, -2);
	EXPECT_EQ(test4.num(), -1);
	EXPECT_EQ(test4.den(), 2);
}

TEST(DefaultCtor, CorrectlyInitlizes) {
	Rational test;
	EXPECT_EQ(test.num(), 0);
	EXPECT_EQ(test.den(), 1);
}

TEST(Setters, Num) {
	Rational test;
	test.num(3);
	EXPECT_EQ(test.num(), 3);
	EXPECT_EQ(test.den(), 1);

	Rational test2(5, 8);
	test2.num(2);
	EXPECT_EQ(test2.num(), 1);
	EXPECT_EQ(test2.den(), 4);

	Rational test3(4, -18);
	test3.num(3);
	EXPECT_EQ(test3.num(), 1);
	EXPECT_EQ(test3.den(), 3);

	Rational test4(-4, 18);
	test4.num(-3);
	EXPECT_EQ(test4.num(), -1);
	EXPECT_EQ(test4.den(), 3);
}

TEST(Setters, Den) {
	Rational test;
	test.den(300);
	EXPECT_EQ(test.num(), 0);
	EXPECT_EQ(test.den(), 1);

	Rational test2(5, 8);
	test2.den(10);
	EXPECT_EQ(test2.num(), 1);
	EXPECT_EQ(test2.den(), 2);

	Rational test3(4, -18);
	test3.den(4);
	EXPECT_EQ(test3.num(), -1);
	EXPECT_EQ(test3.den(), 2);

	Rational test4(-4, 18);
	test4.den(3);
	EXPECT_EQ(test4.num(), -2);
	EXPECT_EQ(test4.den(), 3);

	Rational test5(4, 8);
	try {
		test5.den(0);
		FAIL() << "Allowed den to be set to 0";
	}
	catch (std::domain_error) {
		EXPECT_EQ(test5.num(), 1);
		EXPECT_EQ(test5.den(), 2);
	}
}