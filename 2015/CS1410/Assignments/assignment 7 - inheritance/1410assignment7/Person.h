#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	Person()
		: m_id(""),
		m_name(""),
		m_date(""),
		m_address("")
	{

	}

	string getId() const;
	string getName() const;
	string getDate() const;
	string getAddress() const;
	string getGender() const;

	void setId(int);
	void setName(string);
	void setDate(string);
	void setAddress(string);
	void setGender(string);

		// Virtuals
	virtual void read();
	virtual void write();

protected:

private:
	string m_id;
	string m_name;
	string m_date;
	string m_address;
	string m_gender;
};

#endif