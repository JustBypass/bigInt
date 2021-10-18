#ifndef __BIGINT_H_DEFINEDED__
#define __BIGINT_H_INCLUDED__
#include <iostream>
#include <string.h>
typedef unsigned u_t;

class myVector
{
private:
    char* vector = nullptr;
public:
    myVector(int n = 0) {
        _size = 0;
        _capacity = n;
        vector = new char[n];
    }
    ~myVector() {
        _size = 0;
        delete(vector);
    }
    char operator[](int i) {
        return vector[i];
    }
    char* get_vector() { return vector; }
    void push_back(char _c) { vector[_size++] = _c; }
    char pop_back() { return vector[--_size]; }
    int size() { return _size; }
private:
    int _size = 0;
    int _capacity = 0;
};
class bigInt {
public:
    static constexpr u_t N = 120;
private:
    int _count;
    bool _sgn;
    char _digit[N];//Remove here all functions(hardly all)
public:
    ///Constructors
    bigInt(long long) noexcept;
    bigInt(int) noexcept;
    bigInt(const char* = "0") noexcept;
    bigInt(myVector&) noexcept;
    bigInt(const bigInt&)noexcept;
    bigInt(bigInt&& _t) noexcept{
        *this = _t;
        std::cout << "Move\n";
    }
    ///Деструкторы
    ~bigInt() noexcept
    {
        _sgn = 0;
        _count = 0;
    }
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
    friend std::istream& operator >>(std::istream&,bigInt&) noexcept(false);
    const bigInt& operator =(const bigInt&);
    bigInt& operator=(bigInt&& _old) noexcept{
        std::cout << "Move\n";
        _count = std::move(_old.get_count());
        _sgn = std::move(_old.get_sgn());
        for (int i = 0; i < _count; i++) {
            _digit[i] = std::move(_old.getDigit()[i]);
        }
    }
    const bigInt& operator -=(const bigInt& digit);
    const bigInt operator +(const bigInt& digit);
    const bigInt operator -(const bigInt& digit);
    const bigInt operator+(const char*);
    const bigInt& operator +=(const char*);
    const bigInt& operator -=(const char*);
    const bigInt& operator =(const char*);
    const bigInt operator -(const char*);
    const bigInt& operator >>(int)noexcept;//Dividing numbor by 10
    const bigInt& operator<<(int) noexcept;//Multypying by 10
    //Other methods
    void returnExternal();
private:
    friend void changeSgn(bigInt& a) noexcept
    {
        a._sgn ? a._sgn = 0 : a._sgn = 1;
    }
};
#endif /* !__SOURCE_H_INCLUDED__*/