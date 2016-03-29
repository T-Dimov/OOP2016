#include "stdafx.h"
#include "complex.h"

size_t Complex::counter = 0;

size_t Complex::getCount() const
{
	return counter;
}

Complex::Complex(double a, double b) : real(a), imaginary(b)
{
	c[0] = a;
	c[1] = b;
	++counter;
}

Complex Complex::operator + (const Complex& o) const
{
	return Complex(real + o.real, imaginary + o.imaginary);
}

Complex Complex::operator+(int a) const
{
	return Complex(real + a, imaginary);
}

Complex operator+(double a, Complex o)
{
	return Complex(o.real + a, o.imaginary);
}

Complex& Complex::operator++()
{
	++real;
	return *this;
}

Complex Complex::operator++(int)
{
	Complex temp = *this;
	++real;
	return temp;
}

bool Complex::operator==(const Complex& o) const
{
	return real == o.real && imaginary == o.imaginary;
}

const double Complex::operator[](size_t i) const
{
	return c[i];
}

double& Complex::operator[](size_t i)
{
	return c[i];
}

std::ostream& operator<<(std::ostream& out, const Complex& o)
{
	out << "(" << o.real << ", " << o.imaginary << ")";
	return out;
}

std::istream& operator>>(std::istream& in, Complex& o)
{
	in >> o.real >> o.imaginary;
	return in;
}

