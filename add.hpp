#ifndef __ADD_HPP__
#define __ADD_HPP__
#include "base.hpp"
#include "visitor.hpp"
#include <string>
#include <iostream>



class Add: public Base {
  public:
	Add(Base* a, Base* b) {
		leftNode = a;
		rightNode = b;

	}


	virtual double evaluate() {

		sum = leftNode->evaluate() + rightNode->evaluate();

		return sum;

	}

	virtual std::string stringify() {
		return leftNode->stringify() + " + " + rightNode->stringify();
	}


	virtual int number_of_children() {
		return 2;

	}
	
	virtual Base* get_child(int i) {
		if(i==0)
			return leftNode;
		else if(i==1)
			return rightNode;
	}

	virtual void accept(Visitor* visitor, int index) {
		if(index==0)
			visitor->visit_add_begin(this);
		else if(index==1)
			visitor->visit_add_middle(this);
		else if(index==2)
			visitor->visit_add_end(this);
	}

  private:
	Base* leftNode;
	Base* rightNode;
	double sum;
};
#endif //__ADD_HPP__


