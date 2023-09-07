#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include "Billing.h"
using namespace std;

class Pharmacy
{
private:
	string* prescription;
	int* medicineQuantities;
	int amount, prescriptionSize;
	int user_quantity;
public:
	Billing billing;
	Pharmacy();
	Pharmacy(string*, int*);
	void setPrescription(string*, int);
	void setMedicineQuantities(int*);
	void updateFile();
	void writeQuantity(streampos, int, int);
	void setAmount();
	string* getPrescription();
	friend string spaceRemover(string);
	friend string underScoreRemover(string);
	int digitCount(int);
};