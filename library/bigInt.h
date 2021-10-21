//
// Created by Admin on 20.10.2021.
//

#ifndef CMAKE_TUR_BIGINT_H
#define CMAKE_TUR_BIGINT_H


#include <iostream>
#include <string.h>
#include "myVector.h"
#include <stdexcept>
typedef unsigned u_t;

class bigInt {
public:
    static constexpr u_t N = 120;
private:
    int _count;
    bool _sgn;
    char _digit[N];
public:
    ///Constructors
    bigInt() noexcept { }
    bigInt(long long) noexcept;
    bigInt(int) noexcept;
    bigInt(const char*) noexcept;
    bigInt(myVector<char>&) noexcept;//лучше сделать как дружественный оператор
    bigInt(const bigInt&)noexcept;
    bigInt(bigInt&&) noexcept;
    ///Деструкторы
    inline ~bigInt() noexcept;
    // Getters
    inline char* getDigit() noexcept { return _digit; }
    inline int get_count()const noexcept { return _count; }
    inline bool get_sgn()const noexcept { return _sgn; }
    //Operators
    const bigInt& operator +=(const bigInt& digit)noexcept;
    const bigInt& operator ++()noexcept;///++a
    const bigInt& operator ++(int)noexcept;//a++

    bool operator ==(const bigInt&)noexcept;
    friend std::ostream& operator<<(std::ostream& out, const bigInt& a)noexcept;
    friend std::istream& operator >>(std::istream&, bigInt&) noexcept(false);
    const bigInt& operator =(const bigInt&)noexcept;
    const bigInt& operator=(bigInt&&)noexcept;
    const bigInt& operator -=(const bigInt& digit)noexcept;
    const bigInt operator +(const bigInt& digit)const noexcept;
    const bigInt operator -(const bigInt& digit)const noexcept;
    const bigInt operator+(const char*)const noexcept;
    const bigInt& operator +=(const char*)noexcept;
    const bigInt& operator -=(const char*)noexcept;
    const bigInt& operator =(const char*)noexcept;
    const bigInt operator -(const char*)const noexcept;
    const bigInt operator >>(int)const noexcept;//Dividing numbor by 10
    const bigInt operator<<(int)const  noexcept;//Multypying by 10
    const bigInt& operator >>=(int) noexcept;//Dividing numbor by 10
    const bigInt& operator<<=(int)  noexcept;//Multypying by 10
    //Other methods
    void returnExternal();
private:
    friend  int do_external(int, bigInt&, myVector<char>&);
    template<class T>
    friend void AuxConstructor(T _number, bigInt& _num) {
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
    friend void changeSgn(bigInt& a) noexcept;
};
#endif //CMAKE_TUR_BIGINT_H
