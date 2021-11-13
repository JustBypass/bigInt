//
// Created by Admin on 11.11.2021.
//
#include "Factory/Factory.h"
int main()
{
	printedCircuitBoard a;
	printedCircuitBoard::Contact f;
	std::cin >> f;
	a += f;
	printedCircuitBoard b;
	printedCircuitBoard c;
	printedCircuitBoard d;
	std::string str1("5345");
	std::string str2("5");
	std::string str3("5343565");

	//Factory an(std::string( "53yuhj45"),  std::string('54tg455' ));
	
	Factory an{a,b};
	Factory anew{ a,b,c,d };

	anew = an;
	anew.sortByNumber();
	//std::cout<<an.get_cl(0);
	return 0;
}