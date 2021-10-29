//
// Created by Admin on 22.10.2021.
//

#ifndef CMAKE_TUR_BIGINT2_H
#define CMAKE_TUR_BIGINT2_H
#include "myVector.h"
#include <iostream>
#include <string.h>
class bigInt {

private:
    int _count = 0;
    bool _sgn = 0;
    char* _digit = nullptr;
public:
    ///Constructors
    bigInt() noexcept { _digit = nullptr; }
    bigInt(long long) noexcept;
    bigInt(int) noexcept;
    bigInt(const char*) noexcept;
    bigInt(myVector&) noexcept;
    bigInt(const bigInt&)noexcept;
    bigInt(bigInt&&) noexcept;
    ///Деструкторы
    ~bigInt() noexcept;
    // Getters
    inline int get_count()const noexcept { return _count; }
    inline bool get_sgn()const noexcept { return _sgn; }
    //Operators
    const bigInt& operator +=(const bigInt& digit)noexcept;
    const bigInt operator ++()noexcept;///++a
    const bigInt operator ++(int)noexcept;//a++

    bool operator ==(const bigInt&)noexcept;
    friend std::ostream& operator<<(std::ostream& out, const bigInt& a)noexcept;
    friend std::istream& operator >>(std::istream&, bigInt&) noexcept(false);
    const bigInt& operator =(const bigInt&)noexcept;
    const bigInt& operator=(bigInt&&)noexcept;
    const bigInt& operator -=(const bigInt& digit)noexcept;
    const bigInt operator +(const bigInt& digit)const noexcept;
    const bigInt operator -(const bigInt& digit)const noexcept;
    const bigInt& operator +=(const char*)noexcept;
    const bigInt& operator -=(const char*)noexcept;
    const bigInt&  operator -=(int) noexcept;
    const bigInt&  operator +=(int) noexcept;
    const bigInt&  operator +=(long long) noexcept;
    const bigInt&  operator -=(long long) noexcept;


    const bigInt& operator =(const char*)noexcept;
    const bigInt& operator =(int)noexcept;
    const bigInt& operator =(long long)noexcept;

    const bigInt operator -( long long )          noexcept;
    friend bigInt operator -(long long , const bigInt& )          noexcept;

    const bigInt operator+( long long )          noexcept;
    friend bigInt operator+(long long , const bigInt&)          noexcept;

    const bigInt operator -( int )          noexcept;
    friend bigInt operator -(int , const bigInt& )          noexcept;

    const bigInt operator+( int )          noexcept;
    friend bigInt operator+(int , const bigInt&)          noexcept;

    const bigInt operator+( const char* )  noexcept;
    friend bigInt operator+(const char* , const bigInt& )   noexcept;

    const bigInt operator -(const char* )   noexcept;
    friend bigInt operator -(const char* , const bigInt& )   noexcept;


    const bigInt operator >>(int)const noexcept;//Dividing numbor by 10
    const bigInt operator<<(int)const  noexcept;//Multypying by 10

    const bigInt& operator >>=(int) noexcept;//Dividing numbor by 10
    const bigInt& operator<<=(int)  noexcept;//Multypying by 10

    //Other methods
    void returnExternal();
private:
    friend  void do_external(int, bigInt&, myVector&);
    friend void changeSgn(bigInt& a) ;
    friend char* to_str(const bigInt& a);
    friend char* to_str(bigInt&&);
};
#endif //CMAKE_TUR_BIGINT2_H
