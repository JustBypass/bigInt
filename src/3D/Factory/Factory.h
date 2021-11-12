//
// Created by Admin on 12.11.2021.
//

#ifndef BIGINT_FACTORY_H
#define BIGINT_FACTORY_H
#include "../Class/Printed_Circuit_Board.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
using namespace Lab3C;

void addToVec(std::vector<printedCircuitBoard> &v, const printedCircuitBoard& elem)
{
    v.push_back(elem);
}

template<class ...Args> class Factory {///Завод печатных плат
private:
    std::vector<printedCircuitBoard> vec;
    std::string str{"1.Print AsIs"
                    "2.Print sorted by Max Distance"
                    "3.Add Circuit"
                    "4.Delete circuit"
                    "5."};
    std::string table{"Contact number-----Coords{x,y}-----StateType\n"};
public:
    Factory(Args... args){
        addToVec(vec,args...);
    }

    void sortByType();

    void sortByCount();

    void printFullList();

    void addCircuit(printedCircuitBoard &);
};


#endif //BIGINT_FACTORY_H
