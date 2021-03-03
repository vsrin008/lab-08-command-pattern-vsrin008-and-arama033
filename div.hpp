#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "visitor.hpp"
#include "base.hpp"
#include <string>

using namespace std;


class Div: public Base {
       private:
               Base* leftNum;
               Base* rightNum;
               double quotient;

       public:
               Div(Base* x, Base* y) {
                       leftNum = x;
                       rightNum = y;
     	        }

       	virtual double evaluate() {
               	quotient = leftNum->evaluate() / rightNum->evaluate();
              	        return quotient;
      	        }
      	        virtual string stringify() {
             	        return leftNum->stringify() + " / " + rightNum->stringify();
      	        }

		virtual int number_of_children() {
			return 2;
		}

		virtual Base* get_child(int i) {
			if(i==0)
				return leftNum;
			else if(i==1)
				return rightNum;
		}

		virtual void accept(Visitor* visitor, int index) {
			if(index==0)
				visitor->visit_div_begin(this);
			else if(index==1)
				visitor->visit_div_middle(this);
			else if(index==2)
				visitor->visit_div_end(this);
		}


};

#endif




