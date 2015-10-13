#include "Course.h"
#include "Person.h"
#include "Professor.h"
#include "Student.h"

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

Person* findPerson(string id);
void addPerson(string type);
void addCourse();
void printOptions();
void choose();
void findTranscript();
void printProfessor();
void printPeople();

vector<Person*> people;

int main()
{
	choose();

	return 0;
}

Person* findPerson(string id)
{
	for (int i = 0; i < people.capacity(); i++)
		if (people[i]->getId() == id)
			return people[i];

	if (true)
		throw string("That person could not be found\n");
	Person* p;
	return p;
}

void addPerson(string type)
{
	if (type == "student")
	{
		Person* p = new Student;
		p->read();
		people.push_back(p);
	}
	else if (type == "professor")
	{
		Person* p = new Professor;
		p->read();
		people.push_back(p);
	}
	else
	{
		cout << "That's not an appropriate type\n";
	}
}

void addCourse()
{
	string id;
	cout << "Student ID: ";
	cin >> id;
	
	Course* c = new Course;
	c->read();
	
	try
	{
		static_cast<Student*>(findPerson(id))->addCourse(c);
	}
	catch (string e)
	{
		cout << e;
	}
}

void printOptions()
{
	cout << "Select your choice: \n";
	cout << "1. Add a professor \n";
	cout << "2. Add a student \n";
	cout << "3. Add a course for a student \n";
	cout << "4. Print the transcript of a student\n";
	cout << "5. Print information of a professor\n";
	cout << "6. Quit\n\n";
	cout << "Option: ";
}

void choose()
{
	int x = 0;
	while (x != 6)
	{
		printOptions();
		cin >> x;
		switch (x)
		{
		case 1: addPerson("professor"); break;
		case 2: addPerson("student"); break;
		case 3: addCourse(); break;
		case 4: findTranscript(); break;
		case 5: printProfessor(); break;
		default:
			break;
		}
	}
}

void findTranscript()
{
	string id;
	cout << "Student id: ";
	cin >> id;
	try
	{
		static_cast<Student*>(findPerson(id))->printTranscript();
	}
	catch (string e)
	{
		cout << e << endl;
	}
}

void printProfessor()
{
	string id;
	cout << "Student id: ";
	cin >> id;
	try
	{
		static_cast<Professor*>(findPerson(id))->write();
	}
	catch (string e)
	{
		cout << e;
	}
}