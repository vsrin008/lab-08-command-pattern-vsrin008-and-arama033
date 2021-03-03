#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"
#include "div.hpp"
#include "mult.hpp"


TEST(MultTest, MultiplyPositive) {
   Op* num1 =new Op(5);
   Op* num2 = new Op(12);
   Mult* test = new Mult(num1, num2);
   EXPECT_EQ(test->evaluate(), 60);
   EXPECT_EQ(test->stringify(),"5.000000 * 12.000000");
}



TEST(MultTest, MultiplyZero) {
   Op* num1 =new Op(0);
   Op* num2 = new Op(12);
   Mult* test = new Mult(num1, num2);
   EXPECT_EQ(test->evaluate(), 0);
   EXPECT_EQ(test->stringify(),"0.000000 * 12.000000");
}



TEST(MultTest, MultiplyNegative) {
   Op* num1 =new Op(-5);
   Op* num2 = new Op(12);
   Mult* test = new Mult(num1, num2);
   EXPECT_EQ(test->evaluate(), -60);
   EXPECT_EQ(test->stringify(), "-5.000000 * 12.000000");
}


TEST(MultTest, MultiplyDecimal) {
   Op* num1 =new Op(0.5);
   Op* num2 = new Op(12);
   Mult* test = new Mult(num1, num2);
   EXPECT_EQ(test->evaluate(), 6);
   EXPECT_EQ(test->stringify(), "0.500000 * 12.000000");

}


TEST(MultTest, MultiplyTwoNegative) {
   Op* num1 =new Op(-5);
   Op* num2 = new Op(-5);
   Mult* test = new Mult(num1, num2);
   EXPECT_EQ(test->evaluate(), 25);
   EXPECT_EQ(test->stringify(), "-5.000000 * -5.000000");
}


TEST(MultTest, MultiplyAndDivide) {
   Op* num1 =new Op(-5);
   Op* num2 = new Op(-5);
   Op* num3 = new Op(-5);
   Div* num4 = new Div(num2, num3);
   Mult* test = new Mult(num1, num4);
   EXPECT_EQ(test->evaluate(), -5);
   EXPECT_EQ(test->stringify(), "-5.000000 * -5.000000 / -5.000000");
}

TEST(MultTest, multNumberOfChildren) {
	Op* num1 = new Op(2);
	Op* num2 = new Op(3);
	Mult* test = new Mult(num1, num2);
	EXPECT_EQ(test->number_of_children(), 2);
}


TEST(MultTest, multGetChild) {
	Op* num1 = new Op(2);
	Op* num2 = new Op(3);
	Mult* test = new Mult(num1, num2);
	EXPECT_EQ(test->get_child(0), num1);
	EXPECT_EQ(test->get_child(1), num2);
}


#endif //__MULT_TEST_HPP__
