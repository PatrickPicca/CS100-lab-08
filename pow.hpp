#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <math.h>
#include "iostream"
#include "sstream"
#include <iomanip>
#include <string>
#include "visitor.hpp"
using namespace std;

class Pow : public Base {
    private:
        Base* Base1;
        Base* Base2;
    public:
	Pow(): Base1(0), Base2(0) {}
	Pow(Base* theBase1) : Base1(theBase1), Base2(0) {}
	Pow(Base* theBase1, Base* theBase2) : Base1(theBase1), Base2(theBase2) {}

    double evaluate(){
	if (Base1 && Base2) 
	{ 
		return pow(Base1->evaluate(), Base2->evaluate());
	}
        else if (Base1 && !Base2) 
	{ 
		return Base1->evaluate(); 
	}
        else 
	{ 
		return 1.0; 
	}
    }

    string stringify() {
	string answer;
	ostringstream ss;
	ss << setprecision(3)<< showpoint << 1.00;
        if (Base1 && Base2) 
	{ 
		answer = "(" + Base1->stringify() +  " ** " +  Base2->stringify() + ")";
	}
        else if (Base1 && !Base2) 
	{ 
		answer = "("  + Base1->stringify() + " ** " + ss.str() + ")";
	}
        else 
	{ 
		answer = "(" + ss.str() + " ** " + ss.str() + ")"; 
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
        if (index == 0) visitor->visit_pow_begin(this);
        if (index == 1) visitor->visit_pow_middle((this));
        if (index == 2) visitor->visit_pow_end(this);
    }
};

#endif
