#include <iostream>
using namespace std;


class EquilateralTriangle
{
	float a;
	float circumference;
	float area;

public:
	void SetA(float lenght)
	{
		a = lenght;
		circumference = 3 * a;
		area = (a * a * 1.73) / 4;
	}


	friend void PrintResults1(EquilateralTriangle);
	friend class Homework;
};

class Homework {
public:
	void PrintResults2(EquilateralTriangle et)
	{
		cout << "Circumference: " << et.circumference << endl;
		cout << "Circumference: " << et.area << endl;
	}
};


void PrintResults1(EquilateralTriangle et)
{
	cout << "Circumference: " << et.circumference << endl;
	cout << "Circumference: " << et.area << endl;
}

int main()
{
	EquilateralTriangle	et;
	Homework hw;

	et.SetA(10);
	hw.PrintResults2(et);

	PrintResults1(et);
}

