#include "Patient.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

Patient::Patient()
{
	disease = "";
	symptoms = ""; 
	appointment = ""; 
	patientID = ""; 
	appointedDoctor = "";
}

Patient::Patient(string d, string sym, string a, string ad, string pi, string bg, string n, string bd, string o, 
	string c, string cn, string m, string ci, string co, string s, bool g): Person(n, bd, o, c, cn, m, ci, co, s, g)
{
	disease = d;
	symptoms = s;
	appointment = a;
	appointedDoctor = ad;
	patientID = pi;
	bloodGroup = bg;
}

void Patient::setSymptom(string s)
{
	bool checkSymptom;
	string temp, store;
	ifstream fin("Symptoms.txt");
	string temp2;
	stringConverter(s);
	while (!fin.eof())
	{
		fin >> temp;
		temp = underScoreRemover(temp);
		temp2 = temp;
		stringConverter(temp);
		store = temp;
		if (temp == s)
		{
			checkSymptom = true;
			symptomCount++;
			break;
		}
		checkSymptom = false;
	}
	fin.eof();
	if (checkSymptom == true)
	{
		if (symptoms == "")
			symptoms = temp2;
		else
			symptoms += "," + temp2;
	}
}

string Patient::getSymptom()
{
	return symptoms;
}

void Patient::setDisease(string d)
{
	disease = d;
}

string Patient::getDisease()
{
	return disease;
}

void Patient::setPatientID(string id)
{
	patientID = id;
}

string Patient::getPatientID()
{
	return patientID;
}

void Patient::setAppointment(string ap)
{
	appointment = ap;
}

string Patient::getAppointment()
{
	return appointment;
}

void Patient::setappointedDoctor(string a)
{
	appointedDoctor = a;
}

string Patient::getappointedDoctor()
{
	return appointedDoctor;
}

void Patient::setBloodGroup(string b)
{
	bloodGroup = b;
}

string Patient::getBloodGroup()
{
	return bloodGroup;
}

void Patient::takeInput()
{
	string temp;
	int tempInt = 0, size = 0;
	char tempChar = ' ';
	cout << "\t\t\t\t\t---------------------------------------" << endl;
	cout << "\t\t\t\t\t\tEnter Patient Information" << endl;
	cout << "\t\t\t\t\t---------------------------------------" << endl;
	cout << "\t\t\t\t\tEnter Name: "; getline(cin, temp); setName(temp);
	cout << "\t\t\t\t\t   ~~~Please Enter Your Birth Date~~~" << endl;
	cout << "\t\t\t\t\tEnter Day: "; cin >> tempInt;
	while (tempInt > 30 || tempInt < 1)
	{
		cout << "\t\t\t\t\tInvalid Day!" << endl;
		cout << "\t\t\t\t\tPlease Enter Day Again: "; cin >> tempInt;
	}
	temp = to_string(tempInt);
	cout << "\t\t\t\t\tEnter Month: "; cin >> tempInt;
	while (tempInt > 12 || tempInt < 1)
	{
		cout << "\t\t\t\t\tInvalid Month!" << endl;
		cout << "\t\t\t\t\tPlease Enter Month Again: "; cin >> tempInt;
	}
	temp += '/' + to_string(tempInt);
	cout << "\t\t\t\t\tEnter Year: "; cin >> tempInt;
	while (tempInt > 2022 || tempInt < 1950)
	{
		if (tempInt < 1950)
			cout << "\t\t\t\t\tSorry, We cannot treat Patient of this age." << endl;
		else if (tempInt > 2022)
			cout << "\t\t\t\t\tThe concurrent year is 2022!" << endl;
		cout << "\t\t\t\t\tPlease Enter Year Again: "; cin >> tempInt;
	}
	cin.ignore();
	temp += '/' + to_string(tempInt);
	setBirthDate(temp);
	cout << "\t\t\t\t\t   ~~~Please Enter Your Address~~~" << endl;
	address.inputAddress();
	cout << "\t\t\t\t\tEnter Occupation: "; getline(cin, temp); setOccupation(temp);

	cout << "\t\t\t\t\tEnter Contact Number(03xxxxxxxxx): "; cin >> temp;
	while (temp[0] != '0' || temp[1] != '3')
	{
		cout << "\t\t\t\t\tInvalid Contact Number!" << endl;
		cout << "\t\t\t\t\tPlease Enter Contact Number Again(03xxxxxxxxx):"; cin >> temp;
	}
	setContactNo(temp);
	cout << "\t\t\t\t\tEnter a Blood Group (A+, A-, B+, B-, AB+, AB-, O+, O-): "; cin >> temp; 
	stringConverter(temp);
	while (temp != "A+" && temp != "A-" && temp != "B+" && temp != "B-" && temp != "AB+"  && temp != "AB-"  && temp != "O+"  && temp != "O-")
	{
		cout << "\t\t\t\t\tInvalid Blood Group!" << endl;
		cout << "\t\t\t\t\tPlease Enter a Blood Group:"; cin >> temp;
		stringConverter(temp);
	}
	setBloodGroup(temp);
	cout << "\t\t\t\t\tEnter Martial Status(1 if Married and 2 if Non-married): "; cin >> tempInt;
	while (tempInt < 1 || tempInt > 2)
	{
		cout << "\t\t\t\t\tInvalid Choice!" << endl;
		cout << "\t\t\t\t\tPlease Enter 1 if Married or 2 if Non-married: "; cin >> tempInt;
	}
	if (tempInt == 1)
		setMartialStatus("Married");
	else if (tempInt == 2)
		setMartialStatus("Non-Married");
	cout << "\t\t\t\t\tEnter Gender(M or Male and F or Female): "; cin >> temp;
	stringConverter(temp);
	while (temp != "M" && temp != "F" && temp != "MALE" && temp != "FEMALE")
	{
		cout << "\t\t\t\t\tInvalid Gender Choice!" << endl;
		cout << "\t\t\t\t\tM or F?\n", cin >> temp; 
		stringConverter(temp);
	}
	if (temp == "MALE" || temp == "M")
		setGender("Male");
	else
		setGender("Female");
}

void Patient::setMedicines(string* m)
{
	if (medicines != NULL)
		delete[] medicines;
	medicines = m;
}

string* Patient::getMedicines()
{
	return medicines;
}

void Patient::storeSymptom(string s)
{
	symptoms = s;
}

void Patient::setSymptomCount(int s)
{
	symptomCount = s;
}

int Patient::getSymptomCount()
{
	return symptomCount;
}

void Patient::displayInfo()
{
	cout << "\t\t   ---------------------------------------" << endl;
	cout << "\t\t\t    Patient Information" << endl;
	cout << "\t\t   ---------------------------------------" << endl;
	cout << "\t\t   Patient ID: HSPR" << getPatientID() << endl;
	cout << "\t\t   Disease: " << getDisease() << endl;
	cout << "\t\t   Name: " << getName() << endl;
	cout << "\t\t   Date of Birth: " << getBirthDate() << endl;
	cout << "\t\t   Gender: " << getGender() << endl;
	address.printAddress();
	cout << "\t\t   Contact No: " << getContactNo() << endl;
	cout << "\t\t   Blood Group: " << getBloodGroup() << endl;
	cout << "\t\t   Occupation: " << getOccupation() << endl;
	cout << "\t\t   Martial Status:" << getMartialStatus() << endl;
	cout << "\t\t   =======================================" << endl;

}

void Patient::setMedicineQuantity(int* m)
{
	if (medicineQuantity != NULL)
		delete[] medicineQuantity;
	medicineQuantity = m;
}

int* Patient::getMedicineQuantity()
{
	return medicineQuantity;
}

void Patient::setMedicineCount(int mc)
{
	medicineCount = mc;
}

int Patient::getMedicineCount()
{
	return medicineCount;
}

void Patient::resetPatient()
{
	setappointedDoctor("");
	//setAppointment("");
	setBirthDate("");
	setName("");
	setBloodGroup("");
	setOccupation("");
	setPatientID("");
	setDisease("");
	storeSymptom("");
	setSymptomCount(0);
	setMedicineCount(0);
	setContactNo("");
	setGender("");
	setMartialStatus("");
}

void Patient::displayList(int patientCount)
{
	string temp = "";
	ifstream fin("Patient.txt");
	cout << "\t\t---------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t Patient ID " << setw(12) << "Name" << setw(12)  << "DOB" << setw(12) << "Gender" << setw(15) << "Disease" << setw(27) << "Appointed Doctor" << endl;
	cout << "\t\t---------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < patientCount; i++)
	{
		fin >> temp;
		setPatientID(temp);
		fin >> temp;
		setName(underScoreRemover(temp));
		fin >> temp;
		setBirthDate(temp);
		fin >> temp >> temp;
		setGender(temp);
		fin >> temp >> temp >> temp >> temp >> temp;
		setDisease(underScoreRemover(temp));
		fin >> temp >> temp;
		setappointedDoctor(underScoreRemover(temp));
		fin >> temp;
		cout << "\t\t HSPR" << getPatientID() << setw(18) << getName() << setw(14) << getBirthDate() << setw(8) << getGender() << setw(22) <<
			getDisease() << setw(16) << getappointedDoctor() << endl;
	}
	cout << "\t\t---------------------------------------------------------------------------------------------" << endl;
	fin.close();
}

