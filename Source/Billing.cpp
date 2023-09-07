#include<iostream>
#include<fstream>
#include<string>
#include"Billing.h"
#include"AdmitPatient.h"
using namespace std;
Billing::Billing()
{
	/*doc_fee = 0;
	room_charges = 0;
	parmacy_bills = 0;
	Sum = 0.0;*/
}

Billing::Billing(double df, double rc, double pb, double s)
{
	/*doc_fee = df;
	room_charges = rc;
	parmacy_bills = pb;
	Sum = s;*/
}

void Billing::totalBill(int size)
{
	for (int i = 0; i < size; i++)
			bill += prices[i] * amount[i];
}

void Billing::findPrices(string* medicines, int* quantity, int s)
{
	size = s;
	product = new string[size];
	amount = new int[size];
	for (int i = 0; i < size; i++)
	{
		product[i] = medicines[i];
		amount[i] = quantity[i];
	}
	prices = new int[size];
	int i = 0;
	string temp = "";
	ifstream fin("PharmacyStock.txt");
	while (!fin.eof())
	{
		fin >> temp;
		if (temp == product[i])
		{
			fin >> temp;
			fin >> temp;
			prices[i] = stoi(temp);
			i++;
			if (i == size)
				break;
		}
		else
			getline(fin, temp);
	}
	fin.close();
}


void Billing::display()
{
	cout << "\t\t\t\t--------------------------------------" << endl;
	cout << "\t\t\t\t Medicine\tQuantity\t    Price" << endl;
	cout << "\t\t\t\t--------------------------------------" << endl;
	for (int i = 0; i < size; i++)
		cout << "\t\t\t\t " << product[i] << "\t  " << amount[i] << "\t    " << prices[i] << endl;
	cout << "\t\t\t\t--------------------------------------" << endl;
	cout << "\t\t\t\tTotal Bill : " << bill << " PKR" << endl;
}