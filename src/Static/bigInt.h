#ifndef CMAKE_TUR_BIGINT_H
#define CMAKE_TUR_BIGINT_H
#include <iostream>
#include <string.h>
#include "myVector.h"
#include <stdexcept>
//Разбить все на мини-классы
//Комментарии ко всем методам
class bigInt {
public:
    static constexpr unsigned N = 3;
private:
    int _count;
    bool _sgn;
   mutable char _digit[N];
public:
    ///Constructors
    bigInt()              noexcept;
    bigInt(long long)     noexcept(false);
    bigInt(int)           noexcept;
    bigInt(const char*)   noexcept(false);
    bigInt(myVector&)     noexcept;
    bigInt(const bigInt&) noexcept = default;
    bigInt(bigInt&&)      noexcept = default;
    ///Деструкторы
    inline ~bigInt()      noexcept = default;
    /// Getters
    inline char* getDigit() const  noexcept { return _digit; }
    inline int get_count()  const  noexcept { return _count; }
    inline bool get_sgn()   const  noexcept { return _sgn; }
    ///Operators
    const bigInt& operator ++()                               noexcept;///++a
    const bigInt operator ++(int)                             noexcept;//a++

    bool operator ==(const bigInt&)                           noexcept;

    friend std::ostream& operator<<(std::ostream& out, const bigInt& a)  noexcept;
    friend std::istream& operator >>(std::istream&, bigInt&)  noexcept(false);
    friend bigInt operator -(const bigInt&_n,int _t)          noexcept;
    friend bigInt operator -(int _t,const bigInt&_n)          noexcept;
    friend bigInt operator+(const bigInt& _n,int _t)          noexcept;
    friend bigInt operator+(int _t,const bigInt& _n)          noexcept;
    friend bigInt operator+(const bigInt& _n,const char* _t)  noexcept;
    friend bigInt operator+(const char*_t,const bigInt& _n)   noexcept;
    friend bigInt operator -(const bigInt&_n,const char*_t)   noexcept;
    friend bigInt operator -(const char*_t,const bigInt&_n)   noexcept;

    const bigInt& operator =(const char*)                     noexcept;
    bigInt& operator=(const bigInt&) noexcept = default;
    bigInt& operator=(bigInt&&)      noexcept = default;

    const bigInt operator +(const bigInt& digit) const        noexcept;
    const bigInt operator -(const bigInt& digit) const        noexcept;

    const bigInt& operator +=(const bigInt& digit)            noexcept;
    const bigInt& operator -=(const bigInt& digit)            noexcept;
    const bigInt& operator +=(const char*)                    noexcept;
    const bigInt& operator -=(const char*)                    noexcept;

    const bigInt operator >>(int)                 const       noexcept;//Dividing numbor by 10
    const bigInt operator<<(int)                  const       noexcept;//Multypying by 10
    const bigInt& operator >>=(int)                           noexcept;//Dividing numbor by 10
    const bigInt& operator<<=(int)                            noexcept;//Multypying by 10
    ///Other methods
    void returnExternal();
private:
    friend void change_sgn(bigInt& c);
    friend  void do_external(int, bigInt&, myVector&);
    friend char* to_str(bigInt&&);
};
#endif //CMAKE_TUR_BIGINT_H
