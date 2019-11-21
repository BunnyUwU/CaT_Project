#include "project.h"

QInt::QInt()
{
	data = 0;
}

QInt::QInt(const QInt& bit)
{
	this->data = bit.data;
}

QInt QInt::operator+(const QInt& bit)
{
	QInt result;
	uint16_t carry = 0;
	for (int i = 128 - 1; i >= 0; i--)
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
	uint16_t carry = 0;
	for (int i = 128 - 1; i >= 0; i--)
	{
		if ((!data[i] && !bit.data[i]) || (data[i] && bit.data[i]))
		{
			result.data[i] = (data[i] - bit.data[i]);
		}
		else if (data[i] && !bit.data[i])
		{
			result.data[i] = (data[i] - bit.data[i]);
		}
		else {
			carry = 1;
			result.data[i + 1] = (data[i] - bit.data[i]) - carry;
		}
	}
	return result;
}