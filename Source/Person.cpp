#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

Person::Person()
{
	name = "";
	birthDate = "";
	occupation = "";
	contactNo = "";
	martialStatus = "";
	gender = ' ';
}

Person::Person(string n, string bd, string o, string c, string cn, string m, string ci, string co, string s, bool g)
{
	name = n;
	birthDate = bd;
	occupation = o;
	contactNo = cn;
	martialStatus = m;
	gender = g;
}

void Person::setName(string n)
{
	name = n;
}

string Person::getName()
{
	return name;
}

void Person::setBirthDate(string bd)
{
	birthDate = bd;
}

string Person::getBirthDate()
{
	return birthDate;
}

void Person::setOccupation(string o)
{
	occupation = o;
}

string Person::getOccupation()
{
	return occupation;
}

//void Person::setCNIC(string c)
//{
//	CNIC = c;
//}
//
//string Person::getCNIC()
//{
//	return CNIC;
//}

void Person::setContactNo(string cn)
{
	contactNo = cn;
}

string Person::getContactNo()
{
	return contactNo;
}

void Person::setMartialStatus(string m)
{
	martialStatus = m;
}

string Person::getMartialStatus()
{
	return martialStatus;
}

void Person::setGender(string g)
{
	gender = g;
}

string Person::getGender()
{
	return gender;
}

void Person::setBloodGroup(string b)
{
	bloodGroup = b;
}

string Person::getBloodGroup()

{
	return bloodGroup;
}

Person::~Person()
{
	
}