#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "div.hpp"

TEST(PowTest, numChildren_BlankConstructor){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
  
	test = new Div();
	EXPECT_EQ(test->number_of_children(), 0);

	delete test, x, y;
}

TEST(PowTest, numChildren_typicalConstructor){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(4); 
	y = new Op(8);
	test = new Div(x, y);
	EXPECT_EQ(test->number_of_children(), 2);

	delete test, x, y;
}

TEST(PowTest, getChild_noChildren){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	test = new Div();
	EXPECT_EQ(test->get_child(0), nullptr); 

	delete test, x, y;
}

TEST(PowTest, getChild_twoChildren){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(4);
	y = new Op(8);
	test = new Div(x, y);
	EXPECT_EQ(test->get_child(0), x); 
	EXPECT_EQ(test->get_child(1), y); 
	
	EXPECT_EQ(test->get_child(5), nullptr);
	EXPECT_EQ(test->get_child(-1), nullptr);

	delete test, x, y;
}

TEST(PowTest, getChild_twoChildren_accessingChildren){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(4);
	y = new Op(8);
	test = new Div(x, y);
	EXPECT_EQ(test->get_child(0)->stringify(), "4"); 
	EXPECT_EQ(test->get_child(1)->stringify(), "8"); 

	delete test, x, y;
}

#endif
