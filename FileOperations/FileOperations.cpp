#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

	ifstream inFile;
	ofstream outFile;

	int test1 = 0, test2 = 0, test3 = 0, test4 = 0, test5 = 0;
	int counter = 0;
	double average;
	char studentId = 0;
	string studentID;
	string note;


	inFile.open("test.txt");
	outFile.open("testavg.txt");

	outFile << fixed << showpoint;
	outFile << setprecision(2);

	cout << "Processing data" << endl;

	getline(inFile, studentID);
	outFile << "Student ID: " << studentID << endl;

	while (getline(inFile, note)) {
		try {
			switch (counter)
			{
			case 0:
				test1 = stoi(note);
				break;
			case 1:
				test2 = stoi(note);
				break;
			case 2:
				test3 = stoi(note);
				break;
			case 3:
				test4 = stoi(note);
			case 4:
				test5 = stoi(note);
				break;
			default:
				break;
			}
			counter++;

		}
		catch (const invalid_argument& e) {
			cerr << "conversion error: " << e.what() << endl;
		}
		catch (const out_of_range& e) {
			cerr << "overflow error: " << e.what() << endl;
		}
	}

	outFile << "Test scores: " << setw(4) << test1
		<< setw(4) << test2 << setw(4) << test3
		<< setw(4) << test4
		<< setw(4) << test5 << endl;


	average = (static_cast<double>(test1) + test2 + test3 + test4 + test5) / 5;
	outFile << "Average Note: " << average;

	inFile.close();
	outFile.close();

	return 0;
}