//
// Created by Admin on 12.11.2021.
//

#ifndef BIGINT_FACTORY_H
#define BIGINT_FACTORY_H
#include "../Class/Printed_Circuit_Board.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <string_view>
#include <algorithm>
#include <initializer_list>
#include <exception>
#include <sstream>
struct menu {
private:
	std::string_view a{ "1.PrintAll\n"
					   "2.SortByType\n" 
					   "3.Clear_Factory\n"};
public:

};

class Factory {
private:
	std::vector<printedCircuitBoard> vec;
public:

	printedCircuitBoard get_cl(int i) { return vec[i]; }
	Factory( std::initializer_list<printedCircuitBoard> args);
	void printAll();
	Factory& operator=(const Factory& fact) {
		vec = fact.vec;
		return *this;
	}
	Factory(std::initializer_list<Factory> args) {


	}
	Factory(std::vector<printedCircuitBoard> v) {
		vec = v;
	}
	Factory operator+(printedCircuitBoard& a) {
		std::vector<printedCircuitBoard> _new_vec;
		_new_vec.reserve(vec.size() + 1);
		_new_vec.insert(_new_vec.end(), vec.begin(),vec.end());
		return _new_vec;
	}
	Factory& operator+=(printedCircuitBoard& a) {
		return *this = *this + a;
	}
	Factory& operator =(std::initializer_list<printedCircuitBoard> args) {
		clearFactory();
		Factory _new(args);
		*this = _new;
	}
	void brakePCB();///Удалить плату
	void sortByNumber();///Сортировать по номеру
	void sortByType();//Сортировать по типу состояния
	void clearFactory() { vec.clear(); }//Удалить все из фабрики
};




//using namespace Lab3C;
//
//void addToVec(std::vector<printedCircuitBoard> &v, const printedCircuitBoard& elem)
//{
//    v.push_back(elem);
//}
//
//template<class ...Args> class Factory {///Завод печатных плат
//private:
//    std::vector<printedCircuitBoard> vec;
//    std::string str{"1.Print AsIs"
//                    "2.Print sorted by Max Distance"
//                    "3.Add Circuit"
//                    "4.Delete circuit"
//                    "5."};
//    std::string table{"Contact number-----Coords{x,y}-----StateType\n"};
//public:
//    Factory(Args... args){
//        addToVec(vec,args...);
//    }
//
//    void sortByType();
//
//    void sortByCount();
//
//    void printFullList();
//
//    void addCircuit(printedCircuitBoard &);
//};
//

#endif //BIGINT_FACTORY_H
