#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

using namespace std;

class Course
{
public:
	Course()
		: m_courseId(""),
		m_courseName(""),
		m_credits(0),
		m_grade(""),
		m_semester(""),
		m_year(0)			
	{

	}
		
	string getCourseId() const;
	string getCourseName() const;
	int getCredits() const;
	string getGrade() const;
	string getSemester() const;
	int getYear() const;

	void setCourseId(string);
	void setCourseName(string);
	void setCredits(int);
	void setGrade(string);
	void setSemester(string);
	void setYear(int);

	virtual void read();
	virtual void write();
	

protected:


private:
	string m_courseId;
	string m_courseName;
	int m_credits;
	string m_grade;
	string m_semester;
	int m_year;


};

#endif