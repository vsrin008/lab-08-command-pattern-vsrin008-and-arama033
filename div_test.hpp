#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"
#include "div.hpp"


TEST(DivTest, DividePositive) {
   Op* num1 = new Op(10);
   Op* num2 = new Op(5);
   Div* test = new Div(num1, num2);
   EXPECT_EQ(test->evaluate(), 2);
   EXPECT_EQ(test->stringify(), "10.000000 / 5.000000");
}


TEST(DivTest, MultiplyZero) {
   Op* num1 =new Op(0);
   Op* num2 = new Op(12);
   Div* test = new Div(num1, num2);
   EXPECT_EQ(test->evaluate(), 0);
   EXPECT_EQ(test->stringify(), "0.000000 / 12.000000");

}


TEST(DivTest, MulitplyNegative) {
   Op* num1 =new Op(-5);
   Op* num2 = new Op(1);
   Div* test = new Div(num1, num2);
   EXPECT_EQ(test->evaluate(), -5);
   EXPECT_EQ(test->stringify(), "-5.000000 / 1.000000");

}


TEST(DivTest, DivideDecimal) {
   Op* num1 =new Op(5);
   Op* num2 = new Op(10);
   Div* test = new Div(num1, num2);
   EXPECT_EQ(test->evaluate(), 0.5);
   EXPECT_EQ(test->stringify(), "5.000000 / 10.000000");

}



TEST(DivTest, Indeterminate) {
   Op* num1 =new Op(5);
   Op* num2 = new Op(0);
   Div* test = new Div(num1, num2);
   EXPECT_EQ(test->evaluate(), 0);
   EXPECT_EQ(test->stringify(), "5.000000 / 0.000000");


}


TEST(DivTest, DivNumberOfChildren) {
	Op* num1 = new Op(6);
	Op* num2 = new Op(3);
	Div* test = new Div(num1,num2);
	EXPECT_EQ(test->number_of_children(), 2);


}


TEST(DivTest, DivGetChild) {
	Op* num1 = new Op(6);
	Op* num2 = new Op(3);
	Div* test = new Div(num1,num2);
	EXPECT_EQ(test->get_child(0), num1);
	EXPECT_EQ(test->get_child(1), num2);


}

#endif //__Div_TEST_HPP__


