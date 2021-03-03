#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "visitor.hpp"
#include "base.hpp"
#include <string>

using namespace std;

class Mult: public Base {
	private:
		Base* leftNum;
		Base* rightNum;
		double product;

	public:
		Mult(Base* x, Base* y) {
			leftNum = x;
			rightNum = y;
	}


	virtual double evaluate() {
		product = leftNum->evaluate() * rightNum->evaluate();
		return product;

	}

	virtual string stringify() {
		return leftNum->stringify() + " * " + rightNum->stringify();
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
			visitor->visit_mult_begin(this);
		else if(index==1)
			visitor->visit_mult_middle(this);
		else if(index==2)
			visitor->visit_mult_end(this);
	}


};

#endif
