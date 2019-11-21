#pragma once

#include <iostream>
#include <bitset>
using namespace std;

class QInt {
private:
	
public:
	bitset<128> data;
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

	// Get bit and set bit
	void getBit(bitset<128>, uint16_t);
	void setBit(bitset<128>, uint16_t);

	// read and cout
	/*ostream& operator<<(ostream&, const QInt&);*/
};