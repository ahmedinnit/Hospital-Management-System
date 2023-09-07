#include<iostream>
#include<fstream>
#include<string>
#include <time.h>
#include <ctime>
#include"Inventory.h"

Inventory::Inventory()
{
	PrivateRoomQuantity = 7;
	TotalBedsPrRm = 7;
	occupiedPrivateRm = 0;
	privateRoomPrice = 8000;
	CombinedRoomQuantity = 12;
	TotalBedsCmRm = 34;
	setBedsPerRoom();
	setOccupied();
	bedCount = 0;
}

void Inventory::setOccupied(){
	for (int i = 0; i < 8; i++)
		Occupied[i] = 0;
}

void Inventory::setBedsPerRoom()
{
	int n[12] = { 2, 3, 3, 2, 1, 3, 3, 4, 5, 3, 3, 2 };
	for (int i = 0; i < CombinedRoomQuantity; i++)
	{
		this->BedsPerRoom[i] = n[i];
	}
}

Inventory::Inventory(string s, string T)
{
	setS1(s);
	setTs(T);
}

void Inventory::setS1(string s)
{
	this->s1 = s;
	if (s1 == "1")
	{
		MedicalSupplyList();
	}
	else if (s1 == "2")
	{
		Equipment_Machinery();
	}
}

void Inventory::setTs(string T)
{
	this->ts = T;
}

string Inventory::getS1()
{
	return s1;
}

string Inventory::getTs()
{
	return ts;
}

void Inventory::MedicalSupplyList()
{
	srand((unsigned)time(0));
	int counter = 0;
	string t, s2;
	bool flag = false;
	cout << "\t\t\t\t\tYou Have Been Allocated Following Medical Supplies: " << endl;
	if (s1 == "1")
	{
	l6:
		ifstream Mfin("MedicalSupplyList.txt");
		if (!Mfin.is_open()){
			cout << "Could Not Open File \"MedicalSupplyList.txt\"" << endl;
		}
		else{
			int random;
			random = 1 + (rand() % 8);
			t = to_string(random);
			setTs(t);
			int size = 0;
			while (ts[size] != '\0')
			{
				size++;
			}
		l2: while (!Mfin.eof())
		{
				Mfin >> s2;
				if (s2 == ts)
				{
					flag = true;
					break;
				}
				else
				{
					goto l2;
				}
		}
			if (flag != true)
			{
				goto l6;
			}

			while (s4 != "*")
			{
				Mfin >> s4;
				if (s4 != "*")
				{
					s4 = underScoreRemover(s4);
					cout << "\t\t\t\t\t" << ++counter << ". " << s4 << endl;
				}
			}
			s4 = "";
			Mfin.close();
		}

	}
	cout << "\t\t\t\t\t---------------------------------------------------" << endl;
}
void Inventory::Equipment_Machinery()
{
	srand((unsigned)time(0));
	ifstream Efin;
	string quantity;
	string EquipmentName[3] = {};
	string garbage;
	int fileSerialNum;
	bool isMatched = false;
	int counter = 3, index = 0;
	int serialNum[3];
	for (int i = 0; i < 3; i++){
		serialNum[i] = 1 + (rand() % 19);
	}

openFile:
	Efin.open("Equipment&Machinery.txt");
	if (!Efin.is_open()){
		cout << "Could Not Open File \"Equipment&Machinery.txt\"" << endl;
	}
	else{
		if (index == 0)
			cout << "\t\t\t\t\tYou Have Been Allocated The Following Utilities: " << endl;
		while (!Efin.eof() && counter)
		{
			Efin >> fileSerialNum;
			if (serialNum[index] == fileSerialNum)
			{
				Efin >> garbage;
				for (int i = 0; i < index; i++){
					if (EquipmentName[i] == garbage)
						isMatched = true;
				}
				if (!isMatched)
					EquipmentName[index] = garbage;
				else
					continue;
				EquipmentName[index] = underScoreRemover(EquipmentName[index]);
				cout << "\t\t\t\t\t" << index + 1 << ". " << EquipmentName[index] << endl;
				index++;
				counter--;
				Efin.close();
				goto openFile;
			}
			else
				Efin >> garbage;
		}
	}
	cout << "\t\t\t\t\t---------------------------------------------------" << endl;
}
void Inventory::DomainCheck(string s)
{

	string s2 = s;
l1:	
	if (s2 == "1" || s2 == "2")
	{
		setS1(s2);
	}
	else
	{
		cout << "\t\t\t\t\tThe Domain didn't Match!" << endl;
		cout << "\t\t\t\t\tPlease Enter Domain of Inventory: ";
		int random;
		random = 1 + (rand() % 2);
		s2 = to_string(random);
		goto l1;
	}
}
void Inventory::setRoomType(string rt)
{
	if (rt == "1")
	{
		PrivateRoom();
	}
	if (rt == "2")
	{
		CombinedRoom();
	}
}

void Inventory::PrivateRoom()
{
	if (TotalBedsPrRm == 0 || PrivateRoomQuantity == 0)
		cout << "\t\t\t\t\tSorry We Dont Have Any Private Rooms Available At the Moment.";
	cout << "\t\t\t\t\t---------------------------------------------------" << endl;
	if (TotalBedsPrRm > 0)
	{
		bool isRepeated = false;
		srand((unsigned)time(0));
		int random = (1 + (rand() % 7));
		for (int i = 0; i < 8; i++){
			if (Occupied[i] == 0){
				isRepeated = false;
				for (int j = 0; j < i; j++){
					if (Occupied[j] == random){
						random = (1 + (rand() % 7));
						i--;
						isRepeated = true;
						break;
					}
				}
				if (!isRepeated){
					Occupied[i] = random;
					break;
				}
			}
		}
		if (Occupied[7] != 0){
			cout << "\t\t\t\t\tSorry, All Rooms Are Occupied." << endl;
		}
		else{
			cout << "\t\t\t\t\tYou have been Assigned Room no. " << random << endl;
			cout << "\t\t\t\t\tPrice per day is: " << privateRoomPrice << endl;
			this->TotalBedsPrRm = TotalBedsPrRm - 1;
			this->PrivateRoomQuantity = PrivateRoomQuantity - 1;
			this->occupiedPrivateRm = occupiedPrivateRm + 1;
		}
	}
	cout << "\t\t\t\t\t---------------------------------------------------" << endl;
}
void Inventory::CombinedRoom()
{
	bool flag = false;
	cout << "\t\t\t\t\t---------------------------------------------------" << endl;
	srand((unsigned)time(0));
	int i = 0;
	for (int i = 0; i < 12; i++)
	{
		if (BedsPerRoom[i] > 0)
		{
			cout << "\t\t\t\t\tYou Have Been Assigned Bed No.\"" << ++bedCount << "\" In Room No.\"" << i + 1 << "\"" << endl;
			this->BedsPerRoom[i] = BedsPerRoom[i] - 1;
			flag = true;
			break;
		}
	}
	if (flag != true)
		cout << "\t\t\t\t\tSorry We Dont Have Any Rooms With Any Beds Available For You At The Moment." << endl;
	cout << "\t\t\t\t\t---------------------------------------------------" << endl;
}

void Inventory::RoomTypeCheck(string rt)
{
	string roomt = rt;
l1:	if (roomt == "1" || roomt == "2")
{
		setRoomType(roomt);
}
	else
	{
		cout << "\t\t\t\t\tThe Room Type did not match!" << endl;
		cout << "\t\t\t\t\tPlease Enter Room Type Again: ";
		cin >> roomt;
		goto l1;
	}
}