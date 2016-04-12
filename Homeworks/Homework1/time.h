#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time
{
public:
	Time();
	Time(int, int);
	void reset();
	void alarm() const;
	Time operator+(const int) const;
	Time operator+(const Time&) const;
	friend Time operator+(int, const Time&);
	int operator-(const Time&) const;
	Time operator++(const int);
	Time& operator++();
	Time& operator+=(const int);
	Time& operator+=(const Time&);
	bool operator==(const Time&) const;
	bool operator!=(const Time&) const;
	bool operator<(const Time&) const;
	bool operator<=(const Time&) const;
	bool operator>(const Time&) const;
	bool operator>=(const Time&) const;
	friend std::ostream& operator<<(std::ostream&, const Time&);
	friend std::istream& operator>>(std::istream&, Time&);

private:
	int hours;
	int minutes;

	void normalize();
};

#endif
