#include "Student.h"

#include <iomanip>
#include <iostream>

using namespace std;

	// Getters
string Student::getMajor() const
{
	return m_major;
}


	// Setters
void Student::setMajor(string major)
{
	m_major = major;
}


	// Virtuals
void Student::read()
{
	Person::read();

	cout << "Major: ";
	cin >> m_major;
	cout << endl;
}

void Student::write()
{
	Person::write();
	cout << "Major: " << m_major << endl;
}


	// Tesk 3
float Student::computeGPA()
{
	float gpa = 0;
	float cummulative = 0;
	int credits = 0;
	for (int i = 0; i < m_courses.capacity(); i++)
	{
		if (m_courses[i]->getGrade() == "A-") gpa = 4.0;
		if (m_courses[i]->getGrade() == "A+") gpa = 4.0;
		if (m_courses[i]->getGrade() == "A") gpa = 3.7;
		if (m_courses[i]->getGrade() == "A-") gpa = 3.3;
		if (m_courses[i]->getGrade() == "B+") gpa = 3.0;
		if (m_courses[i]->getGrade() == "B") gpa = 2.7;
		if (m_courses[i]->getGrade() == "B-") gpa = 2.3;
		if (m_courses[i]->getGrade() == "C+") gpa = 2.0;
		if (m_courses[i]->getGrade() == "C") gpa = 1.7;
		if (m_courses[i]->getGrade() == "C-") gpa = 1.3;
		if (m_courses[i]->getGrade() == "D+") gpa = 1.0;
		if (m_courses[i]->getGrade() == "D") gpa = 0.7;
		if (m_courses[i]->getGrade() == "D-") gpa = 0.3;
		if (m_courses[i]->getGrade() == "F") gpa = 0.0;
		if (m_courses[i]->getGrade() == "I") continue;
		if (m_courses[i]->getGrade() == "X") continue;

		credits += m_courses[i]->getCredits();
		cummulative += gpa * m_courses[i]->getCredits();
	}

	if (credits <= 0) return 0;

	gpa = cummulative / credits;
	return gpa;
}

void Student::printTranscript()
{
	int credits = 0;

	Person::write();
	cout << "Major: " << getMajor() << "\n\n";
	cout << "List of courses: \n\n";
	for (int i = 0; i < m_courses.capacity(); i++)
	{
		cout << "Course ID: " << m_courses[i]->getCourseId() << endl;
		cout << "Course name: " << m_courses[i]->getCourseName() << endl;
		cout << "Time taken: " << m_courses[i]->getSemester() << " " << m_courses[i]->getYear() << endl;
		cout << "Number of credits: " << m_courses[i]->getCredits() << endl;
		cout << "Final grade: " << m_courses[i]->getGrade() << "\n\n";
		credits += m_courses[i]->getCredits();
	}

	cout << "Cummulative hourse: " << credits << ". Cummulative GPA: " << setprecision(2) << computeGPA() << "\n\n";

		
	cout << endl;
}

void Student::addCourse(Course *course)
{
	m_courses.push_back(course);
}