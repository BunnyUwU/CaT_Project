#include "project.h"

int main()
{
	QInt bit1(1);
	QInt bit2(7);
	QInt result1 = bit1 + bit2;
	QInt result2 = bit1 & bit2;

	for (int i = bit1.getData().size() - 1; i >= 0; i--)
	{
		cout << bit1.getData()[i];
	}
	cout << endl;

	bit1.roL();
	for (int i = bit1.getData().size() - 1; i >= 0; i--)
	{
		cout << bit1.getData()[i];
	}
	cout << endl;

	return 0;
}