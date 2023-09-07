#pragma once
#include <string>
#include <iostream>
#include "Inventory.h"
#include "AdmitPatient.h"
using namespace std;

class Billing
{
	double bill;
	int* prices, *amount, size;
	string* product;
public:
	Billing();
	Billing(double, double, double, double);
	void findPrices(string*, int*, int);
	void totalBill(int);
	friend string spaceRemover(string);
	friend string underScoreRemover(string);
	void display();
};