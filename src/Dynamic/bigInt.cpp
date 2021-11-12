//
// Created by Admin on 22.10.2021.
//

#include "bigInt.h"
#include "Constructors.h"
#include "functions.h"
#include "translator.h"

bigInt& bigInt::operator=(bigInt&& _t)noexcept
{
    std::cout<<"Move oper\n";
    if(_digit)
        delete(_digit);
   _count = _t._count;
   _sgn = _t._sgn;
   _digit = _t._digit;
   _t._digit = nullptr;
   _t._sgn = {};
   _t._count = {};
   return (*this);
}

bigInt&  bigInt::operator=(bigInt& _num)noexcept
{
    std::cout<<"Cope oper\n";
    delete(_digit);
    _digit = new char[_num._count+1];
    for (int i = _num.get_count() - 1; i >= 0; i--) {
        _digit[i] = _num._digit[i];
    }
    _digit[_num._count] = '\0';
    _count = _num._count;
    _sgn = _num._sgn;
    return *this;
}
bigInt bigInt::operator +(const bigInt& _num)const noexcept
{
    int len = std::max(_count, _num._count);
    myVector vec(len + 2);
    if (_sgn == _num._sgn)//Если числа одинакового знака
    {
        if (_num._sgn == 0) {//Если числа положительны
            auxillary::sum_numbers(vec, *this, _num, len);
            auxillary::deleteZeros(vec);
            vec.push_back('+');
        }
        else {//Если числа отрицательны
            auxillary::sum_numbers(vec, *this, _num, len);
            auxillary::decimalInversion(vec);
            auxillary::plusOne(vec, len);
            vec.pop_back();
            auxillary::deleteZeros(vec);
            vec.push_back('-');
        }
    }
    else//Если числа разных знаков
    {
        auxillary::sum_numbers(vec, *this, _num, len);
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
   // bigInt a((vec));
    return vec;//(a);
}
bigInt&  bigInt::operator<<=(int _n)  noexcept
{
    if(_n == 0)
        return *this;
    else return *this = ((*this << _n));
}
bigInt&  bigInt::operator>>=(int _n)  noexcept
{
    if(_n == 0)
        return *this;
    else return *this = ((*this >> _n));
}
 bigInt bigInt:: operator -( int _t)noexcept
{
    return(*this- bigInt(_t));
}
 bigInt operator -(int _t, const bigInt& _n)noexcept
{
    return(bigInt(_t) - _n);
}
 bigInt bigInt:: operator+(int _t)noexcept
{
    return *this + bigInt(_t);
}

 bigInt operator+(int _t, const bigInt& _n)noexcept
{
    return(_n + _t);
}
 bigInt bigInt:: operator -( long long _t)noexcept
{
    return(*this - bigInt(_t));
}
 bigInt operator -(long long _t, const bigInt& _n)noexcept
{
    return (bigInt(_t) - _n);
}
 bigInt bigInt:: operator+(long long _t)noexcept
{
    return(*this + bigInt(_t));
}
 bigInt operator+(long long _t, const bigInt& _n)noexcept
{
    return(_n + _t);
}
 bigInt bigInt:: operator+(const char* _t)noexcept
{
    return (*this + bigInt(_t));
}
 bigInt operator+(const char* _t, const bigInt& _n)noexcept
{
    return(_n + _t);
}
 bigInt bigInt:: operator -( const char* _t)noexcept
{
    return (*this - bigInt(_t));
}
 bigInt operator -(const char* _t, const bigInt& _n)noexcept
{
    return(~bigInt(_n) + _t);
}
bigInt&  bigInt::operator +=(const bigInt& _num) noexcept {
    *this = *this + _num;
    return *this;
}
bigInt bigInt::operator-(const bigInt& _num) const noexcept {//Здесь лишний копи конструктор т к мы должны гарантировать что все _num'ы не будут изменяться(хч)(нам надо изменить знак в любом случае)
    return (*this + ~bigInt(_num));
}
bigInt&  bigInt::operator -=(const bigInt& _num)noexcept
{
    return *this = (*this+bigInt(_num));
}
std::ostream& operator<<(std::ostream& out,const bigInt& a)noexcept {
    if (a.get_sgn() == 1)
        std::cout << "-";
    for (int i = a.get_count() - 1; i >= 0; i--)
    {
        out << a._digit[i];
    }
    return out;
}
bigInt&  bigInt::operator+=(const char* _t) noexcept{
    return *this = *this+bigInt(_t);
}
bigInt&  bigInt::operator-=(const char* _t)noexcept {
    return (*this= *this + ~bigInt(_t));
}
bigInt& bigInt:: operator ~()noexcept{
    if (_sgn) {
        _sgn = 0;
    }
    else _sgn = 1;
    return *this;
}
bigInt&  bigInt::operator =(const char* _t) noexcept {
    *this = bigInt(_t);//Здесь ли лишнее копирование??//
    return *this;
}
 bigInt bigInt::operator ++(int) noexcept {
    *this += "1";
    return (*this - "1");
}
 bigInt bigInt::operator ++() noexcept {
    return *this += "1";
}
std::istream& operator >>(std::istream& in, bigInt& _num) noexcept(false) ///How to do it??//Подключить гетстр или другой костыль;)
{
    std::string str;
    in >> str;
    const char* s = str.c_str();
    _num = s;
    return in;
}
bool bigInt::operator==(const bigInt& _num)noexcept
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
bigInt bigInt::operator>>(int _n) const noexcept {
    if(_n <= 0 )
        return *this;
    bigInt _new;
    _new._sgn = _sgn;
    _new._count = _count;
    _new._digit = nullptr;
    char* ptr = _digit;
    if (_new._count == 1){ return (long long)0; }
    else {
        _new._digit = new char[_new._count];
    }
    for (int g = 0; g < _n; g++) {
        if (_new._count == 1) {
            return  (long long)0;
        }
        for (int i = 0; i < _new._count - 1; i++) {
            _new._digit[i] = ptr[i + 1];
        }
        _new._digit[_new._count - 1] = '\0';
        _new._count--;
    }
    return (_new);
}
bigInt&  bigInt:: operator -=(int a) noexcept {
    *this = (*this + ~bigInt(a));
    return (*this);
}
bigInt&  bigInt:: operator +=(int a) noexcept
{
    *this = (*this+bigInt(a));
    return (*this );
}
bigInt&  bigInt:: operator -=(long long a) noexcept
{
    *this = (*this + ~bigInt(a));
    return (*this);
}
bigInt&  bigInt:: operator +=(long long a) noexcept
{
    *this = (*this+bigInt(a));
    return *this;
}
bigInt&  bigInt::operator=(long long a)noexcept
{
    *this = (*this+bigInt(a));
    return *this;
}
bigInt& bigInt::operator =(int a)noexcept
{
    return *this = ( bigInt((long long)a));
}
 bigInt bigInt::operator<<(int _n)const noexcept {
    if(_n<=0)
        return (*this);
    bigInt newn;
    newn._sgn = _sgn;
    newn._count = _count;
    newn._digit = nullptr;
    char* ptr = _digit;
    if (newn._count == 1)
    {
        if (ptr[0] != '0')
        {
            newn._digit = new char[3];
        }
    }
    else
    {
        newn._digit = new char[newn._count + 2];
    }
    for (int g = 0; g < _n; g++)
    {
        if (newn._count == 1) {
            if (ptr[0] == '0') {
                return (long long)0;
            }
            newn._digit[0] = '0';
            newn._digit[1] = ptr[0];
            newn._digit[2] = '\0';
            newn._count++;
            return newn;
        }
        for (int i = newn._count - 1; i >= 0; i--)
        {
            newn._digit[i + 1] = ptr[i];
        }
        newn._digit[0] = '0';
        newn._digit[_count + 1] = '\0';
        newn._count++;
    }
    return (newn);
}
