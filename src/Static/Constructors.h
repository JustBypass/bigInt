//
// Created by Admin on 23.10.2021.
//

#ifndef CMAKE_TUR_CONSTRUCTORS_H
#define CMAKE_TUR_CONSTRUCTORS_H
class bigInt;

bigInt::bigInt(int _number) noexcept
{
    *this = bigInt(static_cast<long long>(_number));
}
bigInt::bigInt(long long _number)noexcept(false)
{
    _number >= 0 ? _sgn = 0 : _sgn = 1;
    if (_number < 0)
        _number *= -1;
    if (_number == (long long)0)
    {
        _count = 1;
        _digit[0] = '0';
    }
    else {
        try {
            int g = length_overflow(_number,*this);
            for (int i = 0; i < g; i++) {
                if (_number == (long long) 0)
                    break;
                long long _el = (_number % 10);
                _number = (_number - _el) / 10;
                _digit[i] = _el + '0';
            }
            _count = g;
        }
        catch(...){
            std::cerr<<"Overflow detected!\n";
            *this = bigInt(0);
        }
    }

}
bigInt::bigInt(myVector& _string) noexcept {//выбросить исключение
    _count = _string._size - 1;
    _string.vector[_string._size - 1] == '+' ? _sgn = 0 : _sgn = 1;
    _string.pop_back();
    for (int i = 0; i < _string._size; i++) {
        _digit[i] =  _string.vector[i];
    }
}
bigInt::bigInt()  noexcept:_count(0),_sgn(0) {};

bigInt::bigInt(const char* _string)noexcept(false) {
    try {
        std::string _s = static_cast<std::string>(_string);
        str_check(_s);
        if (_string[0] == '-') {
            _count = strlen(_string) - 1;
            _sgn = 1;
        } else {
            _string[0] == '+' ? _count = strlen(_string) - 1 : _count = strlen(_string);
            _sgn = 0;
        }
        int i = 0, k = 0;
        while (i < _count) {
            if (_count == 1) {
                if (_string[0] == '+' || _string[0] == '-') {
                    _digit[0] = _string[1];
                } else _digit[0] = _string[0];
                break;
            }
            if (_string[k] == '-' || _string[k] == '+') {
                k++;
                continue;
            }
            _digit[i++] = _string[strlen(_string) - i - 1];
        }
    }
    catch(...){
        std::cerr<<"Uncorrect_string\n";
        *this = bigInt(0);
    }
}

#endif //CMAKE_TUR_CONSTRUCTORS_H
