#ifndef __DIV_HPP__
#define __DIV_HPP__
#include "base.hpp"
#include <string>
#include "iostream"
#include "sstream"
#include <iomanip>
#include "visitor.hpp"
using namespace std;

class Div : public Base {
    private:
         Base* Base1;
         Base* Base2;

    public:
	Div(): Base1(0), Base2(0) {}
	Div(Base* theBase1) : Base1(theBase1), Base2(0) {}
	Div(Base* theBase1, Base* theBase2) : Base1(theBase1), Base2(theBase2) {}

    double evaluate(){
	if(!Base1 && !Base2)
	{ 
		return 1.0;
	} 
        else if(Base1 && !Base2)
	{
		 return Base1->evaluate();
	} 
        else 
	{
		if(Base2->evaluate() == 0)
		{
			return -1; //Divide by 0 error.
		}
		else 
		{
		    return Base1->evaluate() /  Base2->evaluate();
	        }
        }
    }
    string stringify(){
	string answer;
	ostringstream ss;
	ss << setprecision(3)<< showpoint << 1.00;
	if(!Base1 && !Base2) {
		answer = "(" + ss.str() + " / " + ss.str() + ")";
	}
        else if(Base1 && !Base2) {
		answer =  "(" + Base1->stringify() + " / " + ss.str() + ")";
	}       
	else 
	{
		if(Base2->evaluate() == 0) 
		{
			answer =  "Undefined";
		}
		else 
		{
			answer =  "(" + Base1->stringify() +  " / " +  Base2->stringify() + ")";
	        }
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

void accept(Visitor* visitor, int index){
        if (index == 0) visitor->visit_div_begin(this);
        if (index == 1) visitor->visit_div_middle((this));
        if (index == 2) visitor->visit_div_end(this);
    }

};
#endif
