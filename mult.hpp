#ifndef __MULT_HPP__
#define __MULT_HPP__
#include "base.hpp"
#include <string>
#include "iostream"
#include "sstream"
#include <iomanip>

using namespace std;

class Mult : public Base {
    private:
         Base* Base1;
         Base* Base2;
    public:
	Mult(): Base1(0), Base2(0) {}
	Mult(Base* theBase1) : Base1(theBase1), Base2(0) {}
	Mult(Base* theBase1, Base* theBase2) : Base1(theBase1), Base2(theBase2) {}

    double evaluate(){
	if (!Base1 && !Base2) 
	{
		return 0.00;
	}
	else if (Base1 && !Base2)
	{
		return Base1->evaluate();
	}
	else
	{
		return Base1->evaluate() * Base2->evaluate();
	}
    }

    string stringify() {
	string answer;
	ostringstream ss;
	ostringstream ss2;
	ss << setprecision(3)<< showpoint << 1.00;
	ss2 << setprecision(3)<< showpoint << 0.00;
	if(!Base1 && !Base2)
	{
		answer =  "(" + ss2.str() + " * " + ss.str() + ")";
	}
	else if(Base1 && !Base2) 
	{
		answer =  "(" + Base1->stringify() + " * " + ss.str() + ")";
	}
	else 
	{
		answer =  "(" + Base1->stringify() + " * " + Base2->stringify() + ")";
	}
	return answer;
    }


virtual int number_of_children() {
        return 2;
    }
virtual Base* get_child(int i) {
        if (i == 0){ 
                 return Base1;
        }
        if (i == 1){ 
                 return Base2;
        }
        else { 
                 return nullptr;
        }
    }
virtual void accept(Visitor* visitor, int index){
        if (index == 0) visitor->visit_add_begin(this);
        if (index == 1) visitor->visit_add_middle((this));
        if (index == 2) visitor->visit_add_end(this);
    }

};
#endif
