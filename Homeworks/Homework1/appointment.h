#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "time.h"
#include <string>

struct Appointment
{

	Appointment();
	Appointment(const Time&, const std::string&);
	friend std::ostream& operator<<(std::ostream&, const Appointment&);

	Time time;
	std::string person;
};

#endif
