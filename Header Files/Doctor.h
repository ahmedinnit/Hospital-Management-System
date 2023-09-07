#pragma once
#include "Person.h"
#include <string>
using namespace std;

class Doctor: public Person
{
	//string medicines[3];
	int* medicineQuantity;
	string speciality, timings, experience, employeeID, duration, instructions;
	double pay;
public:
	Doctor();
	Doctor(string, string, string, string, string);
	void setEmployeeID(string);
	string getEmployeeID();
	void setSpeciality(string);
	string getSpeciality();
	void setTimings(string);
	string getTimings();
	void setExperience(string);
	string getExperience();
	void setDuration(string);
	string getDuration();
	void setInstructions(string);
	string getInstructions();
	void setPay(double);
	double getPay();
	string findDisease(string, bool&);
	string* generatePrescription(string, int*&, int&);
	void setTimings();
	void displayInfo();
	void readData(int);
	void displayList(int);
	friend string spaceRemover(string);
	friend string underScoreRemover(string);
	friend void stringConverter(string &s);
	~Doctor();
};

