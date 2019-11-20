#pragma once

#include <iostream>
#include <bitset>
using namespace std;

//#define QInt bitset<128>

class QInt {
private:
	int arrayBit[4];
public:
	// Construtors
	QInt();
	QInt(const QInt&);

	// Function
	void add();
	void multiply();

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
	QInt Lrotate();
	QInt Rrotate();
};