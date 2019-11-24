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
	for (int i = data.size() - number; i >= 0; i--)
	{
		this->data[i + number] = this->data[i];
		this->data[i] = 0;
	}
	return (*this);
}

QInt QInt::operator>>(uint16_t number)
{
	/*for (int i = 128 - 1; i >= number; i--)
	{
		this->data[i - number] = this->data[i];
		if (this->data[127] == 1)
		{
			for (int j = 0; j < number; j++)
			{
				this->data[127 - j] = 1;
			}
		}
		else if (this->data[127] == 0) {
			for (int j = 0; j < number; j++)
			{
				this->data[127 - j] = 0;
			}
		}
	}*/

	bitset <1> bit_0 = 0;

	/*if (this->data[127])
	{
		for (int i = 127; i >= 127 - number; i--)
		{
			this->data[i] = 1;
			for (int j = 127 - number; j >= number; j--)
			{
				this->data[j - 1] = this->data[j];
				this->data[j] = 0;
			}
		}
	}
	else {
		for (int i = 127; i >= 127 - number; i--)
		{
			this->data[i] = 0;
			for (int j = 127 - number; j >= number; j--)
			{
				this->data[j - 1] = this->data[j];
				this->data[j] = 0;
			}
		}
	}*/
	return (*this);
}
// Left rotate, right rotate
QInt QInt::roL()
{
	size_t _posleft = data.size() - 1, _posright = 0;
	size_t temp;
	temp = data[_posright];
	for (int i = data.size() - 1; i >= 0; i--)
	{
		this->data[i] = this->data[i + 1];
	}
	this->data.set(_posleft, temp);
	return (*this);
}

QInt QInt::roR()
{
	size_t _pos = data.size() - 1;
	size_t temp;
	temp = data[_pos];
	for (int i = data.size() - 1; i >= 0; i--)
	{
		this->data[i] = this->data[i - 1];
	}
	this->data.set(0, temp);
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
