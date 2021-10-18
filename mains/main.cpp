#include "C:\Qt\Qt5.12.10\cmake_tur\library\bigInt.h"
///#include "vld.h"
#include <iostream>
int main() 
{
	/*simpleMenu a;
	return a.mainloop();*/
    bigInt a(57576768);
    std::cout<<(a+="89");
	return 0;
}