#include <iostream>
#include <vector>
#include <string>
#include "Patient.h"
#include <stdlib.h>
using namespace std;

//prototypes
template <class T>
void Vectorprint(vector<T> vector);
void AddClient(vector<Patient> &Patients);
void AddMedication(vector<Patient> &Patients);
void ClientInfo(vector<Patient> &Patients);
int CloseApplication();
int mainPage();

int main() {
	mainPage();

	return 0; //returns that everything works back to system.
}

//Pages
int mainPage() {

	//keeps variable in scope
	static vector<Patient> Patients;

	//prints out dialog
	cout << "Select a page:" << endl;
	cout << "01 - Add Client" << endl;
	cout << "02 - Add Medication" << endl;
	cout << "03 - Client Info" << endl;
	cout << "04 - Close Application" << endl;

	//Validates user input
	string userInput = "0";
	while (userInput != "1" && userInput != "2" && userInput != "3" && userInput != "4") {
		cout << "Enter a number 1-4: " << endl;
		cin >> userInput;
	}

	//selects a page
	switch (stoi(userInput)) {
		case(1): AddClient(Patients);
		case(2): AddMedication(Patients);
		case(3): ClientInfo(Patients);
		case(4): CloseApplication();
		}
	return 0;
	
}

void AddClient(vector<Patient> &Patients) {
	Patient patient;


	//client name
	string name;//string (Receives input from program)
	string email;
	string phone;
	bool emailstatus = 1, phonestatus = 1;//booleans

	//collects information about the object
	cout << "Enter your patient name: " << endl;
	cin >> name;
	cout << "Enter your patient email: " << endl;
	cin >> email;
	cout << "Enter your patient phone: " << endl;
	cin >> phone;

	//Creates object with overload constructor
	Patient newPatient(name, email, phone, emailstatus, phonestatus);

	//Uses vector for object storage
	Patients.push_back(newPatient);

	mainPage();
}

void AddMedication(vector<Patient>& Patients) {

	cout << "Add Medication" << endl;
	string medname, medtime;
	int medtablets;

	//prints list of patients to work with
	Vectorprint(Patients);

	//Prompts the user to select client
	cout << "Select a client numbered above: ";

	//The value of the patient inside the vector "Patients"
	int i;
	//input valid
	while (!(cin >> i)) {
		cout << "Error, enter a number: ";
		cin.clear();
		cin.ignore(123, '\n');
	}
	if (i <= Patients.size() && i > -0.1) {

		//Confirmation 
		cout << "You have selected: " << Patients[i].getName() << endl;

		//Med name
		cout << "Enter the name of medication: " << endl;
		cin >> medname;

		//Med Time
		cout << "Enter time of medication: " << endl;
		cin >> medtime;

		//Med dosage
		cout << "Enter number of tablets: " << endl;

		//Input valid
		while (!(cin >> medtablets)) {
			cout << "Error, enter a number: ";
			cin.clear();
			cin.ignore(123, '\n');
		}

		//Creates object med
		Medication Med(medname, medtime, medtablets);

		//Puts object in vector
		Patients[i].pushMeds(Med);

		//Confirms to user
		cout << Med.getName() << " pushed to " << Patients[i].getName() << endl;
	}
	else {
		cout << "Invalid entry, add a patient before adding meds." << endl;
	}

	//Client
	mainPage();
}

void ClientInfo(vector<Patient> &Patients) {
	if (Patients.size() < 1) {
		cout << "No clients added at the current moment. Add a client from the client add page." << endl;
		mainPage();
	}
	else {
		cout << "Client Info" << endl;
		//Displays Client names
		if (Patients.size() > 0) {
			for (int i = 0; i < Patients.size(); i++) {
				Patients[i].printData();
				Patients[i].printMeds();
			}
		}

		//Validates input
		string input = "0";
		while (input != "1") {
			cout << "Press 1 to continue to home" << endl;
			cin >> input;
		}
		mainPage();
	}
}

int CloseApplication() {
	cout << "Application closed" << endl;
	//Closes Application 
	exit(1);
	return 0;
}

template <class T>
void Vectorprint(vector<T> vector) {
	for (int i = 0; i < vector.size(); i++) {
		cout << i  << ". " << vector[i].getName() << endl;

	}
}