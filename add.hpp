#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"
#include "iostream"
#include "sstream"
#include <iomanip>
#include <string>

using namespace std;

class Add : public Base {
    private:
	 Base* Base1;	
	 Base* Base2;
    public:
	Add(): Base1(0), Base2(0) {}
	Add(Base* theBase1) : Base1(theBase1), Base2(0) {}
	Add(Base* theBase1, Base* theBase2) : Base1(theBase1), Base2(theBase2) {} 

    double evaluate()
    {
	if (Base1 && Base2) 
	{ 
		return Base1->evaluate() + Base2->evaluate();
	}	
        else if (Base1 && !Base2) 
	{ 
		return Base1->evaluate(); 
	}
	else 
        { 
		return  0.0; 
        }
    }	

    string stringify()
    {
	string answer;
	ostringstream ss;
	ss << setprecision(3)<< showpoint << 0.00;
	if (Base1 && Base2) 
	{ 
		answer =  "(" + Base1->stringify() +  " + " + Base2->stringify() + ")";
	}
	else if (Base1 && !Base2) 
	{ 
		answer =  "(" + Base1->stringify() + " + " + ss.str() + ")";
	}
	else 
	{ 
		answer =  "(" + ss.str()  + " + " + ss.str() + ")"; 
	}
	return answer;
    }



//To support simple iteration of nodes, two virtual methods number_of_children() and get_child(int i)

virtual int number_of_children() {
        return 2;
    }
virtual Base* get_child(int i) {
        if (i == 0){
		 return left;
	}
        if (i == 1){
		 return right;
	}
       else {
		 return nullptr;
	}
    }

};



#endif

