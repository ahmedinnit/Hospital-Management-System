#pragma once
#include <string>
using namespace std;
class Address
{
	string city, country, streetNo, concatinatedAddress;
public:
	Address();
	Address(string, string, string);
	void setCity(string);
	string getCity();
	void setCountry(string);
	string getCountry();
	void setStreetNo(string);
	string getStreetNo();
	void setAddress(string);
	string getAddress();
	void inputAddress();
	void printAddress();
	~Address();
};