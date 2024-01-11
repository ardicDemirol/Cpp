#include <iostream>
//using std::string;
//using std::cout;
//using std::endl;
using namespace std;

class  AbstractEmployee {
	virtual void AskForPromotion() = 0;
};

class Employee : AbstractEmployee {
private:
	string Company;
	int Age;
protected:
	string Name;

public:

#pragma region Properties

	void setName(string name) { Name = name; }
	string getName() { return Name; }

	void setCompany(string company) { Company = company; }
	string getCompany() { return Company; }

	void setAge(int age)
	{
		if (age < 18) return;
		Age = age;
	}
	int getAge() { return Age; }

#pragma endregion

#pragma region Method

	void IntroduceYourself() {
		cout << "Name - " << Name << endl;
		cout << "Company - " << Company << endl;
		cout << "Age - " << Age << endl;
	}

#pragma endregion

#pragma region Constructor

	Employee(string name, string company, int age) {
		Name = name;
		Company = company;
		Age = age;
	}
#pragma endregion

#pragma region Abstract Method

	void AskForPromotion() {
		if (Age > 30) {
			cout << Name << " got promoted!" << endl;
		}
		else {
			cout << Name << ", sorry no promotion for you!" << endl;
		}
	}
#pragma endregion

#pragma region Polymorphism

	virtual void Work() {
		cout << Name << " is checking email, task backlog, performing tasks..." << endl;
	}
#pragma endregion


};

class Developer : public Employee {
public:
	string FavProgrammingLanguage;

	Developer(string name, string company, int age, string favProgrammingLanguage) : Employee(name, company, age)
	{
		FavProgrammingLanguage = favProgrammingLanguage;
	}

	void FixBug() {
		//cout << getName() << " fixed bug using " << FavProgrammingLanguage << endl;
		cout << Name << " fixed bug using " << FavProgrammingLanguage << endl;
	}

	void Work() {
		cout << Name << " is writting " << FavProgrammingLanguage << " code " << endl;
	}
};

class Teacher : public Employee {
public:
	string Subject;

	void PrepareLesson() {
		cout << Name << " is preparing " << Subject << " lesson" << endl;
	}

	Teacher(string name, string company, int age, string subject) : Employee(name, company, age)
	{
		Subject = subject;
	}

	void Work() {
		cout << Name << " is teaching " << Subject << endl;
	}
};

int main()
{
	//Employee employee1 = Employee("Ardic", "Creatiny", 40);
	//Employee employee2 = Employee("Eser", "NFK", 16);
	//employee1.AskForPromotion();
	//employee2.AskForPromotion();

	Developer dev = Developer("John", "Rockstar", 40, "C++");
	//dev.FixBug();
	//dev.AskForPromotion();
	//dev.Work();

	Teacher teacher = Teacher("Leonardo", "Cool School", 35, "History");
	//teacher.PrepareLesson();
	//teacher.AskForPromotion();
	//teacher.Work();

	Employee *e1 = &dev;
	Employee *e2 = &teacher;
	e1->Work();
	e2->Work();


}

