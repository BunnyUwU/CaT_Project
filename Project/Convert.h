#pragma once
#include <iostream>
#include <string>
#include <bitset>
using namespace std;


string DetoBi(string decimal);
string HextoBin(string hex);
void reverseStr(string& str);

class QInt {
private:
	bitset<128> data;
public:
	QInt() {
		data = 0;
	}
	QInt(int64_t integer)
	{
		this->data = integer;
	}
	QInt(string bit) {
		int k = 0;
		for (int i = bit.size() - 1; i >= 0; i--) {
			if (bit[i] == '0')
				data[k] = 0;
			else
				data[k] = 1;
			k++;
		}
	}
	QInt(int base, string number) {
		int k = 0;
		if (base == 2) {
			for (int i = number.size() - 1; i >= 0; i--) {
				if (number[i] == '0')
					data[k] = 0;
				else
					data[k] = 1;
				k++;
			}
		}
		else {
			if (base == 10) {
				string bit = DetoBi(number);
				for (int i = bit.size() - 1; i >= 0; i--) {
					if (bit[i] == '0')
						data[k] = 0;
					else
						data[k] = 1;
					k++;
				}
			}
			else {
				if (base == 16) {
					string bit = HextoBin(number);
					for (int i = bit.size() - 1; i >= 0; i--) {
						if (bit[i] == '0')
							data[k] = 0;
						else
							data[k] = 1;
						k++;
					}
				}
			}
		}
	}
	QInt operator+(const QInt& bit) {
		QInt result;
		uint16_t carry = 0;
		for (int i = 0; i < data.size(); i++)
		{
			if (carry) {
				result.data[i] = ((data[i] + bit.data[i]) % 2 + carry) % 2;
				carry = ((data[i] + bit.data[i]) + carry) / 2;

				continue;
			}
			result.data[i] = (data[i] + bit.data[i]) % 2;
			carry = (data[i] + bit.data[i]) / 2;
		}
		return result;
	}
	string getData() {

		string r = data.to_string();

		int i, n = 0;
		for (i = 0; i < r.size(); i++) {
			if (r[i] == '1') {
				n = i;
				break;
			}
		}

		if (i == r.size())
			return "0";

		string result;
		for (i = n; i < r.size(); i++) {
			result += r[i];
		}

		return result;
	}

	string toHex() {
		int i;
		string r = data.to_string();
		if (r.size() % 4 != 0) {
			reverseStr(r);
			while (r.size() % 4 != 0)
				r = r + '0';
			reverseStr(r);
		}

		string temp1, temp2;
		for (i = 0; i < r.size(); i++) {
			temp1 += r[i];
			if ((i + 1) % 4 == 0) {
				if (temp1 == "0000") temp2 += '0';
				if (temp1 == "0001") temp2 += '1';
				if (temp1 == "0010") temp2 += '2';
				if (temp1 == "0011") temp2 += '3';
				if (temp1 == "0100") temp2 += '4';
				if (temp1 == "0101") temp2 += '5';
				if (temp1 == "0110") temp2 += '6';
				if (temp1 == "0111") temp2 += '7';
				if (temp1 == "1000") temp2 += '8';
				if (temp1 == "1001") temp2 += '9';
				if (temp1 == "1010") temp2 += 'A';
				if (temp1 == "1011") temp2 += 'B';
				if (temp1 == "1100") temp2 += 'C';
				if (temp1 == "1101") temp2 += 'D';
				if (temp1 == "1110") temp2 += 'E';
				if (temp1 == "1111") temp2 += 'F';
				temp1 = "";
			}
		}

		int n = 0;
		for (i = 0; i < temp2.size(); i++) {
			if (temp2[i] != '0') {
				n = i;
				break;
			}
		}

		temp1 = "";
		for (i = n; i < temp2.size(); i++) {
			temp1 += temp2[i];
		}

		return temp1;
	}

	void createArray(int array[][40]) {
		for (int i = 0; i < 128; i++) {
			for (int j = 0; j < 40; j++) {
				array[i][j] = 0;
			}
		}
	}

	void madeElement(int array[][40]) {
		array[0][0] = 1;

		int r = 0;

		for (int i = 1; i < 128; i++) {
			for (int j = 0; j < 40; j++) {
				array[i][j] = ((array[i - 1][j] * 2) % 10 + r) % 10;
				r = (array[i - 1][j] * 2) / 10;
			}
		}
	}

	string khongbiet(string bit, int array[][40]) {
		string result = "", temp2;
		int temp, carry = 0, sum = 0;

		for (int j = 0; j < 40; j++) {
			for (int i = 0; i < bit.size(); i++) {
				if (bit[i] == '1') {
					sum = sum + array[i][j];
				}
			}
			sum = sum + carry;

			temp = sum % 10;
			carry = sum / 10;

			temp2 = temp2 + to_string(temp);
			sum = 0;
		}

		return temp2;
	}

	string toDe() {
		int array[128][40];
		int i, j;

		createArray(array);

		madeElement(array);

		string bit = data.to_string();

		reverseStr(bit);

		int mark = 0;
		if (bit[bit.size() - 1] == '1') {
			mark = 1;
		}

		if (mark == 1) {
			for (i = 0; i < bit.size(); i++) {
				bit[i] = bit[i] ^ 1;
			}
			reverseStr(bit);
			QInt a(bit);
			QInt b(1);
			QInt result2 = a + b;

			bit = result2.getData();
			reverseStr(bit);
		}

		string temp2, result;

		temp2 = khongbiet(bit, array);

		int flag = 0;
		for (i = temp2.size() - 1; i >= 0; i--) {
			if (temp2[i] != '0') {
				flag = i;
				break;
			}
		}

		if (mark == 1)
			result = "-";
		else
			result = "";

		for (i = flag; i >= 0; i--) {
			result = result + temp2[i];
		}

		return result;
	}

	~QInt() {

	}
};

void reverseStr(string& str)
{
	int n = str.length();

	for (int i = 0; i < n / 2; i++)
		swap(str[i], str[n - i - 1]);
}

string DetoBi(string decimal) {

	if (decimal == "0")
		return decimal;

	string d2 = decimal;
	string binary = "";
	string temp = "", result = "", temp2, temp3;
	int i = 0, dividend, divisor, r, k;
	do {
		int n = d2.size();
		temp3 = d2[n - 1];
		k = stoi(temp3);
		if (k % 2 == 0)
			binary = binary + "0";
		else
			binary = binary + "1";

		result = "";
		temp = "";
		if (d2[0] == '-')
			i = 1;
		else
			i = 0;
		for (i; i < d2.size(); i++) {

			temp = temp + d2[i];
			dividend = stoi(temp);

			divisor = dividend / 2;
			r = dividend % 2;

			temp = to_string(r);
			temp2 = to_string(divisor);

			if (i == 0 && temp2 == "0")
				result = "";
			else
				result = result + temp2;
		}

		d2 = result;
	} while (result != "1");

	binary = binary + "1";

	reverseStr(binary);

	bitset<128> t(binary);

	if (decimal[0] == '-') {
		for (i = 0; i < t.size(); i++) {
			t[i] = t[i] ^ 1;
		}
		QInt a(t.to_string());
		QInt b(1);
		QInt result2 = a + b;

		return result2.getData();
	}

	return binary;
}

string HextoBin(string hex) {
	int i = 0;
	string bin;

	while (hex[i]) {

		switch (hex[i]) {
		case '0':
			bin = bin + "0000";
			break;
		case '1':
			bin = bin + "0001";
			break;
		case '2':
			bin = bin + "0010";
			break;
		case '3':
			bin = bin + "0011";
			break;
		case '4':
			bin = bin + "0100";
			break;
		case '5':
			bin = bin + "0101";
			break;
		case '6':
			bin = bin + "0110";
			break;
		case '7':
			bin = bin + "0111";
			break;
		case '8':
			bin = bin + "1000";
			break;
		case '9':
			bin = bin + "1001";
			break;
		case 'A':
			bin = bin + "1010";
			break;
		case 'B':
			bin = bin + "1011";
			break;
		case 'C':
			bin = bin + "1100";
			break;
		case 'D':
			bin = bin + "1101";
			break;
		case 'E':
			bin = bin + "1110";
			break;
		case 'F':
			bin = bin + "1111";
			break;
		default:
			break;
		}
		i++;
	}

	return bin;
}