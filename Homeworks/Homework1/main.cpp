// homework1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "schedule.h"
using namespace std;

int main()
{
	Time a, b(10, 30);
	a++;
	b += 20;
	a += 909;
	cout << a << endl << b << endl << a + b << endl;
	cout << b++ << endl << b << endl;
	cout << b + 10 << endl;
	Appointment c, d(b, "kon");
	cout << c << endl << d << endl;
	cout << a - b << endl << b - a << endl;
	Schedule e;
	e.addAppointment(c);
	e.addAppointment(d);
	cout << e;
	Schedule dnes;
	Appointment asa[5];
	Time t;
	string n;
	for (int i = 0; i<5; i++)
	{
		cin >> t >> n;
		asa[i] = Appointment(t, n);
		dnes.addAppointment(asa[i]);
	}
	cout << dnes << endl;
	dnes.sort();
	cout << dnes << endl;
	dnes.clear();
	cout << dnes << endl;
	cin.ignore();
	cin.get();
	return 0;
}

