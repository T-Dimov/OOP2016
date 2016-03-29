// headers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "complex.h"
#include <iostream>
using namespace std;

double operator-(double g, Complex o)
{
	return g - o.neshto;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Complex test(1, 0);
	cout << test << endl;
	test++;
	cout << test << endl;

	Complex tst(2, 0);
	tst = 1.5 + tst;
	cout << tst << endl;

	double g=0;
	tst.neshto = 5;
	cout << (g - tst) << endl;

	cout << tst << "\n(" << tst[0] << ", " << tst[1] << ")\n";


	cout << tst.getCount() << endl << test.getCount() << endl;
	cout << sizeof(test) << " " << sizeof(tst) << endl;
	cin.get();
	return 0;
}

