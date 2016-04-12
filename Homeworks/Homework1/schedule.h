#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "appointment.h"

class Schedule
{
public:
	Schedule();
	Schedule(const Schedule&);
	Schedule& operator=(const Schedule&);
	~Schedule();
	bool addAppointment(const Appointment&);
	void clearBetween(const Time&, const Time&);
	void clear();
	void sort();
	friend std::ostream& operator<<(std::ostream&, const Schedule&);
	const Appointment& operator[](size_t) const;
	Appointment& operator[](size_t);

private:
	void copy(const Schedule&);
	void del();
	bool extend();

	size_t size;
	size_t capacity;
	Appointment* container;
};

#endif
