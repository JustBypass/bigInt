//
// Created by Admin on 20.10.2021.
//

#include "bigInt.h"

void changeSgn(bigInt& a) noexcept
{
    a._sgn ? a._sgn = 0 : a._sgn = 1;
}
template<class T>
void AuxConstructor(T _number, bigInt&_num) {
    _number >= 0 ? _num._sgn = 0 : _num._sgn = 1;
    if (_number < 0)
        _number *= -1;
    int p = 0;
    if (_number == (T)0) {
        _num._count = 1;
        _num._digit[0] = '0';
    }
    else {
        for (int i = 0; i < _num.N; i++)
        {
            if (_number == (T)0)
                break;
            T _el = (_number % 10);
            _number = (_number - _el) / 10;
            _num._digit[i] = _el + '0';
            p++;
        }
        _num._count = p;
    }
}

namespace auxillary
{
    void deleteZeros(myVector<char>& _vec)
    {
        while (_vec.get_vector()[_vec.size() - 1] == '0' && _vec.size() != 1) {
            _vec.pop_back();
        }
    }
    void decimalInversion(myVector<char>& vec)
    {
        for (int i = 0; i < vec.size() - 1; i++)
        {
            vec.get_vector()[i] = (char)('9' - vec.get_vector()[i]) + '0';
        }
    }
    void plusOne(myVector<char>& vec, int len) {
        int transmission = 1;
        for (int i = 0; i < len + 1; i++) {
            if (((((int)vec[i] - '0') + transmission)) / 10 == 1) {
                vec.get_vector()[i] = 0 + '0';
            }
            else {
                vec.get_vector()[i] = (((transmission)+((int)vec[i] - '0')) + '0');
                break;
            }
        }
    }

    int do_external(int len, bigInt& _num, myVector<char>& vec)
    {
        if (len < _num.get_count()) {
            return 0;
        }
        if (_num.get_sgn() == 1) {
            for (int i = 0; i < len; i++) {
                for (i; i < _num.get_count(); i++) {
                    vec.push_back(_num.getDigit()[i]);
                }
                if (len == _num.get_count())
                    break;
                vec.push_back('0');
            }
            vec.push_back('9');
            decimalInversion(*&vec);
            plusOne(*&vec, len);
        }
        else {
            for (int i = 0; i < len; i++) {
                for (i; i < _num.get_count(); i++) {
                    vec.push_back(_num.getDigit()[i]);
                }
                if (len == _num.get_count())
                    break;
                vec.push_back('0');
            }
            vec.push_back('0');
        }
        return 1;
    }
    void sumOperation(myVector<char>& vec, int maximum, myVector<char>& first, myVector<char>& second)//Складываем дополнительные коды
    {
        int transmission = 0;
        for (int i = 0; i < maximum + 1; i++)
        {
            int f = (((((int)first[i] - '0') + ((int)second[i] - '0') + transmission)) % 10);
            vec.push_back(f + '0');
            (((((int)first[i] - '0') + ((int)second[i] - '0' + transmission)) / 10) > 0) ? transmission = 1 : transmission = 0;
        }
    }

    void sum_numbers(myVector<char>& vec, bigInt a, bigInt b, int len)
    {
        int maximum = std::max(a.get_count(), b.get_count());
        myVector<char> first(maximum + 2);
        do_external(maximum, a, first);
        myVector<char> second(maximum + 2);
        do_external(maximum, b, *&second);
        sumOperation(vec, maximum, *&first, *&second);
    }
}

bigInt& bigInt::operator=(bigInt&& _old) noexcept {
    std::cout << "Move\n";
    _count = std::move(_old.get_count());
    _sgn = std::move(_old.get_sgn());
    for (int i = 0; i < _count; i++) {
        _digit[i] = std::move(_old.getDigit()[i]);
    }
    return *this;
}

bigInt::bigInt(bigInt&& _t) noexcept {
    *this = _t;
}
bigInt::bigInt(int _number) noexcept
{
    AuxConstructor(_number,*this);
}
bigInt::bigInt(long long _number)noexcept
{
    AuxConstructor(_number, *this);
}
inline bigInt::~bigInt() noexcept
{
    _sgn = 0;
    _count = 0;
}

bigInt::bigInt(myVector<char>& _string) noexcept {
    _count = _string.size() - 1;
    _string[_string.size() - 1] == '+' ? _sgn = 0 : _sgn = 1;
    _string.pop_back();
    for (int i = 0; i < _string.size(); i++) {
        _digit[i] = _string[i];
    }
}
bigInt::bigInt(const bigInt& _num) noexcept {
    for (int i = 0; i < _num.get_count(); i++) {
        _digit[i] = _num._digit[i];
    }
    _count = _num.get_count();
    _sgn = _num.get_sgn();
}
bigInt::bigInt(const char* _string)noexcept {
    if (_string[0] == '-') {
        _count = strlen(_string) - 1;
        _sgn = 1;
    }
    else
    {
        _string[0] == '+' ? _count = strlen(_string) - 1 : _count = strlen(_string);
        _sgn = 0;
    }
    int i = 0;
    int k = 0;
    while (i < _count)
    {
        if (_count == 1) {
            if (_string[0] == '+' || _string[0] == '-') {
                _digit[0] = _string[1];
            }
            else _digit[0] = _string[0];
            break;
        }
        if (_string[k] == '-' || _string[k] == '+') {
            k++;
            continue;
        }
        _digit[i++] = _string[strlen(_string) - i - 1];
    }
}
const bigInt bigInt::operator +(const bigInt& _num)const
{
    int len = std::max(this->_count, _num.get_count());
    myVector<char> vec(len + 2);
    if (_sgn == _num.get_sgn())
    {
        if (_sgn == 0) {
            auxillary::sum_numbers(*&vec, *this, _num, len);
            auxillary::deleteZeros(*&vec);
            vec.push_back('+');
        }
        else {
            auxillary::sum_numbers(*&vec, *this, _num, len);
            auxillary::decimalInversion(vec);
            auxillary::plusOne(vec, len);
            vec.pop_back();
            auxillary::deleteZeros(vec);
            vec.push_back('-');
        }
    }
    else
    {
        auxillary::sum_numbers(*&vec, *this, _num, len);
        if (vec[vec.size() - 1] == '0') {
            auxillary::deleteZeros(vec);
            vec.push_back('+');
        }
        else {
            auxillary::decimalInversion(vec);
            auxillary::plusOne(vec, len);
            vec.pop_back();
            auxillary::deleteZeros(vec);
            vec.push_back('-');
        }
    }
    bigInt a(vec);
    return a;
}
void bigInt::returnExternal()
{
    myVector<char> _vec(_count + 1);
    if (auxillary::do_external(_count, *this, _vec) == 0)
    {
        std::cout << "ERROR\n";
    };
    while (_vec.size() != 0)
    {
        std::cout << _vec.pop_back();
    }
}
const bigInt& bigInt::operator +=(const bigInt& _num) {
    return (*this+=_num);
}
const bigInt bigInt::operator-(const bigInt& _num) const{
    bigInt c("0");
    c = _num;
    changeSgn(c);
    return (*this + c);
}
const bigInt& bigInt::operator -=(const bigInt& _num) {
    _num.get_sgn() == 1 ? *this = (*this - _num) : *this = (*this + _num);
    return *this;
}
std::ostream& operator<<(std::ostream& out, const bigInt& a) {
    if (a.get_sgn() == 1)
        std::cout << "-";
    for (int i = a.get_count() - 1; i >= 0; i--)
    {
        out << a._digit[i];
    }
    return out;
}
const bigInt& bigInt::operator=(const bigInt& _num)
{
    for (int i = _num.get_count() - 1; i >= 0; i--) {
        _digit[i] = _num._digit[i];
    }
    _count = _num.get_count();
    _sgn = _num.get_sgn();
    return *this;
}
const bigInt& bigInt::operator+=(const char* _t) {
    *this = (*this + _t);
    return *this;
}
const bigInt& bigInt::operator-=(const char* _t) {
    bigInt _new_num(_t);
    *this = (*this - _new_num);
    return *this;
}
const bigInt& bigInt::operator =(const char* _t){
    bigInt _num(_t);
    return (*this = _num);
}

const bigInt& bigInt::operator ++(int) {
    const char* m = "1";
    *this += m;
    return (*this - m);
}
const bigInt& bigInt::operator ++() {
    const char* m = "1";
    return *this += m;
}
std::istream& operator >>(std::istream& in, bigInt& _num) ///How to do it??//Подключить гетстр или другой костыль;)
{
    std::string str;
    in >> str;
    const char* s = str.c_str();
    _num = s;
    return in;
}
const  bigInt bigInt::operator+(const char* _str)const {
    bigInt _new(_str);
    return  (*this + _new);
}
const bigInt& bigInt::operator>>(int _n)const noexcept {
    bigInt _a = *this;
    for (int g = 0; g < _n; g++)
    {
        if (_a._count == 1)
        {
            _a._digit[0] = '0';
            return _a;
        }
        for (int i = 0; i <_a. _count - 1; i++) {
            _a._digit[i] = _a._digit[i + 1];
        }
        _a._count--;

    }
    return _a;
}
const bigInt& bigInt::operator<<(int _n) const noexcept
{
    bigInt _a = *this;
    for (int g = 0; g < _n; g++)
    {
        if (_a._count == 1) {
            if (_a._digit[0] == '0')
            {
                break;
            }
        }
        for (int i =_a. _count - 1; i >= 0; i--)
        {
            _a._digit[i + 1] = _digit[i];
        }
        _a._digit[0] = '0';
        _a._count++;
    }
    return _a;
}
const bigInt& bigInt::operator<<=(int _n)  noexcept {
    return (*this = *this<<_n);
}
const bigInt& bigInt::operator>>=(int _n)  noexcept {
    return (*this = *this >> _n);
}

const bigInt bigInt::operator-(const char* _t)const
{
    bigInt _new_num(_t);
    return (*this - _new_num);
}
bool bigInt::operator==(bigInt& _num)
{
    if (_num.get_count() == _count && _num.get_sgn() == _sgn)
    {
        for (int i = 0; i < _count; i++) {
            if (_num.getDigit()[i] != _digit[i]) return false;
        }
        return true;
    }
    else return false;
}