#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "iostream"
#include "sstream"
#include <iomanip>
#include <string>
using namespace std;

class Op : public Base {
    private:
	double number;
    public:
	Op() : number(0) {}
        Op(double Number) : number(Number) {}
        virtual double evaluate() { return number; }
        virtual std::string stringify() { 
		ostringstream ss;
		ss << setprecision(3)<< showpoint << number;
		return ss.str(); 
	}
	virtual int number_of_children(){
		return 0;
	}
        virtual Base* get_child(int i){
		return nullptr;
	}
};

#endif //__OP_HPP__
