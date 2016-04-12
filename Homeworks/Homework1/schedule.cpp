#include "stdafx.h"
#include "schedule.h"
#include <assert.h>

Schedule::Schedule() :size(0), capacity(20), container(nullptr)
{
	container = new Appointment[capacity];
}

Schedule::Schedule(const Schedule& o) :container(nullptr)
{
	copy(o);
}

Schedule& Schedule::operator=(const Schedule& o)
{
	if (this != &o)
	{
		del();
		copy(o);
	}
	return *this;
}

Schedule::~Schedule()
{
	del();
}

bool Schedule::addAppointment(const Appointment& a)
{
	bool extended = true;
	if (size >= capacity)
	{
		extended = extend();
	}
	container[size++] = a;
	return extended;
}

void Schedule::clearBetween(const Time& a, const Time& b)
{
	for (size_t i = 0; i < size; i++)
	{
		if (container[i].time >= a && container[i].time <= b)
		{
			for (size_t j = i; j < size - 1; j++)
			{
				container[j] = container[j + 1];
			}
			--size;
		}
	}
}

void Schedule::clear()
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = i + 1; j < size; j++)
		{
			if (abs(container[i].time - container[j].time) < 30)
			{
				for (size_t k = j; k < size - 1; k++)
				{
					container[k] = container[k + 1];
				}
				--size;
			}
		}
	}
}

void Schedule::sort()
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = i + 1; j < size; j++)
		{
			if (container[i].time > container[j].time)
			{
				Appointment temporary;
				temporary = container[i];
				container[i] = container[j];
				container[j] = temporary;
			}
		}
	}
}

const Appointment& Schedule::operator[](size_t i) const
{
	assert(i < size);
	return container[i];
}

Appointment& Schedule::operator[](size_t i)
{
	assert(i < size);
	return container[i];
}

void Schedule::copy(const Schedule& o)
{
	size = o.size;
	capacity = o.capacity;
	container = new Appointment[capacity];
	for (size_t i = 0; i < size; i++)
	{
		container[i] = o.container[i];
	}
}

void Schedule::del()
{
	delete[] container;
	container = nullptr;
}

bool Schedule::extend()
{
	Appointment *temp = container;
	capacity += 10;
	container = new Appointment[capacity];
	if (container)
	{
		for (size_t i = 0; i < size; i++)
		{
			container[i] = temp[i];
		}
		delete[] temp;
		return true;
	}
	else
	{
		capacity -= 10;
		container = temp;
		return false;
	}
}

std::ostream& operator<<(std::ostream& out, const Schedule& o)
{
	for (size_t i = 0; i < o.size; i++)
	{
		out << o[i] << std::endl;
	}
	return out;
}
