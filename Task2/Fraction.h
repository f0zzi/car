#pragma once
#include <iostream>
using namespace std;

class Fraction
{
private:
	int numerator = 0;
	int denominator = 1;

public:
	Fraction() = default;
	Fraction(int numerator, int denominator) :numerator(numerator)
	{
		SetDenom(denominator);
	}
	Fraction(int numerator) :numerator(numerator) {}

	void SetDenom(int denominator)
	{
		if (denominator == 0)
		{
			this->denominator = 1;
			return;
		}
		this->denominator = denominator;
		if (denominator < 0)
		{
			this->numerator *= -1;
			this->denominator = -this->denominator;
		}
	}
	void SetNum(int numerator)
	{
		this->numerator = numerator;
	}
	void Show()
	{
		cout << numerator << "/" << denominator << endl;
	}
	Fraction operator+(const Fraction& other) const
	{
		return Fraction(this->numerator*other.denominator + this->denominator*other.numerator, this->denominator * other.denominator);
	}
	Fraction operator-(const Fraction& other) const
	{
		return Fraction(this->numerator*other.denominator - this->denominator*other.numerator, this->denominator * other.denominator);
	}
	Fraction operator*(const Fraction& other) const
	{
		return Fraction(this->numerator * other.numerator, this->denominator * other.denominator);
	}
	Fraction operator/(const Fraction& other) const
	{
		return Fraction(this->numerator*other.denominator, this->denominator*other.numerator);
	}
	bool operator==(const Fraction& other) const
	{
		return this->numerator*other.denominator == this->denominator*other.numerator;
	}
	void Normalize()
	{
		int temp = numerator;
		if (temp < 0)
			temp = -temp;
		int divider = 1;
		for (int i = 1; i < (temp < denominator ? temp : denominator); i++)
		{
			if (denominator % i == 0 && temp % i == 0)
				divider = i;
		}

	}
};