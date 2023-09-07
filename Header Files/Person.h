#pragma once
#include <string>
#include "Address.h"
using namespace std;

class Person
{
	string name, birthDate, contactNo, occupation, bloodGroup, gender, martialStatus;
public:
	Address address;
	Person();
	Person(string, string, string, string, string, string, string, string, string, bool);
	void setName(string);
	string getName();
	void setBirthDate(string);
	string getBirthDate();
	void setOccupation(string);
	string getOccupation();
	void setContactNo(string);
	string getContactNo();
	void setMartialStatus(string);
	string getMartialStatus();
	void setGender(string);
	string getGender();
	void setBloodGroup(string);
	string getBloodGroup();
	virtual void displayInfo() = 0;
	~Person();
};