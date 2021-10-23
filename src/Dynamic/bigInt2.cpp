//
// Created by Admin on 22.10.2021.
//

#include"bigInt2.h"

bigInt::~bigInt() noexcept {
    delete(_digit);
    _count = 0;
    _sgn = 0;
}

bigInt::bigInt(int _number) noexcept
{
    _number > 0 ? _sgn = 0 : _sgn = 1;
    if (_number < 0)
        _number *= -1;
    if (_number == (int)0) {
        _count = 1;
        _digit = new char[2];
        _digit[0] = '0';
        _digit[1] = '\0';
    }
    else {
        int newn = _number;
        int g = 0;
        while (newn != (int)0) {
            int _el = (newn % 10);
            newn = (newn - _el) / 10;
            g++;
        }
        _digit = new char[g + 1];
        for (int i = 0; i < g; i++) {
            if (_number == (int)0)
                break;
            int _el = (_number % 10);
            _number = (_number - _el) / 10;
            _digit[i] = _el + '0';
        }
        _digit[g] = '\0';
        _count = g;
    }
}

bigInt::bigInt(myVector<char>& _string) noexcept {
    _count = _string.size() - 1;
    _string[_string.size() - 1] == '+' ? _sgn = 0 : _sgn = 1;
    _string.pop_back();
    if (_digit != nullptr)
        delete(_digit);
    _digit = new char[_string.size() + 1];
    for (int i = 0; i < _string.size(); i++) {
        _digit[i] = _string[i];
    }
    _digit[_string.size()] = '\0';
}



const bigInt& bigInt::operator=(bigInt&& _t)noexcept {
    if(_digit!=nullptr)
        delete(_digit);
    _count = std::move(_t._count);
    _sgn = std::move(_t._sgn);
    _digit = new char[_count + 1];
    for (int i = 0; i < _count; i++) {
        _digit[i] = _t._digit[i];
    }
    _digit[_count] = '\0';
    return *this;
}

bigInt::bigInt(bigInt&& _t) noexcept{
    _count = std::move(_t._count);
    _sgn = std::move(_t._sgn);
    _digit = new char[_count + 1];
    for (int i = 0; i < _count; i++) {
        _digit[i] = _t._digit[i];
    }
    _digit[_count] = '\0';
}
const bigInt& bigInt::operator=(const bigInt& _num)noexcept
{
    for (int i = _num.get_count() - 1; i >= 0; i--) {
        _digit[i] = _num._digit[i];
    }
    _count = _num.get_count();
    _sgn = _num.get_sgn();
    return *this;
}


bigInt::bigInt(const char* _string)noexcept {

    int p = 0;
    if (_string[0] == '-') {
        _count = strlen(_string) - 1;
        _sgn = 1;
        p = _count + 2;
    }
    else
    {
        _string[0] == '+' ? _count = strlen(_string) - 1,p = _count+2 : _count = strlen(_string), p = _count + 1;
        _sgn = 0;
    }
    _digit = new char[p];
    int i = 0;
    int k = 0;
    while (i < _count)
    {
        if (_count == 1)
        {
            if (_string[0] == '+' || _string[0] == '-')
            {
                _digit[0] = _string[1];
            }
            else _digit[0] = _string[0];
            break;
        }
        if (_string[k] == '-' || _string[k] == '+')
        {
            k++;
            continue;
        }
        _digit[i++] = _string[strlen(_string) - i - 1];
    }
    _digit[p - 1] = '\0';
}

void deleteZeros(myVector<char>& _vec/*std::vector<char>& _vec*/)
{
    while (_vec.get_vector()[_vec.size() - 1] == '0') {
        _vec.pop_back();
    }
}
void decimalXOR(myVector<char>& vec/*std::vector<char>& vec*/)
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
bigInt::bigInt(long long _number)noexcept
{
    _number > 0 ? _sgn = 0 : _sgn = 1;
    if (_number < 0)
        _number *= -1;
    if (_number == (long long)0) {
        _count = 1;
        _digit = new char[2];
        _digit[0] = '0';
        _digit[1] = '\0';
    }
    else {
        long long newn = _number;
        int g = 0;
        while (newn != (long long)0) {
            long long _el = (newn % 10);
            newn = (newn - _el) / 10;
            g++;
        }
        _digit = new char[g + 1];
        for (int i = 0; i < g; i++) {
            if (_number == (long long)0)
                break;
            long long _el = (_number % 10);
            _number = (_number - _el) / 10;
            _digit[i] = _el + '0';
        }
        _digit[g] = '\0';
        _count = g;
    }
}
const bigInt bigInt::operator-(const char* _t)const noexcept
{
    bigInt _new_num(_t);
    return (*this - _new_num);
}



void sumOperation(myVector<char>& vec, int maximum, myVector<char>& first, myVector<char>& second) {
    int transmission = 0;
    for (int i = 0; i < maximum + 1; i++)
    {
        int f = (((((int)first[i] - '0') + ((int)second[i] - '0') + transmission)) % 10);
        //std::cout <<f ;
        vec.push_back(f + '0');
        if ((((((int)first[i] - '0') + ((int)second[i] - '0') + transmission)) / 10) > 0)
        {
            transmission = 1;
        }
        else
        {
            transmission = 0;
        }
    }
}
void sum_numbers(myVector<char>& vec/*std::vector<char>& vec,*/, bigInt a, bigInt b, int len)
{
    int maximum = std::max(a.get_count(), b.get_count());
    myVector<char> first(maximum + 2);
    do_external(maximum, a, first);
    myVector<char> second(maximum + 2);
    do_external(maximum, b, *&second);
    sumOperation(vec, maximum, *&first, *&second);
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
        decimalXOR(*&vec);
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
const bigInt bigInt::operator +(const bigInt& _num)const noexcept
{
    int maximum = std::max(this->_count, _num.get_count());
    int len = maximum;
    /*std::vector<char> vec;*/myVector<char> vec(maximum + 2);
    if (_sgn == _num.get_sgn()) {
        if (_sgn == 0) {
            sum_numbers(*&vec, *this, _num, len);
            deleteZeros(*&vec);
            vec.push_back('+');
        }
        else {
            sum_numbers(*&vec, *this, _num, len);
            decimalXOR(vec);
            plusOne(vec, len);
            vec.pop_back();
            deleteZeros(vec);
            vec.push_back('-');
        }
    }
    else
    {
        sum_numbers(*&vec, *this, _num, len);
        if (vec[vec.size() - 1] == '0') {
            deleteZeros(vec);
            vec.push_back('+');
        }
        else {
            decimalXOR(vec);
            plusOne(vec, len);
            vec.pop_back();
            deleteZeros(vec);
            vec.push_back('-');

        }
    }
    bigInt newBig(vec);
    return newBig;
}

void bigInt::returnExternal() {

    myVector<char> _vec(_count + 1);
    if (do_external(_count, *this, _vec) == 0) {
        std::cout << "ERROR\n";
    };
    while (_vec.size() != 0)
    {
        std::cout << _vec.pop_back();
    }
}

bigInt::bigInt(const bigInt& _num)noexcept {
    if (_digit != nullptr)
        delete(_digit);
    _digit = new char[_num._count + 1];
    for (int i = 0; i < _num.get_count(); i++) {
        _digit[i] = _num._digit[i];
    }
    _count = _num.get_count();
    _digit[_count] = '\0';
    _sgn = _num.get_sgn();
}
const bigInt& bigInt::operator +=(const bigInt& _num) noexcept {
    *this = *this + _num;
    return *this;
}
const bigInt bigInt::operator-(const bigInt& _num) const noexcept {
    bigInt c = _num;
    changeSgn(c);
    return *this + c;
}
const bigInt& bigInt::operator -=(const bigInt& _num)noexcept {
    _num.get_sgn() == 1 ? *this = *this - _num : *this = *this + _num;
    return *this;
}
std::ostream& operator<<(std::ostream& out, bigInt& a)noexcept {
    if (a.get_sgn() == 1)
        std::cout << "-";
    for (int i = a.get_count() - 1; i >= 0; i--)
    {
        out << a.getDigit()[i];
    }
    return out;
}

const bigInt& bigInt::operator+=(const char* _t) noexcept {
    *this = *this + _t;
    return (*this);
}

const bigInt& bigInt::operator-=(const char* _t)noexcept {
    bigInt _new_num(_t);
    *this = (*this - _new_num);
    return (*this);
}
const bigInt& bigInt::operator =(const char* _t) noexcept {
    bigInt _num(_t);
    return (*this = _num);
}

const bigInt& bigInt::operator ++(int)noexcept {
    *this += "1";
    return *this - "1";
}
const bigInt& bigInt::operator ++() noexcept
{
    return *this += "1";
}


std::istream& operator >>(std::istream& in,bigInt& _num) noexcept(false) ///How to do it??//Подключить гетстр или другой костыль;)
{
    std::string str;
    in >> str;
    const char* s = str.c_str();
    _num = s;
    return in;
}

const bigInt bigInt::operator+(const char* _str) const noexcept
{
    bigInt _new(_str);
    return (*this + _new);
}
//const bigInt bigInt::operator>>(int _n) const noexcept {
//	bigInt _new = *this;
//	if (_new == bigInt(0))
//		return *this;
//	delete(_new._digit);
//	if (_new._count == 1)
//		_new._digit = new char[1];
//	else {
//		_new._digit = new char[_new._count - 1];
//	}
//	for (int g = 0; g < _n; g++) {
//		if (_new._count == 1) {
//			_new._digit[0] = '0';
//			return *this;
//		}
//		for (int i = 0; i <_new. _count - 1; i++) {
//			_new._digit[i] =_new. _digit[i + 1];
//		}
//		_new._count--;
//	}
//	return _new;
//}
//
//const bigInt bigInt::operator<<(int _n)const noexcept {
//	bigInt newn = *this;
//	if (newn == bigInt(0))
//		return *this;
//	delete(newn._digit);
//	newn._digit = new char[_count + 1];
//	for (int g = 0; g < _n; g++) {
//		for (int i = _count - 1; i >= 0; i--) {
//			newn._digit[i + 1] = newn._digit[i];
//		}
//		newn._digit[0] = '0';
//		newn._count++;
//	}
//	return newn;
//}


