#pragma once
#include "Patient.h"
#include "Doctor.h"
#include "Pharmacy.h"
#include "AdmitPatient.h"
#include <string>
using namespace std;

class Hospital
{
	bool patientCheck;
	int patientCount, doctorCount;
	static Hospital* hospital;
	Hospital();
	Hospital(string, string, string, string, string, string, string);
public:
	Patient patients;
	Doctor doctor;
	Pharmacy pharmacy;
	AdmitPatient* admitPatients;
	static Hospital* getHospital();
	void emergencyAdmit();
	void generatePatientID();
	void admitPatient(string);
	bool checkPatient(string p_id);
	void dischargePatient(string);
	void getPatient(string);
	void checkPatientCount();
	void checkDoctorCount();
	int getPatientCount();
	int getDoctorCount();
	string appointDoctor();
	void resetPatientCount();
	void AboutUs();
	void showDiseases();
	void showPatientHistory();
	friend string spaceRemover(string);
	friend string underScoreRemover(string);
};