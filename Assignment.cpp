#include <iostream>
#include <iomanip>
#include "reservation_manager.h"
#include "guests_res_request.h"
#include "information.h"
#include "guests.h"
#include "date.h"

using namespace std;

void displayMenu(Reservation_Manager &rm);

int main()
{
	Reservation_Manager rm;
    displayMenu(rm);
}



void displayMenu(Reservation_Manager &rm){
	char choice;
	bool exit = false;
	while (!exit) {
		cout << "\nSelect your choice: " << endl;
		cout << "\t1) Add a reservation." << endl;
		cout << "\t2) Cancel a reservation." << endl;
		cout << "\t3) Display information of a reservation." << endl;
		cout << "\t4) Check if the bathroom is empty." << endl;
		cout << "\t5) Exit the program." << endl << endl;

		cin >> choice;

		int id;
		int temp;
		int no_of_people;
		int no_of_nights;
		Date checkIn;
		Date checkOut;
		Information edgars_people[4];
		short room_id;
		char firstName[25];
		char lastName[25];
		Date dateOfBirth;
		Guests* people;
		Guests_Res_Request* new_req;

		switch (choice) {
			case '1':
			cout << "\nHow many nights are they staying: ";
			cin >> no_of_nights;
			cout << "How many people: ";
			cin >> no_of_people;
			for (int i = 0; i < no_of_people && i < 4; i++) {
				cout << "Person " << i+1 << ":\n";
				cout << "First name? ";
				cin >> firstName;
				cout << "Last name? ";
				cin >> lastName;
				cout << "Date Of Birth: \n\tday:";
				cin >> temp;
				dateOfBirth.setDay(temp);
				cout << "\tmonth:";
				cin >> temp;
				dateOfBirth.setMonth(temp);
				cout << "\tyear:";
				cin >> temp;
				dateOfBirth.setYear(temp);

				edgars_people[i] = Information(firstName, lastName, dateOfBirth);
			}
			cout << "What room: ";
			cin >> room_id;
			cout << "Check in date: \n\tday:";
			cin >> temp;
			checkIn.setDay(temp);
			checkIn.setMonth(3);
			checkIn.setYear(2026);
			cout << "Check Out date: \n\tday:";
			cin >> temp;
			checkOut.setDay(temp);
			checkOut.setMonth(3);
			checkOut.setYear(2026);
			people = new Guests(checkIn, checkOut, edgars_people, no_of_people, room_id);
			new_req = new Guests_Res_Request(no_of_nights, people);
			id = rm.processReservation(new_req);
			cout << "Reservation created at id: " << id << endl;
			break;
			case '2':
			cout << "ID of reservation: ";
			cin >> id;
			rm.cancelReservation(id);
			break;
			case '3':
			cout << "ID of reservation: ";
			cin >> id;
			rm.displayDetails(id);
			break;
			case '4':
			cout << "Yeah its empty big dawg" << endl;
			break;
			case '5':
			cout << "We out" << endl;
			exit = true;
			break;
			default:
			cout << "??? stop inting" << endl;
			break;
		}

	}

}
