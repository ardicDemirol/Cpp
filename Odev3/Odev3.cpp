// 402570 - Ardýç Demirol
// 410730 - MOHAMMAD SABIR NAZIRI

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm> 
using namespace std;

class CourseInfo {
public:
	string CourseName;
	string CourseNo;
	char CourseGrade;
	short CourseCredit;
};

class CourseType : public CourseInfo {
public:
	void SetCourseInfo(string courseName, string courseNo, char courseGrade, short courseCredit) {
		CourseName = courseName;
		CourseNo = courseNo;
		CourseGrade = courseGrade;
		CourseCredit = courseCredit;
	}

	void PrintCourseInfoToFile(ofstream& outputFile) const {
		outputFile << setw(10) << CourseNo << setw(15) << CourseName << setw(8) << CourseCredit << setw(6) << CourseGrade << endl;
	}
};

class PersonType {
public:
	string FirstName;
	string  LastName;
};

class StudentInfo : public PersonType {
public:
	int StudentID;
	bool IsTuitionPaid;
	int CoursesEnrolled;
};

class StudentType : public StudentInfo {
public:
	vector<CourseType> courses;

	void SetName(string firstName, string lastName) {
		FirstName = firstName;
		LastName = lastName;
	}

	void SetInfo(int studentID, string isTuitionPaid, int coursesEnrolled) {
		StudentID = studentID;
		if (isTuitionPaid == "Y") {
			IsTuitionPaid = true;
		}
		else {
			IsTuitionPaid = false;
		}
		CoursesEnrolled = coursesEnrolled;
	}

	void AddCourse(CourseType course) {
		courses.push_back(course);
	}

	void PrintStudentInfo(string fileName, int courseAmountPerCredit) const {
		ofstream outputFile(fileName, ios::app);
		outputFile << "Student Name: " << FirstName << " " << LastName << endl;

		if (IsTuitionPaid) {

			outputFile << "Student ID: " << StudentID << endl;
			outputFile << "Number of courses enrolled: " << CoursesEnrolled << endl;
			outputFile << setw(10) << "Course No" << setw(15) << "Course Name" << setw(8) << "Credits" << setw(6) << "Grade" << endl;

			vector<CourseType> sortedCourses = courses;
			sort(sortedCourses.begin(), sortedCourses.end(), [](const CourseType& a, const CourseType& b) {
				return a.CourseName < b.CourseName;
				});

			// aralýklý for döngüsü , auto& deðiþeken türünü otomatik olarak belirler.
			for (const auto& course : sortedCourses) {
				course.PrintCourseInfoToFile(outputFile);
			}

			//for (const CourseType& course : sortedCourses) {
			//	course.PrintCourseInfoToFile(outputFile);
			//}

			outputFile << "Total number of credits: " << CalculateTotalCredits() << endl;
			outputFile << "Mid-Semester GPA: " << fixed << setprecision(2) << CalculateGPA() << endl;
			outputFile << endl;

		}
		else {

			outputFile << "Tuition is not paid. And total tuition is: " << courseAmountPerCredit * CalculateTotalCredits() << endl;
		}

		outputFile.close();

	}


	int CalculateTotalCredits() const {
		int totalCredits = 0;
		for (const auto& course : courses) {
			totalCredits += course.CourseCredit;
		}
		return totalCredits;
	}

	double CalculateGPA() const {
		double totalPoints = 0.0;
		for (const auto& course : courses) {
			totalPoints += GradeToPoint(course.CourseGrade) * course.CourseCredit;
		}
		return totalPoints / CalculateTotalCredits();
	}

	static double GradeToPoint(char grade) {
		switch (grade) {
		case 'A': return 4.0;
		case 'B': return 3.0;
		case 'C': return 2.0;
		case 'D': return 1.0;
		case 'F': return 0.0;
		default: return 0.0;
		}
	}
};

int main() {
	ifstream inputFile("input.txt");
	if (!inputFile) {
		cerr << "Error opening input file." << endl;
		return 1;
	}

	vector<StudentType> students;
	string line;
	int courseAmountPerCredit;
	int numberOfStudents;

	while (getline(inputFile, line)) {
		istringstream iss(line);
		iss >> numberOfStudents >> courseAmountPerCredit;

		for (int i = 0; i < numberOfStudents; i++) {
			StudentType student;
			int studentID, actualNumberOfCourses;
			string isTuitionPaid;
			string studentInfoLine;
			// Öðrenci bilgilerini oku
			
			getline(inputFile, studentInfoLine);  // Bir sonraki satýrý oku
			istringstream studentInfoStream(studentInfoLine);

			studentInfoStream >> student.FirstName >> student.LastName >> studentID >> isTuitionPaid >> actualNumberOfCourses;

			student.SetName(student.FirstName, student.LastName);
			student.SetInfo(studentID, isTuitionPaid, actualNumberOfCourses);

			// Kurs bilgilerini oku
			for (int j = 0; j < actualNumberOfCourses; j++) {
				CourseType course;
				getline(inputFile, line);  // Bir sonraki satýrý oku
				istringstream courseInfoStream(line);

				courseInfoStream >> course.CourseName >> course.CourseNo >> course.CourseCredit >> course.CourseGrade;
				student.AddCourse(course);
			}

			students.push_back(student);
		}
	}

	inputFile.close();

	for (const auto& student : students) {
		student.PrintStudentInfo("output.txt", courseAmountPerCredit);
	}

	cout << "Results saved a txt file" << endl;
	return 0;
}

