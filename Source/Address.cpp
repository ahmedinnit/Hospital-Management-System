#pragma once
#include "Address.h"
#include <iostream>
#include <string>
using namespace std;

Address::Address()
{
	streetNo = "";
	city = "";
	country = "";
}

Address::Address(string ci, string co, string sn)
{
	city = ci;
	country = co;
	streetNo = sn;
}

void Address::setCity(string ci)
{
	this->city = ci;
}

string Address::getCity()
{
	return city;
}

void Address::setCountry(string co)
{
	this->country = co;
}

string Address::getCountry()
{
	return country;
}

void Address::setStreetNo(string s)
{
	streetNo = s;
}

string Address::getStreetNo()
{
	return streetNo;
}

Address::~Address()
{

}

void Address::setAddress(string a)
{
	concatinatedAddress = a;
}

string Address::getAddress()
{
	return concatinatedAddress;
}

void Address::inputAddress()
{
	cout << "\t\t\t\t\tEnter Street No: "; getline(cin, streetNo);
	cout << "\t\t\t\t\tEnter City: "; getline(cin, city);
	cout << "\t\t\t\t\tEnter Country: "; getline(cin, country);
	concatinatedAddress = streetNo + "," + city + "," + country;
}

void Address::printAddress()
{
	cout << "\t\t   Address: " << concatinatedAddress << endl;
}