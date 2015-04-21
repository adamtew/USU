#include "Course.h"

	// Getters
string Course::getCourseId() const
{
	return m_courseId;
}
string Course::getCourseName() const
{
	return m_courseName;
}
int Course::getCredits() const
{
	return m_credits;
}

string Course::getGrade() const
{
	return m_grade;
}

string Course::getSemester() const
{
	return m_semester;
}

int Course::getYear() const
{
	return m_year;
}


	// Setters
void Course::setCourseId(string id)
{
	m_courseId = id;
}

void Course::setCourseName(string name)
{
	m_courseName = name;
}

void Course::setCredits(int credits)
{
	m_credits = credits;
}

void Course::setGrade(string grade)
{
	m_grade = grade;
}

void Course::setSemester(string semester)
{
	m_semester = semester;
}

void Course::setYear(int year)
{
	m_year = year;
}


	// Virtuals
void Course::read()
{
	cout << "Course ID: ";
	cin >> m_courseId;
	cout << "Course Name: ";
	cin >> m_courseName;
	cout << "Credits: ";
	cin >> m_credits;
	cout << "Grade: ";
	cin >> m_grade;
	cout << "Semester: ";
	cin >> m_semester;
	cout << "Year: ";
	cin >> m_year;
	cout << endl;
}

void Course::write()
{
	cout << "Course ID: " << m_courseId << endl;
	cout << "Course Name: " << m_courseName << endl;
	cout << "Credits: " << m_credits << endl;
	cout << "Grade: " << m_grade << endl;
	cout << "Semester: " << m_semester << endl;
	cout << "Year: " << m_year << endl;
}
