#pragma once

#include <iostream>
#include <bitset>
using namespace std;

class QInt {
private:
	bitset<128> data;
public:
	// Construtors
	QInt();
	QInt(int64_t);
	// QInt();
	QInt(const QInt&);

	// Function
	// operator +, -, *, /
	QInt operator+(const QInt&);
	QInt operator-(const QInt&);
	QInt operator*(const QInt&);
	QInt operator/(const QInt&);

	// logic operator: AND, OR, XOR, NOT
	QInt operator&(const QInt&);
	QInt operator|(const QInt&);
	QInt operator~();
	QInt operator^(const QInt&);

	// SHL, SHR
	QInt operator>>(uint16_t);
	QInt operator<<(uint16_t);

	// Left rotate, right rotate
	QInt roL();
	QInt roR();

	// Assign operator
	QInt& operator=(const QInt&);

	// read and cout
	/*ostream& operator<<(ostream&, const QInt&);*/

	// Get data
	bitset<128> getData();
};