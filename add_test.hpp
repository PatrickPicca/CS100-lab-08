#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"

#include "add.hpp"
#include "op.hpp"

TEST(AddTest, GetLeft) {
      Base *num1 = new Op(0);
      Base *num2 = new Op(1);
      Base *add = new Add(num1, num2);

    EXPECT_EQ(add->get_child(0)->evaluate(), 0);
}


TEST(AddTest, GetRight) {
      Base *num1 = new Op(0);
      Base *num2 = new Op(1);
      Base *add = new Add(num1, num2);

    EXPECT_EQ(add->get_child(1)->evaluate(), 1);
}

TEST(AddTest, NumChildren) {
      Base *num1 = new Op(3);
      Base *num2 = new Op(7);
      Base *add = new Add();
      EXPECT_EQ(add->number_of_children(), 2);	
}

TEST(AddTest, NoChildren) {
      Base *num1 = nullptr;
      Base *num2 = nullptr;
      Base *add = new Add();
      EXPECT_EQ(add->number_of_children(), 2);
}


#endif //__ADD_TEST_HPP__
