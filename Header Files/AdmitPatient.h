#pragma once
#include<iostream>
#include"Inventory.h"
using namespace std;
class AdmitPatient //:
{
private:
	static int IDInitializer;
	int patientId;
	string name, phone, gender, roomType;
	float price;
public:
	Inventory* inv;
	AdmitPatient();

	void setRoom(string);
	void getPatientInfo();
	void assignRoom(string&);
	void assignSupplies();
	void addPatientToFile();
	void display();
	void setID();
	void dischargePatient(int);
	friend string spaceRemover(string);
	friend string underScoreRemover(string);
	int getDigits(string);
	void setPatientID(string);
	string getpatient_id();
	void setprice(float);
	float getprice();
	void Rooms(int);
	void patient_information();
};