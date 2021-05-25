#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <math.h>
#include "iostream"
#include "sstream"
#include <iomanip>
#include <string>

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
};

#endif
