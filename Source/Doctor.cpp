#include "Doctor.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <iomanip>
using namespace std;

Doctor::Doctor()
{

}

Doctor::Doctor(string, string, string, string, string)
{

}

void Doctor::setEmployeeID(string id)
{
	employeeID = id;
}

string Doctor::getEmployeeID()
{
	return employeeID;
}


void Doctor::setDuration(string d)
{
	duration = d;
}

string Doctor::getDuration()
{
	return duration;
}

void Doctor::setInstructions(string i)
{
	instructions = i;
}

string Doctor::getInstructions()
{
	return instructions;
}

void Doctor::setSpeciality(string s)
{
	speciality = s;
}

string Doctor::getSpeciality()
{
	return speciality;
}

void Doctor::setTimings(string t)
{
	timings = t;
}

string Doctor::getTimings()
{
	return timings;
}

void Doctor::setExperience(string e)
{
	experience = e;
}

string Doctor::getExperience()
{
	return experience;
}

void Doctor::setPay(double p)
{
	pay = p;
}

double Doctor::getPay()
{
	return pay;
}

string Doctor::findDisease(string symptom, bool& diseaseCheck)
{
	int count = 0, i = 0;
	string disease, value;
	bool flag = false;
	ifstream fin("Disease.txt");
	stringConverter(symptom);
	while (!fin.eof())
	{
		if (flag == false)
		{
			fin >> value;
			value = underScoreRemover(value);
			stringConverter(value);
			if (value == symptom)
			{
				fin.get();
				getline(fin, disease);
				flag = true;
				break;
			}
			else
			{
				getline(fin, value);
				flag = false;
			}
		}
	}
	if (flag == true)
	{
		cout << "\t\t\t\t\t Disease: " << disease << endl;
		diseaseCheck = true;
	}
	else
	{
		cout << "\t\t\t\t\t No Disease Found!" << endl;
		diseaseCheck = false;
	}
	fin.close();
	return disease;
}


string* Doctor::generatePrescription(string disease, int*& medicinesQuantity, int& medicineCount)
{
	medicineCount = 0;
	int len = 0;
	string temp;
	string temp2[3];
	ifstream fin("Prescriptions.txt");
	disease = underScoreRemover(disease);
	while (!fin.eof())
	{
		getline(fin, temp, '@');
		if (temp == disease)
		{
			for (int i = 0; i < 3; i++)
			{
				fin >> temp;
				len = temp.length();
				medicineCount++;
				if (temp[len - 1] == '.')
				{
					for (int j = 0; j < len - 1; j++)
						temp2[i] += temp[j];
					break;
				}
				temp2[i] = temp;
			}
			fin.get();
			getline(fin, temp, '@');
			setDuration(temp);
			fin.get();
			getline(fin, temp, '.');
			setInstructions(temp);
			break;
		}
	}
	string* medicines = new string[medicineCount];
	medicinesQuantity = new int[medicineCount];
	srand((unsigned)time(NULL));
	for (int i = 0; i < medicineCount; i++)
	{
		medicines[i] = temp2[i];
		medicinesQuantity[i] = 1 + (rand() % 4);
	}
	fin.close();
	return medicines;
}

void Doctor::displayInfo()
{
	cout << setw(12) << employeeID << setw(15) << getName() << setw(12) << getBirthDate() << setw(9) << getGender() << setw(20) << speciality
		<< setw(15) << experience << setw(10) << "PKR " << pay << setw(15) << timings << endl;
}

void Doctor::displayList(int doctorCount)
{	
	string temp = "";
	ifstream fin("DoctorInformation.txt");
	cout << "\t-----------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t ID" << setw(12) << "Name" << setw(12) << "DOB" << setw(13) << "Gender" << setw(20) << "Speciality" << setw(15) << "Experience" << setw(12) << "Pay" << setw(15) << "Timings" << endl;
	cout << "\t-----------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < doctorCount; i++)
	{
		fin >> temp;
		setEmployeeID(temp);
		fin >> temp;
		setName(underScoreRemover(temp));
		fin >> temp;
		setBirthDate(temp);
		fin >> temp;
		setGender(underScoreRemover(temp));
		fin >> temp;
		setSpeciality(underScoreRemover(temp));
		fin >> temp;
		setExperience(underScoreRemover(temp));
		fin >> temp;
		setPay(stod(temp));
		fin >> temp;
		setTimings(temp);
		displayInfo();
	}
	fin.close();
	cout << "\t-----------------------------------------------------------------------------------------------------------" << endl;
}

Doctor::~Doctor()
{

}