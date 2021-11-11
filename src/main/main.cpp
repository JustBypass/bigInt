//
// Created by Admin on 20.10.2021.
//

#include "../Dynamic/bigInt.h"
#include "../../include/menu/menu.h"
int main(){
/*    menu a;
    return a.mainloop();*/
//    bigInt c(4);// = bigInt("43");
//    bigInt cj(std::move(c));
  //  c = "534";
   /* bigInt c(0);
    c>>=1;*/
   bigInt a(0563456);
   bigInt b(4556);
   a = std::move(b);
    getchar();
    return 0;
}


