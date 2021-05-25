#ifndef __MATHML_HPP__
#define __MATHML_HPP__

#include "visitor.hpp"
#include "iterator.hpp"
#include "base.hpp"
#include <sstream>


class Mathml : public Visitor
{
	public:
		virtual ~Mathml(){}
		std::string text = "";
    		int indent = 1;
		
		virtual void visit_op(Op* node){
        		for (int i = 0; i<indent; i++){
            			exp += "    ";
        		}
			text += "<cn>";
			std::ostringstream stream;
			stream << std::noshowpoint << node->value;
			text += stream.str();
			text += "</cn>\n";
		}
}
#endif
