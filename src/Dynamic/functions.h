//
// Created by Admin on 28.10.2021.
//

#ifndef CMAKE_TUR_FUNCTIONS_H
#define CMAKE_TUR_FUNCTIONS_H
class bigInt;

namespace auxillary//Пространство имен для работы с дополнительным кодом десятичного числа
{
    void deleteZeros(myVector& _vec)// удаляем все нули из итогового вектора числа(если все нули, то последний сохраняем)
    {
        while (_vec.vector[_vec._size - 1] == '0' && _vec._size != 1) {
            _vec.pop_back();
        }
    }
    void decimalInversion(myVector& vec)//Делаем инверсию(10-n, где n- текущая iая цифра числа)в случае отрицательности числа
    {
        for (int i = 0; i < vec._size - 1; i++)
        {
            vec.vector[i] = (char)('9' - vec.vector[i]) + '0';
        }
    }
    void plusOne(myVector& vec, int len) //Просто прибавляем '1' к числу
    {
        int transmission = 1;
        for (int i = 0; i < len + 1; i++) {
            if (((((int)vec.vector[i] - '0') + transmission)) / 10 == 1) {
                vec.vector[i] = '0';//
            }
            else {
                vec.vector[i] = (((transmission)+((int)vec.vector[i] - '0')) + '0');
                break;
            }
        }
    }
    void sumOperation(myVector& vec, int maximum, myVector& first, myVector& second)//Складываем дополнительные коды
    {
        int transmission = 0;
        for (int i = 0; i < maximum + 1; i++)
        {
            int f = (((((int)first.vector[i] - '0') + ((int)second.vector[i] - '0') + transmission)) % 10);
            vec.push_back(f + '0');
            (((((int)first.vector[i] - '0') + ((int)second.vector[i] - '0' + transmission)) / 10) > 0) ? transmission = 1 : transmission = 0;
        }
    }
    void sum_numbers(myVector& vec, bigInt a, bigInt b, int len)//0поучаем вектор в дополнителном коде
    {
        int maximum = std::max(a.get_count(), b.get_count());
        myVector first(maximum + 2);
        do_external(maximum, a, first);
        myVector second(maximum + 2);
        do_external(maximum, b, second);
        sumOperation(vec, maximum, first, second);
    }
}
void do_external(int len, bigInt& _num, myVector& vec)//Перревод числа в вектор с доп кодом
{
    for (int i = 0; i < len; i++) {
        for (i; i < _num.get_count(); i++) {
            vec.push_back(_num._digit[i]);
        }
        if (len == _num.get_count())
            break;
        vec.push_back('0');
    }
    if (_num.get_sgn() == 1)
    {
        vec.push_back('9');
        auxillary::decimalInversion(vec);
        auxillary::plusOne(vec, len);
    }
    else
    {
        vec.push_back('0');
    }
}
void changeSgn(bigInt& c) // Меняем знак числа(побочная функция)
{
    if (c._sgn) {
        c._sgn = 0;
    }
    else c._sgn = 1;
}
void bigInt::returnExternal()// Печатаем число в доп. коде
{
    myVector _vec(_count + 1);
    while (_vec._size != 0)
    {
        std::cout << _vec.pop_back();
    }
}
#endif //CMAKE_TUR_FUNCTIONS_H
