#include "project.h"

int main()
{
	QInt bit1("1111");
	QInt bit2("1010");
	QInt result1 = bit1 * bit2;

	/*bit1.roR();
	for (int i = bit1.getData().size() - 1; i >= 0; i--)
	{
		cout << bit1.getData()[i];
	}
	cout << endl;*/

	for (int i = result1.getData().size() - 1; i >= 0; i--)
	{
		cout << result1.getData()[i];
	}
	cout << endl;

	return 0;
}