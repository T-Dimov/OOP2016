#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex
{
public:
	Complex(double, double);
	Complex operator+(const Complex&) const;
	Complex operator+(int) const;
	Complex& operator++();
	Complex operator++(int);
	bool operator==(const Complex&) const;
	friend Complex operator+(double, Complex);
	friend std::ostream& operator<<(std::ostream&, const Complex&);
	friend std::istream& operator>>(std::istream&, Complex&);
	const double operator[](size_t) const;
	double& operator[](size_t);
	double neshto;
	size_t getCount() const;
private:
	double real, imaginary;
	static size_t counter;
	double c[2];
};

#endif
