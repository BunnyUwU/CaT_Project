#include "project.h"

int main()
{
	QInt bit1(15);
	QInt bit2(7);
	QInt result1 = bit1 + bit2;
	QInt result2 = bit1 & bit2;

	for (int i = 8 - 1; i >= 0; i--)
	{
		cout << result1.getData()[i];
	}
	cout << endl;

	return 0;
}