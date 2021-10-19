//
// Created by Admin on 20.10.2021.
//

#ifndef CMAKE_TUR_DLG_H
#define CMAKE_TUR_DLG_H
#include <iostream>
namespace dlg {
    std::string _menu = "1.Get_Sum\n"
                        "2.Minus_function:\n"
                        "3.Divide_on_10\n"
                        "4.Multiply_on_10\n"
                        "5.Change_quantity\n"
                        "6.Enter_number\n"
                        "7.Get_number:\n";
    std::string _choose = "--->Choose the variant:\n";
    std::string _error = "You are wrong,repeat!\n";
    template<typename T>
    int getNum(T& a)
    {
        int rc = 0;
        std::cin >> a;
        if (!std::cin.good())
            rc = 1; // Обнаружена ошибка ввода
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return rc;
    };
}



#endif //CMAKE_TUR_DLG_H
