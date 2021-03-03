#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"
#include "add.hpp"
#include "op.hpp"


TEST(AddTest, Addtest1) {


   Op* var1 = new Op(3);


   Op* var2 = new Op(28);


   Add* test = new Add(var1, var2);


   EXPECT_EQ(test->evaluate(), 31);


   EXPECT_EQ(test->stringify(), "3.000000 + 28.000000");


}




TEST(AddTest, Addtest2) {


   Op* var1 = new Op(0);


   Op* var2 = new Op(0);


   Add* test = new Add(var1, var2);


   EXPECT_EQ(test->evaluate(), 0);


   EXPECT_EQ(test->stringify(), "0.000000 + 0.000000");


}



TEST(AddTest, Addtest3) {


   Op* var1 = new Op(-5);


   Op* var2 = new Op(-6);


   Add* test = new Add(var1, var2);


   EXPECT_EQ(test->evaluate(), -11);


   EXPECT_EQ(test->stringify(), "-5.000000 + -6.000000");


}




TEST(AddTest, Addtest4) {


   Op* var1 = new Op(-5);


   Op* var2 = new Op(10);


   Add* test = new Add(var1, var2);


   EXPECT_EQ(test->evaluate(), 5);


   EXPECT_EQ(test->stringify(), "-5.000000 + 10.000000");


}




TEST(AddTest, AddNumberOfChildren) {


	Op* var1 = new Op(2);


	Op* var2 = new Op(3);


	Add* test = new Add(var1, var2);


	EXPECT_EQ(test->number_of_children(), 2);


}



TEST(AddTest, AddGetChild) {


	Op* var1 = new Op(2);


	Op* var2 = new Op(3);


	Add* test = new Add(var1, var2);


	EXPECT_EQ(test->get_child(0), var1);


	EXPECT_EQ(test->get_child(1), var2);


}


#endif //__ADD_TEST_HPP__


