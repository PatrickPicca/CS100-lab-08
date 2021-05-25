#ifndef __LATEX_HPP__
#define __LATEX_HPP__

#include "visitor.hpp"
#include "base.hpp"
#include "iterator.cpp"
#include <sstream>

class VisitorLatex : public Visitor
{
	public:
		//virtual ~Latex(){}
		std::string text = "";

		virtual void visit_op(Op* node){
			text += "{";
			std::ostringstream stream;
			stream << std::noshowpoint << node->evaluate();
			text += stream.str();
				
			text += "}";
		}
		virtual void visit_rand(Op* node){
			text += "{";
			std::ostringstream stream;
			stream << std::noshowpoint << node->evaluate();
			text += stream.str();
			text += "}";
		}
		virtual void visit_add_begin(Add* node){
			text += "{(";
		}
        	virtual void visit_add_middle(Add* node){
			text += "+";
		}
        	virtual void visit_add_end(Add* node){
			text += ")}";
		}
        	virtual void visit_sub_begin(Sub* node){
			text += "{(";
		}
        	virtual void visit_sub_middle(Sub* node){
			text += "-";
		}
        	virtual void visit_sub_end(Sub* node){
			text += ")}";
		}
        	virtual void visit_mult_begin(Mult* node){
			text += "{(";
		}
        	virtual void visit_mult_middle(Mult* node){
			text += "\\cdot";
		}
        	virtual void visit_mult_end(Mult* node){
			text += ")}";
		}
        	virtual void visit_div_begin(Div* node){
			text += "{\\frac{(";
		}
        	virtual void visit_div_middle(Div* node){
			text += ")}{(";
		}
        	virtual void visit_div_end(Div* node){
			text += ")}";
		}
        	virtual void visit_pow_begin(Pow* node){
			text += "{(";
		}
        	virtual void visit_pow_middle(Pow* node){
			text += "^";
		}
        	virtual void visit_pow_end(Pow* node){
			text += ")}";
		}
		std::string PrintLaTeX(Base* ptr){
        		auto* iter = new Iterator(ptr);
        		text += "$";
        
                	while (!iter->is_done()) {
	        		iter->current_node()->accept(this, iter->current_index());
                		iter->next();
        		}
			text += "$";
			text += "\n";
			std::string temp = text;
			text = "";
	
			delete iter;
			return temp;
		}
          
};

#endif
