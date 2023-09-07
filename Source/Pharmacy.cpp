#include<iostream>
#include<fstream>
#include<string>
#include"Pharmacy.h"
#include"inventory.h"
using namespace std;
Pharmacy::Pharmacy()
{
	/*prescriptionSize = 3;*/
}

Pharmacy::Pharmacy(string* prescription, int* quantity)
{
	//this->prescriptionSize = 3;
	//setPrescription(prescription);
	//setMedicineQuantities(quantity);
	//updateFile();
}

void Pharmacy::setPrescription(string* p, int count){
	this->prescription = new string[count];
	prescriptionSize = count;
	for (int i = 0; i < prescriptionSize; i++)
		prescription[i] = p[i];
}

void Pharmacy::setMedicineQuantities(int* quantities){
	this->medicineQuantities = new int[prescriptionSize];
	for (int i = 0; i < prescriptionSize; i++)
		medicineQuantities[i] = quantities[i];
}

//string Pharmacy::(int index)
//{
//	return prescription[index];
//}

void Pharmacy::updateFile(){
	streampos quantityPos;
	int garbage = 0;
	bool medicineMatched = false;
	string fileMedicine = "";
	int fileQuantity = 0, filePrice = 0, index = 0;
	fstream file("PharmacyStock.txt", ios::in | ios::out);
	if (!file.is_open()){
		cout << "\t\t\t\t\tCould Not Open \"Pharamcy Stock File\"." << endl;
	}
	else{
		while (!file.eof()){
			file >> fileMedicine;
			for (int i = 0; i < prescriptionSize; i++){
				if (prescription[i] == fileMedicine){
					medicineMatched = true;
					quantityPos = file.tellg();
					quantityPos += 1;
					file >> fileQuantity;
					index = i;
					writeQuantity(quantityPos, fileQuantity, index);
				}
			}
		}
	}
}

void Pharmacy::writeQuantity(streampos quantityPos, int fileQuantity, int index){
	int newQuantity;
	int fileQuantityDigits, userQuantityDigits, newQuantityDigits;
	int spaces;
	fstream file("PharmacyStock.txt", ios::in | ios::out);
	if (fileQuantity <= 0){
		cout << "\t\t\t\t\tMedicine \"" << prescription[index] << "\" Is Not Available." << endl;
		cout << "\t\t\t\t\t---------------------------------------------------------------" << endl;
		return;
	}
	else if (medicineQuantities[index] > fileQuantity){
		cout << "\t\t\t\t\t Not Enough Quantity Available Of \"" << prescription[index] << "\"" << endl;
		cout << "\t\t\t\t\t We Gave You \"" << fileQuantity << "\" As This Is All That's Available" << endl;
		cout << "\t\t\t\t\t---------------------------------------------------------------" << endl;
		newQuantity = 0;
	}
	else{
		newQuantity = fileQuantity - medicineQuantities[index];
	}

	fileQuantityDigits = digitCount(fileQuantity);
	userQuantityDigits = digitCount(medicineQuantities[index]);
	newQuantityDigits = digitCount(newQuantity);
	spaces = fileQuantityDigits - newQuantityDigits;
	file.seekp(quantityPos, ios::beg);
	file << newQuantity;
	while (spaces){
		file << " ";
		spaces--;
	}
}

int Pharmacy::digitCount(int number){
	int digitCount = 0;
	while (number){
		number /= 10;
		digitCount++;
	}
	return digitCount;
}

string* Pharmacy::getPrescription()
{
	return prescription;
}