#pragma once
#include<iostream>
#include<string>
using namespace std;

class Inventory
{
private:
	string s1, ts;
	string RoomType;
	int TotalBedsPrRm;
	int PrivateRoomQuantity;
	int occupiedPrivateRm;
	int privateRoomPrice;
	int CombinedRoomQuantity;
	int BedsPerRoom[12];
	int TotalBedsCmRm;
	int bedCount;

public:
	int Occupied[8];
	void setOccupied();
	string name, s4, s3;
	Inventory();
	Inventory(string s, string T);
	void setS1(string s);
	string getS1();
	void setTs(string T);
	string getTs();
	void MedicalSupplyList();
	void Equipment_Machinery();
	void PrivateRoom();
	void CombinedRoom();
	friend string spaceRemover(string);
	friend string underScoreRemover(string);
	void setBedsPerRoom();
	void setRoomType(string rt);
	string getRoomType();
	void DomainCheck(string s);
	void RoomTypeCheck(string rt);
};