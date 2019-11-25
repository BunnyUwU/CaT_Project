#include "project.h"

int main()
{
	QInt bit(10, "7564");
	QInt bit2(10, "234");

	QInt result = bit * bit2;
	cout << result.toDe() << endl;

	return 0;
}