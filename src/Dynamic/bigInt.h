//
// Created by Admin on 22.10.2021.
//

#ifndef CMAKE_TUR_BIGINT2_H
#define CMAKE_TUR_BIGINT2_H
#include "myVector.h"
#include <iostream>
#include <string.h>
#include <utility>
#include <exception>
#include <stdexcept>
//#include "Utils.h"


class bigInt {

private:
    int _count = 0;
    bool _sgn = 0;
    char* _digit = nullptr;
public:
    ///Constructors
    bigInt() noexcept { _digit = nullptr;_count = 0;_sgn = 0; }
    bigInt(long long)                                             noexcept;
    bigInt(int)                                                   noexcept;
    bigInt(const char*);
    bigInt(myVector&)                                             noexcept;
    bigInt(const bigInt&)                                         noexcept;
    bigInt(bigInt&&)                                              noexcept;
    ///Деструкторы
    ~bigInt()                                                     noexcept;
    /// Getters
    inline int get_count()const noexcept { return _count; }
     inline bool get_sgn()const noexcept { return _sgn; }
    inline char* get_digit()const noexcept { return _digit; }
    ///Operators
    bigInt& operator +=(const bigInt& digit)                      noexcept;
     bigInt operator ++()                                         noexcept;///++a
    bigInt operator ++(int)                                       noexcept;//a++

    bool operator ==(const bigInt&)                               noexcept;
    friend std::ostream& operator<<(std::ostream& out, const bigInt& a) noexcept;
    friend std::istream& operator >>(std::istream&, bigInt&)      noexcept(false);
    bigInt&  operator =(bigInt&)                                  noexcept;
    bigInt& operator=(bigInt&&)                                   noexcept;
    bigInt& operator -= (const bigInt& digit)                     noexcept;
    bigInt operator +(const bigInt& digit)  const                 noexcept;
    bigInt operator -(const bigInt& digit) const                  noexcept;
        
    bigInt &operator =(const char*)                               noexcept;
    bigInt& operator =(int)                                      noexcept;
    bigInt&  operator =(long long)                                noexcept;

    bigInt operator -( long long )                                noexcept;
    friend bigInt operator -(long long, const bigInt& )           noexcept;

    bigInt operator+( long long )                                 noexcept;
    friend bigInt operator+(long long , const bigInt&)            noexcept;

    bigInt operator -( int )                                      noexcept;
    friend bigInt operator -(int , const bigInt& )                noexcept;

    bigInt operator+( int )                                       noexcept;
    friend  bigInt operator+(int , const bigInt&)                 noexcept;

    bigInt operator+( const char* );
    friend  bigInt operator+(const char* , const bigInt& )        noexcept;

    bigInt operator -(const char* );
    friend bigInt operator -(const char* , const bigInt& )        noexcept;


    bigInt operator >>(int)const;//Dividing numbor by 10
    bigInt operator<<(int)const;//Multypying by 10

    bigInt&  operator >>=(int)                                    noexcept;//Dividing numbor by 10
    bigInt&  operator<<=(int)                                     noexcept;//Multypying by 10


    bigInt& operator ~()noexcept;

    ///Other methods
    void returnExternal();
private:
      friend  void do_external(int, const bigInt&, myVector&);
      friend char* to_str(const bigInt& a);
};
#endif //CMAKE_TUR_BIGINT2_H
