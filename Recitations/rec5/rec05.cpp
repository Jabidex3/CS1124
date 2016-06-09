/*
	Jabid Methun
	CS-UY 1124
	Section: B
	jhm414
	N14285139
	Rec05
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TimeSlot
{
private:
	string day;
	int hours;
public:
	TimeSlot(const string& day, int hours) : day(day), hours(hours){}

	string getDay()
	{
		return day;
	}

	int getHours()
	{
		return hours;
	}

	void display()
	{
		cout << day << " ";
		if (hours > 12)
		{
			cout << hours - 12 << "PM" << endl;
		}
		else if (hours == 12)
			cout << hours << "PM" << endl;
		else
			cout << hours << "AM" << endl;
	}

};

class Student
{
private:
	string name;
	vector<int> grade;

public:
	Student(const string& name) : name(name), grade(13, -1) {}

	string getName()
	{
		return name;
	}

	void setGrade(int gr, int week) 
	{ 
		grade[week] = gr; 
	}

	void display()
	{
		cout << "Student: " << name << "; Grades: ";
		for (int g : grade)
		{
			cout << g << " ";
		}
	}
};

class Section
{
private:
	string name;
	string day;
	int hour;
	vector <Student*> students ;
	TimeSlot ts;
public:
	Section(const string& name,  const string& day, int hour) :name(name), day(day), hour(hour), ts(day, hour) {}
	vector<Student*> getStudents() 
	{
		return students; 
	}

	void addStudent(const string& name)
	{
		bool thereAlready = false;
		for (size_t i = 0; i < students.size(); i++)
		{
			if (students[i]->getName() == name)
			{
				thereAlready;
			}
		}
		if (!thereAlready)
		{
			Student* stu = new Student(name);
			students.push_back(stu);
		}
	}

	int getIndex(const string& name)
	{
		int x;
		for (size_t i = 0; i < students.size(); i++)
		{
			if (name == students[i]->getName())
			{
				x = i;
			}
		}
		return x;
	}

	void setGrade(int x, int grade, int week)
	{
		students[x]->setGrade(grade, week);
	}
	void reset() 
	{ 
		students.clear(); 
	}

	void display()
	{
		cout << "Section: " << name << "; ";
		ts.display();
		for (size_t i = 0; i < students.size(); i++)
		{
			students[i]->display();
			cout << endl;
		}
		cout << endl;
	}


};

class LabWorker
{
private:
	string name;
	Section* section;
public:
	LabWorker(const string& name) :name(name), section(nullptr) {}
	string getName()
	{
		return name;
	}

	void addGrade(const string &name, int grade, int week)
	{
		int x = section->getIndex(name);
		section->setGrade(x, grade, week);
	}

	void addSection(Section& sec)
	{
		section = &sec;
	}
	void displayGrades()
	{
		cout << name << " has ";
        section->display();
        //cout << endl;
	}
};
int main()
{
	// lab workers
	LabWorker moe("Moe");
	LabWorker jane("Jane");

		// sections and setup and testing
	Section secA2("A2", "Tuesday", 16);
	//secA2.loadStudentsFromFile( "A2.txt" );
	secA2.addStudent("John");
	secA2.addStudent("George");
	secA2.addStudent("Paul");
	secA2.addStudent("Ringo");

	
	cout << "\ntest A2\n";    // here the modeler-programmer checks that load worked
	secA2.display();          // YOU'll DO THIS LATER AS: cout << secA2 << endl;
	moe.addSection(secA2);
	moe.displayGrades();       // here the modeler-programmer checks that adding the Section worked
	
	
	Section secB3("B3", "Thursday", 11);
	//secB3.loadStudentsFromFile( "B3.txt" );
	secB3.addStudent("Thorin");
	secB3.addStudent("Dwalin");
	secB3.addStudent("Balin");
	secB3.addStudent("Kili");
	secB3.addStudent("Fili");
	secB3.addStudent("Dori");
	secB3.addStudent("Nori");
	secB3.addStudent("Ori");
	secB3.addStudent("Oin");
	secB3.addStudent("Gloin");
	secB3.addStudent("Bifur");
	secB3.addStudent("Bofur");
	secB3.addStudent("Bombur");

	cout << "\ntest B3\n";    // here the modeler-programmer checks that load worked
	secB3.display();          // YOU'll DO THIS LATER AS: cout << secB3 << endl;
	jane.addSection(secB3);
	jane.displayGrades();      // here the modeler-programmer checks that adding Instructor worked


	// setup is complete, now a real world scenario can be written in the code
	// [NOTE: the modeler-programmer is only modeling joe's actions for the rest of the program]

	// week one activities  
	cout << "\nModeling week: 1\n";
	moe.addGrade("John", 7, 1);
	moe.addGrade("Paul", 9, 1);
	moe.addGrade("George", 7, 1);
	moe.addGrade("Ringo", 7, 1);
	cout << "End of week one\n";
	moe.displayGrades();

	// week two activities
	cout << "\nModeling week: 2\n";
	moe.addGrade("John", 5, 2);
	moe.addGrade("Paul", 10, 2);
	moe.addGrade("Ringo", 0, 2);
	cout << "End of week two\n";
	moe.displayGrades();

	//test that reset works  // NOTE: can we check that the heap data was dealt with?
	cout << "\ntesting reset()\n";
	secA2.reset();
	secA2.display();
	moe.displayGrades();
	system("pause");
}