//
// Created by Admin on 28.10.2021.
//

#ifndef CMAKE_TUR_TRANSLATOR_H
#define CMAKE_TUR_TRANSLATOR_H

char* to_str(const bigInt& a)//Перевод большого числа в строку(используется а тестах)
{
    int p = 0;
    if (a._sgn) {
        p = a._count + 2;
    }
    else
    {
        p = a._count + 1;
    }
    char* str = new char[p];
    if (a._sgn == 1)
    {
        str[0] = '-';
        for (int i = a._count; i > 0; i--) {
            str[i] = a._digit[a._count - i];
        }
    }
    else {
        for (int i = a._count - 1; i >= 0; i--) {
            str[i] = a._digit[a._count - i - 1];
        }
    }
    str[p - 1] = '\0';
    return str;

}
#endif //CMAKE_TUR_TRANSLATOR_H
