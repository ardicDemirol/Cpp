#include <iostream>
using namespace std;

class baseClass
{
public:
	void print();
	void Test();
	baseClass(int u = 0);

private:
	int x;
};


class derivedClass : public baseClass
{
public:
	void print();
	derivedClass(int u = 0, int v = 0);

private:
	int a;
};


void baseClass::print()
{
	cout << "In baseClass x = " << x << endl;
}

void baseClass::Test()
{
	cout << "Test Method " << x << endl;
}

baseClass::baseClass(int u)
{
	x = u;
}

void derivedClass::print()
{
	cout << "In derivedClass ***: ";
	baseClass::print();
	cout << "In derivedClass a = " << a << endl;
}

derivedClass::derivedClass(int u, int v)
	: baseClass(u)
{
	a = v;
}

void callPrint(baseClass& p)
{
	p.print();
}

int main()
{
	baseClass one(5);				//Line 1
	derivedClass two(3, 15);		//Line 2

	one.print();					//Line 3
	two.print();					//Line 4

	cout << "*** Calling the function callPrint  ***"
		<< endl;					//Line 5
	callPrint(one); 				//Line 6
	callPrint(two); 				//Line 7

	return 0;
}






