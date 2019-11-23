#include "project.h"

int main()
{
	QInt bit1;
	bit1.data = 72;
	QInt bit2;
	bit2.data = 15;
	QInt result1 = bit1 + bit2;
	QInt result2 = bit1 - bit2;
	//QInt result3 = bit1 * bit2;

	//for (int i = 8 - 1; i >= 0; i--)
	//{
	//	cout << result1.data[i];
	//}
	//cout << endl;

	//for (int i = 9 - 1; i >= 0; i--)
	//{
	//	cout << result2.data[i];
	//}
	//cout << endl;

	/*for (int i = 10 - 1; i >= 0; i--)
	{
		cout << result3.data[i];
	}
	cout << endl;*/
	
	for (int i = 15; i >= 0; i--)
	{
		cout << bit2.data[i];
	}

	cout << endl;
	bit2.operator<<(1);
	for (int i = 15; i >= 0; i--)
	{
		cout << bit2.data[i];
	}
	cout << endl;

	for (int i = 15; i >= 0; i--)
	{
		cout << bit1.data[i];
	}
	cout << endl;

	bit1.operator>>(1);
	for (int i = 15; i >= 0; i--)
	{
		cout << bit1.data[i];
	}
	/*QInt bit_test;
	bit_test.data = 18444744073709551616;
	for (int i = 128 - 1; i >= 0; i--)
	{
		cout << bit_test.data[i];
	}
	cout << endl;*/
	//cout << sizeof(QInt) << endl;
	return 0;
}