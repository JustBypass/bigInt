//
// Created by Admin on 28.10.2021.
//

#ifndef CMAKE_TUR_CONSTRUCTORS_H
#define CMAKE_TUR_CONSTRUCTORS_H
#include "Utils.h"

class bigInt;

bigInt::~bigInt() noexcept
{
    delete (_digit);
    _digit = nullptr;
    _count = 0;
    _sgn = 0;
}
bigInt::bigInt(long long _number)noexcept
{
    _number >= 0 ? _sgn = 0 : _sgn = 1;
    if (_number < 0)
        _number *= -1;
    if (_number == (long long)0) {
        _count = 1;
        _digit = new char[2];
        _digit[0] = '0';
        _digit[1] = '\0';
    }
    else {
        long long newn = _number;
        int g = 0;
        while (newn != (long long)0) {
            long long _el = (newn % 10);
            newn = (newn - _el) / 10;
            g++;
        }
        _digit = new char[g + 1];
        for (int i = 0; i < g; i++) {
            if (_number == (long long)0)
                break;
            long long _el = (_number % 10);
            _number = (_number - _el) / 10;
            _digit[i] = _el + '0';
        }
        _digit[g] = '\0';
        _count = g;
    }
}

bigInt::bigInt(int _number) noexcept
{
    /*_number >= 0 ? _sgn = 0 : _sgn = 1;
    if (_number < 0)
        _number *= -1;
    if (_number == (int)0) {
        _count = 1;
        _digit = new char[2];
        _digit[0] = '0';
        _digit[1] = '\0';
    }
    else {
        int newn = _number;
        int g = 0;
        while (newn != (int)0) {
            int _el = (newn % 10);
            newn = (newn - _el) / 10;
            g++;
        }
        _digit = new char[g + 1];
        for (int i = 0; i < g; i++) {
            if (_number == (int)0)
                break;
            int _el = (_number % 10);
            _number = (_number - _el) / 10;
            _digit[i] = _el + '0';
        }
        _digit[g] = '\0';
        _count = g;
    }*/
    *this = bigInt(static_cast<long long>(_number));
}

bigInt::bigInt(myVector& _string) noexcept {
    _count = _string._size - 1;
    _string.vector[_string._size - 1] == '+' ? _sgn = 0 : _sgn = 1;
    _string.pop_back();
    if (_digit != nullptr)
        delete(_digit);
    _digit = new char[_string._size + 1];
    for (int i = 0; i < _string._size; i++) {
        _digit[i] = _string.vector[i];
    }
    _digit[_string._size] = '\0';
}
bigInt::bigInt(bigInt&& _t) noexcept {
    _count = std::move(_t._count);
    _sgn = std::move(_t._sgn);
    _digit = new char[_count + 1];
    for (int i = 0; i < _count; i++) {
        _digit[i] = _t._digit[i];
    }
    _digit[_count] = '\0';
}
bigInt::bigInt(const char* _string)noexcept {
    try {
        std::string _s = static_cast<std::string>(_string);
        check::str_check((_s));
        int p = 0;
        if (_string[0] == '-')
        {
            _count = strlen(_string) - 1;
            _sgn = 1;
            p = _count + 2;
        }
        else
        {
            _string[0] == '+' ? _count = strlen(_string) - 1, p = _count + 2 : _count = strlen(_string), p = _count + 1;
            _sgn = 0;
        }
        _digit = new char[p];
        int i = 0;
        int k = 0;
        while (i < _count)
        {
            if (_count == 1)
            {
                if (_string[0] == '+' || _string[0] == '-')
                {
                    _digit[0] = _string[1];
                }
                else _digit[0] = _string[0];
                break;
            }
            if (_string[k] == '-' || _string[k] == '+')
            {
                k++;
                continue;
            }
            _digit[i++] = _string[strlen(_string) - i - 1];
        }
        _digit[p - 1] = '\0';
    }
    catch (...) {
        std::cerr << "Uncorrect_string\n";
        *this = bigInt(0);
    }
}
bigInt::bigInt(const bigInt& _num)noexcept {
    if (_digit != nullptr)
        delete(_digit);
    _digit = new char[_num._count + 1];
    for (int i = 0; i < _num.get_count(); i++) {
        _digit[i] = _num._digit[i];
    }
    _count = _num.get_count();
    _digit[_count] = '\0';
    _sgn = _num.get_sgn();
}

#endif //CMAKE_TUR_CONSTRUCTORS_H
