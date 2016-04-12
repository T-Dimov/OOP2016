#include "stdafx.h"
#include "time.h"
#include <iomanip>

Time::Time() : hours(0), minutes(0)
{}

Time::Time(int h, int m) : hours(h), minutes(m)
{
	normalize();
}

void Time::reset()
{
	hours = 0;
	minutes = 0;
}

void Time::alarm() const
{
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << '\a';
	}
}

Time Time::operator+(int m) const
{
	return Time(hours, minutes + m);
}

Time Time::operator+(const Time& o) const
{
	return Time(hours + o.hours, minutes + o.minutes);
}

Time operator+(int m, const Time& o)
{
	return Time(o.hours, o.minutes + m);
}

int Time::operator-(const Time & o) const
{
	return hours * 60 + minutes - o.hours * 60 - o.minutes;
}

Time Time::operator++(int)
{
	Time temp = *this;
	minutes++;
	normalize();
	return temp;
}

Time& Time::operator++()
{
	minutes++;
	normalize();
	return *this;
}

Time& Time::operator+=(const int m)
{
	minutes += m;
	normalize();
	return *this;
}

Time& Time::operator+=(const Time& o)
{
	minutes += o.minutes;
	hours += o.hours;
	normalize();
	return *this;
}

bool Time::operator==(const Time& o) const
{
	return hours == o.hours && minutes == o.minutes;
}

bool Time::operator!=(const Time& o) const
{
	return !this->operator==(o);
}

bool Time::operator<(const Time& o) const
{
	return hours < o.hours || hours == o.hours && minutes < o.minutes;
}

bool Time::operator<=(const Time& o) const
{
	return this->operator==(o) || this->operator<(o);
}

bool Time::operator>(const Time& o) const
{
	return !this->operator<=(o);
}

bool Time::operator>=(const Time& o) const
{
	return !this->operator<(o);
}

std::ostream& operator<<(std::ostream& out, const Time& o)
{
	out << '<' << std::setfill('0') << std::setw(2) << o.hours
		<< ":" << std::setfill('0') << std::setw(2) << o.minutes << '>';
	return out;
}

std::istream& operator>>(std::istream& in, Time& o)
{
	in >> o.hours >> o.minutes;
	o.normalize();
	return in;
}

void Time::normalize()
{
	hours += minutes / 60;
	minutes %= 60;
	hours %= 24;
}
