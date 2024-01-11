#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm> 
using namespace std;

void Addition(int array1[], int size1, int array2[], int size2);
void Multiplication(int array1[], int size1, int array2[], int size2);
void SaveFile(int number[], int size,int operationIndex);
void OddAndEven(int array[], int size);


int main()
{
	int array1Size;
	int array2Size;
	int counter = 0;
	int maxSize = 0;

	string line;
	ifstream inFile;

	inFile.open("input.txt");


	cout << "Please enter the size of the array:" << endl;
	cin >> array1Size;

	getline(inFile, line);
	array2Size = stoi(line);


	int* dizi1 = new int[array1Size];
	int* dizi2 = new int[array2Size];


	cout << "Enter " << array1Size << " elements to this array: ";

	for (int i = 0; i < array1Size; i++) {
		cin >> dizi1[i];
	}


	for (int i = 0; i < array2Size; i++) {
		getline(inFile, line);
		dizi2[i] = stoi(line);
	}

	

	Addition(dizi1, array1Size, dizi2, array2Size);

	Multiplication(dizi1, array1Size, dizi2, array2Size);

	OddAndEven(dizi1,array1Size);

	inFile.close();

}

void Addition(int array1[], int size1, int array2[], int size2) {

	int maxSize = max(size1, size2);
	int* additionResult = new int[maxSize];

	for (int i = 0; i < maxSize; i++) {
		additionResult[i] = (i < size1 ? array1[i] : 0) + (i < size2 ? array2[i] : 0);
	}

	SaveFile(additionResult, maxSize,0);
}

void Multiplication(int array1[], int size1, int array2[], int size2) {
	int maxSize = max(size1, size2);
	int* multiplicationResult = new int[maxSize];

	for (int i = 0; i < maxSize; i++) {
		multiplicationResult[i] = (i < size1 ? array1[i] : 0) * (i < size2 ? array2[i] : 0);
	}

	SaveFile(multiplicationResult, maxSize,1);
}

void OddAndEven(int array[], int size) {
	int* oddArray = new int[size];
	int* evenArray = new int[size];
	int oddCount = 0;
	int evenCount = 0;

	for (int i = 0; i < size; i++) {
		if (array[i] % 2 == 0) {
			evenArray[evenCount] = array[i];
			evenCount++;
		}
		else {
			oddArray[oddCount] = array[i];
			oddCount++;
		}
	}

	SaveFile(oddArray, oddCount, 2);
	SaveFile(evenArray, evenCount, 3);
}


void SaveFile(int number[], int size, int operationIndex) {
	ofstream outFile;
	outFile.open("output.txt", ios::app);

	switch (operationIndex)
	{
	case 0:
		outFile << "Toplama işleminin sonucu: ";
		break;
	case 1:
		outFile << "Çarpma işleminin sonucu: ";
		break;
	case 2:
		outFile << "Tek sayıları tutan dizi: ";
		break;
	case 3:
		outFile << "Çift sayıları tutan dizi: ";
		break;
	default:
		break;
	}

	for (int i = 0; i < size; i++)
	{
		outFile << number[i] << setw(5);
	}
	outFile << endl;
	outFile.close();
}




