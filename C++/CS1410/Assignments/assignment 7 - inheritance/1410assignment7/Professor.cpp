#include "Professor.h"


	// Getters
string Professor::getJobTitle() const
{
	return m_jobTitle;
}

string Professor::getOffice() const
{
	return m_office;
}

double Professor::getSalary() const
{
	return m_salary;
}


	 // Setters
void Professor::setJobTitle(string title)
{
	m_jobTitle = title;
}

void Professor::setOffice(string office)
{
	m_office = office;
}

void Professor::setSalary(double salary)
{
	m_salary = salary;
}


	// Virtuals
void Professor::read()
{
	Person::read();
	cout << "Job Title: ";
	cin >> m_jobTitle;
	cout << "Office: ";
	cin >> m_office;
	cout << "Salary: ";
	cin >> m_salary;
	cout << endl;
}

void Professor::write()
{
	Person::write();
	cout << "Job Title: " << m_jobTitle << endl;
	cout << "Office: " << m_office << endl;
	cout << "Salary: " << m_salary << endl;
	cout << endl;
}