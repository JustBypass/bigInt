//
// Created by Admin on 20.10.2021.
//

#include "C:\Qt\Qt5.12.10\cmake_tur\src\Dynamic\bigInt.h"
#include "../../include/menu/menu.h"
int main()
{
/*    menu a;
    return a.mainloop();*/
    bigInt a(0);
    std::cout << (a -= bigInt(54));
    int b;
    std::cin>>a;
    return 0;
}


