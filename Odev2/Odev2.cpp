#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

// 402570 - Ardýç Demirol
// 410730 - MOHAMMAD SABIR NAZIRI

struct Name {
	string candidatesName[6] = { "Goofy","Mickey","Donald","Pluto","Doc","Balto" };
};

void SortNames(Name& name);
void Votes(Name& nameStruct);
void Result(const int array[], int size,Name& name);
int FindMax(const int array[], int size);
int FindWinner(const int array[], int size);

int main()
{
	Name name;
	SortNames(name);
	Votes(name);
}

void SortNames(Name& name) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (name.candidatesName[i] < name.candidatesName[j]) {
				string temp = name.candidatesName[i];
				name.candidatesName[i] = name.candidatesName[j];
				name.candidatesName[j] = temp;
			}
		}
	}
}

void Votes(Name& nameStruct) {

	string line;
	ifstream inFile;

	int votesByRegion[6][4];
	int totalVotes[6];
	int tempTotalVotes = 0;

	inFile.open("voteData.txt");

	for (int i = 0; i < 6; ++i) {
		fill(totalVotes, totalVotes + 6, 0);
		fill(votesByRegion[i], votesByRegion[i] + 4, 0);
	}


	cout << "--------------Election Results--------------" << endl;
	cout << "Candidate       Votes" << endl;
	cout << "Name Region1 Region2 Region3 Region4 Total" << endl;
	cout << "--------------------------------------------" << endl;

	while (getline(inFile, line))
	{
		istringstream stream(line);
		string name;
		int number1, number2;
		int nameIndex = -1;

		stream >> name >> number1 >> number2;

		for (int i = 0; i < 6; ++i) {
			if (name == nameStruct.candidatesName[i]) {
				nameIndex = i;
				votesByRegion[nameIndex][number1 - 1] = number2;
				totalVotes[nameIndex] += number2;
			}
		}
	}

	for (int i = 0; i < 6; ++i) {
		cout << setw(10) << left << nameStruct.candidatesName[i];
		for (int j = 0; j < 4; ++j) {
			cout << setw(8) << votesByRegion[i][j];
		}
		cout << setw(8) << totalVotes[i] << endl;
	}

	Result(totalVotes, sizeof(totalVotes) / sizeof(totalVotes[0]),nameStruct);

	inFile.close();
}

void Result(const int array[], int arraySize, Name& name) {
	int totalVotes = 0;
	int maxElement = FindMax(array, arraySize);
	int winnerIndex = FindWinner(array, arraySize);
	cout << "Winner: " << name.candidatesName[winnerIndex] << "   " << "Votes Received: " << maxElement << endl;

	
	for (int i = 0; i < arraySize; i++)
	{
		totalVotes += array[i];
	}
	cout << "Total votes polled: " << totalVotes << endl;
}


int FindMax(const int array[], int size) {
	int maxElement = array[0];
	int winnerIndex = 0;

	for (int i = 1; i < size; ++i) {
		if (array[i] > maxElement) maxElement = array[i];
	}
	return maxElement;
}

int FindWinner(const int array[], int size) {
	int maxElement = array[0];
	int winnerIndex = 0;

	for (int i = 1; i < size; ++i) {
		if (array[i] > maxElement) winnerIndex = i;
	}
	return winnerIndex;
}


