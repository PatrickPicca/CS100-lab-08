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
        		for (int i = 0; i < indent; i++){
            			exp += "    ";
        		}
			text += "<cn>";
			std::ostringstream stream;
			stream << std::noshowpoint << node->value;
			text += stream.str();
			text += "</cn>\n";
		}
		virtual void visit_rand(Rand* node){
	    		for (int i = 0; i < indent; i++){
	        		text += "    ";
			}
			text += "<cn>";
			std::ostringstream stream;
			stream << std::noshowpoint << node->value;
			text += stream.str();
			text += "</cn>\n";
		}

		virtual void visit_add_begin(Add* node){
        		for (int i = 0; i < indent; i++){
            			text += "    ";
        		}
			text += "<apply>\n";
        		indent += 1;
        		for (int i = 0; i < indent; i++){
            			text += "    ";
        		}
        		text += "<plus/>\n";
		}
        	virtual void visit_add_middle(Add* node){

		}
        	virtual void visit_add_end(Add* node){
	    		indent -= 1;
	    		for (int i = 0; i < indent; i++){
	        		text += "    ";
	    		}
			text += "</apply>\n";
		}
        	virtual void visit_sub_begin(Sub* node){
	    		for (int i = 0; i < indent; i++){
	        		text += "    ";
	    		}
	    		text += "<apply>\n";
           	 	indent += 1;
            		for (int i = 0; i < indent; i++){
                		text += "    ";
            		}
            		text += "<minus/>\n";
		}
        	virtual void visit_sub_middle(Sub* node){

		}
        	virtual void visit_sub_end(Sub* node){
	    		indent -= 1;
	    		for (int i = 0; i < indent; i++){
	        		text += "    ";
	    		}
			text += "</apply>\n";
		}
        	virtual void visit_mult_begin(Mult* node){
            		for (int i = 0; i < indent; i++){
                	text += "    ";
            		}
            		text += "<apply>\n";
	        	indent+=1;
	        	for (int i = 0; i < indent; i++){
                		text += "    ";
            		}
            		text += "<times/>\n";
		}
        	virtual void visit_mult_middle(Mult* node){
			text += "";
		}
        	virtual void visit_mult_end(Mult* node){
	    		indent -= 1;
	    		for (int i = 0; i < indent; i++){
	        		text += "    ";
	    		}
			text += "</apply>\n";
		}
        	virtual void visit_div_begin(Div* node){
            		for (int i = 0; i < indent; i++){
                		text += "    ";
            		}
		    	text += "<apply>\n";
            		indent+=1;
            		for (int i = 0; i < indent; i++){
                		text += "    ";
            		}
            		text += "<divide/>\n";
		}
        	virtual void visit_div_middle(Div* node){
	        	text += "";
		}
        	virtual void visit_div_end(Div* node){
            		indent -= 1;
            		for (int i = 0; i < indent; i++){
                		exp += "    ";
            		}
            		text += " </apply>\n";
		}
        	virtual void visit_pow_begin(Power* node){
            		for (int i = 0; i < indent; i++){
                		text += "    ";
            		}
		    	text += "<apply>\n";
            		indent += 1;
            		for (int i = 0; i < indent; i++){
                		text += "    ";
            		}
            		text += "<power/>\n";
		}
        	virtual void visit_pow_middle(Power* node){
	        	text += "";
		}
        	virtual void visit_pow_end(Power* node){
            		indent -= 1;
            		for (int i = 0; i < indent; i++){
               	 		text += "    ";
            		}
            		text += "</apply>\n";
		}
		std::string PrintMathML(Base* ptr){
        		auto* iter = new Iterator(ptr);
        		text += "<math>\n";
			while (!iter->is_done()) {
		        	iter->current_node()->accept(this, iter->current_index());
                		iter->next();
        		}
			text += "</math>\n";
			std::string temp = text;
			text = "";
			delete iter;
        		return temp;
		}

};
#endif
