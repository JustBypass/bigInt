//
// Created by Admin on 22.10.2021.
//

#ifndef CMAKE_TUR_FUNCTIONS_H
#define CMAKE_TUR_FUNCTIONS_H

class bigInt;


namespace check {
    void str_check(std::string& _str) //Проверка корректности вводимого числа
    {
        int i = 0;
        for (char c : _str) {
            if (c < 48 || c > 57) {
                    if(i == 0&&((c == 45)||c == 43)){}
               else{
                     throw "String is uncorrect";
                     break;
               }
            }
            i++;
        }
    }
    int length_overflow(long long _num, bigInt& a) //Проверка на перепонение заданной длины числа
    {
        int g = 0;
        while (_num != (long long)0) {
            _num /= (long long)10;
            g++;
        }
        if (g >= bigInt().N) {
            std::cout << "grther";
            throw "Overflow";
        }
        return g;
    }
}
char* to_str(const bigInt& a)//Перевод большого числа в строку(используется а тестах)
{
    int p = 0;
    if (a._sgn)
    {
        p = a._count + 2;
    }
    else
    {
        p = a._count + 1;
    }
    char* str = new char[p];
    if (a._sgn == 1) {
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

 char* to_str(bigInt&& a){
    int p = 0;
    if (a._sgn) {
        p = a._count + 2;
    }
    else
    {
        p = a._count + 1;
    }
    char* str = new char[p];
    if (a._sgn == 1) {
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


/*

char* to_str( bigInt& a)//Перевод большого числа в строку(используется а тестах)
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
    if (a._sgn == 1) {
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
*/


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
const bigInt& mainPlusFunction(const bigInt& num1, const bigInt& num2)
{
    int len = std::max(num1._count, num2._count);
    myVector vec(len + 2);
    if (num1._sgn == num2._sgn)//Если числа одинакового знака
    {
        if (num1._sgn == 0) {//Если числа положительны
            auxillary::sum_numbers(vec, num1, num2, len);
            auxillary::deleteZeros(vec);
            vec.push_back('+');
        }
        else {//Если числа отрицательны
            auxillary::sum_numbers(vec, num1, num2, len);
            auxillary::decimalInversion(vec);
            auxillary::plusOne(vec, len);
            vec.pop_back();
            auxillary::deleteZeros(vec);
            vec.push_back('-');
        }
    }
    else//Если числа разных знаков
    {
        auxillary::sum_numbers(vec, num1, num2, len);
        if (vec.vector[vec._size - 1] == '0') {//если получилось положительное число
            auxillary::deleteZeros(vec);
            vec.push_back('+');
        }
        else {// если отрицательное
            auxillary::decimalInversion(vec);
            auxillary::plusOne(vec, len);
            vec.pop_back();
            auxillary::deleteZeros(vec);
            vec.push_back('-');
        }
    }
    return bigInt(vec);//Если не писать const, то Non-const lvalue reference to type 'bigInt' cannot bind to a temporary of type 'bigInt'
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
void change_sgn(bigInt& c) // Меняем знак числа(побочная функция)
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
