#include "project.h"

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

//QInt QInt::operator*(const QInt& bit)
//{
//	QInt sum;
//	QInt result;
//	for (int i = 0; i < 128; i++)
//	{
//		for (int j = 128 - 1; j >= 0; j++)
//		{
//			result.data[j] = data[j] * bit.data[i];
//		}
//		sum = sum + result;
//		result.data << 1;
//	}
//	return sum;
//}

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

	QInt bit_0;
	bit_0.data = 0;

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

QInt QInt::roL(uint16_t number)
{
	if (data[data.count() - 1] == 1)
	{
		
	}
	return (*this);
}

QInt QInt::roR(uint16_t number)
{
	if (data[data.count() - 1] == 1)
	{

	}
	return (*this);
}

QInt& QInt::operator=(const QInt& bit)
{
	if (this == &bit)
	{
		return *this;
	}
	this->data = bit.data;
	return (*this);
}

bitset<128> QInt::getData()
{
	return data;
}
