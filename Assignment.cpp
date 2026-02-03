#include <iostream>
#include <iomanip>
#include "reservation_manager.h"
#include "guests_res_request.h"
#include "information.h"
#include "guests.h"
#include "date.h"

using namespace std;

void displayMenu(Reservation_Manager &rm);
bool userInput(Reservation_Manager &rm);

int main()
{
	Reservation_Manager rm;
    displayMenu(rm);
}



void displayMenu(Reservation_Manager &rm){
	bool exit = false;
	while (!exit) {
		cout << "\nSelect your choice: " << endl;
		cout << "\t1) Add a reservation." << endl;
		cout << "\t2) Cancel a reservation." << endl;
		cout << "\t3) Display information of a reservation." << endl;
		cout << "\t4) Display information of all reservations." << endl;
		cout << "\t5) Exit the program." << endl << endl;
		exit = userInput(rm);
	}

}

bool userInput(Reservation_Manager &rm){
	char choice;
	cin >> choice;

	int id;
	int temp;
	short userCheckIn;
	short userCheckOut;
	int no_of_people;
	int no_of_nights;
	Date checkIn;
	Date checkOut;
	Information list_people[4];
	short room_id;
	char firstName[25];
	char lastName[25];
	Date dateOfBirth;
	Guests* people;
	Guests_Res_Request* new_req;

	switch (choice) {
		case '1':
		do{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\nHow many nights are they staying: ";
			cin >> no_of_nights;
			if(no_of_nights > 6) cout << "Max of 6 nights available!" << endl;
			else if(no_of_nights < 1) cout << "Must stay for at least 1 night!" << endl;
		}while(no_of_nights > 6 || no_of_nights < 1);

		do{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\nHow many people: ";
			cin >> no_of_people;
			if(no_of_people > 4) cout << "There is a max of 4 people per room!" << endl;
			else if(no_of_people < 1) cout << "Must have at least one person in the room!" << endl;
		}while(no_of_people > 4 || no_of_people < 1);

		for (int i = 0; i < no_of_people && i < 4; i++) {
			cin.clear();
			cin.ignore(1000, '\n');
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

			list_people[i] = Information(firstName, lastName, dateOfBirth);
		}

		do{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Which room?" << endl;
			cin >> room_id;
			if(room_id < 1 || room_id > 20) cout << "Rooms go from 1 to 20!" << endl << endl;
		}while(room_id < 1 || room_id > 20);

		do{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Check in date: \n\tday:";
			cin >> userCheckIn;
			userCheckOut = no_of_nights + userCheckIn;
			if(userCheckIn < 1 || userCheckIn > 6) cout << "Check in dates go from 1 to 6!" << endl;
			else if(userCheckOut > 7) cout << "Check in day and duration of stay bypass hotel's last available day!" << endl;
		}while(userCheckIn < 1 || userCheckIn > 6 || userCheckOut > 7);

		checkIn.setDay(userCheckIn);
		checkIn.setMonth(3);
		checkIn.setYear(2026);

		cout << "Check out will be on day " << userCheckOut << endl;
		checkOut.setDay(userCheckOut);
		checkOut.setMonth(3);
		checkOut.setYear(2026);

		people = new Guests(checkIn, checkOut, list_people, no_of_people, room_id);
		new_req = new Guests_Res_Request(no_of_nights, people);
		id = rm.processReservation(new_req);
		
		cout << "Reservation created at id: " << rm.getNoGuestsRequest() << endl;
		return false;
		break;

		case '2':

		do{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "ID of reservation (0 to exit): ";
			cin >> id;
			if(rm.getNoGuestsRequest() == 0) cout << "There are currently no assigned hotel IDs (0 to exit)" << endl;
			else if(id < 1 || id > rm.getNoGuestsRequest()) cout << "IDs must range from 1 to " << rm.getNoGuestsRequest() << endl;
		}while(id < 0 || id > rm.getNoGuestsRequest());

		if(id <= rm.getNoGuestsRequest() && id > 0){
			rm.cancelReservation(id);
		}else if(id == 0) cout << "Exiting cancelling.";
		return false;
		break;

		case '3':

		do{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "ID of reservation (0 to exit): ";
			cin >> id;
			if(rm.getNoGuestsRequest() == 0) cout << "There are currently no assigned hotel IDs (0 to exit)" << endl;
			else if(id < 1 || id > rm.getNoGuestsRequest()) cout << "IDs must range from 1 to " << rm.getNoGuestsRequest() << endl;
		}while(id < 0 || id > rm.getNoGuestsRequest());

		if(id <= rm.getNoGuestsRequest() && id > 0){
			rm.displayDetails(id);
		}else if(id == 0) cout << "Exiting display.";
		return false;
		break;

		case '4':
		
		for(id = 1; id <= rm.getNoGuestsRequest(); id++){
			rm.displayDetails(id);
		}

		return false;
		break;

		case '5':
		cout << "Exiting..." << endl;
		return true;
		break;

		default:
		cout << "Invalid input" << endl;
		return false;
		break;
	}
}

