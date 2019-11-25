#include "project.h"

int main()
{
	QInt bit1(18127103);
	QInt bit2(18127087);
	QInt bit3(16);
	QInt bit4(-5);
	QInt result1 = bit1 - bit2;

	for (int i = bit3.getData().size() - 1; i >= 0; i--)
	{
		cout << bit3.getData()[i];
	}
	cout << endl;

	bit4 >> 1;
	for (int i = bit4.getData().size() - 1; i >= 0; i--)
	{
		cout << bit4.getData()[i];
	}
	cout << endl;

	for (int i = result1.getData().size() - 1; i >= 0; i--)
	{
		cout << result1.getData()[i];
	}
	cout << endl;

	return 0;
}