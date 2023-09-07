#pragma once
#include "Person.h"
#include <string>
using namespace std;

class Patient: public Person
{
	string* medicines;
	int* medicineQuantity;
	string disease, symptoms, patientID, appointment, appointedDoctor, bloodGroup, martialStatus;
	int symptomCount, medicineCount;
public:
	Patient();
	Patient(string, string, string, string, string, string, 
			string, string, string, string, string, string, string, string, string, bool);
	void setSymptom(string);
	string getSymptom();
	void setDisease(string);
	string getDisease();
	void setPatientID(string);
	string getPatientID();
	void setAppointment(string);
	string getAppointment();
	void setappointedDoctor(string);
	string getappointedDoctor();
	void setBloodGroup(string);
	string getBloodGroup();
	void setMedicines(string*);
	string* getMedicines();
	void setMedicineQuantity(int*);
	int* getMedicineQuantity();
	void storeSymptom(string);
	int getSymptomCount();
	void setSymptomCount(int);
	void setMedicineCount(int);
	int getMedicineCount();
	void takeInput();
	void displayInfo();
	void resetPatient();
	void displayList(int);
	friend void stringConverter(string&);
	friend string spaceRemover(string);
	friend string underScoreRemover(string);
};


