#include <iostream>
#include "Fraction.h"
using namespace std;

int main()
{
	Fraction f1(5);
	Fraction f2(10, 1);
	f1.Show();
	f2.Show();
	Fraction f3 = f1 + f2;
	f3.Show();
	f3 = f1 - f2;
	f3.Show();
	system("pause");
	return 0;
}