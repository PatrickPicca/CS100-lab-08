#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"

#include "sub.hpp"
#include "op.hpp"

TEST(SubTest, GetLeft) {
      Base *num1 = new Op(0);
      Base *num2 = new Op(1);
      Base *sub = new Sub(num1, num2);

    EXPECT_EQ(sub->get_child(0)->evaluate(), 0);
}


TEST(SubTest, GetRight) {
      Base *num1 = new Op(0);
      Base *num2 = new Op(1);
      Base *sub = new Sub(num1, num2);

    EXPECT_EQ(sub->get_child(1)->evaluate(), 1);
}

TEST(SubTest, NumChildren) {
      Base *num1 = new Op(3);
      Base *num2 = new Op(7);
      Base *sub = new Sub();
      EXPECT_EQ(sub->number_of_children(), 2);
}

TEST(SubTest, NoChildren) {
      Base *num1 = nullptr;
      Base *num2 = nullptr;
      Base *sub = new Sub();
      EXPECT_EQ(sub->number_of_children(), 2);
}


#endif //__SUB_TEST_HPP__

