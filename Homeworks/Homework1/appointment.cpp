#include "stdafx.h"
#include "appointment.h"

Appointment::Appointment()
{}

Appointment::Appointment(const Time& t, const std::string& s): time(t), person(s)
{}

std::ostream& operator<<(std::ostream& out, const Appointment& o)
{
	out << o.time << " - " << o.person;
	return out;
}
