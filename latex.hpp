#ifndef __LATEX_HPP__
#define __LATEX_HPP__

#include "visitor.hpp"
#include "base.hpp"
#include "iterator.cpp"
#include <sstream>

class Latex : public Visitor
{
	public:
		virtual ~Latex(){}
		std::string text = "";

		virtual void visit_op(Op* node){
			text += "{";
			std::ostringstream stream;
			stream << std::noshowpoint << node->value;
			text += stream.str();
				
			text += "}";
		}
}

#endif
