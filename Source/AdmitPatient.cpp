#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include"AdmitPatient.h"
#include "Inventory.h"
using namespace std;

int AdmitPatient::IDInitializer = 100;

AdmitPatient::AdmitPatient(){

	patientId = 0;
	price = 0.0;
	inv = new Inventory;
}

void AdmitPatient::setID(){
	string patientID, name, phone, gender, roomType, garbage;
	int counter = 0;
	ifstream fin("AdmittedPatients.txt");
	if (!fin.is_open()){
		cout << "Could Not Open File\"admittedPatients.txt.\"" << endl;
		cout << "Could Not New Generate Patient ID." << endl;
	}
	else{
		while (!fin.eof()){
			fin >> garbage;
			counter++;
		}
		fin.close();
	}
	if (counter <= 4)
		this->patientId = 101;
	else{
		counter -= 4;
		fin.open("AdmittedPatients.txt");
		for (int i = 0; i < counter; i++){
			fin >> patientID;
		}
		int id = stoi(patientID);
		this->patientId = ++id;
	}
}

void AdmitPatient::getPatientInfo(){
	cin.ignore();
	cout << "\t\t\t\t\t---------------------------------------" << endl;
	cout << "\t\t\t\t\t\tEnter Patient Information" << endl;
	cout << "\t\t\t\t\t---------------------------------------" << endl;
	cout << "\t\t\t\t\tEnter Name: "; getline(cin, name);
	name = spaceRemover(name);
	cout << "\t\t\t\t\tEnter Phone: "; cin >> this->phone;
	cout << "\t\t\t\t\tEnter Gender: "; cin >> this->gender;
}

void AdmitPatient::assignRoom(string& roomType){
	srand((unsigned)time(0));
	if (inv == nullptr)
		inv = new Inventory;
	system("cls");
	inv->RoomTypeCheck(roomType);
}

void AdmitPatient::assignSupplies(){
	int domain;
	domain = 1;
	string stringDomain = to_string(domain);
	inv->DomainCheck(stringDomain);
	domain = 2;
	stringDomain = to_string(domain);
	inv->DomainCheck(stringDomain);
}

void AdmitPatient::display(){
	cout << "\t\t\t\t\t---------------------" << endl;
	cout << "\t\t\t\t\tPatient Information" << endl;
	cout << "\t\t\t\t\t---------------------" << endl;
	cout << "\t\t\t\t\tName: " << this->name << endl;
	cout << "\t\t\t\t\tPhone: " << this->phone << endl;
	cout << "\t\t\t\t\tGender: " << this->gender << endl;
	cout << "\t\t\t\t\t---------------------" << endl;
}

void AdmitPatient::addPatientToFile(){
	ofstream fout("admittedPatients.txt", ios::app);
	fout << endl;
	fout << this->patientId;
	fout << " ";
	fout << this->name;
	fout << " ";
	fout << this->phone;
	fout << " ";
	fout << this->gender;
	fout << " ";
	if (roomType == "1")
		fout << "Private";
	else
		fout << "Combined";
}

void AdmitPatient::dischargePatient(int id){
	string idHolder;
	int fileID;
	string temp, garbage, dataToWrite;
	ifstream fin("AdmittedPatients.txt");
	if (!fin.is_open()){
		cout << "Could Not Open File\"admittedPatients.txt.\"" << endl;
		cout << "\t\t Could Not Discharge Patient With ID: \"" << id << "\"" << endl;
	}
	else{
		while (!fin.eof()){
			fin >> idHolder;
			fileID = stoi(idHolder);
			if (fileID != id){
				getline(fin, temp);
				temp = idHolder + temp + "\n";
				dataToWrite += temp;
			}
			else{
				cout << "\t   Discharging EMR" << idHolder << " - ";
				fin >> temp;
				temp = underScoreRemover(temp);
				cout << temp << "!" << endl;
				getline(fin, temp);
			}
		}
		fin.close();
	}
	if (!dataToWrite.empty())
		dataToWrite.pop_back();
	ofstream fout("AdmittedPatients.txt", ios::trunc);
	fout << dataToWrite;
	fout.close();
}

int AdmitPatient::getDigits(string s){
	int digits = 0;
	for (int i = 0; s[i] != '\0'; i++)
		digits++;
	return digits;
}

void AdmitPatient::setprice(float price)
{
	this->price = price;
}

float AdmitPatient::getprice()
{
	return price;
}

void AdmitPatient::Rooms(int room){

	if (room == 1)
	{
		cout << "===========Private room===========" << endl;
	}
	if (room == 2)
	{

		cout << "===========Common Room============" << endl;
	}
	else{
		cout << "Please Enter Again:" << endl;
		cin >> room;
	}
}