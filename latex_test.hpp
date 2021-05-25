#ifndef __LATEX_TEST_HPP__
#define __LATEX_TEST_HPP__

#include "gtest/gtest.h"

#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"

#include "latex.hpp"
#include "iterator.hpp"

TEST(VisitLatextest, basicOp)
{   
    	Base* num[10] = {new Op(0), new Op(1), new Op(2), new Op(3), new Op(4), new Op(5), new Op(6), new Op(7), new Op(8), new Op(9) };

	VisitorLatex* latex = new VisitorLatex();
	std::string expect = "${0}$\n";    
	EXPECT_EQ(latex->PrintLaTeX(num[0]), expect);

	for (auto i : num) delete i;
	delete latex;
}

TEST(VisitLatextest, multipleComposites)
{
    	Base* num[10] = {new Op(0), new Op(1), new Op(2), new Op(3), new Op(4), new Op(5), new Op(6), new Op(7), new Op(8), new Op(9) };

	//Base* a = new Mult(num[2], num[5]);
	Base* b = new Pow(num[5], num[2]);
	//Base* test = new Div(a, b);

	VisitorLatex* latex = new VisitorLatex();
	VisitorLatex* latex2 = new VisitorLatex();
	std::string expect2 = "${({5}^{2})}$\n";
	std::string expect = "${\\frac{({2}\\cdot{5})}{({5}^{2})}}$\n";
	EXPECT_EQ(latex2->PrintLaTeX(b), expect2);
	//EXPECT_EQ(latex->PrintLaTeX(test), expect);

	//for (auto i : num) delete i;
	//delete latex, a, b, test;
}

TEST(VisitLatexTest, fraction)
{
	

}


#endif
