#include "project.h"
// Construtors
QInt::QInt()
{
	this->data = 0;
}
QInt::QInt(int64_t integer)
{
	this->data = integer;
}
QInt::QInt(string bit)
{
	int k = 0;
	for (int i = bit.size() - 1; i >= 0; i--)
	{
		if (bit[i] == '0')
			data[k] = 0;
		else
			data[k] = 1;
		k++;
	}
}
QInt::QInt(const QInt& bit)
{
	this->data = bit.data;
}

// operator +, -, *, /
QInt QInt::operator+(const QInt& bit)
{
	QInt result;
	bool carry = 0;

	for (int i = 0; i < this->data.size(); i++)
	{
		if (carry)
		{
			result.data[i] = this->data[i] ^ bit.data[i] ^ carry;
			if ((!this->data[i] && !bit.data[i]))
			{
				carry = 0;
			}
		}
		else {
			if (this->data[i] && bit.data[i])
			{
				carry = 1;
			}
			result.data[i] = this->data[i] ^ bit.data[i];
		}
	}

	return result;

	/*bitset<1> temp = { 0 };
	QInt tempQi;
	for (int i = 0; i < bit.data.size(); i++) {
		tempQi.data[i] = (this->data[i] ^ bit.data[i]);
		if (this->data[i] == bit.data[i]) {
			if ((temp[0] == 1 && bit.data[i] == 0) || (temp[0] == 0 && bit.data[i] == 1)) {
				tempQi.data[i] = tempQi.data[i] + temp[0];
				temp.flip();
			}	
		}
		else {
			if (this->data[i] == 1)
				tempQi.data[i] = this->data[i] ^ temp[0];
			else
				tempQi.data[i] = bit.data[i] ^ temp[0];
		}
	}
	return tempQi;*/
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
	int count = 0;
	for (int i = bit.data.size() - 1; i >= 0; i--)
	{
		if (bit.data[i] == 1)
		{
			count = i;
			break;
		}
	}

	QInt k = (*this);
	k << 1;
	for (int i = 0; i < count; i++)
	{
		if (bit.data[i] == 0)
		{
			(*this) << 1;
			k << 1;
		}
		else {
			(*this) = (*this) + k;
			k << 1;
		}
	}

	return (*this);
}
QInt QInt::operator/(const QInt& bit)
{
	QInt result;
	return result;
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
		if (this->data[i])
		{
			this->data[i] = 0;
		}
		else {
			this->data[i] = 1;
		}
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
			result.data[i] = 0;
		}
		else {
			result.data[i] = 1;
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
	
	for (int i = result.data.size() - 1; i	> (result.data.size() - 1) - number; i--)
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
	temp = data[_posleft];
	(*this) << 1;
	this->data.set(_posright, temp);
	return (*this);
}
QInt QInt::roR()
{
	size_t _posleft = data.size() - 1, _posright = 0;
	size_t temp;
	size_t carry = 0;
	temp = data[_posright];
	(*this) >> 1;
	this->data.set(_posleft, temp);
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