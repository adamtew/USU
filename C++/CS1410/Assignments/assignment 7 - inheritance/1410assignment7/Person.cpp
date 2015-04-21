#include "Person.h"
#include <iostream>
using namespace std;

	// Getters
string Person::getId() const
{
	return m_id;
}

string Person::getName() const
{
	return m_name;
}

string Person::getDate() const
{
	return m_date;
}

string Person::getAddress() const
{
	return m_address;
}

void Person::setId(int id)
{
	m_id = id;
}

void Person::setName(string name)
{
	m_name = name;
}

void Person::setDate(string date)
{
	m_date = date;
}

void Person::setAddress(string address)
{
	m_address = address;
}

	// Virtuals
void Person::read()
{
	cout << "Personal information: \n\n";
	cout << "ID: ";
	cin >> m_id;
	cout << "Name: ";
	cin >> m_name;
	cout << "Gender: ";
	cin >> m_gender;
	cout << "Date of Birth: ";
	cin >> m_date;
	cout << "Address: ";
	cin >> m_address;
}

void Person::write()
{
	cout << "\nID: " << m_id << endl;
	cout << "Name: " << m_name << endl;
	cout << "Date of Birth: " << m_date << endl;
	cout << "Gender: " << m_gender << endl;
	cout << "Address: " << m_address << endl;
}