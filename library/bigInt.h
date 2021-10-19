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
    bigInt(long long ) noexcept;
    bigInt(int) noexcept;
    bigInt(const char* ) noexcept;
    bigInt(myVector<char>&) noexcept;//лучше сделать как дружественный оператор
    bigInt(const bigInt&)noexcept;
    bigInt(bigInt&& _t) noexcept;
    ///Деструкторы
    inline ~bigInt() noexcept;
    // Getters
    inline char* getDigit() noexcept { return _digit; }
    inline int get_count()const noexcept { return _count; }
    inline bool get_sgn()const noexcept { return _sgn; }
    //Operators
    const bigInt& operator +=(const bigInt& digit);
    const bigInt& operator ++();///++a
    const bigInt& operator ++(int);//a++
    bool operator ==(bigInt&);
    friend std::ostream& operator<<(std::ostream& out, const bigInt& a);
    friend std::istream& operator >>(std::istream&, bigInt&) noexcept(false);
    const bigInt& operator =(const bigInt&);
    bigInt& operator=(bigInt&& _old) noexcept;
    const bigInt& operator -=(const bigInt& digit);
    const bigInt operator +(const bigInt& digit)const;
    const bigInt operator -(const bigInt& digit)const;
    const bigInt operator+(const char*)const;
    const bigInt& operator +=(const char*);
    const bigInt& operator -=(const char*);
    const bigInt& operator =(const char*) ;
    const bigInt operator -(const char*)const;
    const bigInt& operator >>(int)const noexcept ;//Dividing numbor by 10
    const bigInt& operator<<(int) const noexcept ;//Multypying by 10
    const bigInt& operator >>=(int) noexcept;//Dividing numbor by 10
    const bigInt& operator<<=(int)  noexcept;//Multypying by 10
    //Other methods
    void returnExternal();
private:
    template<class T>
    friend void AuxConstructor(T _number, bigInt&_num) ;
    friend void changeSgn(bigInt& a) noexcept;
};


#endif //CMAKE_TUR_BIGINT_H
