#pragma once

#include <iostream>
#include <bitset>
#include <string>
#include <fstream>
using namespace std;

class QInt {
private:
	bitset<128> data;
public:
	// Construtors
	QInt();
	QInt(int64_t);
	QInt(string);
	QInt(const QInt&);
	QInt(int, string);

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

	// Get data
	string getData();

	// Conversion
	string toHex();
	string toDe();
	string DetoBi(string);
	string HextoBin(string);

	// Optional Functions
	void createArray(int array[][40]);
	void madeElement(int array[][40]);
	void reverseStr(string&);
	string getTempArray(string, int[][40]);
};