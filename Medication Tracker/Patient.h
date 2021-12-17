#pragma once
#include "Medication.h"
#include "Prescription.h"
#include "Supplement.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;
/* This object should be capable of holding an array of objects
"Supplements""
*/

class Patient {
private: //The following field keeps the variable "passcode" inside the patient class encapsulated from the user
	//Member Variables
	int m_passcode = NULL;
	vector<Medication> Vectorofmeds;//Medications of patient
	vector<Prescription> Vectorofprescriptions;//Prescriptions of patient
	vector<Supplement> Vectorofsupplements;//Supplements of patient


	/*
	Source: https://www.youtube.com/watch?v=iPlW5tSUOUM
	*/

	//Member variables
	string m_pname;//System::string (Receives input from program)
	string m_pemail;
	string m_pnumber;
	bool m_textnotifications = false; //default sets to false
	bool m_emailnotifications = false; //default sets to false

public:

	//Default Constructor
	Patient() {

	}

	//Overload Constructors
	Patient(string Name, string Email, string Phone, bool emailbool, bool textbool) {
		m_pname = Name;
		m_pemail = Email;
		m_pnumber = Phone;
		m_textnotifications = emailbool;
		m_emailnotifications = textbool;
	}

	//Destructor
	~Patient() {

	}

	//Mutator Functions
	void pushMeds(Medication meds) { Vectorofmeds.push_back(meds); }
	void setPrescriptions(vector<Prescription> prescriptions) { Vectorofprescriptions = prescriptions; }
	void setSupplements(vector<Supplement> Supplements) { Vectorofsupplements = Supplements; }
	void setName(string name) { m_pname = name; }
	void setEmail(string email) { m_pemail = email; }
	void setPhone(string number) { m_pnumber = number; }
	void setEmailson() { m_emailnotifications = true; }
	void setEmailsoff() { m_emailnotifications = false; }
	void setTextson() { m_textnotifications = true; }
	void setTextsoff() { m_textnotifications = false; }
	void printData() {
		cout << "Patient's Name: " << m_pname << endl;
		cout << "Patient's Email: " << m_pemail << endl;
		cout << "Patient's Phone: " << m_pnumber << endl;
	}
	void printMeds() {
		for (int i = 0; i < Vectorofmeds.size(); i++) {
			cout << "Medication: " << Vectorofmeds[i].getName()
				<< " Time: " << Vectorofmeds[i].getTime() << " Tablets: " 
				<< Vectorofmeds[i].getNumoftablets() << endl;
		}
	}

	//Accessor Functions
	vector<Medication> getMeds() { return Vectorofmeds; } //Reveals encapsulated variables
	vector<Prescription> getPrescription() { return Vectorofprescriptions; }
	vector<Supplement> getSupplement() { return Vectorofsupplements; }
	string getName() { return m_pname; }
	string getEmail() { return m_pname; }
	string getNumber() { return m_pnumber; }
	bool Textnotifications() { return m_textnotifications; }
	bool Emailnotifications() { return m_emailnotifications; }
};
