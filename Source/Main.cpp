//										   Project Name : Hospital Management System
//														 Semester: 3
//												 Project Type : Group Project
//												  Instructor: Ramna Maqsood
//													   	Section: C13
//									 Group Member 1: Syed Ahmed Ali  | Reg#: L1F20BSCS0207
//									 Group Member 2: Affan Bin Tariq | Reg#: L1F20BSCS0221
//									 Group Member 3: Mohammed		 | Reg#: L1F20BSCS0056
//									 Group Member 4: Safoora Masood  | Reg#: L1F20BSCS0467
#pragma warning(disable : 4996)
#include "Hospital.h"
#include "AdmitPatient.h"
#include <fstream>
#include <string>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include <iostream>
using namespace std;
string spaceRemover(string);
string underScoreRemover(string s);
void stringConverter(string&);
void testingPatient();
void menu();
Hospital* Hospital::hospital = NULL;
int main()
{
	Hospital* hospital = Hospital::getHospital();
	//AdmitPatient* patient = nullptr;
	string temp2;
	int* quantity;
	int count = 0;
	int choice = -1, temp = 0, innerChoice = 0;
	bool wrongChoice = true, firstIteration = true, diseaseCheck = false;
	while (choice != 9)
	{
		hospital->resetPatientCount();
		if (wrongChoice == false)
		{
			cout << "\n\t\t\t\t\tPlease Press A Key To Continue.." << endl;
			getch();
			system("cls");
			menu();
			cout << "\t   Enter Choice: "; cin >> choice;
		}
		else if (firstIteration == true)
		{
			menu();
			cout << "\t   Enter Choice: "; cin >> choice;
		}

		switch (choice)
		{
		case 1:
		{
				  cout << "\t   1. Are You an Old Patient?" << endl;
				  cout << "\t   2. Are You a New Patient?" << endl;
			  Invalid:
				  cout << "\t   Please Enter Your Choice: ";
				  cin >> innerChoice;
				  cin.ignore();
				  if (innerChoice == 1)
				  {
					  cout << "\t   Please Enter Your Patient ID: ";
					  cin >> temp2;
					  hospital->checkPatientCount();
					  if (hospital->checkPatient(temp2))
						  hospital->patients.displayInfo();
					  else
						  cout << "\t   Patient ID Not Found!" << endl;

				  }

				  else if (innerChoice == 2)
				  {
					  hospital->patients.resetPatient();
					  hospital->checkPatientCount();
					  hospital->generatePatientID();
					  hospital->patients.takeInput();
					  cout << "\t\t\t\t\t~~~Please Tell Us About Your Symptoms~~~" << endl;
					  cin.ignore();
				  InvalidSymptoms:
					  for (int i = 0; i < 3; i++)
					  {
						  cout << "\t\t\t\t\t Please Enter Symptom " << i + 1 << ": "; getline(cin, temp2);
						  hospital->patients.setSymptom(temp2);
					  }
					  cout << "\t\t\t\t\t\tPlease wait..." << endl;
					  testingPatient();
					  cout << "\t\t\t\t\t Symptoms: " << hospital->patients.getSymptom() << endl;
					  hospital->patients.setDisease(hospital->doctor.findDisease(hospital->patients.getSymptom(), diseaseCheck));
					  if (diseaseCheck == false)
					  {
						  hospital->patients.storeSymptom("");
						  goto InvalidSymptoms;
					  }
					  hospital->patients.setappointedDoctor("Dr.Ahmed");
					  hospital->admitPatient(hospital->patients.getPatientID());
					  hospital->patients.setMedicines(hospital->doctor.generatePrescription(hospital->patients.getDisease(), quantity, count));
					  string* medicines = hospital->patients.getMedicines();
					  hospital->patients.setMedicineQuantity(quantity);
					  hospital->patients.setMedicineCount(count);
					  if (hospital->patients.getMedicineCount() > 0)
					  {
						  cout << "\t\t\t\t\t Duration: " << hospital->doctor.getDuration() << endl;
						  cout << "\t\t\t\t\t Instructions: " << hospital->doctor.getInstructions() << endl;
						  hospital->pharmacy.setPrescription(hospital->patients.getMedicines(), hospital->patients.getMedicineCount());
						  hospital->pharmacy.setMedicineQuantities(hospital->patients.getMedicineQuantity());
						  hospital->pharmacy.updateFile();
						  hospital->pharmacy.billing.findPrices(hospital->patients.getMedicines(), hospital->patients.getMedicineQuantity(), hospital->patients.getMedicineCount());
						  hospital->pharmacy.billing.totalBill(hospital->patients.getMedicineCount());
						  hospital->pharmacy.billing.display();
					  }
					  else
					  {
						  cout << "\n\t\t\t\t\t-------------------------------------" << endl;
						  cout << "\n\t\t\t The Medicines for this Disease aren't Available at the moment!" << endl;
						  cout << "\t\t\t\t\tPlease Visit A Nearby Pharmacy" << endl;
					  }
					  cout << "\t\t\t\t\t----------------------------" << endl;
					  cout << "\t\t\t\t\t Thank You For Visiting By!" << endl;
					  cout << "\t\t\t\t\t----------------------------" << endl;
				  }

				  else
				  {
					  cout << "\t   Invalid Choice!" << endl;
					  goto Invalid;
				  }
				  wrongChoice = false;
				  firstIteration = false;
				  break;
		}
		case 2:
		{
				  int id = 0;
				  string roomType = "";
				  if (hospital->admitPatients == NULL)
					  hospital->admitPatients = new AdmitPatient;
				  int addChoice;
				  cout << "\t   ------------------------------------------------" << endl;
				  cout << "\t\t\tPlease Select An Option" << endl;
				  cout << "\t   ------------------------------------------------" << endl;
				  cout << "\t   1. Admit an Patient\t   2. To Discharge Patient" << endl;
				  cout << "\t   Enter Choice: "; cin >> addChoice;
				  cout << "\t   ------------------------------------------------" << endl;
				  if (addChoice == 1){
					  cout << "\t   Please Select a Room Type " << endl;
					  cout << "\t   1. Private Room		2. Combined Room" << endl;
					  cout << "\t   Please Enter Choice: "; cin >> roomType;
					  hospital->admitPatients->getPatientInfo();
					  hospital->admitPatients->setID();
					  hospital->admitPatients->addPatientToFile();
					  hospital->admitPatients->display();
					  hospital->admitPatients->assignRoom(roomType);
					  hospital->admitPatients->assignSupplies();
				  }
				  else{
					  cout << "\t   Enter ID: "; cin >> id;
					  hospital->admitPatients->dischargePatient(id);
				  }
				  firstIteration = false;
				  wrongChoice = false;
				  break;
		}

		case 3:
		{
				  cout << "\t   Please Enter Your Patient ID: ";
				  cin >> temp;
				  hospital->checkPatientCount();
				  if (hospital->checkPatient(to_string(temp)) == true)
					  hospital->dischargePatient(to_string(temp));
				  else
					  cout << "\t   No Patient to Discharge!" << endl;
				  wrongChoice = false;
				  firstIteration = false;
				  break;
		}

		case 4:
		{
				  hospital->checkPatientCount();
				  hospital->patients.displayList(hospital->getPatientCount());
				  wrongChoice = false;
				  firstIteration = false;
				  break;
		}

		case 5:
		{
				  hospital->checkDoctorCount();
				  hospital->doctor.displayList(hospital->getDoctorCount());
				  wrongChoice = false;
				  firstIteration = false;
				  break;
		}

		case 6:
		{
				 hospital->showPatientHistory();
				  wrongChoice = false;
				  firstIteration = false;
				  break;
		}

		case 7:
		{
				  hospital->showDiseases();
				  wrongChoice = false;
				  firstIteration = false;
				  break;
		}

		case 8:
		{
				  hospital->AboutUs();
				  wrongChoice = false;
				  firstIteration = false;
				  break;
		}

		case 9:
		{
				  cout << "\t\t\t\t\t---------------------------------------" << endl;
				  cout << "\t\t\t\t\t Thank you For Visiting Our Hospital!" << endl;
				  cout << "\t\t\t\t\t---------------------------------------" << endl;
				  system("pause");
				  return 0;
				  break;
		}

		default:
		{
				   cout << "\t   Wrong Choice!" << endl;
				   do
				   {
					   cout << "\t   Enter Choice Again: "; cin >> choice;

				   } while (choice < 1 || choice > 12);
				   wrongChoice = true;
				   firstIteration = false;
				   break;
		}
		}
	}
	system("pause");
	return 0;
}

void menu()
{
	cout << "\t\t\t\t  ============================================" << endl;
	cout << "\t\t\t\t   Welcome to our Hospital Management System!" << endl;
	cout << "\t\t\t\t  ============================================\n\n";
	cout << "\t   ----------------------------------------------------------------------------------------------" << endl;
	cout << "\t  |  1. Checkup\t\t\t\t2. Emergency Admit\t\t3. Discharge Patient     |" << endl;
	cout << "\t  |  4. List of Patients\t\t5. List of Doctors\t\t6. Patient History	 |" << endl;
	cout << "\t  |  7. Diseases With their Symptoms\t8. About Us\t\t\t9. Exit Program\t\t |" << endl;
	cout << "\t   ----------------------------------------------------------------------------------------------" << endl;
}

void stringConverter(string &s)
{
	int size = s.length();
	for (int i = 0; i < size; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
	}
}


void testingPatient()
{
	Sleep(1500);
	for (int i = 1; i <= 50; i++)
	{
		system("cls");
		cout << "\n\n\t\t\t\t\t\t    Testing.. " << '\n' << "\t\t\t\t";
		for (int j = 1; j <= 50; j++)
			cout << "²";
		cout << "\n\n\t\t\t\tProgress: " << 2 * i << "%";
		if (i > 1 && i < 20)
			cout << "\n\t\t\t\tChecking Patient";
		else if (i > 20 && i<40)
			cout << "\n\t\t\t\tGenerating Possible Disease";
		else if (i >40 && i<48)
			cout << "\n\t\t\t\tCollecting Results";
		else cout << "\n\t\t\t\tTest Completed. ";
		Sleep(150 - i * 3);
	}
	cout << "\n\t\t\t\t\t-------------------------------------" << endl;
	cout << "\t\t\t\t\t   Press a Key to get Presciption!" << endl;
	cout << "\t\t\t\t\t-------------------------------------" << endl;
	_getch();
}

string spaceRemover(string s)
{
	int length = s.length();
	for (int i = 0; i < length; i++)
	{
		if (s[i] == ' ')
			s[i] = '_';
	}
	return s;
}

string underScoreRemover(string s)
{
	int length = s.length();
	for (int i = 0; i < length; i++)
	{
		if (s[i] == '_')
			s[i] = ' ';
	}
	return s;
}