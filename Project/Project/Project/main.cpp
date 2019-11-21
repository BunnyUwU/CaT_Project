#include "project.h"

int main()
{
	QInt bit1;
	bit1.data = 72;
	QInt bit2;
	bit2.data = 15;
	QInt result1 = bit1.operator+(bit2);
	QInt result2 = bit1.operator-(bit2);

	for (int i = 8 - 1; i >= 0; i--)
	{
		cout << result1.data[i];
	}
	cout << endl;

	for (int i = 8 - 1; i >= 0; i--)
	{
		cout << result2.data[i];
	}
	cout << endl;

	QInt bit_test;
	bit_test.data = 18444744073709551616;
	for (int i = 128 - 1; i >= 0; i--)
	{
		cout << bit_test.data[i];
	}
	cout << endl;
	//cout << sizeof(QInt) << endl;
	return 0;
}