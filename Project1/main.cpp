#include <iostream>
#include "Car.h"
using namespace std;

int main()
{
	Car** arr = new Car*[2];
	arr[0] = new Car("car1", "color1", 101, 11, 2001 );
	arr[1] = new Car("car2", "color2", 102, 12, 2002 );
	Car car1("car1", "color1", 101, 11, 2001);
	Car car2("car2", "color2", 102, 12, 2002);
	car1.ShowInfo();
	car2.ShowInfo();
	Car car3(car2);
	car3.ShowInfo();
	cout << "Cars counter: " << Car::GetCarsCounter() << endl;
	Car car4(Car::GetFaster(car1, car2));
	car4.ShowInfo();
	cout << Car::GetByColor(arr, 2, "color1") << endl;
	system("pause");
	return 0;
}