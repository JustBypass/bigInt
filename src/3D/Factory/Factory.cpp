//
// Created by Admin on 12.11.2021.
//

#include "Factory.h"

Factory::Factory(std::initializer_list<printedCircuitBoard>  args) {
	///addToVec(vec, args);
	std::stringstream sstr;
	sstr << "here\n";//Вывод инфы в логи
	for (auto& ex:args) {
		vec.push_back(ex);
		std::cout << ex;
	}
}

bool my_comparator(const printedCircuitBoard& fst, const printedCircuitBoard& snd) {
	return fst.getCurrentNumber() > snd.getCurrentNumber();
}

void Factory::sortByNumber() {
	std::sort(vec.begin(), vec.end(), my_comparator);
}

void Factory::printAll() {
	std::cout << "This is all PCB's of Factory:\n";
	for (auto& c : vec) {
		std::cout << c;
	}
}


