#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Car
{
private:
	char* brand;
	char* color;
	int maxSpeed;
	int fuelUsage;
	const int year;
	static const int LIMITSPEED = 420;
	static const int LIMITFUELUSAGE = 15;
	static int carsCounter;
	int carId;
public:
	Car() : Car("No brand", "No color", 0, 0, 1999) {}
	Car(const char* brand, const char* color, int maxSpeed, int fuelUsage, int year) : year(year)
	{
		SetBrand(brand);
		SetColor(color);
		SetMaxSpeed(maxSpeed);
		SetFuelUsage(fuelUsage);
		carId = ++carsCounter;
	}

	Car(const Car& other) :
		Car(other.brand, other.color, other.maxSpeed, other.fuelUsage, other.year) {}

	~Car()
	{
		if (brand != nullptr)
			delete[] brand;
		if (color != nullptr)
			delete[] color;
	}

	void SetBrand(const char* brand)
	{
		if (this->brand != nullptr)
			delete[] this->brand;
		int size = strlen(brand) + 1;
		this->brand = new char[size];
		strcpy_s(this->brand, size, brand);
	}
	void SetColor(const char* color)
	{
		if (this->color != nullptr)
			delete[] this->color;
		int size = strlen(color) + 1;
		this->color = new char[size];
		strcpy_s(this->color, size, color);
	}
	void SetMaxSpeed(int maxSpeed)
	{
		if (maxSpeed >= 0 && maxSpeed < LIMITSPEED)
			this->maxSpeed = maxSpeed;
		else
			cout << "Invalid speed.\n" << endl;
	}
	void SetFuelUsage(int fuelUsage)
	{
		if (fuelUsage >= 0 && fuelUsage < LIMITFUELUSAGE)
			this->fuelUsage = fuelUsage;
		else
			cout << "Invalid fuel usage.\n" << endl;
	}
	void SetCarId(int carId)
	{
		this->carId = carId;
	}
	const char* GetBrand() const
	{
		return brand;
	}
	const char* GetColor() const
	{
		return color;
	}
	int GetMaxSpeed() const
	{
		return maxSpeed;
	}
	int GetFuelUsage() const
	{
		return fuelUsage;
	}
	int GetCarId() const
	{
		return carId;
	}
	int GetYear()
	{
		return year;
	}
	int GetLIMITSPEED()
	{
		return LIMITSPEED;
	}
	int GetLIMITFUELUSAGE()
	{
		return LIMITFUELUSAGE;
	}
	void ShowInfo()
	{
		cout << "Car ID:     " << GetCarId() << endl;
		cout << "Brand:      " << GetBrand() << endl;
		cout << "Color:      " << GetColor() << endl;
		cout << "Max speed:  " << GetMaxSpeed() << endl;
		cout << "Fuel usage: " << GetFuelUsage() << endl;
		cout << "Year:       " << GetYear() << endl;
	}
	static int GetCarsCounter()
	{
		return carsCounter;
	}
	static Car GetFaster(const Car& first,const Car& second)
	{
		cout << "Faster car is:\n";
		if (first.GetMaxSpeed() > second.GetMaxSpeed())
			return first;
		else
			return second;
	}
	static int GetByColor(Car ** arr, int size, const char* color)
	{
		for (int i = 0; i < size; i++)
		{
			if (!strcmp(arr[i]->GetColor(), color))
				return i;
		}
		return -1;
	}
};

int Car::carsCounter = 0;