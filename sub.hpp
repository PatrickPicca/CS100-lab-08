#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include "iostream"
#include "sstream"
#include <iomanip>
#include <string>

using namespace std;

class Sub : public Base {
    private:
	Base* Base1;
        Base* Base2;
    public:
	Sub(): Base1(0), Base2(0) {}
	Sub(Base* theBase1) : Base1(theBase1), Base2(0) {}
	Sub(Base* theBase1, Base* theBase2) : Base1(theBase1), Base2(theBase2) {}

    double evaluate() {
        if (Base1 && Base2) 
	{ 
		return Base1->evaluate() - Base2->evaluate();
	}
        else if (Base1 && !Base2) 
	{ 
		return Base1->evaluate(); 
	}
       	else 
	{ 
		return 0.0; 
	}
    }
    string stringify() {
	string answer;
	ostringstream ss;
	ss << setprecision(3)<< showpoint << 0.00;
        if (Base1 && Base2) 
	{ 
		answer =  "(" + Base1->stringify() +  " - " + Base2->stringify() + ")";
	}
        else if (Base1 && !Base2) 
	{ 
		answer =  "(" + Base1->stringify() + " - " + ss.str() + ")";
	}
        else 
	{ 
		answer =  "(" + ss.str() + " - " + ss.str() + ")"; 
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
