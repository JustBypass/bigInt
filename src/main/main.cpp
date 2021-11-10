//
// Created by Admin on 20.10.2021.
//

#include "C:\Users\Admin\CLionProjects\untitled12\bigInt\src\Dynamic\bigInt.h"
#include "../../include/menu/menu.h"
int main(){
/*    menu a;
    return a.mainloop();*/
    bigInt c = bigInt("43");
    bigInt cj(std::move(c));
  //  c = "534";
    getchar();
    return 0;
}


