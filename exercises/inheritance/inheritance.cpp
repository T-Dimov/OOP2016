// inheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Vehicle.h"
#include <iostream>

using namespace std;

int main()
{
	Vehicle c("Audi");
	c.print();
	cout << endl;
	Car a("i8", 200, "BMW");
	a.print();
	cout << endl;
	Bicycle b("C1", 21, "Drag");
	b.print();
	cout << endl;
	cin.get();
    return 0;
}

