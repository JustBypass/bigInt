#include "bigInt.h"
#define _CRT_SECURE_NO_WARNINGS_
bigInt::bigInt(int _number) noexcept{

	_number >= 0 ? _sgn = 0 : _sgn = 1;
	if (_number < 0)
		_number *= -1;
	int p = 0;
	if (_number == (int)0) {
		_count = 1;
		_digit[0] = '0';
	}
	else {
		for (int i = 0; i < N; i++)
		{
			if (_number == (int)0)
				break;
			int _el = (_number % 10);
			_number = (_number - _el) / 10;
			_digit[i] = _el + '0';
			p++;
		}
		_count = p;
	}
}

bigInt::bigInt(myVector& _string) noexcept{
	_count = _string.size() - 1;
	_string[_string.size() - 1] == '+' ? _sgn = 0 : _sgn = 1;
	_string.pop_back();
	for (int i = 0; i < _string.size(); i++) {
		_digit[i] = _string[i];
	}
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

void deleteZeros(myVector& _vec)
{
	while (_vec.get_vector()[_vec.size() - 1] == '0'&&_vec.size()!=1) {
		_vec.pop_back();
	}
}
void decimalInversion(myVector& vec)
{
	for (int i = 0; i < vec.size() - 1; i++)
	{
		vec.get_vector()[i] = (char)('9' - vec.get_vector()[i]) + '0';
	}
}
void plusOne(myVector& vec, int len) {
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
		_number *= (long long)-1;
	int p = 0;
	for (int i = 0; i < N; i++) {
		if (_number == (long long)0)
			break;
		long long _el = (_number % 10);
		_number = (_number - _el) / 10;
		_digit[i] = _el + '0';
		p++;
	}
	_count = p;
}
int do_external(int len, bigInt& _num, myVector& vec)
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
void sumOperation(myVector& vec, int maximum, myVector& first, myVector& second )//Складываем дополнительные коды
{
	int transmission = 0;
	for (int i = 0; i < maximum + 1; i++)
	{
		int f = (((((int)first[i] - '0') + ((int)second[i] - '0') + transmission)) % 10);
		vec.push_back(f + '0');
		 (((((int)first[i] - '0') + ((int)second[i] - '0' + transmission)) / 10) > 0) ? transmission = 1 : transmission = 0;
	}
}
bigInt::bigInt(const bigInt& _num) noexcept{
	for (int i = 0; i < _num.get_count(); i++) {
		_digit[i] = _num._digit[i];
	}
	_count = _num.get_count();
	_sgn = _num.get_sgn();
}
void sum_numbers(myVector& vec, bigInt a, bigInt b, int len)
{
	int maximum = std::max(a.get_count(), b.get_count());
	myVector first(maximum + 2);
	do_external(maximum, a, first);
	myVector second(maximum + 2);
	do_external(maximum, b, *&second);
	sumOperation(vec, maximum, *&first, *&second);
}

const bigInt bigInt::operator +(const bigInt& _num)
{
	int maximum = std::max(this->_count, _num.get_count());
	int len = maximum;
	myVector vec(maximum + 2);
	if (_sgn == _num.get_sgn()) 
	{
		if (_sgn == 0) {
			sum_numbers(*&vec, *this, _num, len);
			deleteZeros(*&vec);
			vec.push_back('+');
		}
		else {
			sum_numbers(*&vec, *this, _num, len);
			decimalInversion(vec);
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
			decimalInversion(vec);
			plusOne(vec, len);
			vec.pop_back();
			deleteZeros(vec);
			vec.push_back('-');
		}
	}
	bigInt a(vec);
	return a;
}
void bigInt::returnExternal()
{
	myVector _vec(_count + 1);
	if (do_external(_count, *this, _vec) == 0) 
	{
		std::cout << "ERROR\n";
	};
	while (_vec.size() != 0) 
	{
		std::cout << _vec.pop_back();
	}
}


const bigInt& bigInt::operator +=(const bigInt& _num) {
	*this = (*this + _num);
	return *this;
}
const bigInt bigInt::operator-(const bigInt& _num) {
	bigInt c("0");
	c = _num;
	//(_num.get_sgn() == 1) ? (changeSgn(c), *this = ) : (, *this = *this + c);
	changeSgn(c);
	return (*this + c);
}


const bigInt& bigInt::operator -=(const bigInt& _num) {
	_num.get_sgn() == 1 ? *this = (*this - _num) : *this = (*this + _num);
	return *this;
}
std::ostream& operator<<(std::ostream& out,const bigInt& a)  {
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
	//*_digit = _num.get_count();
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
const bigInt& bigInt::operator =(const char* _t) {
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
std::istream& operator >>(std::istream& in,bigInt& _num) ///How to do it??//Подключить гетстр или другой костыль;)
{
	std::string str;
	in >> str;
	const char* s = str.c_str();
	//bigInt _new(s);
	_num = s;
	return in;
}
const  bigInt bigInt::operator+(const char* _str) {
	bigInt _new(_str);
	return  (*this + _new);
}
const bigInt& bigInt::operator>>(int _n) noexcept{
	for (int g = 0; g < _n; g++)
	{
		if (_count == 1) 
		{
			_digit[0] = '0';
			return *this;
		}
		for (int i = 0; i < _count - 1; i++) {
			_digit[i] = _digit[i + 1];
		}
		_count--;

	}
	return *this;
}
const bigInt& bigInt::operator<<(int _n) noexcept
{
	for (int g = 0; g < _n; g++)
	{
		if (_count == 1) {
			if (_digit[0] == '0')
			{
				break;
			}
		}
		for (int i = _count - 1; i >= 0; i--)
		{
			_digit[i + 1] = _digit[i];
		}
		_digit[0] = '0';
		_count++;
	}
	return *this;
}
const bigInt bigInt::operator-(const char* _t)
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
