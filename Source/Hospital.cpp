#include "Hospital.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

Hospital::Hospital()
{
	patientCount = 0;
}


Hospital::Hospital(string n, string bd, string d, string g, string m, string pi, string s)
{
	patients.setName(n);
	patients.setBirthDate(bd);
	patients.setDisease(d);
	patients.setGender(g);
	patients.setMartialStatus(m);
	patients.setPatientID(pi);
	patients.setSymptom(s);
	patientCount = 0;
}

Hospital* Hospital::getHospital()
{
	if (hospital == NULL)
		hospital = new Hospital;
	return hospital;
}

void Hospital::emergencyAdmit()
{

}

void Hospital::admitPatient(string p_id)
{
	string temp;
	temp = patients.getName();
	patients.setName(spaceRemover(temp));
	temp = patients.getDisease();
	patients.setDisease(spaceRemover(temp));
	temp = patients.getappointedDoctor();
	patients.setappointedDoctor(spaceRemover(temp));
	temp = patients.getSymptom();
	patients.storeSymptom(spaceRemover(temp));
	string sum = "";
	sum = patients.getPatientID() + " " + patients.getName() + " " + patients.getBirthDate() + " " + patients.address.getAddress() + " " +
	patients.getGender() + " " + patients.getContactNo() + " " +  patients.getMartialStatus() + " " + 
	patients.getBloodGroup() + " " + patients.getOccupation() + " " + patients.getDisease() + " " + patients.getSymptom() + " " +
	patients.getappointedDoctor() + " " + to_string(patients.getSymptomCount());
	ofstream fout("Patient.txt", ios::app);
	if (patientCount == 0)
		fout << sum;
	else
		fout << '\n' << sum;
	fout.close();
	patientCount++;
}

bool Hospital::checkPatient(string p_id)
{	
	string temp = "";
	ifstream fin("Patient.txt");
	patientCheck = false;
	if (patientCount == 0)
		cout << "\t   No Patient in List!" << endl;
	else
	{
		while (!fin.eof())
		{
			fin >> temp;
			if (temp == p_id)
			{
				patientCheck = true;
				patients.setPatientID(temp);
				fin >> temp;
				patients.setName(underScoreRemover(temp));
				fin >> temp;
				patients.setBirthDate(temp);
				fin >> temp;
				patients.address.setAddress(temp);
				fin >> temp;
				patients.setGender(temp);
				fin >> temp;
				patients.setContactNo(temp);
				fin >> temp;
				patients.setMartialStatus(temp);
				fin >> temp;
				patients.setBloodGroup(temp);
				fin >> temp;
				patients.setOccupation(temp);
				fin >> temp;
				patients.setDisease(underScoreRemover(temp));
				fin >> temp;
				patients.storeSymptom(temp);
 				fin >> temp;
				patients.setappointedDoctor(underScoreRemover(temp));
				fin >> temp;
				patients.setSymptomCount(stoi(temp));
				break;
			}
			getline(fin, temp);
		}
	
	}
		fin.close();
		return patientCheck;
}

void Hospital::dischargePatient(string p_id)
{
	string temp = "", store = "", compare = p_id, dischargedPatient = "";
	int count = 1, i = 0, line = 1, size = 0, firstLine = 1;
	bool flag = true, found = false;
	ifstream fin("Patient.txt");
	while (!fin.eof())
	{
		getline(fin, temp);
		size++;
	}
	fin.close();
	fin.open("Patient.txt");
	while (count != size)
	{
		fin >> temp;
		if (temp != compare)
			flag = true;
		else
		{
			flag = false;
			found = true;
			checkPatient(temp);
		}

		if (flag == true)
		{
			if (firstLine == 1)
			{
				store += temp;
				getline(fin, temp);
				store += temp;
				firstLine++;
			}
			else
			{
				store += '\n' + temp;
				getline(fin, temp);
				store += temp;
			}
		}
		else
		{
			dischargedPatient = temp;
			getline(fin, temp);
			dischargedPatient += temp;
		}
		count++;
		i++;
	}
	fin >> temp;
	if (temp != compare)
		flag = true;
	else
	{
		flag = false;
		found = true;
	}

	if (flag == true)
	{
		store += '\n' + temp;
		getline(fin, temp);
		store += temp;
	}
	else if (flag == false && found == false)
		cout << "\t   No Patient Found!" << endl;

	if (found == true)
	{
		cout << "\t\t\t\t---------------------------------------------------" << endl;
		cout << "\t\t\t\t\t Discharging  HSPR" << patients.getPatientID() << " - " << patients.getName() << "!" << endl;
		cout << "\t\t\t\t---------------------------------------------------" << endl;
	}
	fin.close();
	ofstream fout("Patient.txt", ios::trunc);
	fout << store;
	fout.close();
	patientCount--;
}

void Hospital::generatePatientID()
{
		int temp;
		int position = 0;
		ifstream fin("PatientID's.txt");
		while (!fin.eof())
			fin >> temp;
		temp++;
		fin.close();
		ofstream fout("PatientID's.txt", ios::app);
		fout << "\n" << temp;
		fout.close();
		patients.setPatientID(to_string(temp));
}

void Hospital::checkPatientCount()
{
	patientCount = 0;
	string temp;
	patientCheck = false;
	ifstream fin("Patient.txt");
	fin >> temp;
	if (temp == "")
	{
		cout << "\t   File is Empty!" << endl;
		patientCheck = false;
	}
	else
		patientCheck = true;
	if (patientCheck == true)
	{
		while (!fin.eof())
		{
			getline(fin, temp);
			patientCount++;
		}
	}
	else
		cout << "\t   No Patient History Found!" << endl;
	cout << "\t   Patient Count: " << patientCount << endl;
	fin.close();
}


void Hospital::checkDoctorCount()
{
	doctorCount = 0;
	string temp;
	bool doctorCheck = false;
	ifstream fin("DoctorInformation.txt");
	fin >> temp;
	if (temp == "")
	{
		cout << "\t   File is Empty!" << endl;
		doctorCheck = false;
	}
	else
		doctorCheck = true;
	if (doctorCheck == true)
	{
		while (!fin.eof())
		{
			getline(fin, temp);
			doctorCount++;
		}
	}
	else
		cout << "\t   No Doctor History Found!" << endl;
	cout << "\t   Doctor Count: " << doctorCount << endl;
	fin.close();
}

int Hospital::getPatientCount()
{
	return patientCount;
}

int Hospital::getDoctorCount()
{
	return doctorCount;
}

void Hospital::resetPatientCount()
{
	patientCount = 0;
}

void Hospital::AboutUs()
{
	string temp = "";
	ifstream fin("AboutUs.txt");
	while (!fin.eof())
		temp += fin.get();
	cout << temp;
	fin.eof();
}

void Hospital::showDiseases()
{
	string symp = "";
	string disease = "";
	ifstream fin("Disease.txt");
	cout << "\t\t----------------------------------------------------------------------" << endl;
	cout << "\t\t Diseases with Symptoms" << endl;
	cout << "\t\t----------------------------------------------------------------------" << endl;
	int i = 0;
	while (!fin.eof())
	{
		fin >> symp;
		symp = underScoreRemover(symp);
		getline(fin, disease);
		if (i < 9)
			cout << "\t\t 0" << i + 1 << "." << disease << ": " << symp << endl;
		else 
			cout << "\t\t " << i + 1 << "." << disease << ": " << symp << endl;
		i++;
	}
	cout << "\t\t----------------------------------------------------------------------" << endl;
	fin.close();
}
void Hospital::showPatientHistory()
{

	int id;
	string name = "";
	string date = "";
	string addres = "";
	string gender = "";
	string phone = "";
	string data="";
	ifstream fin("Patient.txt");
	cout << "\t\t----------------------------------------------------------------------" << endl;
	cout << "\t\t Patient History" << endl;
	cout << "\t\t----------------------------------------------------------------------" << endl;
	int i = 0;
	while (!fin.eof())
	{
		fin >> id;
		//id = underScoreRemover(id);
		fin>> name;
		fin>>date;
		fin >> addres;
		fin >> gender;
		fin >> phone;
		getline(fin, data);
		cout << /*"\t\t "*/ /*<< i + 1 << "." */  id << " : " << date << "\n " << name << "\n Address : " << addres << "\n Gender : " << gender << "\n Phone number : " << phone << "\n Other Data : " << data << endl;
		i++;
	}
	cout << "\t\t----------------------------------------------------------------------" << endl;
	fin.close();
}

//string Hospital::appointDoctor()
//{
//
//}
//int main()
//{
//	time_t t;
//	time(&t);
//	string currentTime = ctime(&t);
//	cout << "Time: " << currentTime << endl;
//	system("pause");
//	return 0;
//}
