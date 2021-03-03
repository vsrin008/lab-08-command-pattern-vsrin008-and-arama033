#include <iostream>
#include <string>
#include "base.hpp"
#include "visitor.hpp"
#include "iterator.hpp"
#include "visitorLatex.hpp"



int main() {
	Base* test1 = new Add( new Op(1), new Sub( new Op(5), new Op(0) ) );
	std::cout << "1+(5-0) = " << PrintLaTeX(test1);




	Base* test2 = new Pow(new Op(5), new Op(2));
	std::cout << "5^2 = " <<  PrintLaTeX(test2);



	Base* test3 = new Mult(new Op(2), new Op(5));
	std::cout << "2*5 = " << PrintLaTeX(test3);




	Base* test4 = new Div(new Op(2), new Op(3));
	std::cout << "2/3 = " << PrintLaTeX(test4);


	Base* test5 = new Div( new Mult( new Op(2), new Op(5)), new Pow( new Op(5), new Op(2)));


	std::cout << "(2*5)/(5^2) = " << PrintLaTeX(test5);


	return 0;


}
