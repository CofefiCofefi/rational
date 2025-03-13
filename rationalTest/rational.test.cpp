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
	EXPECT_EQ(test.num(), 1);
	EXPECT_EQ(test.den(), 2);

	Rational test2(65, -75);
	EXPECT_EQ(test2.num(), -13);
	EXPECT_EQ(test2.den(), 15);

	Rational test3(92, -66);
	EXPECT_EQ(test3.num(), -46);
	EXPECT_EQ(test3.den(), 33);

	Rational test4(-1, 2);
	EXPECT_EQ(test4.num(), -1);
	EXPECT_EQ(test4.den(), 2);

	Rational test5(-5, 24);
	EXPECT_EQ(test5.num(), -5);
	EXPECT_EQ(test5.den(), 24);
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
};

TEST(MathOps, Plus) {
	Rational test1{ 3, 4 };
	Rational test2{ 5, 6 };
	Rational test3;

	test3 = test1 + test2;

	EXPECT_EQ(test3.num(), 19);
	EXPECT_EQ(test3.den(), 12);

	const Rational test4{ -1, 6 };
	const Rational test5{ 3, 8 };
	Rational test6;

	test6 = test4 + test5;

	EXPECT_EQ(test6.num(), 5);
	EXPECT_EQ(test6.den(), 24);
};

TEST(MathOps, Minus) {
	Rational test1{ 5, 6 };
	Rational test2{ 1, 9 };
	Rational test3;

	test3 = test1 - test2;

	EXPECT_EQ(test3.num(), 13);
	EXPECT_EQ(test3.den(), 18);

	const Rational test4{ -1, 6 };
	const Rational test5{ 3, 8 };
	Rational test6;

	test6 = test4 - test5;

	EXPECT_EQ(test6.num(), -13);
	EXPECT_EQ(test6.den(), 24);

	Rational test7{ 3, 4 };
	Rational test8{ 5, 6 };
	Rational test9;

	test9 = test7 - test8;

	EXPECT_EQ(test9.num(), -1);
	EXPECT_EQ(test9.den(), 12);
};

TEST(MathOps, Multiply) {
	Rational test1{ 3, 4 };
	Rational test2{ 5, 6 };
	Rational test3;

	test3 = test1 * test2;

	EXPECT_EQ(test3.num(), 5);
	EXPECT_EQ(test3.den(), 8);
};

TEST(MathOps, Divide) {
	Rational test1{ 3, 8 };
	Rational test2{ 4, 9 };
	Rational test3;

	test3 = test1 / test2;

	EXPECT_EQ(test3.num(), 27);
	EXPECT_EQ(test3.den(), 32);

	try {
		Rational test4{ 3, 8 };
		Rational test5{ 0, 9 };
		Rational test6;

		test6 = test4 / test5;
	}
	catch (std::domain_error) {}
};

TEST(MathOps, UnaryMinus) {
	Rational test1{ 3, 4 };
	Rational test2;

	test2 = -test1;

	EXPECT_EQ(test2.num(), -3);
	EXPECT_EQ(test2.den(), 4);

	test2 = -test2;
	EXPECT_EQ(test2.num(), 3);
	EXPECT_EQ(test2.den(), 4);
};

TEST(MathAssignOps, PlusEqual) {
	Rational test1{ 1, 4 };
	Rational test2{ 1, 3 };

	test1 += test2;

	EXPECT_EQ(test1.num(), 7);
	EXPECT_EQ(test1.den(), 12);
};

TEST(MathAssignOps, MultiplyEqual) {
	Rational test1{ 3, 4 };
	Rational test2{ 1, 3 };

	test1 *= test2;

	EXPECT_EQ(test1.num(), 1);
	EXPECT_EQ(test1.den(), 4);
};

TEST(MathAssignOps, MinusEqual) {
	Rational test1{ 3, 4 };
	Rational test2{ 1, 3 };

	test1 -= test2;

	EXPECT_EQ(test1.num(), 5);
	EXPECT_EQ(test1.den(), 12);
};

TEST(MathAssignOps, DivideEqual) {
	Rational test1{ 3, 4 };
	Rational test2{ 1, 3 };

	test1 /= test2;

	EXPECT_EQ(test1.num(), 9);
	EXPECT_EQ(test1.den(), 4);

	try {
		Rational test4{ 3, 8 };
		Rational test5{ 0, 9 };
		test4 /= test5;
	}
	catch (std::domain_error) {}
};

TEST(MathAssignOps, PrePlusPlus) {
	Rational test1{ 7, 12 };

	++test1;

	EXPECT_EQ(test1.num(), 19);
	EXPECT_EQ(test1.den(), 12);
};

TEST(MathAssignOps, PreMinusMinus) {
	Rational test1{ 19, 12 };

	--test1;

	EXPECT_EQ(test1.num(), 7);
	EXPECT_EQ(test1.den(), 12);
};

TEST(MathAssignOps, PostPlusPlus) {
	Rational test1{ 7, 12 };

	Rational result = test1++;

	EXPECT_EQ(result.num(), 7);
	EXPECT_EQ(result.den(), 12);

	EXPECT_EQ(test1.num(), 19);
	EXPECT_EQ(test1.den(), 12);
};

TEST(MathAssignOps, PostMinusMinus) {
	Rational test1{ 19, 12 };

	Rational result = test1--;

	EXPECT_EQ(result.num(), 19);
	EXPECT_EQ(result.den(), 12);

	EXPECT_EQ(test1.num(), 7);
	EXPECT_EQ(test1.den(), 12);
};

TEST(CompareOp, EqualEqual) {
	Rational test1{ 1, 2 };
	Rational test2{ 2, 5 };

	EXPECT_EQ(test1 == test2, false);

	Rational test3{ 1, 2 };
	Rational test4{ 1, 2 };

	EXPECT_EQ(test3 == test4, true);
};

TEST(CompareOp, NotEqual) {
	Rational test1{ 1, 2 };
	Rational test2{ 2, 5 };

	EXPECT_EQ(test1 != test2, true);

	Rational test3{ 1, 2 };
	Rational test4{ 1, 2 };

	EXPECT_EQ(test3 != test4, false);
};

TEST(CompareOp, LessThan) {
	Rational test1{ 1, 2 };
	Rational test2{ 2, 5 };

	EXPECT_EQ(test1 < test2, false);

	Rational test3{ 1, 2 };
	Rational test4{ 1, 2 };

	EXPECT_EQ(test3 < test4, false);

	Rational test5{ 3, 8 };
	Rational test6{ 5, 12 };

	EXPECT_EQ(test5 < test6, true);

	Rational test7{ 3, 8 };
	Rational test8{ 5, -12 };

	EXPECT_EQ(test7 < test8, false);

	Rational test9{ 3, 8 };
	Rational test10{ 0, 12 };

	EXPECT_EQ(test9 < test10, false);
};

TEST(CompareOp, GreaterThanOrEqualTo) {
	Rational test1{ 1, 2 };
	Rational test2{ 2, 5 };

	EXPECT_EQ(test1 >= test2, true);

	Rational test3{ 1, 2 };
	Rational test4{ 1, 2 };

	EXPECT_EQ(test3 >= test4, true);

	Rational test5{ 3, 8 };
	Rational test6{ 5, 12 };

	EXPECT_EQ(test5 >= test6, false);

	Rational test7{ 3, 8 };
	Rational test8{ 5, -12 };

	EXPECT_EQ(test7 >= test8, true);

	Rational test9{ 3, 8 };
	Rational test10{ 0, 12 };

	EXPECT_EQ(test9 >= test10, true);
};

TEST(CompareOp, GreaterThan) {
	Rational test1{ 1, 2 };
	Rational test2{ 2, 5 };

	EXPECT_EQ(test1 > test2, true);

	Rational test3{ 1, 2 };
	Rational test4{ 1, 2 };

	EXPECT_EQ(test3 > test4, false);

	Rational test5{ 3, 8 };
	Rational test6{ 5, 12 };

	EXPECT_EQ(test5 > test6, false);

	Rational test7{ 3, 8 };
	Rational test8{ 5, -12 };

	EXPECT_EQ(test7 > test8, true);

	Rational test9{ 3, 8 };
	Rational test10{ 0, 12 };

	EXPECT_EQ(test9 > test10, true);
};

TEST(CompareOp, LessThanOrEqualTo) {
	Rational test1{ 1, 2 };
	Rational test2{ 2, 5 };

	EXPECT_EQ(test1 <= test2, false);

	Rational test3{ 1, 2 };
	Rational test4{ 1, 2 };

	EXPECT_EQ(test3 <= test4, true);

	Rational test5{ 3, 8 };
	Rational test6{ 5, 12 };

	EXPECT_EQ(test5 <= test6, true);

	Rational test7{ 3, 8 };
	Rational test8{ 5, -12 };

	EXPECT_EQ(test7 <= test8, false);

	Rational test9{ 3, 8 };
	Rational test10{ 0, 12 };

	EXPECT_EQ(test9 <= test10, false);
};