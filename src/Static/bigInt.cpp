//
// Created by Admin on 20.10.2021.
//

#include "bigInt.h"
#include "functions.h"
#include"Constructors.h"
#include"Constructors.h"
//ператор -+-=+= от long long

const bigInt bigInt::operator +(const bigInt& _num)const noexcept
{
    return mainPlusFunction(*this,_num);
}
const bigInt bigInt::operator-(const bigInt& _num) const noexcept {
    bigInt c = _num;
    change_sgn(c);
    return *this + (c);
}
const bigInt& bigInt::operator +=(const bigInt& _num) noexcept {
    return (*this = *this + _num);
}
const bigInt& bigInt::operator -=(const bigInt& _num) noexcept {
    return *this = (*this - _num);
}
const bigInt& bigInt::operator+=(const char* _t) noexcept {
    return (*this = (*this + _t));
}
const bigInt& bigInt::operator-=(const char* _t) noexcept {
    return (*this = (*this - bigInt(_t)));
}
const bigInt bigInt::operator ++(int) noexcept {
    *this += "1";
    return (*this - "1");
}
const bigInt& bigInt::operator ++() noexcept {
    return *this += "1";
}
std::ostream& operator<<(std::ostream& out, const bigInt& a) noexcept {
    if (a.get_sgn() == 1)
        std::cout << "-";
    for (int i = a.get_count() - 1; i >= 0; i--)
    {
        out << a._digit[i];
    }
    return out;
}
std::istream& operator >>(std::istream& in, bigInt& _num)noexcept(false)///How to do it??//Подключить гетстр или другой костыль;)
{
    std::string str;
    in >> str;
    try {
        check::str_check(str);
        _num = bigInt(str.c_str());
    }
    catch (...) {
        std::cerr << "Uncorrect_string!\n";
        _num = "0";
    }
    return in;
}
bigInt operator -(const bigInt& _n, int _t)noexcept
{
    return(_n - bigInt(_t));
}
bigInt operator -(int _t, const bigInt& _n)noexcept
{
    return(bigInt(_t) - _n);
}
bigInt operator+(const bigInt& _n, int _t)noexcept
{
    return(_n + bigInt(_t));
}
bigInt operator+(int _t, const bigInt& _n)noexcept
{
    return(_n + _t);
}
bigInt operator+(const bigInt& _n, const char* _t)noexcept
{
    return(_n + bigInt(_t));
}
bigInt operator+(const char* _t, const bigInt& _n)noexcept
{
    return(_n + _t);
}
bigInt operator -(const bigInt& _n, const char* _t)noexcept
{
    return(_n - bigInt(_t));
}
bigInt operator -(const char* _t, const bigInt& _n)noexcept
{
    return(_n - _t);
}
const bigInt bigInt::operator>>(int _n)const noexcept
{
    bigInt _a = *this;
    if (_a._digit[0] == '0' && _a._count == 1)
        return _a;
    for (int g = 0; g < _n; g++)
    {
        if (_a._count == 1)
        {
            _a._digit[0] = '0';
            return _a;
        }
        for (int i = 0; i < _a._count - 1; i++) {
            _a._digit[i] = _a._digit[i + 1];
        }
        _a._count--;
    }
    return _a;
}
const bigInt bigInt::operator<<(int _n) const noexcept
{
    bigInt _a(*this);
    if (_a._digit[0] == '0' && _a._count == 1)
        return _a;
    for (int g = 0; g < _n; g++)
    {
        if (_a._count == 1) {
            if (_a._digit[0] == '0')
            {
                break;
            }
        }
        for (int i = _a._count - 1; i >= 0; i--)
        {
            _a._digit[i + 1] = _digit[i];
        }
        _a._digit[0] = '0';
        _a._count++;
    }
    return _a;
}
const bigInt& bigInt::operator<<=(int _n)  noexcept
{
    return (*this = *this << _n);
}
const bigInt& bigInt::operator>>=(int _n)  noexcept
{
    return (*this = *this >> _n);
}

const bigInt& bigInt::operator =(const char* _t)noexcept
{
    return (*this = bigInt(_t));
}
bool bigInt::operator==(const bigInt& _num) noexcept
{
    if (_num.get_count() == _count && _num.get_sgn() == _sgn)
    {
        for (int i = 0; i < _count; i++) {
            if (_num._digit[i] != _digit[i]) return false;
        }
        return true;
    }
    else return false;
}