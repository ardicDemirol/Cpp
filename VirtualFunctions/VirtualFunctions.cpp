#include <iostream>
using namespace std;


class Instrument {
public:
	virtual void MakeSound() const = 0; // pure virtual function
	
	//  --virtual function--
	/*virtual void MakeSound()
	{
		cout << "Instrument Make Sound\n";
	}*/
};

class Accordion : public Instrument {
public:
	void MakeSound() const {
		cout << "squeeze squeeze\n";
	}
};

class Piano : public Instrument {
public:
	void MakeSound() const {
		cout << "plink plink\n";
	}
};



int main()
{
	Instrument* i1 = new Accordion();
	//i1->MakeSound();
	Instrument* i2 = new Piano();
	//i2->MakeSound();

	Instrument* instruments[2] = { i1,i2 };
	for (int i = 0; i < 2; i++) {
		instruments[i]->MakeSound();
	}

}


