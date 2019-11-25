#include "project.h"
// Construtors
QInt::QInt()
{
	data = 0;
}
QInt::QInt(int64_t integer)
{
	this->data = integer;
}
QInt::QInt(const QInt& bit)
{
	this->data = bit.data;
}

// operator +, -, *, /
QInt QInt::operator+(const QInt& bit)
{
	QInt result;
	uint16_t carry = 0;
	for (int i = data.size() - 1; i >= 0; i--)
	{
		if (data[i] && bit.data[i])
		{
			carry = 1;
			result.data[i + 1] = ((data[i + 1] + bit.data[i + 1]) + carry);
		}
		else {
			result.data[i] = ((data[i] + bit.data[i]) + carry);
		}
	}
	return result;
}
QInt QInt::operator-(const QInt& bit)
{
	QInt result;
	for (int i = data.size() - 1; i >= 0; i--)
	{
		result.data[i] = data[i] + ((~bit.data[i]) + 1);
	}
	return result;
}
QInt QInt::operator*(const QInt& bit)
{
	QInt sum;
	QInt result;
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = data.size() - 1; j >= 0; j--)
		{
			result.data[j] = data[j] * bit.data[i];
		}
		sum = sum + result;
		result.data << 1;
	}
	return sum;
}

// logic operator: AND, OR, XOR, NOT
QInt QInt::operator&(const QInt& bit)
{
	QInt result;
	for (int i = data.size() - 1; i >= 0; i--)
	{
		if (data[i] && bit.data[i])
		{
			result.data[i] = 1;
		}
		else {
			result.data[i] = 0;
		}
	}
	return result;
}
QInt QInt::operator|(const QInt& bit)
{
	QInt result;
	for (int i = data.size() - 1; i >= 0; i--)
	{
		if (!data[i] && !bit.data[i])
		{
			result.data[i] = 0;
		}
		else {
			result.data[i] = 1;
		}
	}
	return result;
}
QInt QInt::operator~()
{
	for (int i = data.size() - 1; i >= 0; i--)
	{
		this->data[i].flip();
	}
	return (*this);
}
QInt QInt::operator^(const QInt& bit)
{
	QInt result;
	for (int i = data.size() - 1; i >= 0; i--)
	{
		if ((data[i] && bit.data[i]) || (!data[i] && !data[i]))
		{
			result.data[i] = 1;
		}
		else {
			result.data[i] = 0;
		}
	}
	return result;
}

// SHL, SHR
QInt QInt::operator<<(uint16_t number)
{
	for (int i = (data.size() - 1) - number; i >= 0; i--)
	{
		this->data[i + number] = this->data[i];
		this->data[i] = 0;
	}
	return (*this);
}
QInt QInt::operator>>(uint16_t number)
{
	size_t _posleft = data.size() - 1;
	size_t temp;
	temp = data[_posleft];
	QInt result;
	for (int i = data.size() - 1; i >= number; i--)
	{
		result.data[i - number] = data[i];
	}
	
	for (int i = result.data.size() - 1; i > (result.data.size() - 1) - number; i--)
	{
		result.data[i] = temp;
	}

	for (int i = data.size() - 1; i >= 0; i--)
	{
		data[i] = result.data[i];
	}
	return (*this);
}

// Left rotate, right rotate
QInt QInt::roL()
{
	size_t _posleft = data.size() - 1, _posright = 0;
	size_t temp;
	temp = data[_posright];
	(*this) >> 1;
	this->data.set(_posleft, temp);
	return (*this);
}
QInt QInt::roR()
{
	size_t _posleft = data.size() - 1, _posright = 0;
	size_t temp;
	size_t carry = 0;
	temp = data[_posleft];
	(*this) << 1;
	this->data.set(_posright, temp);
	return (*this);
}

// Assign operator
QInt& QInt::operator=(const QInt& bit)
{
	if (this == &bit)
	{
		return *this;
	}
	this->data = bit.data;
	return (*this);
}
// Get data
bitset<128> QInt::getData()
{
	return data;
}
