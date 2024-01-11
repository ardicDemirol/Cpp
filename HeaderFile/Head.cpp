#include "Head.h"
#include <iostream>

const char* GetUpper(char currentChar)
{
	if (currentChar == 'a') return "A";
	if (currentChar == 'b') return "B";
}

void GetPizza()
{
	std::cout << "Pizza" << std::endl;
}