#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "Course.h"
#include <map>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student : public Person
{
public:
	Student()
		: Person(),
		m_major(""),
		m_courses()
	{

	}

	// Getters
	string getMajor() const;

	// Setters
	void setMajor(string);

	// Virtual functions:
	virtual void read();
	virtual void write();

	// Tesk 3
	float computeGPA();
	void printTranscript();
	void addCourse(Course *course);


protected:

private:
	string m_major;
	vector<Course*> m_courses;

	map<string, float>my_map;
};
#endif