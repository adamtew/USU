#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Person.h"
#include <iostream>

using namespace std;

class Professor : public Person
{
public:
	Professor()
		: Person(),
		m_jobTitle(""),
		m_office(""),
		m_salary(0)
	{

	}

	string getJobTitle() const;
	string getOffice() const;
	double getSalary() const;

	void setJobTitle(string);
	void setOffice(string);
	void setSalary(double);

		// Virtual functions:
	virtual void read();
	virtual void write();
protected:

private:
	string m_jobTitle;
	string m_office;
	double m_salary;
};

#endif;