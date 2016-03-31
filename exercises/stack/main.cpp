// stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stack.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Stack<int> a;
	a.push(1);
	a.push(3);
	a.push(2);
	for(int i = 0; a.size(); ++i)
	{
		cout << a.top() << ' ';
		a.pop();
	}
	cout << endl;
	cin.get();
	return 0;
}

