//
// Created by Admin on 12.11.2021.
//

#include "Factory.h"



bool my_comparator(const printedCircuitBoard& cl1, const printedCircuitBoard& cl2)
{
    return (int)cl1.getCurrentNumber()<(int)cl2.getCurrentNumber();
}
template<>
void Factory<>::sortByType(){
    std::qsort(vec.begin(),&vec.front(),my_comparator);//??
}

/*template<printedCircuitBoard... Args>
Factory<>::Factory(Args... args) {
    addToVec(vec, args);
}*/
